#ifndef DEF_ICE_COLOR
#define DEF_ICE_COLOR

#include "TypesGraphics.h"

#define ICE_ColorRed ICE_ColorNew(255,0,0)
#define ICE_ColorBlue ICE_ColorNew(0,0,255)
#define ICE_ColorGreen ICE_ColorNew(0,255,0)
#define ICE_ColorBlack ICE_ColorNew(0,0,0)
#define ICE_ColorWhite ICE_ColorNew(255,255,255)
#define ICE_ColorGrey ICE_ColorNew(127,127,127)

inline ICE_Color ICE_ColorNew(const unsigned int r, const unsigned int g, const unsigned int b) {
	return (r << 24) + (g << 16) + (b << 8) + 255;
}

inline ICE_Color ICE_ColorANew(const unsigned int r, const unsigned int g, const unsigned int b, const unsigned int a) {
	return (r << 24) + (g << 16) + (b << 8) + a;
}

#endif
