#include <ICE.h>

#include "config.h"
#include "game.h"
#include "player.h"
#include "debug.h"

#include "Ressources/bin/space.jpg.bin.c"

extern ICE_Config CONFIG;

ICE_Game_Create()
{
	GAME_DATA * D = ICE_Data_Insert(ICE_State_Current, GAME_DATA);

	SDL_RWops * rwops_test = SDL_RWFromConstMem(ICE_BinaryFile_space_jpg, ICE_BinaryFile_space_jpg_length);
	D->texture_background = ICE_Texture_Load_RW(rwops_test);
	D->texture_tileset = ICE_Texture_Load("res//img//001-SPRITESHEET");
	D->texture_gui_icons = ICE_Texture_Load("res//img//002-ICONS");
	D->texture_gui = ICE_Texture_Load("res//img//003-GUI");
	D->texture_items_spritesheet = ICE_Texture_Load("res//img//004-ITEMS");
	D->sprite_player = ICE_Sprite_Load(D->texture_tileset, ICE_Vect_New(64, 64));

	D->main_theme = ICE_Music_Load("res//snd//001-MUSIC");
	D->explosion = ICE_Sound_Load("res//snd//001-SOUND");
	D->font = ICE_Font_Load("res//ttf//001-FONT");

	D->rectangle = ICE_Gui_Create(NULL, ICE_Box_New(0, 0, 0, 50), D->texture_gui);

	ICE_Entity_SetTexture(ICE_Entity_Get(NULL, ICE_Entity_Create(NULL, ICE_Box_New(0, 0, 1920, 1080))), D->texture_background);

	ICE_Debug_CallbackDraw(GAME_Debug_LateDraw);
	ICE_Music_Play(0, 0.05);

	GAME_Player_Init();
}

ICE_Game_Update()
{

}

ICE_Game_Destroy()
{

}