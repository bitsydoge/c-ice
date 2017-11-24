#include "hdr/Rect.h"

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