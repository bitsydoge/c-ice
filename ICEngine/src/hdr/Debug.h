#ifndef DEF_ICE_DEBUG
#define DEF_ICE_DEBUG
#include "TypesCore.h"

/**
 * \brief Set if the debug is On or Off
 * \param yn Bool, ICE_True or ICE_False. Use ICE_BoolNone if you just want to know the state
 * \return The actual state
 */
ICE_Bool ICE_Debug(const ICE_Bool yn);

/**
 * \brief Draw the mouse coordinate
 */
void ICE_Debug_DrawCoordinate();

/**
 * \brief Draw the fps on screen using debug font
 */
void ICE_Debug_DrawFps();

/**
 * \brief Show FPS in the title
 */
void ICE_Debug_TitleFps();

/**
 * \brief The background color of the debug font
 * \param r Red value
 * \param g Green value
 * \param b Blue value
 */
void ICE_Debug_FontSetColorBg(int r, int g, int b);

/**
 * \brief The color of the debug font
 * \param r Red value
 * \param g Green value
 * \param b Blue value
 */
void ICE_Debug_FontSetColorFg(int r, int g, int b);

/**
 * \brief Draw text on screen
 * \param y The position in the Y axis, 0 = First line, 1 = Second line etc ...
 * \param format char array formated
 * \param ... value for formating
 */
void ICE_Debug_FontDraw(int y, const char* format, ...);

/**
 * \brief Basic control for camera (WQSD, ARROW)
 */
void ICE_Debug_CameraControl();

#endif
