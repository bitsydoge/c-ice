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

inline SDL_Color iceColorToSdl(const iceColor ice_color) {
	SDL_Color sdl_color;
	sdl_color.r = ice_color >> 24 & 255;
	sdl_color.g = ice_color >> 16 & 255;
	sdl_color.b = ice_color >> 8 & 255;
	sdl_color.a = ice_color & 255;
	return sdl_color;
}

#endif
