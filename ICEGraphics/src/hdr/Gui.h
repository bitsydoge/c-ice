#ifndef DEF_ICE_GUI
#define DEF_ICE_GUI
#include "StructCore.h"
#include "Texture.h"

#define ICE_DEFAULT_GUI_SIZE 4

void iceGuiCreateManager();
void iceGuiCreate();
void iceGuiRect(iceGame *game, int man, int text, iceBox rect);

#endif
