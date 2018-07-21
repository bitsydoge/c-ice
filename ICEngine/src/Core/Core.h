#ifndef DEF_ICE_CORE
#define DEF_ICE_CORE

#define ICE_VERSION "105<dev>"
#define ICE_DEBUG_BUILD 1;

#if defined(_DEBUG)
#define ICE_Start(NAME, WIDTH, HEIGHT) ICE_Debug_Set(ICE_True);\
ICE_Core_Main(NAME, WIDTH, HEIGHT, ICE_User_Preload, ICE_User_Create, ICE_User_Update, ICE_User_Destroy)
#else
#define ICE_Start(NAME, WIDTH, HEIGHT) ICE_Debug_Set(ICE_False);\
ICE_Core_Main(NAME, WIDTH, HEIGHT, ICE_User_Preload, ICE_User_Create, ICE_User_Update, ICE_User_Destroy)
#endif

#define ICE_Main_Preload() void ICE_User_Preload(void)
#define ICE_Main_Create() void ICE_User_Create(void)
#define ICE_Main_Update() void ICE_User_Update(void)
#define ICE_Main_Destroy() void ICE_User_Destroy(void)

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
int ICE_Core_Main(const ICE_String title, const int window_width, const int window_height, void(*call_preload)(void), void(*call_create)(void), void(*call_update)(void), void(*call_destroy)(void));

#endif