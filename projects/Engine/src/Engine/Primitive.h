#ifndef DEF_ICE_PRIMITIVE
#define DEF_ICE_PRIMITIVE

#include "Vect2D.h"
#include "Color.h"
#include "Box.h"


/**
 * \brief Draw a pixel on the screen with a defined color
 * \param vect Vector that is the Coordinate of the pixel
 * \param color Color of the pixel
 * \return 1
 */
int ICE_Draw_Point(const ICE_Vect2D vect, const ICE_Color color);


/**
 * \brief Draw a line of pixel on the screen with a defined color
 * \param vect1 Vector that is the first point of the line
 * \param vect2 Vector that is the second point of the line
 * \param color Color of the line
 * \return 0
 */
int ICE_Draw_Line(const ICE_Vect2D vect1, const ICE_Vect2D vect2, const ICE_Color color);

/**
 * \brief Draw a rectangle of pixel on the screen with a defined color
 * \param box Box that is the position and size of the rectangle drawed
 * \param color Color of the rectangle
 * \return 0
 */
int ICE_Draw_Rectangle(ICE_Box box, const ICE_Color color);

/**
 * \brief Draw a filled rectangle of pixel on the screen with a defined color
 * \param box Box that is the position and size of the rectangle drawed
 * \param color Color of the rectangle
 * \return 0
 */
int ICE_Draw_RectangleFill(ICE_Box box, const ICE_Color color);

#endif
