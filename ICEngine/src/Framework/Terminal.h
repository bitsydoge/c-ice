#ifndef DEF_ICE_TERMINALCOLOR
#define DEF_ICE_TERMINALCOLOR

/**
 * \brief Color usable in the terminal with ICE_Term_ function
 */
enum ICE_TermColor {
	ICE_T_BLACK,
	ICE_T_BLUE,
	ICE_T_GREEN,
	ICE_T_CYAN,
	ICE_T_RED,
	ICE_T_MAGENTA,
	ICE_T_BROWN,
	ICE_T_GREY,
	ICE_T_DARKGREY,
	ICE_T_LIGHTBLUE,
	ICE_T_LIGHTGREEN,
	ICE_T_LIGHTCYAN,
	ICE_T_LIGHTRED,
	ICE_T_LIGHTMAGENTA,
	ICE_T_YELLOW,
	ICE_T_WHITE
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
void ICE_Term_Clock();

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