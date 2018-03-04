#ifndef DEF_ICE_BOX
#define DEF_ICE_BOX

#include "TypesMaths.h"
#include "TypesCore.h"

// Creation
inline ICE_Box ICE_BoxNew(const ICE_Float x, const ICE_Float y, const ICE_Float w, const ICE_Float h) {
	ICE_Box box = { x,y,w,h };
	return box;
}

// Math
inline ICE_Box ICE_BoxScale(ICE_Box rect, ICE_Float scale)
{
	return ICE_BoxNew(rect.x, rect.y, rect.w * scale, rect.h * scale);
}

inline ICE_Bool ICE_BoxCompare(ICE_Box box1, ICE_Box box2)
{
	if (box1.x != box2.x ||
		box1.y != box2.y ||
		box1.w != box2.w ||
		box1.h != box2.h)
		return ICE_False;
	return ICE_True;
}

inline ICE_Bool ICE_BoxCompareSize(ICE_Box box1, ICE_Box box2)
{
	if (box1.w != box2.w ||
		box1.h != box2.h)
		return ICE_False;
	return ICE_True;
}

inline ICE_Bool ICE_BoxComparePos(ICE_Box box1, ICE_Box box2)
{
	if (box1.x != box2.x ||
		box1.y != box2.y)
		return ICE_False;
	return ICE_True;
}

// Edit
inline void ICE_BoxSetPos(ICE_Box *rect, ICE_Float x, ICE_Float y)
{
	rect->x = x; rect->y = y;
}
inline void ICE_BoxSetSize(ICE_Box *rect, ICE_Float w, ICE_Float h)
{
	rect->w = w; rect->h = h;
}
inline void ICE_BoxShift(ICE_Box *rect, ICE_Float x, ICE_Float y)
{
	rect->x += x; rect->y += y;
}
#endif
