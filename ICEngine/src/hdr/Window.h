#ifndef DEF_ICE_WINDOW
#define DEF_ICE_WINDOW

#include "TypesCore.h"

void iceWindowSetSize(int w, int h);
void iceWindowResizable(iceBool yn);
void iceWindowFullscreen(iceBool yn);
void iceWindowTitle(const char *title);
void iceWindowSetIcon(char * path);

#endif