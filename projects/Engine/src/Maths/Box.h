#ifndef DEF_ICE_BOX
#define DEF_ICE_BOX

#include "TypesMaths.h"
#include "../Framework/Inline.h"

/**
 * \brief Create a new Box
 * \param x Position X
 * \param y Position Y
 * \param w Width
 * \param h Height
 * \return The new Box
 */
ICE_INLINE ICE_Box ICE_Box_New(const ICE_Float x, const ICE_Float y, const ICE_Float w, const ICE_Float h) {
	ICE_Box box = { x,y,w,h };
	return box;
}

/**
 * \brief 
 * \param rect Rectangle to scale
 * \param scale Value to scale (<1 reduce size, >1 enlarge size)
 * \return The scaled box
 */
ICE_INLINE ICE_Box ICE_Box_Scale(ICE_Box rect, ICE_Float scale)
{
	return ICE_Box_New(rect.x, rect.y, rect.w * scale, rect.h * scale);
}

/**
 * \brief Compare two Box if they are exactly the same
 * \param box1 First Box
 * \param box2 Second Box
 * \return ICE_True or ICE_False
 */
ICE_INLINE ICE_Bool ICE_Box_Compare(ICE_Box box1, ICE_Box box2)
{
	if (box1.x != box2.x ||
		box1.y != box2.y ||
		box1.w != box2.w ||
		box1.h != box2.h)
		return ICE_False;
	return ICE_True;
}

/**
* \brief Compare two Box if they have the same size
* \param box1 First Box
* \param box2 Second Box
* \return ICE_True or ICE_False
*/
ICE_INLINE ICE_Bool ICE_Box_CompareSize(ICE_Box box1, ICE_Box box2)
{
	if (box1.w != box2.w ||
		box1.h != box2.h)
		return ICE_False;
	return ICE_True;
}

/**
* \brief Compare two Box if they are at the same position
* \param box1 First Box
* \param box2 Second Box
* \return ICE_True or ICE_False
*/
ICE_INLINE ICE_Bool ICE_Box_ComparePos(ICE_Box box1, ICE_Box box2)
{
	if (box1.x != box2.x ||
		box1.y != box2.y)
		return ICE_False;
	return ICE_True;
}

/**
 * \brief Set the Box position to a new position with a Vector
 * \param box The Box to change position
 * \param vect The Vector that is the new position
 */
ICE_INLINE void ICE_Box_SetPos(ICE_Box *box, ICE_Vect vect)
{
	box->x = vect.x; box->y = vect.y;

}

/**
 * \brief Set the Box size to a new size 
 * \param box The Box to change size
 * \param w The width value
 * \param h The height value
 */
ICE_INLINE void ICE_Box_SetSize(ICE_Box *box, ICE_Float w, ICE_Float h)
{
	box->w = w; box->h = h;
}

/**
 * \brief Shift the box position by a value
 * \param box The box to move
 * \param x The X value added to position
 * \param y The Y value added to position
 */
ICE_INLINE void ICE_Box_Shift(ICE_Box *box, ICE_Float x, ICE_Float y)
{
	box->x += x; box->y += y;
}
#endif
