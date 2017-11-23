#ifndef DEF_ICE_RENDER
#define DEF_ICE_RENDER 

#include <SDL2/SDL.h>
#include "Types.h"

int ICE_RenderSetClearColor(SDL_Renderer *render,const iceColor color);
int ICE_RenderClear(SDL_Renderer *render);
void ICE_RenderPresent(SDL_Renderer *render);

#endif