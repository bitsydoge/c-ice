#ifndef DEF_ICE_RENDER
#define DEF_ICE_RENDER 
#include <SDL2/SDL.h>

int ICE_SetRenderClearColor(SDL_Renderer *render,const Uint32 rgba_hex);
int ICE_RenderClear(SDL_Renderer *render);
void ICE_RenderPresent(SDL_Renderer *render);

#endif