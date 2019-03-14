#include <ICE.h>

#include "config.h"
#include "game.h"
#include "player.h"
#include "debug.h"


#include "Engine/Data.h"
#include "Engine/Pack.h"
#include "Engine/Music.h"
#include "Engine/Sound.h"
#include "Engine/Box.h"
#include "Engine/Entity.h"
#include "Engine/Debug.h"
#include "Engine/Input.h"
#include "Framework/Random.h"
#include "Engine/Time_.h"
#include "Engine/Game.h"
#include "Engine/Screenshot.h"

void ICE_Game_Create()
{
	// Data 
	GAME_DATA * D = ICE_Data_Insert(NULL, GAME_DATA);

	// Pack Load
	ICE_Pack_Load("res\\pak\\pak1.zip");
	
	// Texture Load
	D->texture_tileset = ICE_Texture_Load("res://001-SPRITESHEET$CoLdRaGoN");
	D->texture_gui_icons = ICE_Texture_Load("res://002-ICONS$CoLdRaGoN");
	D->texture_gui = ICE_Texture_Load("res://003-GUI$CoLdRaGoN");
	D->texture_items_spritesheet = ICE_Texture_Load("res://004-ITEMS");
	D->texture_background = ICE_Texture_Load("res://005-BACKGROUND$CoLdRaGoN");

	// Sprite Load
	D->sprite_player = ICE_Sprite_Load(D->texture_tileset, ICE_Vect_New(64, 64));

	// Sound & Music Load
	D->main_theme = ICE_Music_Load("res//snd//001-MUSIC");
	D->explosion = ICE_Sound_Load("res//snd//001-SOUND");
	
	// Font Load
	D->font = ICE_Font_Load("res//ttf//001-FONT");

	// GUI Create
	D->rectangle = ICE_Gui_Create(NULL, ICE_Box_New(0, 0, 0, 64), ICE_GUITYPE_9PATCH);
	ICE_Gui_SetTexture(ICE_Gui_Get(NULL, D->rectangle), D->texture_gui);

	// Background create
	ICE_Entity_SetTexture(ICE_Entity_Get(NULL, ICE_Entity_Create(NULL, ICE_Box_New(0, 0, 1920, 1920))), D->texture_background);

	// Music Start
	ICE_Music_Play(0, 0.05);
	
	// Player Init
	GAME_Player_Init();

	// Debug Init
	ICE_Debug_CallbackDraw(GAME_Debug_LateDraw);
}

void ICE_Game_Update()
{
	GAME_DATA * D = ICE_Data_Get(ICE_State_Current, 0);

	ICE_String temp = ICE_String_Init("");
	static ICE_Float timer_screenshot_value = 0.0;
	
	if(ICE_Input_OnPress(ICE_KEY_L))
	{
		ICE_EntityID entity_temp = ICE_Entity_Create(ICE_State_Current, ICE_Box_New(ICE_Random_Int(-500, 500), ICE_Random_Int(-500, 500), 64, 64));
		ICE_Entity_SetSprite(ICE_Entity_Get(NULL, entity_temp), D->sprite_player); // Set Sprite to Entity
		ICE_Entity_SetSpriteFrame(ICE_Entity_Get(NULL, entity_temp), 10); // Select Frame
	}

	if(ICE_Input_OnPress(ICE_KEY_K))
	{
		ICE_Screenshot(NULL, "png");

		timer_screenshot_value = 3.0;
		D->screenShotDraw = ICE_True;

		if(D->screenshot_name == 0)
			D->screenshot_name = ICE_String_Init("Screenshot taken ! %ld", ICE_Time_GetMS());
	}
	if(D->screenShotDraw == ICE_True)
	{
		if(timer_screenshot_value > 0)
		{
			timer_screenshot_value -= ICE_Game_GetDelta();
		}
		else
		{
			D->screenShotDraw = ICE_False;
			ICE_String_Destroy(&D->screenshot_name);
		}
	}

	ICE_String_Free(temp);
}

void ICE_Game_Destroy()
{
	ICE_Pack_Unload("res//pak//pak1.zip");
	GAME_DATA * D = ICE_Data_Get(NULL, 0);
	ICE_String_Destroy(&D->screenshot_name);
}