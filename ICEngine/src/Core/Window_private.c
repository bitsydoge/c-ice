#include <SDL2/SDL.h>
#include "TypesCore.h"
#include "Window.h"
#include "Window_private.h"

extern ICE_Config CONFIG;
extern ICE_Core CORE;

void ICE_Window_Config()
{
	if (CONFIG.resizable)
		SDL_SetWindowResizable(CORE.window.handle, 1);
	if (CONFIG.fullscreen == 1)
		SDL_SetWindowFullscreen(CORE.window.handle, SDL_WINDOW_FULLSCREEN);
	if (CONFIG.fullscreen == 2)
		SDL_SetWindowFullscreen(CORE.window.handle, SDL_WINDOW_FULLSCREEN_DESKTOP);

	ICE_Window_SetIcon(CONFIG.window_icon);

	SDL_ShowWindow(CORE.window.handle);
}

