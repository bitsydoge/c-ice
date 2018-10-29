#include <ICE.h>

#define ICE_CONFIG_EDITORNAME "coldragon"
#define ICE_CONFIG_PRODUCTNAME "test"
#define ICE_CONFIG_TITLE "Test"
#define ICE_CONFIG_WINDOW_W 1280
#define ICE_CONFIG_WINDOW_H 720
#define ICE_CONFIG_WINDOW_ICON "res//img//pic_64x64.png"

ICE_Game_Create()
{
	ICE_ID tx_spritesheet = ICE_Texture_Load("res//img//spritesheet.png");
	ICE_ID sp_main_sprite = ICE_Sprite_Load(tx_spritesheet, ICE_Vect_New(64,64));
	ICE_ID ms_main_theme = ICE_Music_Load("res//snd//music.ogg");
	ICE_ID sn_explosion = ICE_Sound_Load("res//snd//explosion.wav");
}

ICE_Game_Update()
{
	if (ICE_Input_OnPress(ICE_KEY_ESCAPE))
		ICE_Input_Quit();
}

ICE_Game_Destroy()
{
	
}