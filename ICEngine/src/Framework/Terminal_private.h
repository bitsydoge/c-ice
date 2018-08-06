#ifndef DEF_ICE_TERMINAL_PRIVATE
#define DEF_ICE_TERMINAL_PRIVATE

#if defined(_DEBUG)

/**
 * \brief Save default terminal color
 */
void ICE_Term_SaveColor();

/**
 * \brief Hide cursor
 */
void ICE_Term_HideCursor();

#else
#define ICE_Term_SaveColor()
#define ICE_Term_HideCursor()
#endif

#endif
