#include "hdr/Texture.h"
#include <stdio.h>
#include "external/lodepng.h"
#include "hdr/TerminalColor.h"
#include "external/rlutil.h"
#include "external/icestd.h"

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
Uint32 static const rmask = 0xff000000;
Uint32 static const gmask = 0x00ff0000;
Uint32 static const bmask = 0x0000ff00;
Uint32 static const amask = 0x000000ff;
#else
Uint32 static const rmask = 0x000000ff;
Uint32 static const gmask = 0x0000ff00;
Uint32 static const bmask = 0x00ff0000;
Uint32 static const amask = 0xff000000;
#endif

ICE_Texture* ICE_LoadPNG(SDL_Renderer *render, char *path){
	unsigned char* raw_img;
	unsigned w, h;
	unsigned const error = lodepng_decode32_file(&raw_img, &w, &h, path);
	if (error)
		printf("\"%s\" -> PNG Decoder error %u : %s\n", path, error, lodepng_error_text(error));

	SDL_Surface *surf = SDL_CreateRGBSurfaceFrom(raw_img, w, h, 32, 4 * w, rmask, gmask, bmask, amask);
	if (error){
		#include "raw/Raw_error.c"
		surf = SDL_CreateRGBSurfaceFrom((void*)ice_raw_img_error.pixel_data, ice_raw_img_error.width,
			ice_raw_img_error.height, ice_raw_img_error.bytes_per_pixel * 8, ice_raw_img_error.bytes_per_pixel*ice_raw_img_error.width,
			rmask, gmask, bmask, amask);
	}
	ICE_Texture *text = (ICE_Texture*)malloc(sizeof(ICE_Texture));
	text->handle = SDL_CreateTextureFromSurface(render, surf);
	if (text->handle == NULL)
		printf("CRITICAL : Can't create Texture from Surface \"%s\" : %s \n", path, SDL_GetError());
	text->w = surf->w; text->h = surf->h;
	SDL_FreeSurface(surf);
	return text;
}

ICE_Texture* ICE_LoadBMP(SDL_Renderer *render, char *path){
	SDL_Surface *surf = SDL_LoadBMP(path);
	if (surf == NULL){
		#include "raw/Raw_error.c"
		surf = SDL_CreateRGBSurfaceFrom((void*)ice_raw_img_error.pixel_data, ice_raw_img_error.width,
			ice_raw_img_error.height, ice_raw_img_error.bytes_per_pixel * 8, ice_raw_img_error.bytes_per_pixel*ice_raw_img_error.width,
			rmask, gmask, bmask, amask);
	}
	ICE_Texture *text = (ICE_Texture*)malloc(sizeof(ICE_Texture));
	text->handle = SDL_CreateTextureFromSurface(render, surf);
	if (text->handle == NULL)
		printf("CRITICAL : Can't create Texture from Surface \"%s\" : %s \n", path, SDL_GetError());
	text->w = surf->w; text->h = surf->h;
	SDL_FreeSurface(surf);
	return text;
}

ICE_Texture* ICE_LoadBMPAlpha(SDL_Renderer *render, char *path, const ICE_Color rgba_hex){
	const int r = rgba_hex >> 24 & 255;
	const int g = rgba_hex >> 16 & 255;
	const int b = rgba_hex >> 8 & 255;
	const int a = rgba_hex & 255;

	SDL_Surface *surf = SDL_LoadBMP(path);
	if (surf == NULL){
		#include "raw/Raw_error.c"
		surf = SDL_CreateRGBSurfaceFrom((void*)ice_raw_img_error.pixel_data, ice_raw_img_error.width,
			ice_raw_img_error.height, ice_raw_img_error.bytes_per_pixel * 8, ice_raw_img_error.bytes_per_pixel*ice_raw_img_error.width,
			rmask, gmask, bmask, amask);
	}
	else if (r >= 0 && g >= 0 && b >= 0){
		SDL_SetColorKey(surf, SDL_TRUE, SDL_MapRGB(surf->format, r, g, b));
		if (a < 255 && a >= 0)
			SDL_SetSurfaceAlphaMod(surf, a);
	}
	ICE_Texture *text = (ICE_Texture*)malloc(sizeof(ICE_Texture));
	text->handle = SDL_CreateTextureFromSurface(render, surf);
	if (text->handle == NULL){
		ICE_TC_SetColor(LIGHTRED);
		printf("CRITICAL");
		ICE_TC_ResetColor();
		printf(" : Can't create Texture from Surface \"%s\" : %s \n", path, SDL_GetError());
	}
	text->w = surf->w; text->h = surf->h;
	SDL_FreeSurface(surf);
	return text;
}

void ICE_DestroyTexture(ICE_Texture *tex){
	SDL_DestroyTexture(tex->handle);
	free(tex);
}

