#ifndef DEF_ICE_COLOR
#define DEF_ICE_COLOR
#include <SDL2/SDL.h>
#include "TypesGraphics.h"

inline iceColor iceColorNew(const unsigned int r, const unsigned int g, const unsigned int b) {
	return (r << 24) + (g << 16) + (b << 8) + 255;
}

inline iceColor iceColorANew(const unsigned int r, const unsigned int g, const unsigned int b, const unsigned int a) {
	return (r << 24) + (g << 16) + (b << 8) + a;
}

#endif
