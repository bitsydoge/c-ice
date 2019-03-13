#ifndef DEF_ICE_RENDERER_PRIVATE_H
#define DEF_ICE_RENDERER_PRIVATE_H

#include "Renderer.h"

#include <SDL2/SDL.h>

struct ICE_Render
{
	SDL_Renderer* render;

}; typedef struct ICE_Render ICE_Renderer;

#endif