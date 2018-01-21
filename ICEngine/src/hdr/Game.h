#ifndef DEF_ICE_GAME
#define DEF_ICE_GAME

#include "TypesCore.h"

void iceGameCreate(char *window_title, const unsigned int width_window, const unsigned int height_window);
void iceGameDestroy(iceGame *app);

//get value
iceFloat iceGameDelta();
iceFloat iceGameFps();

iceGame* EOFUNC_iceGameGetGameObject();

#endif