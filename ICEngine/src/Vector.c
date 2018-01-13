#include "hdr/Vector.h"

// Create a new vector
iceVect iceVectNew(iceFloat x, iceFloat y) {
	iceVect vect = { x,y };
	return vect;
}
// The sum of two vector
iceVect iceVectSum(iceVect vect1, iceVect vect2){
	return iceVectNew(vect1.x + vect2.x, vect1.y + vect2.y);
}
// Sub Vector 2 from vector 1
iceVect iceVectSub(iceVect vect1, iceVect vect2){
	return iceVectNew(vect1.x - vect2.x, vect1.y - vect2.y);
}
// Scale a vector from another value
iceVect iceVectScale(iceVect vect1, iceFloat value){
	return iceVectNew(vect1.x * value, vect1.y * value);
}
// Multiplication of two vectors
iceVect iceVectMulti(iceVect vect1, iceVect vect2){
	return iceVectNew(vect1.x * vect2.x, vect1.y * vect2.y);
}
// Calculate the magnitude of a vector
iceFloat iceVectLenght(iceVect vect){
	return sqrt((vect.x*vect.x) + (vect.y*vect.y));
}