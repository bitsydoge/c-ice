﻿#ifndef DEF_ICE_PRIMITIVE
#define DEF_ICE_PRIMITIVE

#include "TypesGraphics.h"
#include "../Maths/TypesMaths.h"


/**
 * \brief Draw a pixel on the screen with a defined color
 * \param vect Vector that is the Coordinate of the pixel
 * \param color Color of the pixel
 * \return 1
 */
int ICE_Draw_Point(ICE_Vect vect, const ICE_Color color);


/**
 * \brief Draw a line of pixel on the screen with a defined color
 * \param vect1 Vector that is the first point of the line
 * \param vect2 Vector that is the second point of the line
 * \param color Color of the line
 * \return 0
 */
int ICE_Draw_Line(ICE_Vect vect1, ICE_Vect vect2, const ICE_Color color);


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

/**
 * \brief Draw an antialiased line of pixel on the screen with a defined color
 * \param vect1 Vector that is the first point of the line
 * \param vect2 Vector that is the second point of the line
 * \param color Color of the line
 * \return 0
 */
int ICE_Draw_LineAA(const ICE_Vect vect1, const ICE_Vect vect2, const ICE_Color color);

/**
 * \brief Draw an antialiased circle on the screen with a defined color
 * \param vect Vector that is the position of the center of the circle
 * \param r Radius of the circle
 * \param color Color of the circle
 * \return 0
 */
int ICE_Draw_CircleAA(ICE_Vect vect, ICE_Float r, ICE_Color color);

#endif
