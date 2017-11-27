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

iceBool iceBoxCompare(iceBox box1, iceBox box2)
{
	if (box1.p.x != box2.p.x ||
		box1.p.y != box2.p.y ||
		box1.w != box2.w ||
		box1.h != box2.h)
		return iceFalse;
	return iceTrue;
}

iceBool iceBoxCompareSize(iceBox box1, iceBox box2)
{
	if (box1.w != box2.w ||
		box1.h != box2.h)
		return iceFalse;
	return iceTrue;
}

iceBool iceBoxComparePos(iceBox box1, iceBox box2)
{
	if (box1.p.x != box2.p.x ||
		box1.p.y != box2.p.y)
		return iceFalse;
	return iceTrue;
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