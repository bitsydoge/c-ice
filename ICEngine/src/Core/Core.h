#ifndef DEF_ICE_CORE
#define DEF_ICE_CORE

#define ICE_VERSION "105<dev>"
#define ICE_DEBUG_BUILD 1;

#define ICE_START(NAME, WIDTH, HEIGHT) ICE_Core_Main(NAME, WIDTH, HEIGHT, ICE_User_Preload, ICE_User_Create, ICE_User_Update, ICE_User_Destroy)

#define ICE_PRELOAD() void ICE_User_Preload(void)
#define ICE_CREATE() void ICE_User_Create(void)
#define ICE_UPDATE() void ICE_User_Update(void)
#define ICE_DESTROY() void ICE_User_Destroy(void)

#if defined(_MSC_VER) && defined(_DEBUG)
	#include <vld.h>
#endif

#include "../Framework/String_.h"

/**
 * \brief The main loop of the engine
 * \param title The Title of the game
 * \param window_width The width of the window
 * \param window_height The height of the window
 * \param call_preload The preload function where you load Assets (Img, Sound, Ttf)
 * \param call_create The create function where you create entitys 
 * \param call_update The update function called every frames
 * \param call_destroy The destroy function called at the end
 * \return 0
 */
int ICE_Core_Main(ICE_String title, int window_width, int window_height, void (*call_preload)(void),
				  void (*call_create)(void), void (*call_update)(void), void (*call_destroy)(void));

#endif