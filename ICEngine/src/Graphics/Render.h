#ifndef DEF_ICE_INPUT_RENDER
#define DEF_ICE_INPUT_RENDER

#include "TypesGraphics.h"


/**
 * \brief Enable or Disable Auto Drawing at each loop
 * \param yn Answer
 */
void ICE_Render_AutoDraw(ICE_Bool yn);

/**
 * \brief Enable or Disable Auto Screen clearing at each loop
 * \param yn Answer
 */
void ICE_Render_AutoClear(ICE_Bool yn);

/**
 * \brief Set a color to be the background color of the renderer
 * \param rgba_hex Color to set
 */
void ICE_Render_Color(const ICE_Color rgba_hex);

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
