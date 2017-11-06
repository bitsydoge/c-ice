#ifndef DEF_ICE_FONT
#define DEF_ICE_FONT

#include "Game.h"

void ICE_FontLoad(ICE_Game* game, char *path);
void ICE_FontDraw(ICE_Game* game, char* text, int size, ICE_Rect rect);

#endif
