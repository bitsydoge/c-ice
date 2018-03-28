#ifndef DEF_ICE_CONVERTER_PRIVATE
#define DEF_ICE_CONVERTER_PRIVATE

////////////////////////////////////
//      Converter ice<->sdl       //
////////////////////////////////////

#include <SDL2/SDL.h>

#include "TypesMaths.h"

/**
 * \brief Convert a SDL_Rect to a ICE_Box
 * \param rect The SDL_Rect to convert
 * \return The converted ICE_Box
 */
inline ICE_Box ICE_Convert_SDLtoBox(SDL_Rect *rect)
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
inline SDL_Rect ICE_Convert_BoxToSDL(ICE_Box *box)
{
	SDL_Rect sdl = { 0 };
	if (box)
	{
		sdl.x = box->x; 
		sdl.y = box->y; 
		sdl.w = box->w; 
		sdl.h = box->h;
	}
		
	return sdl;
}
////////////////////////////////////

#endif