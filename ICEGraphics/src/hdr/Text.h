#ifndef DEF_ICE_TEXT
#define DEF_ICE_TEXT

#define ICE_DEFAULT_TEXT_SIZE 4

#include <stdio.h>
#include "StructCore.h"
#include "Terminal.h"
#include "Gui.h"
#include "Color.h"

#ifndef _WIN32
#define STRDUP(STRING_PARAMETER) strdup(STRING_PARAMETER)
#else
#define STRDUP(STRING_PARAMETER) _strdup(STRING_PARAMETER)
#endif


// Create manager of Text Object
void iceTextManagerCreate(iceGame *game);
// Create a text object in manager
void iceTextCreate(iceGame *game, unsigned int man, iceVect pos, char *label);
//
void iceTextUpdateTexture(iceGame *game, int man, int text);
//
void iceTextSetPos(iceGame *game, int man, int text, iceVect vect);
//
void iceTextSetSize(iceGame *game, int man, int text, int size);
//
void iceTextSetColor(iceGame *game, int man, int text, iceColor color);
//
void iceTextSetLabel(iceGame *game, int man, int text, char * label);
//
void iceTextIsFixedToWorld(iceGame *game, int man, int text, iceBool bool);

#endif
