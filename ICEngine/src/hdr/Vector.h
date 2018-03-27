#ifndef DEF_ICE_VECTOR
#define DEF_ICE_VECTOR

#include "TypesMaths.h"
#include <math.h>

// Create a new vector
inline ICE_Vect ICE_Vect_New(ICE_Float x, ICE_Float y) {
	ICE_Vect vect = { x,y };
	return vect;
}
// The sum of two vector
inline ICE_Vect ICE_Vect_Sum(ICE_Vect vect1, ICE_Vect vect2) {
	return ICE_Vect_New(vect1.x + vect2.x, vect1.y + vect2.y);
}
// Sub Vector 2 from vector 1
inline ICE_Vect ICE_Vect_Sub(ICE_Vect vect1, ICE_Vect vect2) {
	return ICE_Vect_New(vect1.x - vect2.x, vect1.y - vect2.y);
}
// Scale a vector from another value
inline ICE_Vect ICE_Vect_Scale(ICE_Vect vect1, ICE_Float value) {
	return ICE_Vect_New(vect1.x * value, vect1.y * value);
}
// Multiplication of two vectors
inline ICE_Vect ICE_Vect_Multi(ICE_Vect vect1, ICE_Vect vect2) {
	return ICE_Vect_New(vect1.x * vect2.x, vect1.y * vect2.y);
}
// Calculate the magnitude of a vector
inline ICE_Float ICE_Vect_Magn(ICE_Vect vect) {
	return sqrt((vect.x*vect.x) + (vect.y*vect.y));
}

#define ICE_Vect_Null ICE_Vect_New(0,0)
#define ICE_Vect_Screen ICE_Vect_New(ICE_Window_GetW(), ICE_Window_GetH())

#endif