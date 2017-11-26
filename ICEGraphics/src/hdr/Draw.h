#ifndef DEF_ICE_RENDER
#define DEF_ICE_RENDER 

#include <SDL2/SDL.h>
#include "TypesCore.h"
#include "StructCore.h"
#include <string.h>

int iceDrawClearColor(SDL_Renderer *render,const iceColor color);
void iceDrawSetColor(iceGame *game, iceColor color);
int iceDrawClear(SDL_Renderer *render);
void iceDrawPresent(SDL_Renderer *render);
void iceDrawAllEntity(iceGame *game);
void iceDrawLabelScreen(iceGame *game);
void iceDrawLabelWorld(iceGame *game);
void iceDrawAllGui(iceGame *game);

#endif