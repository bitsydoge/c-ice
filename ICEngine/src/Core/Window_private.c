#include <SDL2/SDL.h>
#include "TypesCore.h"
#include "Window.h"
#include "Window_private.h"
#include "../Framework/Log.h"

extern ICE_Config CONFIG;
extern ICE_Core CORE;

void ICE_Window_Config()
{
	if (CONFIG.resizable)
		ICE_Window_SetResizable(1);

	if (CONFIG.fullscreen == 1)
		ICE_Window_SetFullscreen(SDL_WINDOW_FULLSCREEN);
	
	if (CONFIG.fullscreen == 2)
	{
		int display_index = SDL_GetWindowDisplayIndex(CORE.window.handle);
		SDL_Rect screen_size;
		SDL_GetDisplayBounds(display_index, &screen_size);
		ICE_Window_SetSize(screen_size.w, screen_size.h);
		ICE_Window_SetFullscreen(SDL_WINDOW_FULLSCREEN_DESKTOP);
	}
	ICE_Window_SetIcon(CONFIG.window_icon);
	SDL_ShowWindow(CORE.window.handle);
}

