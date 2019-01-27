#ifndef DEF_ICE_TERMINALCOLOR
#define DEF_ICE_TERMINALCOLOR

/**
 * \brief Color usable in the terminal with ICE_Term_ function
 */
enum ICE_TermColor {
	ICE_TERMCOLOR_BLACK,
	ICE_TERMCOLOR_BLUE,
	ICE_TERMCOLOR_GREEN,
	ICE_TERMCOLOR_CYAN,
	ICE_TERMCOLOR_RED,
	ICE_TERMCOLOR_MAGENTA,
	ICE_TERMCOLOR_BROWN,
	ICE_TERMCOLOR_GREY,
	ICE_TERMCOLOR_DARKGREY,
	ICE_TERMCOLOR_LIGHTBLUE,
	ICE_TERMCOLOR_LIGHTGREEN,
	ICE_TERMCOLOR_LIGHTCYAN,
	ICE_TERMCOLOR_LIGHTRED,
	ICE_TERMCOLOR_LIGHTMAGENTA,
	ICE_TERMCOLOR_YELLOW,
	ICE_TERMCOLOR_WHITE
};

#if defined(_DEBUG)
/**
 * \brief Reset color to default terminal color
 */
void ICE_Term_ResetColor();

/**
 * \brief Set color of text in terminal
 * \param c Color to set
 */
void ICE_Term_SetColor(const int c);

/**
 * \brief Set background color of text in terminal
 * \param c Color to set
 */
void ICE_Term_SetBgColor(const int c);

/**
 * \brief Clear everything in terminal
 */
void ICE_Term_Clear();

/**
 * \brief Draw time since game start on terminal without line return
 */
void ICE_Term_Clock(int color);

void ICE_Term_Hour();

/**
 * \brief Wait a key to continue with message 
 */
void ICE_Term_Wait();
#else
#define ICE_Term_ResetColor()
#define ICE_Term_SetColor(INT)
#define ICE_Term_SetBgColor(INT)
#define ICE_Term_Clear()
#define ICE_Term_Clock()
#define ICE_Term_Wait()
#endif
#endif