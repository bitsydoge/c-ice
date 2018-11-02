#include <ICE.h>

#include "config.h"
#include "game.h"
#include "control.h"
#include "player.h"

ICE_Game_Create()
{
	GAME_DATA * D = ICE_Data_Insert(NULL, GAME_DATA);
	D->spritesheet = ICE_Texture_Load("res//img//spritesheet.png");
	D->texture_gui = ICE_Texture_Load("res//img//gui.png");
	D->main_sprite = ICE_Sprite_Load(D->spritesheet, ICE_Vect_New(64, 64));
	D->main_theme = ICE_Music_Load("res//snd//music.ogg");
	D->explosion = ICE_Sound_Load("res//snd//explosion.wav");
	ICE_Font_Load("res//ttf//FiraSans-Medium.ttf");

	D->rectangle = ICE_Gui_Insert(NULL, 0, ICE_Box_New(0, 0, 1280, 50), D->texture_gui);
	D->hello_world = ICE_Label_Create(NULL, "Player", ICE_Vect_Zero, 15, ICE_LABELTYPE_WORLD);
	ICE_Music_Play(0, 0.1);

	GAME_Player_Init();
}

ICE_Game_Update()
{
	GAME_Control();
}

ICE_Game_Destroy()
{
	
}