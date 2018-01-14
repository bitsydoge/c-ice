#ifndef DEF_ICE_LABEL
#define DEF_ICE_LABEL

#define ICE_DEFAULT_TEXT_SIZE 4

#include "TypesCore.h"

#ifndef _WIN32
#define STRDUP(STRING_PARAMETER) strdup(STRING_PARAMETER)
#else
#define STRDUP(STRING_PARAMETER) _strdup(STRING_PARAMETER)
#endif


// Create manager of Text Object
void iceLabelManagerCreate();
// Create a text object in manager
void iceLabelCreate(unsigned int man, iceVect pos, char *label);
//
void iceLabelUpdateTexture(int man, int text);
//
void iceLabelSetPos(int man, int text, iceVect vect);
//
void iceLabelSetSize(int man, int text, int size);
//
void iceLabelSetColor(int man, int text, iceColor color);
//
void iceLabelSetText(int man, int text, char * label);
//
void iceLabelIsInWorld(int man, int text, iceBool bool);

#endif
