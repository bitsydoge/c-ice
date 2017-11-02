#include "hdr/Math.h"

// Move point to an other point from a r distance in float
void move_from_angle(float *x, float *y, double angle, float r){
	*x += r * cos(angle); *y += r * sin(angle);
}

// Calculate the angle for two point in degree
double angle_calculate_degree(float x1, float y1, float x2, float y2) {
	float xdif = x2 - x1; float ydif = y2 - y1;
	return 57.29*atan2(ydif, xdif);
}

// Calculate the angle for two point in radiant
double angle_calculate_radiant(float x1, float y1, float x2, float y2){
	float xdif = x2 - x1; float ydif = y2 - y1;
	return atan2(ydif, xdif);
}

void move_position_r(float *x1, float *y1, float x2, float y2, float r) {
	float xdif = x2 - *x1; float ydif = y2 - *y1;
	float angle = atan2(ydif, xdif);
	float distance_r_r = xdif*xdif + ydif*ydif;
	*x1 += r * cos(angle); *y1 += r * sin(angle);
	if (distance_r_r < r*r) {
		*x1 = x2;
		*y1 = y2;
	}
}