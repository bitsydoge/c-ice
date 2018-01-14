#ifndef DEF_ICE_GUI
#define DEF_ICE_GUI

#include "Vector.h"

#define ICE_DEFAULT_GUI_SIZE 4

void iceGuiManagerCreate();

void iceGuiCreate(int man);

void iceGuiCreateTextureCache(int man, int gui);

void iceGuiSetTexture(int man, int gui, int texture_man, int texture);

void iceGuiSetBox(int man, int gui, iceBox box);

void iceGuiSetPos(int man, int gui, iceVect pos);

void iceGuiSetSize(int man, int gui, iceFloat w, iceFloat h);

void iceGuiRect(int man, int text, iceBox rect);

#endif
