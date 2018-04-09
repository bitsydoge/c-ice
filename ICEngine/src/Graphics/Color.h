﻿#ifndef DEF_ICE_COLOR
#define DEF_ICE_COLOR

#include "TypesGraphics.h"

#define ICE_Color_Red ICE_Color_New(255,0,0)
#define ICE_Color_Blue ICE_Color_New(0,0,255)
#define ICE_Color_Green ICE_Color_New(0,255,0)
#define ICE_Color_Black ICE_Color_New(0,0,0)
#define ICE_Color_White ICE_Color_New(255,255,255)
#define ICE_Color_Grey ICE_Color_New(127,127,127)

/**
 * \brief Create a new Color 
 * \param r The red value
 * \param g The green value
 * \param b The blue value
 * \return The new created Color
 */
inline ICE_Color ICE_Color_New(const size_t r, const size_t g, const size_t b) {
	return (r << 24) + (g << 16) + (b << 8) + 255;
}

/**
* \brief Create a new Color
* \param r The red value
* \param g The green value
* \param b The blue value
* \param a the alpha value
* \return The new created Color
*/
inline ICE_Color ICE_Color_New_Rgba(const size_t r, const size_t g, const size_t b,
									const size_t a)
{
	return (r << 24) + (g << 16) + (b << 8) + a;
}

#endif
