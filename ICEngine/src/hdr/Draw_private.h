#ifndef DEF_ICE_DRAW_PRIVATE
#define DEF_ICE_DRAW_PRIVATE
#include "Color.h"

int iceDrawClearColor(const iceColor color);
int iceDrawClear();
void iceDrawPresent();
void iceDrawAllEntity();
void iceDrawLabelScreen();
void iceDrawLabelWorld();
void iceDrawAllGui();

#endif