#ifndef DEF_ICE_RENDER
#define DEF_ICE_RENDER 

#include <SDL2/SDL.h>
#include "TypesCore.h"
#include <string.h>

int iceDrawClearColor(const iceColor color);
void iceDrawSetColor(iceColor color);
int iceDrawClear();
void iceDrawPresent();
void iceDrawAllEntity();
void iceDrawLabelScreen();
void iceDrawLabelWorld();
void iceDrawAllGui();

#endif