#ifndef DEF_ICE_TYPESMATHS
#define DEF_ICE_TYPESMATHS

typedef double iceFloat;

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

} iceRect;

#endif