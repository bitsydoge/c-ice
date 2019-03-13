#ifndef ICE_SDL2_CONVERTER_H
#define ICE_SDL2_CONVERTER_H

#include "Color.h"
#include "Box.h"

#include <SDL2/SDL.h>

ICE_INLINE SDL_Color ICE_Color_ToSdl(const ICE_Color ice_color) 
{
	SDL_Color sdl_color;
	sdl_color.r = ice_color >> 24 & 255;
	sdl_color.g = ice_color >> 16 & 255;
	sdl_color.b = ice_color >> 8 & 255;
	sdl_color.a = ice_color & 255;
	return sdl_color;
}

ICE_INLINE ICE_Box ICE_Convert_SDLtoBox(SDL_Rect* rect)
{
	ICE_Box ice = { 0 };
	if (rect)
	{
		ice.x = rect->x;
		ice.y = rect->y;
		ice.w = rect->w;
		ice.h = rect->h;
	}
	return ice;
}

/**
 * \brief Convert a ICE_Box to a SDL_Rect
 * \param box The ICE_Box to convert
 * \return The converted SDL_Rect
 */
ICE_INLINE SDL_Rect ICE_Convert_BoxToSDL(ICE_Box* box)
{
	SDL_Rect sdl = { 0 };
	if (box)
	{
		sdl.x = (int)box->x;
		sdl.y = (int)box->y;
		sdl.w = (int)box->w;
		sdl.h = (int)box->h;
	}

	return sdl;
}

#endif