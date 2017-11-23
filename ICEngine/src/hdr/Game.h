#ifndef DEF_iceGAME
#define DEF_iceGAME
#include "Struct.h"
#include "Render.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "Texture.h"
#include "Sound.h"
#include "Debug.h"
#include "Types.h"

iceGame iceGameCreate(char *window_title, const unsigned int width_window, const unsigned int height_window);
void iceGameDestroy(iceGame *app);
void iceGameResizable(iceGame *game, iceBool yn);
void iceGameTitle(iceGame *game, const char *title);
void iceGameSetIcon(iceWindow *window, char * path);

#endif