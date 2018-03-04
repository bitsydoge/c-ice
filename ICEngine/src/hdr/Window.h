#ifndef DEF_ICE_WINDOW
#define DEF_ICE_WINDOW

#include "TypesCore.h"

void ICE_WindowSetSize(int w, int h);
void ICE_WindowResizable(ICE_Bool yn);
void ICE_WindowFullscreen(ICE_Bool yn);
void ICE_WindowTitle(const char *title);
void ICE_WindowSetIcon(char * path);
int ICE_WindowGetW();
int ICE_WindowGetH();

#endif