#include "Game_private.h"

#include "TypesCore.h"

#include "../Framework/Log.h"

#include <stdio.h>

ICE_Game game = { 0 };

void ICE_Game_Create(char *window_title, const unsigned int width_window, const unsigned int height_window)
{
	// Window and Render
	game.window.handle = SDL_CreateWindow(
		window_title,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		width_window,
		height_window,
		SDL_WINDOW_OPENGL | SDL_RENDERER_PRESENTVSYNC | SDL_WINDOW_RESIZABLE
	);
	game.window.render = SDL_CreateRenderer(game.window.handle, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawBlendMode(game.window.render, SDL_BLENDMODE_BLEND);
	
	game.window.w = width_window; game.window.h = height_window;
	game.camera.w = width_window; game.camera.h = height_window;

	game.window.auto_clear = 1;
	game.window.auto_render = 1;

	game.state_mngr.current = game.state_main;

	printf("------------------------\n");
	ICE_Log(ICE_LOG_SUCCES, "Engine]::[Init]::[Finish");
	printf("------------------------\n");
	printf("\n");
}

void ICE_Game_Destroy()
{
	SDL_DestroyWindow(game.window.handle);
	SDL_DestroyRenderer(game.window.render);
}