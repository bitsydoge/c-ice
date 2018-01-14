#ifndef DEF_ICE_RENDER
#define DEF_ICE_RENDER 

#include "TypesCore.h"

int iceDrawClearColor(const iceColor color);
void iceDrawSetColor(iceColor color);
int iceDrawClear();
void iceDrawPresent();
void iceDrawAllEntity();
void iceDrawLabelScreen();
void iceDrawLabelWorld();
void iceDrawAllGui();

#endif