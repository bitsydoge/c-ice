#ifndef DEF_ICE_GAME
#define DEF_ICE_GAME

#include "../Framework/String_.h"
#include "Types.h"

/**
 * \brief Get the value of time between last frame
 * \return The elapsed time between last frame
 */
ICE_Float ICE_Game_GetDelta();

/**
 * \brief Get the fps value
 * \return The fps value
 */
ICE_Float ICE_Game_GetFps();

ICE_StringStd ICE_Game_GetVersion();

#endif
