#ifndef DEF_ICE_FONT
#define DEF_ICE_FONT

#include "TypesGraphics.h"
#include "../Maths/TypesMaths.h"

/**
 * \brief Load the font
 * \param path Path to the font file
 */
void ICE_Font_Insert(char *path);

/**
 * \brief Unoptimized font drawing
 * \param text Text to draw
 * \param vect Position of the text
 * \param fg Color of the text
 * \param bg Color of the background
 */
void ICE_Font_Draw(char* text, ICE_Vect vect, ICE_Color fg, ICE_Color bg);

#endif
