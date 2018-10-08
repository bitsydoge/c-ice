#ifndef DEF_ICE_CORE
#define DEF_ICE_CORE

#define ICE_VERSION (ICE_StringStd)"DEV.1810.02"

#define ICE_Game_Update() void ICE_User_Update(void)
#define ICE_Game_Destroy() void ICE_User_Destroy(void)

#define ICE_Game_Create(TITLE, WIDTH, HEIGHT) void ICE_User_Create(void);\
	ICE_Game_Update();\
	ICE_Game_Destroy();\
	int main(int argc, char ** argv)\
	{\
		ICE_Core_Main(TITLE, WIDTH, HEIGHT, ICE_User_Create, ICE_User_Update, ICE_User_Destroy, argc, argv);\
		return 0;\
	}\
	void ICE_User_Create(void)

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
