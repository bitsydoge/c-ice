#ifndef DEF_ICE_CORE
#define DEF_ICE_CORE

#include "Config.h"
#include "ConfigDefault.h"

#define ICE_Game_Update() ICE_User_Update(void)
#define ICE_Game_Destroy() ICE_User_Destroy(void)
#define ICE_Game_Create() ICE_User_Create(void);\
	void ICE_Game_Update();\
	void ICE_Game_Destroy();\
	int main(int argc, char ** argv)\
	{\
		ICE_Config_GetPtr()->argc = argc;\
		ICE_Config_GetPtr()->argv = argv;\
		ICE_Config_GetPtr()->title = ICE_CONFIG_TITLE;\
		ICE_Config_GetPtr()->editor_name = ICE_CONFIG_EDITORNAME;\
		ICE_Config_GetPtr()->product_name = ICE_CONFIG_PRODUCTNAME;\
		ICE_Config_GetPtr()->window_w = ICE_CONFIG_WINDOW_W;\
		ICE_Config_GetPtr()->window_h = ICE_CONFIG_WINDOW_H;\
		ICE_Config_GetPtr()->window_icon = ICE_CONFIG_WINDOW_ICON;\
		ICE_Config_GetPtr()->refresh_rate = ICE_CONFIG_REFRESHRATE;\
		ICE_Config_GetPtr()->fullscreen = ICE_CONFIG_FULLSCREEN;\
		ICE_Config_GetPtr()->resizable = ICE_CONFIG_RESIZABLE;\
		ICE_Config_GetPtr()->vsync = ICE_CONFIG_VSYNC;\
		ICE_Config_GetPtr()->game_version = ICE_CONFIG_GAME_VERSION;\
		ICE_Core_Main(ICE_User_Create, ICE_User_Update, ICE_User_Destroy);\
		return 0;\
	}\
	void ICE_User_Create(void)

void ICE_Core_Main(void(*call_create)(void), void(*call_update)(void), void(*call_destroy)(void));

#endif
