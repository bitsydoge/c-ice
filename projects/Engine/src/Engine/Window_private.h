#ifndef DEF_ICE_WINDOW_PRIVATE_H
#define DEF_ICE_WINDOW_PRIVATE_H

#include "Window.h"

#include "../Framework/String_.h"

#include <SDL2/SDL.h>

struct ICE_Window
{
	ICE_String				title;
	int w, h;
	SDL_Window* handle;
};

ICE_Window* ICE_Window_Get();
void ICE_Window_Config();

#endif