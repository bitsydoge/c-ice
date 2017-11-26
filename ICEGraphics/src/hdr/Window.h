#ifndef DEF_ICE_WINDOW
#define DEF_ICE_WINDOW

#include "StructCore.h"

void iceWindowSetSize(iceGame *game, int w, int h);
void iceWindowResizable(iceGame *game, iceBool yn);
void iceWindowFullscreen(iceGame *game, iceBool yn);
void iceWindowTitle(iceGame *game, const char *title);
void iceWindowSetIcon(iceWindow *window, char * path);

#endif