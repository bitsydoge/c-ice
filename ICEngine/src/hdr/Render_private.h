#ifndef DEF_ICE_INPUT_RENDER_PRIVATE
#define DEF_ICE_INPUT_RENDER_PRIVATE

#include "TypesGraphics.h"

/**
 * \brief Change the rendering color in SDL
 * \param rgba_hex color to change
 * \return 0
 */
int ICE_Render_SetColor(const ICE_Color rgba_hex);

/**
 * \brief Clear screen
 * \return 0
 */
int ICE_Render_Clear();

/**
 * \brief Flip the buffer to draw everything on screen
 */
void ICE_Render_Now();

#endif
