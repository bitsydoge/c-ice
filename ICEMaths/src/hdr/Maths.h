#ifndef DEF_ICE_MATHS
#define DEF_ICE_MATHS

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>
#include "TypesMaths.h"

// Move point to an other point from a r distance in iceiceFloat
void move_from_angle(iceFloat *x, iceFloat *y, double angle, iceFloat r);
// Calculate the angle for two point in degree
double angle_calculate_degree(iceFloat x1, iceFloat y1, iceFloat x2, iceFloat y2);
// Calculate the angle for two point in radiant
double angle_calculate_radiant(iceFloat x1, iceFloat y1, iceFloat x2, iceFloat y2);
void move_position_r(iceFloat *x1, iceFloat *y1, iceFloat x2, iceFloat y2, iceFloat r);

#endif
