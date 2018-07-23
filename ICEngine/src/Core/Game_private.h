#ifndef DEF_ICE_GAME_PRIVATE
#define DEF_ICE_GAME_PRIVATE

/**
 * \brief Create the ICE_Game object
 * \param window_title The game title
 * \param width_window The window witdh
 * \param height_window The window height
 */
void ICE_Game_Create(char *window_title, const unsigned int width_window, const unsigned int height_window, int argc, char **argv);

/**
 * \brief Destroy the game object
 */
void ICE_Game_Destroy();

#endif