#ifndef DEF_ICE_DEBUG
#define DEF_ICE_DEBUG

#include "TypesCore.h"
#include "../Framework/Inline.h"

// Get the Header and User debug mode
ICE_INLINE ICE_Bool ICE_Debug_Get_Compiled()
{
#if defined(_DEBUG)
	return ICE_True;
#else
	return ICE_False;
#endif
}

// Get the Library Debug
ICE_Bool ICE_Debug_Get_Linked();

#if defined(_DEBUG)

/**
 * \brief Draw the mouse coordinate
 */
void ICE_Debug_DrawCoordinate();

/**
 * \brief Draw the fps on screen using debug font
 * \param y_pos Position of the font on screen line
 */
void ICE_Debug_DrawFps(int y_pos);

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


/**
 * \brief 
 * \param callback Callback to the function to debug draw
 */
void ICE_Debug_CallbackDraw(void(*callback)());

#else
#define ICE_Debug_DrawCoordinate();
#define ICE_Debug_DrawFps(...);
#define ICE_Debug_TitleFps();
#define ICE_Debug_FontSetColorBg(...);
#define ICE_Debug_FontSetColorFg(...);
#define ICE_Debug_FontDraw(...);
#define ICE_Debug_CameraControl();
#define ICE_Debug_CallbackDraw(...);
#endif

#endif

