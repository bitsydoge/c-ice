#ifndef DEF_ICE_CORE
#define DEF_ICE_CORE

#include "Config.h"
#include "ConfigDefault.h"

#define ICE_Game_Update() ICE_User_Update(void)
#define ICE_Game_Destroy() ICE_User_Destroy(void)
#define ICE_Game_Create() ICE_User_Create(void);\
	void ICE_Game_Update();\
	void ICE_Game_Destroy();\
	extern ICE_Config ICE_GLOBJ_CONFIG;\
	int main(int argc, char ** argv)\
	{\
		ICE_GLOBJ_CONFIG.argc = argc;\
		ICE_GLOBJ_CONFIG.argv = argv;\
		ICE_GLOBJ_CONFIG.title = ICE_CONFIG_TITLE;\
		ICE_GLOBJ_CONFIG.editor_name = ICE_CONFIG_EDITORNAME;\
		ICE_GLOBJ_CONFIG.product_name = ICE_CONFIG_PRODUCTNAME;\
		ICE_GLOBJ_CONFIG.window_w = ICE_CONFIG_WINDOW_W;\
		ICE_GLOBJ_CONFIG.window_h = ICE_CONFIG_WINDOW_H;\
		ICE_GLOBJ_CONFIG.window_icon = ICE_CONFIG_WINDOW_ICON;\
		ICE_GLOBJ_CONFIG.refresh_rate = ICE_CONFIG_REFRESHRATE;\
		ICE_GLOBJ_CONFIG.fullscreen = ICE_CONFIG_FULLSCREEN;\
		ICE_GLOBJ_CONFIG.resizable = ICE_CONFIG_RESIZABLE;\
		ICE_GLOBJ_CONFIG.vsync = ICE_CONFIG_VSYNC;\
		ICE_GLOBJ_CONFIG.game_version = ICE_CONFIG_GAME_VERSION;\
		ICE_Core_Main(ICE_User_Create, ICE_User_Update, ICE_User_Destroy);\
		return 0;\
	}\
	void ICE_User_Create(void)

void ICE_Core_Main(void(*call_create)(void), void(*call_update)(void), void(*call_destroy)(void));

#endif
