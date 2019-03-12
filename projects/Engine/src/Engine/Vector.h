#ifndef DEF_ICE_VECTOR
#define DEF_ICE_VECTOR

#include <math.h>
#include "../Framework/TypesFramework.h"
#include "../Framework/Inline.h"

/**
 * \brief Vector2D
 */
struct ICE_Vect
{
	ICE_Float x;
	ICE_Float y;

}; typedef struct ICE_Vect ICE_Vect;

/**
 * \brief Create a new Vector
 * \param x X value
 * \param y Y value
 * \return The created Vector
 */
ICE_INLINE ICE_Vect ICE_Vect_New(ICE_Float x, ICE_Float y) {
	ICE_Vect vect = { x,y };
	return vect;
}

/**
 * \brief Sum two vector
 * \param vect1 Vector 1
 * \param vect2 Vector 2
 * \return Sum of the two Vector
 */
ICE_INLINE ICE_Vect ICE_Vect_Sum(ICE_Vect vect1, ICE_Vect vect2) {
	return ICE_Vect_New(vect1.x + vect2.x, vect1.y + vect2.y);
}

/**
 * \brief Sub vector 2 from vector 1
 * \param vect1 Vector 1
 * \param vect2 Vector 2
 * \return Vect1-Vect2
 */
ICE_INLINE ICE_Vect ICE_Vect_Sub(ICE_Vect vect1, ICE_Vect vect2) {
	return ICE_Vect_New(vect1.x - vect2.x, vect1.y - vect2.y);
}

/**
 * \brief Scale a Vector by a value
 * \param vect1 Vector to scale
 * \param value Scaling value
 * \return Vector scaled
 */
ICE_INLINE ICE_Vect ICE_Vect_Scale(ICE_Vect vect1, ICE_Float value) {
	return ICE_Vect_New(vect1.x * value, vect1.y * value);
}

/**
 * \brief Multiply a Vector by another 
 * \param vect1 Vector1
 * \param vect2 Vector2
 * \return Vector1 * Vector2
 */
ICE_INLINE ICE_Vect ICE_Vect_Multi(ICE_Vect vect1, ICE_Vect vect2) {
	return ICE_Vect_New(vect1.x * vect2.x, vect1.y * vect2.y);
}

/**
 * \brief Magnitude of a vector
 * \param vect Vector1
 * \return Magnitude of Vector1
 */
ICE_INLINE ICE_Float ICE_Vect_Magn(ICE_Vect vect) {
	return sqrt((vect.x*vect.x) + (vect.y*vect.y));
}

/**
 * \brief Vector Null (0, 0)
 */
#define ICE_Vect_Zero ICE_Vect_New(0,0)

/**
 * \brief Vector that is the size of the screen
 */
#define ICE_Vect_Screen ICE_Vect_New(ICE_Window_GetW(), ICE_Window_GetH())

#endif
