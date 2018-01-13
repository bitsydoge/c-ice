#ifndef DEF_ICE_GAME
#define DEF_ICE_GAME

#include "TypesCore.h"
#include "Draw.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "Texture.h"
#include "Debug.h"
#include "TypesCore.h"
#include "Sound.h"
#include "Color.h"
#include "Gui.h"
#include "Label.h"

void iceGameCreate(char *window_title, const unsigned int width_window, const unsigned int height_window);
void iceGameDestroy(iceGame *app);

//get value
iceFloat iceGameDelta();

#endif