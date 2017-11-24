#include "hdr/Rect.h"

/// iceRect to SDL_Rect
iceRect sdlRectToICE(SDL_Rect *rect)
{
	iceRect ice = { 0 };
	if (rect)
	{
		ice.p.x = rect->x, ice.p.y = rect->y, ice.w = rect->w, ice.h = rect->h;
	}
	return ice;
}
/// SDL_Rect to iceRect
SDL_Rect iceRectToSDL(iceRect *rect)
{
	SDL_Rect sdl = { 0 };
	if (rect)
	{
		sdl.x = rect->p.x, sdl.y = rect->p.y, sdl.w = rect->w, sdl.h = rect->h;
	}
	return sdl;
}

// Creation
iceRect iceRectNew(iceFloat x, iceFloat y, iceFloat w, iceFloat h) {
	iceRect rect = { x,y,w,h };
	return rect;
}

// Math
iceRect iceRectScale(iceRect rect, iceFloat scale)
{
	return iceRectNew(rect.p.x * scale, rect.p.y * scale, rect.w * scale, rect.h * scale);
}

// Edit
void iceRectSetPos(iceRect *rect, iceFloat x, iceFloat y)
{
	rect->p.x = x; rect->p.y = y;
}
void iceRectSetSize(iceRect *rect, iceFloat w, iceFloat h)
{
	rect->w = w; rect->h = h;
}
void iceRectShift(iceRect *rect, iceFloat x, iceFloat y)
{
	rect->p.x += x; rect->p.y += y;
}