#ifndef DEF_ICE_VECTOR_H
#define DEF_ICE_VECTOR_H

#include <math.h>
#include "../Framework/BasicTypes.h"
#include "../Framework/Inline.h"

/**
 * \brief Vector2D
 */
struct ICE_Vect2D
{
	ICE_Float x;
	ICE_Float y;

}; typedef struct ICE_Vect2D ICE_Vect2D;

/**
 * \brief Create a new Vector2D
 * \param x X value
 * \param y Y value
 * \return The created Vector2D
 */
ICE_INLINE ICE_Vect2D ICE_Vect2D_New(ICE_Float x, ICE_Float y) {
	ICE_Vect2D vect = { x,y };
	return vect;
}

/**
 * \brief Sum two vector
 * \param vect1 Vector2D 1
 * \param vect2 Vector2D 2
 * \return Sum of the two Vector2D
 */
ICE_INLINE ICE_Vect2D ICE_Vect2D_Sum(ICE_Vect2D vect1, ICE_Vect2D vect2) {
	return ICE_Vect2D_New(vect1.x + vect2.x, vect1.y + vect2.y);
}

/**
 * \brief Sub vector 2 from vector 1
 * \param vect1 Vector2D 1
 * \param vect2 Vector2D 2
 * \return Vector2D1-Vector2D2
 */
ICE_INLINE ICE_Vect2D ICE_Vect2D_Sub(ICE_Vect2D vect1, ICE_Vect2D vect2) {
	return ICE_Vect2D_New(vect1.x - vect2.x, vect1.y - vect2.y);
}

/**
 * \brief Scale a Vect2Dor2D by a value
 * \param vect1 Vect2Dor2D to scale
 * \param value Scaling value
 * \return Vector2D scaled
 */
ICE_INLINE ICE_Vect2D ICE_Vect2D_Scale(ICE_Vect2D vect1, ICE_Float value) {
	return ICE_Vect2D_New(vect1.x * value, vect1.y * value);
}

/**
 * \brief Multiply a Vect2D by another 
 * \param vect1 Vect2D-1
 * \param vect2 Vect2D-2
 * \return Vector2D * Vector2D
 */
ICE_INLINE ICE_Vect2D ICE_Vect2D_Multi(ICE_Vect2D vect1, ICE_Vect2D vect2) {
	return ICE_Vect2D_New(vect1.x * vect2.x, vect1.y * vect2.y);
}

/**
 * \brief Magnitude of a vector
 * \param vect Vector2D
 * \return Magnitude of Vector2D 
 */
ICE_INLINE ICE_Float ICE_Vect2D_Magn(ICE_Vect2D vect) {
	return sqrt((vect.x*vect.x) + (vect.y*vect.y));
}

/**
 * \brief Vect2D Null (0, 0)
 */
#define ICE_Vect2D_Zero ICE_Vect2D_New(0,0)

/**
 * \brief Vect2D that is the size of the screen
 */
#define ICE_Vect2D_Screen ICE_Vect2D_New(ICE_Window_GetW(), ICE_Window_GetH())

#endif
