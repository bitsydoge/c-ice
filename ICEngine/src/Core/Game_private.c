#include "Game_private.h"

#include "TypesCore.h"

#include "../Framework/Log.h"

#include <stdio.h>
#include "../Core/Window.h"
#include "DebugGUI.h"

ICE_Game game = { 0 };

void ICE_GameObject_Create(char *window_title, const unsigned int width_window, const unsigned int height_window, int argc, char **argv)
{
	game.argc = argc;
	game.argv = argv;

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

#if defined(_DEBUG)
	game.lateDrawDebug = NULL;
#endif
	game.current = &game.state_main;
	game.window.w = (ICE_Float)width_window; game.window.h = (ICE_Float)height_window;

	game.window.auto_clear = ICE_True;
	game.window.auto_render = ICE_True;

	SDL_SetRenderDrawBlendMode(game.window.render, SDL_BLENDMODE_BLEND);

	ICE_Window_SetIcon(0);
	// Debug
	ICE_DebugGUI_ThreadStart();
	ICE_Log(ICE_LOG_SUCCES, "Engine]::[Init]::[Finish");
	printf("\n");
}

void ICE_GameObject_Destroy()
{
	// Debug
	ICE_DebugGUI_Close();

	SDL_DestroyWindow(game.window.handle);
	SDL_DestroyRenderer(game.window.render);
}