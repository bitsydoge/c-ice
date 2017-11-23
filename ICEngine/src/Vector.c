#include "hdr/Vector.h"

iceVect iceVectNew(iceFloat x, iceFloat y) {
	iceVect vect = { x,y };
	return vect;
}

void iceVectAdd(iceVect *point, iceVect vect)
{
	point->x += vect.x; point->y += vect.y;
}

void iceVectSub(iceVect *point, iceVect vect)
{
	point->x -= vect.x; point->y -= vect.y;
}