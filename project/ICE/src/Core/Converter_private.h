#ifndef DEF_ICE_CONVERTER_PRIVATE
#define DEF_ICE_CONVERTER_PRIVATE
#include "SDL2_Includer.h"

////////////////////////////////////
//      Converter ice<->sdl       //
////////////////////////////////////

#include ICE_INCLUDE_SDL2

#include "../Maths/TypesMaths.h"
#include "../Framework/Inline.h"

/**
 * \brief Convert a SDL_Rect to a ICE_Box
 * \param rect The SDL_Rect to convert
 * \return The converted ICE_Box
 */
ICE_INLINE ICE_Box ICE_Convert_SDLtoBox(SDL_Rect *rect)
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
ICE_INLINE SDL_Rect ICE_Convert_BoxToSDL(ICE_Box *box)
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
////////////////////////////////////

#endif
