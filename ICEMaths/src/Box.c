#include "hdr/Box.h"

// Creation
iceBox iceBoxNew(iceFloat x, iceFloat y, iceFloat w, iceFloat h) {
	iceBox box = { x,y,w,h };
	return box;
}

// Math
iceBox iceBoxScale(iceBox rect, iceFloat scale)
{
	return iceBoxNew(rect.p.x * scale, rect.p.y * scale, rect.w * scale, rect.h * scale);
}

// Edit
void iceBoxSetPos(iceBox *rect, iceFloat x, iceFloat y)
{
	rect->p.x = x; rect->p.y = y;
}
void iceBoxSetSize(iceBox *rect, iceFloat w, iceFloat h)
{
	rect->w = w; rect->h = h;
}
void iceBoxShift(iceBox *rect, iceFloat x, iceFloat y)
{
	rect->p.x += x; rect->p.y += y;
}