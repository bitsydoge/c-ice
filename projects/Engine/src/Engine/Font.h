#ifndef DEF_ICE_FONT
#define DEF_ICE_FONT

#include "Types.h"
#include "Vect2D.h"
#include "Color.h"
#include "../Framework/String_.h"
#include "IO.h"

ICE_FontID ICE_Font_GetLastLoaded();
ICE_FontID ICE_Font_Load(ICE_StringStd path_);
ICE_FontID ICE_Font_Load_RW(ICE_IO rwops_);
void ICE_Font_Destroy(ICE_FontID font_);

#if defined(_DEBUG)
/**
 * \brief Unoptimized font drawing
 * \param text Text to draw
 * \param vect Position of the text
 * \param fg Color of the text
 * \param bg Color of the background
 */
void ICE_Font_Draw(ICE_StringStd text, ICE_Vect2D vect, ICE_Color fg, ICE_Color bg);
#else
#define ICE_Font_Draw(...)
#endif

#endif
