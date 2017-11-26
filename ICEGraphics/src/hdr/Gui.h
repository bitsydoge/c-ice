#ifndef DEF_ICE_GUI
#define DEF_ICE_GUI
#include "StructCore.h"
#include "Texture.h"

#define ICE_DEFAULT_GUI_SIZE 4

void iceGuiManagerCreate(iceGame *game);

void iceGuiCreate(iceGame *game, int man);

void iceGuiSetTexture(iceGame *game, int man, int gui, int texture_man, int texture);

void iceGuiSetBox(iceGame *game, int man, int gui, iceBox box);

void iceGuiSetPos(iceGame *game, int man, int gui, iceVect pos);

void iceGuiSetSize(iceGame *game, int man, int gui, iceFloat w, iceFloat h);

void iceGuiRect(iceGame *game, int man, int text, iceBox rect);

#endif
