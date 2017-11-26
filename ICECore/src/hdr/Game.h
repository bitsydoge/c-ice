#ifndef DEF_ICE_GAME
#define DEF_ICE_GAME

#include "StructCore.h"
#include "Draw.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "Texture.h"
#include "Debug.h"
#include "TypesCore.h"
#include "Sound.h"

iceGame iceGameCreate(char *window_title, const unsigned int width_window, const unsigned int height_window);
void iceGameDestroy(iceGame *app);

#endif