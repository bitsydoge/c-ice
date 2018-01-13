#include "hdr/Maths.h"

/// Move point to an other point from a r distance in float
void iceMathsMoveFromAngle(iceFloat *x, iceFloat *y, iceFloat angle, iceFloat r) {
	*x += r * cos(angle); *y += r * sin(angle);
}

/// Calculate the angle for two point in degree
double iceMathsAngleCalculatDegree(iceFloat x1, iceFloat y1, iceFloat x2, iceFloat y2) {
	iceFloat xdif = x2 - x1; iceFloat ydif = y2 - y1;
	return 57.29*atan2(ydif, xdif);
}

/// Calculate the angle for two point in radiant
double iceMathsAngleCalculatRadiant(iceFloat x1, iceFloat y1, iceFloat x2, iceFloat y2) {
	iceFloat xdif = x2 - x1; iceFloat ydif = y2 - y1;
	return atan2(ydif, xdif);
}

void iceMathsMoveToPosition(iceFloat *x1, iceFloat *y1, iceFloat x2, iceFloat y2, iceFloat r) {
	iceFloat xdif = x2 - *x1; iceFloat ydif = y2 - *y1;
	iceFloat angle = atan2(ydif, xdif);
	iceFloat distance_r_r = xdif*xdif + ydif*ydif;
	*x1 += r * cos(angle); *y1 += r * sin(angle);
	if (distance_r_r < r*r) {
		*x1 = x2;
		*y1 = y2;
	}
}