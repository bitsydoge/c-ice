#include "hdr/Texture.h"
#include "external/lodepng.h"
#include "external/icestd.h"

#include <SDL2/SDL.h>

#include <stdio.h>
#include "hdr/Texture_private.h"
#include "hdr/Terminal.h"

extern iceGame game;

//////////////////////// TEXTURE MANAGER /////////////////////////////////
//                                                                      //
//       The texture create and texture manager create                  //
//       functions                                                      //                        
//                                                                      //
//////////////////////////////////////////////////////////////////////////

void iceTextureManagerCreate(){
	iceTextureManager texture_manager = { 0 };
	texture_manager.array_size = ICE_DEFAULT_TEXTURE_SIZE;
	texture_manager.texture = calloc(texture_manager.array_size, sizeof(iceTexture));
	texture_manager.ren = game.drawer.render;
	game.texturemanager_nb++;
	game.texturemanager = realloc(game.texturemanager, game.texturemanager_nb * sizeof(iceTextureManager));
	game.texturemanager[game.texturemanager_nb - 1] = texture_manager;
	printf("TextureManager number %d created \n", game.texturemanager_nb - 1);
}

int iceTextureCreate(int manager, char* path){

	Uint32 color_hex = 0xFF00FFFF;
	char path2[500]; strcpy(path2, path);
	char* ext = icestd_ext(path2);
	icestd_sup(ext);

	iceTexture *text;
	if (!strcmp(ext, "PNG")){
		text = iceLoadPNG(path);
		printf("Texture number %d created on from : \"", game.texturemanager[manager].nb_existing);
		iceTermSetColor(iceYELLOW);
		printf("%s", path);
		iceTermResetColor();
		printf("\"\n");
	}
	else if (!strcmp(ext, "JPG")) {
		text = iceLoadJPG(path);
		printf("Texture number %d created on from : \"", game.texturemanager[manager].nb_existing);
		iceTermSetColor(iceYELLOW);
		printf("%s", path);
		iceTermResetColor();
		printf("\"\n");
	}
	else if (!strcmp(ext, "BMP")){
		if (color_hex != 0){
			text = iceLoadBMPAlpha(path, color_hex);
			printf("Texture number %d created from : \"", game.texturemanager[manager].nb_existing);
			iceTermSetColor(iceYELLOW);
			printf("%s", path);
			iceTermResetColor();
			printf("\"\n");
		}
		else{
			text = iceLoadBMP(path);
			printf("Texture number %d created from : \"", game.texturemanager[manager].nb_existing);
			iceTermSetColor(iceYELLOW);
			printf("%s", path);
			iceTermResetColor();
			printf("\"\n");
		}
	}
	else{
		text = iceLoadBMP("res/img/error");
		iceTermSetColor(iceLIGHTRED);
		printf("ERROR ");
		iceTermResetColor();
		printf(": %s is not a valid filetype for loading texture.\n", ext);
	}
	text->exist = 1;
	SDL_QueryTexture(text->handle, NULL, NULL, &text->w, &text->h);
	game.texturemanager[manager].texture[game.texturemanager[manager].nb_existing] = *text;
	game.texturemanager[manager].nb_existing++;
	
	if (game.texturemanager[manager].array_size <= game.texturemanager[manager].nb_existing){
		iceTermSetColor(iceLIGHTCYAN);
		printf("Extending texture size to %d \n", game.texturemanager[manager].array_size * 2);
		iceTermResetColor();
		game.texturemanager[manager].texture = realloc(game.texturemanager[manager].texture, sizeof(iceTexture)*(game.texturemanager[manager].array_size * 2));
		game.texturemanager[manager].array_size *= 2;
	}
	free(text);
	return game.texturemanager->nb_existing - 1;
}

int iceTextureGetWidth(int manager, int texture)
{
	return game.texturemanager[manager].texture[texture].w;
}

int iceTextureGetHeight(int manager, int texture)
{
	return game.texturemanager[manager].texture[texture].h;
}