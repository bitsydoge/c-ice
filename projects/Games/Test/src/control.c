#include <ICE.h>
#include "game.h"
#include "projectile.h"
#include "player.h"

void GAME_Control()
{
	GAME_DATA * D = ICE_Data_Get(NULL, 0);
	ICE_Entity * player = ICE_Entity_Get(NULL, D->player);
	GAME_DATA_PLAYER * D_player = ICE_Entity_DataGet(player, 0);
	ICE_Gui_SetSize(ICE_Gui_Get(NULL, D->rectangle), ICE_Vect_New(ICE_Window_GetW(), 64));
	if (ICE_Entity_GetSpriteFrame(player) == D_player->frame_down)
	{
		D_player->dx = 0;
		D_player->dy = 1;
	}
	if (ICE_Entity_GetSpriteFrame(player) == D_player->frame_up)
	{
		D_player->dx = 0;
		D_player->dy = -1;
	}
	if (ICE_Entity_GetSpriteFrame(player) == D_player->frame_left)
	{
		D_player->dx = -1;
		D_player->dy = 0;
	}
	if (ICE_Entity_GetSpriteFrame(player) == D_player->frame_right)
	{
		D_player->dx = 1;
		D_player->dy = 0;
	}
	if (ICE_Input_Pressed(ICE_KEY_D))
	{
		ICE_Entity_ShiftPos(player, D_player->speed * ICE_Game_GetDelta(), 0);
		ICE_Entity_SetSpriteFrame(player, D_player->frame_right);
		D_player->dx = 1;
	}
	if (ICE_Input_Pressed(ICE_KEY_A))
	{
		ICE_Entity_ShiftPos(player, -D_player->speed * ICE_Game_GetDelta(), 0);
		ICE_Entity_SetSpriteFrame(player, D_player->frame_left);
		D_player->dx = -1;
	}
	if (ICE_Input_Pressed(ICE_KEY_W))
	{
		ICE_Entity_ShiftPos(player, 0, -D_player->speed * ICE_Game_GetDelta());
		ICE_Entity_SetSpriteFrame(player, D_player->frame_up);
		D_player->dy = -1;
	}
	if (ICE_Input_Pressed(ICE_KEY_S))
	{
		ICE_Entity_ShiftPos(player, 0, D_player->speed * ICE_Game_GetDelta());
		ICE_Entity_SetSpriteFrame(player, D_player->frame_down);
		D_player->dy = 1;
	}

	if (ICE_Input_OnPress(ICE_KEY_RETURN))
	{
		ICE_Vect vect = ICE_Entity_GetPosition(player);
		const ICE_Box box = { vect.x, vect.y, 32, 32 };
		ICE_Entity * fireball = ICE_Entity_Get(NULL, ICE_Entity_Create(NULL, box));
		ICE_Entity_SetFunction(fireball, GAME_Projectile_Create, GAME_Projectile_Update, GAME_Projectile_Destroy);
	}

	if (ICE_Input_Pressed(ICE_KEY_KP_PLUS))
	{
		D_player->size_text++;

		if (D_player->size_text > 255)
			D_player->size_text = 255;

		ICE_Label_SetSize(ICE_Label_Get(NULL, D->hello_world), D_player->size_text);
	}

	if (ICE_Input_Pressed(ICE_KEY_KP_MINUS))
	{
		D_player->size_text--;

		if (D_player->size_text < 1)
			D_player->size_text = 1;

		ICE_Label_SetSize(ICE_Label_Get(NULL, D->hello_world), D_player->size_text);
	}


}
