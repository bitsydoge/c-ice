#include "hdr/Color.h"

iceColor iceColorNew(const unsigned int r, const unsigned int g, const unsigned int b) {
	return (r << 24) + (g << 16) + (b << 8) + 255;
}

iceColor iceColorANew(const unsigned int r, const unsigned int g, const unsigned int b, const unsigned int a) {
	return (r << 24) + (g << 16) + (b << 8) + a;
}

SDL_Color iceColorToSdl(iceColor ice_color)
{
	SDL_Color sdl_color = { 0,0,0,255 };
	sdl_color.r = ice_color >> 24 & 255;
	sdl_color.g = ice_color >> 16 & 255;
	sdl_color.b = ice_color >> 8 & 255;
	sdl_color.a = ice_color & 255;
	return sdl_color;
}