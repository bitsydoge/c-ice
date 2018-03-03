#ifndef DEF_ICE_COLOR
#define DEF_ICE_COLOR

#include "TypesGraphics.h"

inline ICE_Color ICE_ColorNew(const unsigned int r, const unsigned int g, const unsigned int b) {
	return (r << 24) + (g << 16) + (b << 8) + 255;
}

inline ICE_Color ICE_ColorANew(const unsigned int r, const unsigned int g, const unsigned int b, const unsigned int a) {
	return (r << 24) + (g << 16) + (b << 8) + a;
}

#endif
