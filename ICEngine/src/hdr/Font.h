#ifndef DEF_ICE_FONT
#define DEF_ICE_FONT

#include "TypesCore.h"

void ICE_Font_Load(char *path);
void ICE_Font_Draw(char* text, ICE_Vect vect, ICE_Color fg, ICE_Color bg);

#endif
