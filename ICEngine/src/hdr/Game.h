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


void ICE_SetWindowIcon(ICE_Window *window, char * path);
ICE_Game ICE_CreateGame(char *window_title, const unsigned int width_window, const unsigned int height_window);
void ICE_DestroyGame(ICE_Game *app);
void* ICE_AddData(ICE_Game *game, size_t _size);
void* ICE_GetData(ICE_Game *game, int nb_data);
void ICE_DestroyData(ICE_Game *game, int nb_data);

#endif