#ifndef DEF_ICE_MATHS
#define DEF_ICE_MATHS

#include <math.h>
#include "../Framework/Inline.h"
#include "../Framework/BasicTypes.h"

/// Move point to an other point from a r distance in float
ICE_INLINE void ICE_Maths_MoveFromAngle(ICE_Float *x, ICE_Float *y, const ICE_Float angle, const ICE_Float r) {
	*x += r * cos(angle); *y += r * sin(angle);
}

/// Calculate the angle for two point in degree
ICE_INLINE ICE_Float ICE_Maths_AngleCalculatDegree(const ICE_Float x1, const ICE_Float y1, const ICE_Float x2, const ICE_Float y2) {
	ICE_Float xdif = x2 - x1; ICE_Float ydif = y2 - y1;
	return 57.29*atan2(ydif, xdif);
}

/// Calculate the angle for two point in radiant
ICE_INLINE ICE_Float ICE_Maths_AngleCalculatRadiant(const ICE_Float x1, const ICE_Float y1, const ICE_Float x2, const ICE_Float y2) {
	ICE_Float xdif = x2 - x1; ICE_Float ydif = y2 - y1;
	return atan2(ydif, xdif);
}

ICE_INLINE void ICE_Maths_MoveToPosition(ICE_Float *x1, ICE_Float *y1, ICE_Float x2, ICE_Float y2, ICE_Float r) {
	ICE_Float xdif = x2 - *x1; ICE_Float ydif = y2 - *y1;
	ICE_Float angle = atan2(ydif, xdif);
	ICE_Float distance_r_r = xdif * xdif + ydif * ydif;
	*x1 += r * cos(angle); *y1 += r * sin(angle);
	if (distance_r_r < r*r) {
		*x1 = x2;
		*y1 = y2;
	}
}

#endif
