#ifndef DEF_ICE_COLOR
#define DEF_ICE_COLOR
#include <SDL2/SDL.h>
#include "TypesGraphics.h"

/// Create a new iceColor from a R G and B int; The A is 255, use iceColorANew to set the transparancy
iceColor iceColorNew(const unsigned int r, const unsigned int g, const unsigned int b);
/// Create a new iceColor from a R G B and A int
iceColor iceColorANew(const unsigned int r, const unsigned int g, const unsigned int b, const unsigned int a);
/// Convert a iceColor to a SDL_Color
SDL_Color iceColorToSdl(iceColor ice_color);

#endif
