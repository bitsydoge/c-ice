#ifndef DEF_ICE_FONT
#define DEF_ICE_FONT

#include "Game.h"
#include <stdio.h>

void ICE_FontLoad(ICE_Game* game, char *path);
void ICE_FontDraw(ICE_Game* game, char* text, int size, ICE_Point point);

#endif
