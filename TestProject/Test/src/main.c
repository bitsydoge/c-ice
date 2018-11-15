#include <ICE.h>

#include "config.h"
#include "game.h"
#include "player.h"
#include "debug.h"

ICE_Game_Create()
{
	GAME_DATA * D = ICE_Data_Insert(NULL, GAME_DATA);

	D->spritesheet = ICE_Texture_Load("res//img//spritesheet.png");
	D->texture_items_spritesheet = ICE_Texture_Load("res//img//001-ITEMS");
	D->texture_gui_icons = ICE_Texture_Load("res//img//002-ICONS");
	D->texture_gui = ICE_Texture_Load("res//img//003-GUI");
	D->background = ICE_Texture_Load("res//img//background.png");
	D->main_theme = ICE_Music_Load("res//snd//music.ogg");
	D->explosion = ICE_Sound_Load("res//snd//explosion.wav");
	D->font = ICE_Font_Load("res//ttf//FiraSans-Medium.ttf");
	D->main_sprite = ICE_Sprite_Load(D->spritesheet, ICE_Vect_New(64, 64));

	D->rectangle = ICE_Gui_Create(NULL, ICE_Box_New(0, 0, 1280, 50), D->texture_gui);

	// Map	
	ICE_Entity_SetTexture(ICE_Entity_Get(NULL, ICE_Entity_Create(NULL, ICE_Box_New(0, 0, 1920, 1920))), D->background);

	ICE_Debug_CallbackDraw(GAME_Debug_LateDraw);
	ICE_Music_Play(0, 0.1);

	GAME_Player_Init();
}

ICE_Game_Update()
{

}

ICE_Game_Destroy()
{

}