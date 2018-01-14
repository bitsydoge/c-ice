#ifndef DEF_ICE_VECTOR
#define DEF_ICE_VECTOR

#include "TypesMaths.h"

// Create a new vector
iceVect iceVectNew(iceFloat x, iceFloat y);
// The sum of two vector
iceVect iceVectSum(iceVect vect1, iceVect vect2);
// Sub Vector 2 from vector 1
iceVect iceVectSub(iceVect vect1, iceVect vect2);
// Scale a vector from another value
iceVect iceVectScale(iceVect vect1, iceFloat x);
// Multiplication of two vectors
iceVect iceVectMulti(iceVect vect1, iceVect vect2);
// Calculate the magnitude of a vector
iceFloat iceVectLenght(iceVect vect);

#endif
