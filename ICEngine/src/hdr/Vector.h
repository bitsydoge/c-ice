#ifndef DEF_ICE_VECTOR
#define DEF_ICE_VECTOR

#include "TypesMaths.h"
#include <math.h>

// Create a new vector
inline ICE_Vect ICE_VectNew(ICE_Float x, ICE_Float y) {
	ICE_Vect vect = { x,y };
	return vect;
}
// The sum of two vector
inline ICE_Vect ICE_VectSum(ICE_Vect vect1, ICE_Vect vect2) {
	return ICE_VectNew(vect1.x + vect2.x, vect1.y + vect2.y);
}
// Sub Vector 2 from vector 1
inline ICE_Vect ICE_VectSub(ICE_Vect vect1, ICE_Vect vect2) {
	return ICE_VectNew(vect1.x - vect2.x, vect1.y - vect2.y);
}
// Scale a vector from another value
inline ICE_Vect ICE_VectScale(ICE_Vect vect1, ICE_Float value) {
	return ICE_VectNew(vect1.x * value, vect1.y * value);
}
// Multiplication of two vectors
inline ICE_Vect ICE_VectMulti(ICE_Vect vect1, ICE_Vect vect2) {
	return ICE_VectNew(vect1.x * vect2.x, vect1.y * vect2.y);
}
// Calculate the magnitude of a vector
inline ICE_Float ICE_VectMagn(ICE_Vect vect) {
	return sqrt((vect.x*vect.x) + (vect.y*vect.y));
}

#define ICE_VectNull ICE_VectNew(0,0)
#define ICE_VectScreen ICE_VectNew(ICE_WindowGetW(), ICE_WindowGetH())

#endif