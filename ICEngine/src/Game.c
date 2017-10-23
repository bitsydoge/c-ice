#include "hdr/Game.h"
#include "hdr/Render.h"
#include <stdio.h>
#include <string.h>

void ICE_SetWindowIcon(ICE_Window *window, char * path)
{
	if (!path)
	{
		#include "RawImg_icon.c"

		Uint32 rmask, gmask, bmask, amask;
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
		int shift = (my_icon.bytes_per_pixel == 3) ? 8 : 0;
		rmask = 0xff000000 >> shift;
		gmask = 0x00ff0000 >> shift;
		bmask = 0x0000ff00 >> shift;
		amask = 0x000000ff >> shift;
#else // little endian, like x86
		rmask = 0x000000ff;
		gmask = 0x0000ff00;
		bmask = 0x00ff0000;
		amask = (ice_raw_img_icon.bytes_per_pixel == 3) ? 0 : 0xff000000;
#endif

		SDL_Surface* icon = SDL_CreateRGBSurfaceFrom((void*)ice_raw_img_icon.pixel_data, ice_raw_img_icon.width,
			ice_raw_img_icon.height, ice_raw_img_icon.bytes_per_pixel * 8, ice_raw_img_icon.bytes_per_pixel*ice_raw_img_icon.width,
			rmask, gmask, bmask, amask);

		SDL_SetWindowIcon(window, icon);

		SDL_FreeSurface(icon);
	}
	else
	{
		SDL_Surface *icon = SDL_LoadBMP(path);
		SDL_SetWindowIcon(window, icon);
		SDL_FreeSurface(icon);
	}
}

ICE_Game ICE_CreateApp(char *window_title, const unsigned int width_window, const unsigned int height_window)
{
	ICE_Game game = {0};

	// Window and Render
	game.window = SDL_CreateWindow(window_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width_window, height_window, SDL_RENDERER_PRESENTVSYNC | SDL_WINDOW_RESIZABLE);
	game.render = SDL_CreateRenderer(game.window, -1, SDL_RENDERER_ACCELERATED);
	ICE_SetRenderClearColor(game.render, 0x2bccf4ff);    
	// 

	// Input
	game.input = (ICE_Input*)calloc(1, sizeof(ICE_Input));
	//

	// TextureManager
	game.texturemanager_size = 0;

	// Render Info
	SDL_RendererInfo info;
	SDL_GetRendererInfo(game.render, &info);
	printf("Graphic API : %s \n", info.name);
	
	// Time
	memset(&game.time, 0, sizeof(ICE_Time));
	game.time.fps = 120;	game.time.ticks = 1000 / game.time.fps;

	ICE_SetWindowIcon(game.window, 0);


	return game;    
}

void ICE_DestroyGame(ICE_Game *app)
{
	SDL_DestroyWindow(app->window);
	SDL_DestroyRenderer(app->render);
	free(app->input);
}