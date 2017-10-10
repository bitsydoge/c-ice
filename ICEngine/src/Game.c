#include "hdr/Game.h"
#include "hdr/Render.h"
#include "hdr/Type.h"
#include <stdio.h>

void ICE_SetWindowIcon(ICE_Window *window, char * path)
{
	SDL_SetWindowIcon(window, SDL_LoadBMP(path));
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
	//

	ICE_SetWindowIcon(game.window, "res/img/error.bmp");


	return game;    
}

void ICE_DestroyGame(ICE_Game *app)
{
	SDL_DestroyWindow(app->window);
	SDL_DestroyRenderer(app->render);
	free(app->input);
}