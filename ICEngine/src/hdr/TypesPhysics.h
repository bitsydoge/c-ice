#ifndef DEF_ICE_TYPESPHYSICS
#define DEF_ICE_TYPESPHYSICS

#include <chipmunk/chipmunk.h>

typedef struct
{
	cpSpace *space;
	cpVect gravity;

} icePhysics;

#endif