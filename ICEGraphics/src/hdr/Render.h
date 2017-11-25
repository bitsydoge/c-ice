#ifndef DEF_ICE_RENDER
#define DEF_ICE_RENDER 

#include <SDL2/SDL.h>
#include "TypesCore.h"
#include "StructCore.h"

int iceRenderSetClearColor(SDL_Renderer *render,const iceColor color);
void iceRenderSetBackgroundColor(iceGame *game, iceColor color);
int iceRenderClear(SDL_Renderer *render);
void iceRenderPresent(SDL_Renderer *render);

#endif