int ICE_TextureRender(ICE_Game *game, int man, int text, SDL_Rect* source, SDL_Rect* destination){
	if (destination){
		SDL_Rect dst = { destination->x - (destination->w / 2), destination->y - (destination->h / 2), destination->w, destination->h };
		return SDL_RenderCopy(game->render, game->texturemanager[man].texture[text].handle, source, &dst);
	}
	else
		return SDL_RenderCopy(game->render, game->texturemanager[man].texture[text].handle, source, NULL);
}

int ICE_TextureRenderNC(ICE_Game *game, int man, int text, SDL_Rect* source, SDL_Rect* destination) {
	if (destination) {
		return SDL_RenderCopy(game->render, game->texturemanager[man].texture[text].handle, source, destination);
	}
	return SDL_RenderCopy(game->render, game->texturemanager[man].texture[text].handle, source, NULL);
}

int ICE_TextureRenderEx(SDL_Renderer* renderer, const ICE_Texture *tex, SDL_Rect* source, SDL_Rect* destination, const double angle){
	return SDL_RenderCopyEx(renderer, tex->handle, source, destination, angle, NULL, SDL_FLIP_NONE);
}

ICE_Color NewColor(const unsigned int r, const unsigned int g,const unsigned int b){
	return (r << 24) + (g << 16) + (b << 8) + 255;
}

ICE_Color NewColorA(const unsigned int r, const unsigned int g, const unsigned int b, const unsigned int a) {
	return (r << 24) + (g << 16) + (b << 8) + a;
}


//////////////////////// TEXTURE MANAGER /////////////////////////////////
//                                                                      //
//       The texture create and texture manager create                  //
//       functions                                                      //
//                                                                      //
//                                                                      //
//                                                                      //
//                                                                      //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

void ICE_CreateTextureManager(ICE_Game *game){
	ICE_TextureManager texture_manager = { 0 };
	texture_manager.array_size = 4;
	texture_manager.texture = calloc(texture_manager.array_size, sizeof(ICE_Texture));
	texture_manager.ren = game->render;
	game->texturemanager_size++;
	game->texturemanager = realloc(game->texturemanager, game->texturemanager_size * sizeof(ICE_TextureManager));
	game->texturemanager[game->texturemanager_size - 1] = texture_manager;
	printf("TextureManager number %d created \n", game->texturemanager_size - 1);
}

int ICE_CreateTexture(ICE_Game *game, int manager, char* path){
	Uint32 color_hex = 0xFF00FFFF;
	char path2[500]; strcpy(path2, path);
	char* ext = icestd_ext(path2);
	icestd_sup(ext);

	ICE_Texture *text;
	if (!strcmp(ext, "PNG")){
		text = ICE_LoadPNG(game->texturemanager[manager].ren, path);
		printf("Texture number %d created on from : \"", game->texturemanager[manager].nb_existing_texture);
		ICE_TC_SetColor(YELLOW);
		printf("%s", path);
		ICE_TC_ResetColor();
		printf("\"\n");
	}
	else if (!strcmp(ext, "BMP")){
		if (color_hex != 0){
			text = ICE_LoadBMPAlpha(game->texturemanager[manager].ren, path, color_hex);
			printf("Texture number %d created from : \"", game->texturemanager[manager].nb_existing_texture);
			ICE_TC_SetColor(YELLOW);
			printf("%s", path);
			ICE_TC_ResetColor();
			printf("\"\n");
		}
		else{
			text = ICE_LoadBMP(game->texturemanager[manager].ren, path);
			printf("Texture number %d created from : \"", game->texturemanager[manager].nb_existing_texture);
			ICE_TC_SetColor(YELLOW);
			printf("%s", path);
			ICE_TC_ResetColor();
			printf("\"\n");
		}
	}
	else{
		text = ICE_LoadBMP(game->texturemanager[manager].ren, "res/img/error");
		ICE_TC_SetColor(LIGHTRED);
		printf("ERROR ");
		ICE_TC_ResetColor();
		printf(": %s is not a valid filetype for loading texture.\n", ext);
	}
	text->exist = 1;
	SDL_QueryTexture(text->handle, NULL, NULL, &text->w, &text->h);
	game->texturemanager[manager].texture[game->texturemanager[manager].nb_existing_texture] = *text;
	game->texturemanager[manager].nb_existing_texture++;
	
	if (game->texturemanager[manager].array_size <= game->texturemanager[manager].nb_existing_texture){
		ICE_TC_SetColor(LIGHTCYAN);
		printf("Extending texture size to %d \n", game->texturemanager[manager].array_size * 2);
		ICE_TC_ResetColor();
		game->texturemanager[manager].texture = realloc(game->texturemanager[manager].texture, sizeof(ICE_Texture)*(game->texturemanager[manager].array_size * 2));
		game->texturemanager[manager].array_size *= 2;
	}
	free(text);
	return game->texturemanager->nb_existing_texture - 1;
}