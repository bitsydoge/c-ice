#ifndef DEF_ICE_STRUCTMATHS
#define DEF_ICE_STRUCTMATHS

#include "TypesMaths.h"

typedef struct iceVect
{
	iceFloat x;
	iceFloat y;

} iceVect;

typedef struct iceRect
{
	iceVect p;
	iceFloat w;
	iceFloat h;

} iceBox;

#endif