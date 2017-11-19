#ifndef DEF_ICE_RENDER
#define DEF_ICE_RENDER 

#include <SDL2/SDL.h>
#include "Struct.h"

int ICE_RenderSetClearColor(SDL_Renderer *render,const ICE_Color color);
int ICE_RenderClear(SDL_Renderer *render);
void ICE_RenderPresent(SDL_Renderer *render);

#endif