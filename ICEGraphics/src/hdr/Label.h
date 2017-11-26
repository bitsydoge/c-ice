#ifndef DEF_ICE_LABEL
#define DEF_ICE_LABEL

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
void iceLabelManagerCreate(iceGame *game);
// Create a text object in manager
void iceLabelCreate(iceGame *game, unsigned int man, iceVect pos, char *label);
//
void iceLabelUpdateTexture(iceGame *game, int man, int text);
//
void iceLabelSetPos(iceGame *game, int man, int text, iceVect vect);
//
void iceLabelSetSize(iceGame *game, int man, int text, int size);
//
void iceLabelSetColor(iceGame *game, int man, int text, iceColor color);
//
void iceLabelSetText(iceGame *game, int man, int text, char * label);
//
void iceLabelIsInWorld(iceGame *game, int man, int text, iceBool bool);

#endif
