#ifndef DEF_ICE_CORE
#define DEF_ICE_CORE

#define ICE_VERSION (ICE_StringStd)"105<dev>"

#define ICE_Game_Update() void ICE_User_Update(void)
#define ICE_Game_Destroy() void ICE_User_Destroy(void)

#if defined(_DEBUG)
#define ICE_Game_Create(NAME, WIDTH, HEIGHT) void ICE_User_Create(void);\
	ICE_Game_Update();\
	ICE_Game_Destroy();\
	int main(int argc, char ** argv)\
	{\
		ICE_Debug_Set(ICE_True);\
		ICE_Core_Main(NAME, WIDTH, HEIGHT, ICE_User_Create, ICE_User_Update, ICE_User_Destroy, argc, argv);\
	}\
	void ICE_User_Create(void)
#else
#define ICE_Game_Create(NAME, WIDTH, HEIGHT) void ICE_User_Create(void); \
	ICE_Game_Update(); \
	ICE_Game_Destroy(); \
	int main(int argc, char ** argv)\
	{\
		ICE_Debug_Set(ICE_False); \
		ICE_Core_Main(NAME, WIDTH, HEIGHT, ICE_User_Create, ICE_User_Update, ICE_User_Destroy, argc, argv); \
	}\
	void ICE_User_Create(void)
#endif

#include "../Framework/String_.h"

/**
 * \brief The main loop of the engine
 * \param title The Title of the game
 * \param window_width The width of the window
 * \param window_height The height of the window
 * \param call_create The create function where you create entitys 
 * \param call_update The update function called every frames
 * \param call_destroy The destroy function called at the end
 * \return 0
 */
int ICE_Core_Main(char * title, const int window_width, const int window_height, void(*call_create)(void), void(*call_update)(void), void(*call_destroy)(void), int argc, char **argv);


/**
 * \brief 
 * \return 
 */
ICE_StringStd ICE_Core_GetLinkedVersion();
inline ICE_StringStd ICE_Core_GetCompiledVersion()
{
	return ICE_VERSION;
}

#endif
