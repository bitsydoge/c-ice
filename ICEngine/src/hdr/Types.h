#ifndef DEF_ICE_TYPES
#define DEF_ICE_TYPES
#include <stdint.h>

typedef char iceBool;
#define iceTrue 1
#define iceFalse 0

typedef double iceFloat;

typedef struct iceVect
{
	iceFloat x;
	iceFloat y;

} iceVect;

typedef struct iceRect
{
	iceFloat x;
	iceFloat y;
	iceFloat w;
	iceFloat h;

} iceRect;

typedef uint32_t iceColor;

#endif
