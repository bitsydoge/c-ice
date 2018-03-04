#include "hdr/Game_private.h"
#include "hdr/TypesCore.h"
#include "hdr/Log.h"

ICE_Game game = { 0 };

void ICE_GameCreate(char *window_title, const unsigned int width_window, const unsigned int height_window)
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

	ICE_Log(ICE_LOG_SUCCES, "GAMELAUNCH");
}

void ICE_GameDestroy()
{
	SDL_DestroyWindow(game.window.handle);
	SDL_DestroyRenderer(game.window.render);
}