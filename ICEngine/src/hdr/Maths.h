#ifndef DEF_ICE_MATHS
#define DEF_ICE_MATHS

#include "TypesMaths.h"

#include <math.h>

/// Move point to an other point from a r distance in float
inline void iceMathsMoveFromAngle(iceFloat *x, iceFloat *y, const iceFloat angle, const iceFloat r) {
	*x += r * cos(angle); *y += r * sin(angle);
}

/// Calculate the angle for two point in degree
inline iceFloat iceMathsAngleCalculatDegree(const iceFloat x1, const iceFloat y1, const iceFloat x2, const iceFloat y2) {
	iceFloat xdif = x2 - x1; iceFloat ydif = y2 - y1;
	return 57.29*atan2(ydif, xdif);
}

/// Calculate the angle for two point in radiant
inline iceFloat iceMathsAngleCalculatRadiant(const iceFloat x1, const iceFloat y1, const iceFloat x2, const iceFloat y2) {
	iceFloat xdif = x2 - x1; iceFloat ydif = y2 - y1;
	return atan2(ydif, xdif);
}

inline void iceMathsMoveToPosition(iceFloat *x1, iceFloat *y1, iceFloat x2, iceFloat y2, iceFloat r) {
	iceFloat xdif = x2 - *x1; iceFloat ydif = y2 - *y1;
	iceFloat angle = atan2(ydif, xdif);
	iceFloat distance_r_r = xdif * xdif + ydif * ydif;
	*x1 += r * cos(angle); *y1 += r * sin(angle);
	if (distance_r_r < r*r) {
		*x1 = x2;
		*y1 = y2;
	}
}

#endif
