#ifndef DEF_ICE_CORE
#define DEF_ICE_CORE

#define ICE_Game_Update() void ICE_User_Update(void)
#define ICE_Game_Destroy() void ICE_User_Destroy(void)
#define ICE_Game_Create() void ICE_User_Create(void);\
	ICE_Game_Update();\
	ICE_Game_Destroy();\
	extern ICE_Config CONFIG;\
	int main(int argc, char ** argv)\
	{\
		CONFIG.argc = argc;\
		CONFIG.argv = argv;\
		CONFIG.title = ICE_CONFIG_TITLE;\
		CONFIG.editor_name = ICE_CONFIG_EDITORNAME;\
		CONFIG.product_name = ICE_CONFIG_PRODUCTNAME;\
		CONFIG.window_w = ICE_CONFIG_WINDOW_W;\
		CONFIG.window_h = ICE_CONFIG_WINDOW_H;\
		CONFIG.window_icon = ICE_CONFIG_WINDOW_ICON;\
		CONFIG.refresh_rate = ICE_CONFIG_REFRESHRATE;\
		CONFIG.fullscreen = ICE_CONFIG_FULLSCREEN;\
		CONFIG.resizable = ICE_CONFIG_RESIZABLE;\
		CONFIG.vsync = ICE_CONFIG_VSYNC;\
		CONFIG.game_version = ICE_CONFIG_GAME_VERSION;\
		ICE_Core_Main(ICE_User_Create, ICE_User_Update, ICE_User_Destroy);\
		return 0;\
	}\
	void ICE_User_Create(void)

void ICE_Core_Main(void(*call_create)(void), void(*call_update)(void), void(*call_destroy)(void));

#endif
