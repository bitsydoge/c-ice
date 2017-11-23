#ifndef DEF_iceRENDER
#define DEF_iceRENDER 

#include <SDL2/SDL.h>
#include "Types.h"

int iceRenderSetClearColor(SDL_Renderer *render,const iceColor color);
int iceRenderClear(SDL_Renderer *render);
void iceRenderPresent(SDL_Renderer *render);

#endif