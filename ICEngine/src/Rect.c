#include "hdr/Rect.h"

/// iceRect to SDL_Rect
iceRect sdlRectToICE(SDL_Rect *rect)
{
	iceRect ice = { 0 };
	if (rect)
	{
		ice.x = rect->x, ice.y = rect->y, ice.w = rect->w, ice.h = rect->h;
	}
	return ice;
}

/// SDL_Rect to iceRect
SDL_Rect iceRectToSDL(iceRect *rect)
{
	SDL_Rect sdl = { 0 };
	if (rect)
	{
		sdl.x = rect->x, sdl.y = rect->y, sdl.w = rect->w, sdl.h = rect->h;
	}
	return sdl;
}
