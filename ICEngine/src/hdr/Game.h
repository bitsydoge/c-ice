#ifndef DEF_ICE_GAME
#define DEF_ICE_GAME
#include "Struct.h"
#include "Render.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "Texture.h"
#include "Sound.h"
#include "Debug.h"
#include "Types.h"

ICE_Game ICE_GameCreate(char *window_title, const unsigned int width_window, const unsigned int height_window);
void ICE_GameDestroy(ICE_Game *app);
void ICE_GameResizable(ICE_Game *game, iceBool yn);
void ICE_GameTitle(ICE_Game *game, const char *title);
void ICE_GameSetIcon(ICE_Window *window, char * path);

#endif