#ifndef DEF_ICE_CONVERTER_PRIVATE
#define DEF_ICE_CONVERTER_PRIVATE

////////////////////////////////////
//      Converter ice<->sdl       //
////////////////////////////////////

#include <SDL2/SDL.h>
#include "TypesMaths.h"

/// iceBox to SDL_Rect
inline ICE_Box ICE_ConvertSDLtoBox(SDL_Rect *rect)
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
}/// SDL_Rect to iceBox
inline SDL_Rect ICE_ConvertBoxToSDL(ICE_Box *rect)
{
	SDL_Rect sdl = { 0 };
	if (rect)
	{
		sdl.x = rect->x; 
		sdl.y = rect->y; 
		sdl.w = rect->w; 
		sdl.h = rect->h;
	}
		
	return sdl;
}
////////////////////////////////////

#endif