#ifndef DEF_ICE_RENDER_PRIVATE
#define DEF_ICE_RENDER_PRIVATE

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

void ICE_Render_SplashScreen();

#if defined(_DEBUG)
void ICE_Render_Info();
#else
#define ICE_Render_Info(...)
#endif

void ICE_Render_Init();
void ICE_Render_Quit();

#endif
