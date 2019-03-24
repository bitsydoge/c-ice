#ifndef DEF_ICE_RENDERER_PRIVATE_H
#define DEF_ICE_RENDERER_PRIVATE_H

#include "Renderer.h"

#include <SDL2/SDL.h>
#include "Color.h"

struct ICE_Renderer
{
	SDL_Renderer* handle;

};

ICE_Renderer* ICE_Renderer_GetPtr();
int ICE_Renderer_SetColor(const ICE_Color rgba_hex);
int ICE_Renderer_Clear();
void ICE_Renderer_Now();
void ICE_Renderer_SplashScreen();
void ICE_Renderer_Init();
void ICE_Renderer_Quit();
#if defined(_DEBUG)
void ICE_Renderer_Info();
#else
#define ICE_Renderer_Info()
#endif

#endif