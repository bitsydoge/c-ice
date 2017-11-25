#include "hdr/Converter.h"

/// iceBox to SDL_Rect
iceBox sdlRectToICE(SDL_Rect *rect)
{
	iceBox ice = { 0 };
	if (rect)
	{
		ice.p.x = rect->x, ice.p.y = rect->y, ice.w = rect->w, ice.h = rect->h;
	}
	return ice;
}
/// SDL_Rect to iceBox
SDL_Rect iceRectToSDL(iceBox *rect)
{
	SDL_Rect sdl = { 0 };
	if (rect)
	{
		sdl.x = rect->p.x, sdl.y = rect->p.y, sdl.w = rect->w, sdl.h = rect->h;
	}
	return sdl;
}