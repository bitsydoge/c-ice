#ifndef DEF_ICE_COLOR
#define DEF_ICE_COLOR

#include "TypesGraphics.h"

#define ICE_Color_Red ICE_Color_New(255,0,0)
#define ICE_Color_Blue ICE_Color_New(0,0,255)
#define ICE_Color_Green ICE_Color_New(0,255,0)
#define ICE_Color_Black ICE_Color_New(0,0,0)
#define ICE_Color_White ICE_Color_New(255,255,255)
#define ICE_Color_Grey ICE_Color_New(127,127,127)

inline ICE_Color ICE_Color_New(const unsigned int r, const unsigned int g, const unsigned int b) {
	return (r << 24) + (g << 16) + (b << 8) + 255;
}

inline ICE_Color ICE_Color_ANew(const unsigned int r, const unsigned int g, const unsigned int b, const unsigned int a) {
	return (r << 24) + (g << 16) + (b << 8) + a;
}

#endif
