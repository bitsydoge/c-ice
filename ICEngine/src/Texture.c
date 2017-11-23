#include "hdr/Texture.h"


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

ICE_Texture* ICE_LoadJPG(SDL_Renderer *render, char *path)
{
	/*
	
	int size;
	char *buf;
	FILE *f = fopen(path, "rb");
	if (!f) {
		printf("Error opening the input file.\n");
		return 1;
	}
	fseek(f, 0, SEEK_END);
	size = (int)ftell(f);
	buf = (char*)malloc(size);
	fseek(f, 0, SEEK_SET);
	size = (int)fread(buf, 1, size, f);
	fclose(f);

	njInit();
	if (njDecode(buf, size)) {
		free((void*)buf);
		printf("Error decoding the input file.\n");
	}
	
	fclose(f);
	SDL_Surface *surf = SDL_CreateRGBSurfaceFrom(buf, njGetWidth(), njGetHeight(), 32, 4 * njGetWidth(), rmask, gmask, bmask, amask);
	if (!surf) {
	*/
	#include "raw/Raw_error.c"
		SDL_Surface *surf = SDL_CreateRGBSurfaceFrom((void*)ice_raw_img_error.pixel_data, ice_raw_img_error.width,
			ice_raw_img_error.height, ice_raw_img_error.bytes_per_pixel * 8, ice_raw_img_error.bytes_per_pixel*ice_raw_img_error.width,
			rmask, gmask, bmask, amask);
	//}
	ICE_Texture *text = (ICE_Texture*)malloc(sizeof(ICE_Texture));
	text->handle = SDL_CreateTextureFromSurface(render, surf);
	if (text->handle == NULL)
		printf("CRITICAL : Can't create Texture from Surface \"%s\" : %s \n", path, SDL_GetError());
	text->w = surf->w; text->h = surf->h;
	SDL_FreeSurface(surf);
	//free((void*)buf);
	//njDone();
	return text;
}

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

ICE_Texture* ICE_LoadBMPAlpha(SDL_Renderer *render, char *path, const iceColor rgba_hex){
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
		ICE_TermSetColor(LIGHTRED);
		printf("CRITICAL");
		ICE_TermResetColor();
		printf(" : Can't create Texture from Surface \"%s\" : %s \n", path, SDL_GetError());
	}
	text->w = surf->w; text->h = surf->h;
	SDL_FreeSurface(surf);
	return text;
}

void ICE_TextureDestroy(ICE_Texture *tex){
	SDL_DestroyTexture(tex->handle);
	free(tex);
}

int ICE_TextureRender(ICE_Game *game, int man, int text, iceRect* src, iceRect* dst){
	if(!src && dst)
	{
		SDL_Rect s_dst = iceRectToSDL(dst);
		return SDL_RenderCopy(game->render, game->texturemanager[man].texture[text].handle, NULL, &s_dst);
	}
	if (src && !dst)
	{
		SDL_Rect s_src = iceRectToSDL(src);
		return SDL_RenderCopy(game->render, game->texturemanager[man].texture[text].handle, &s_src, NULL);
	}
	if (!src && !dst)
	{
		return SDL_RenderCopy(game->render, game->texturemanager[man].texture[text].handle, NULL, NULL);
	}
		SDL_Rect s_dst = iceRectToSDL(dst);
		SDL_Rect s_src = iceRectToSDL(src);
		return SDL_RenderCopy(game->render, game->texturemanager[man].texture[text].handle, &s_src, &s_dst);
}

int ICE_TextureRenderCentered(ICE_Game *game, int man, int text, iceRect* src, iceRect* dst) {
	if (!src && dst)
	{
		SDL_Rect s_dst = iceRectToSDL(dst);
		s_dst.x -= s_dst.w / 2; s_dst.y -= s_dst.h / 2;
		return SDL_RenderCopy(game->render, game->texturemanager[man].texture[text].handle, NULL, &s_dst);
	}
	if (src && !dst)
	{
		SDL_Rect s_src = iceRectToSDL(src);
		return SDL_RenderCopy(game->render, game->texturemanager[man].texture[text].handle, &s_src, NULL);
	}
	if (!src && !dst)
	{
		return SDL_RenderCopy(game->render, game->texturemanager[man].texture[text].handle, NULL, NULL);
	}
	SDL_Rect s_dst = iceRectToSDL(dst);
	s_dst.x -= s_dst.w / 2; s_dst.y -= s_dst.h / 2;
	SDL_Rect s_src = iceRectToSDL(src);
	return SDL_RenderCopy(game->render, game->texturemanager[man].texture[text].handle, &s_src, &s_dst);
}

