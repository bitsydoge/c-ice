#ifndef DEF_ICE_BOX
#define DEF_ICE_BOX

#include "TypesMaths.h"

// Creation
inline iceBox iceBoxNew(const iceFloat x, const iceFloat y, const iceFloat w, const iceFloat h) {
	iceBox box = {x,y,w,h};
	return box;
}

// Math
inline iceBox iceBoxScale(iceBox rect, iceFloat scale)
{
	return iceBoxNew(rect.p.x, rect.p.y, rect.w * scale, rect.h * scale);
}

inline iceBool iceBoxCompare(iceBox box1, iceBox box2)
{
	if (box1.p.x != box2.p.x ||
		box1.p.y != box2.p.y ||
		box1.w != box2.w ||
		box1.h != box2.h)
		return iceFalse;
	return iceTrue;
}

inline iceBool iceBoxCompareSize(iceBox box1, iceBox box2)
{
	if (box1.w != box2.w ||
		box1.h != box2.h)
		return iceFalse;
	return iceTrue;
}

inline iceBool iceBoxComparePos(iceBox box1, iceBox box2)
{
	if (box1.p.x != box2.p.x ||
		box1.p.y != box2.p.y)
		return iceFalse;
	return iceTrue;
}

// Edit
inline void iceBoxSetPos(iceBox *rect, iceFloat x, iceFloat y)
{
	rect->p.x = x; rect->p.y = y;
}
inline void iceBoxSetSize(iceBox *rect, iceFloat w, iceFloat h)
{
	rect->w = w; rect->h = h;
}
inline void iceBoxShift(iceBox *rect, iceFloat x, iceFloat y)
{
	rect->p.x += x; rect->p.y += y;
}
#endif