int ICE_TextureRenderEx(SDL_Renderer* renderer, const ICE_Texture *tex, SDL_Rect* source, SDL_Rect* destination, const double angle){
	return SDL_RenderCopyEx(renderer, tex->handle, source, destination, angle, NULL, SDL_FLIP_NONE);
}

iceColor NewColor(const unsigned int r, const unsigned int g,const unsigned int b){
	return (r << 24) + (g << 16) + (b << 8) + 255;
}

iceColor NewColorA(const unsigned int r, const unsigned int g, const unsigned int b, const unsigned int a) {
	return (r << 24) + (g << 16) + (b << 8) + a;
}

//////////////////////// TEXTURE MANAGER /////////////////////////////////
//                                                                      //
//       The texture create and texture manager create                  //
//       functions                                                      //                        
//                                                                      //
//////////////////////////////////////////////////////////////////////////

void ICE_TextureManagerCreate(ICE_Game *game){
	ICE_TextureManager texture_manager = { 0 };
	texture_manager.array_size = 4;
	texture_manager.texture = calloc(texture_manager.array_size, sizeof(ICE_Texture));
	texture_manager.ren = game->render;
	game->texturemanager_size++;
	game->texturemanager = realloc(game->texturemanager, game->texturemanager_size * sizeof(ICE_TextureManager));
	game->texturemanager[game->texturemanager_size - 1] = texture_manager;
	printf("TextureManager number %d created \n", game->texturemanager_size - 1);
}

int ICE_TextureCreate(ICE_Game *game, int manager, char* path){
	Uint32 color_hex = 0xFF00FFFF;
	char path2[500]; strcpy(path2, path);
	char* ext = icestd_ext(path2);
	icestd_sup(ext);

	ICE_Texture *text;
	if (!strcmp(ext, "PNG")){
		text = ICE_LoadPNG(game->texturemanager[manager].ren, path);
		printf("Texture number %d created on from : \"", game->texturemanager[manager].nb_existing_texture);
		ICE_TermSetColor(YELLOW);
		printf("%s", path);
		ICE_TermResetColor();
		printf("\"\n");
	}
	else if (!strcmp(ext, "JPG")) {
		text = ICE_LoadJPG(game->texturemanager[manager].ren, path);
		printf("Texture number %d created on from : \"", game->texturemanager[manager].nb_existing_texture);
		ICE_TermSetColor(YELLOW);
		printf("%s", path);
		ICE_TermResetColor();
		printf("\"\n");
	}
	else if (!strcmp(ext, "BMP")){
		if (color_hex != 0){
			text = ICE_LoadBMPAlpha(game->texturemanager[manager].ren, path, color_hex);
			printf("Texture number %d created from : \"", game->texturemanager[manager].nb_existing_texture);
			ICE_TermSetColor(YELLOW);
			printf("%s", path);
			ICE_TermResetColor();
			printf("\"\n");
		}
		else{
			text = ICE_LoadBMP(game->texturemanager[manager].ren, path);
			printf("Texture number %d created from : \"", game->texturemanager[manager].nb_existing_texture);
			ICE_TermSetColor(YELLOW);
			printf("%s", path);
			ICE_TermResetColor();
			printf("\"\n");
		}
	}
	else{
		text = ICE_LoadBMP(game->texturemanager[manager].ren, "res/img/error");
		ICE_TermSetColor(LIGHTRED);
		printf("ERROR ");
		ICE_TermResetColor();
		printf(": %s is not a valid filetype for loading texture.\n", ext);
	}
	text->exist = 1;
	SDL_QueryTexture(text->handle, NULL, NULL, &text->w, &text->h);
	game->texturemanager[manager].texture[game->texturemanager[manager].nb_existing_texture] = *text;
	game->texturemanager[manager].nb_existing_texture++;
	
	if (game->texturemanager[manager].array_size <= game->texturemanager[manager].nb_existing_texture){
		ICE_TermSetColor(LIGHTCYAN);
		printf("Extending texture size to %d \n", game->texturemanager[manager].array_size * 2);
		ICE_TermResetColor();
		game->texturemanager[manager].texture = realloc(game->texturemanager[manager].texture, sizeof(ICE_Texture)*(game->texturemanager[manager].array_size * 2));
		game->texturemanager[manager].array_size *= 2;
	}
	free(text);
	return game->texturemanager->nb_existing_texture - 1;
}

int ICE_TextureGetWidth(ICE_Game *game, int manager, int texture)
{
	return game->texturemanager[manager].texture[texture].w;
}

int ICE_TextureGetHeight(ICE_Game *game, int manager, int texture)
{
	return game->texturemanager[manager].texture[texture].h;
}