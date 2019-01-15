#include <ICE.h>
#include "player.h"
#include "game.h"
#include "control.h"

void GAME_Player_Create(ICE_Entity*  this_)
{
	GAME_DATA * D = ICE_Data_Get(NULL, 0);
	GAME_DATA_PLAYER * D_player = ICE_Entity_DataAdd(ICE_Entity_Get(NULL, D->player), GAME_DATA_PLAYER);
	
	D_player->speed = 190;
	D_player->frame_down = 53;
	D_player->frame_up = 56;
	D_player->frame_left = 82;
	D_player->frame_right = 79;
	D_player->size_text = 25;
	D_player->name = ICE_String_Init("Coldragon");
	
	ICE_Entity_SetSprite(ICE_Entity_Get(NULL, D->player), D->sprite_player); // Set Sprite to Entity
	ICE_Entity_SetSpriteFrame(ICE_Entity_Get(NULL, D->player), D_player->frame_down); // Select Frame

	D->hello_world = ICE_Label_Create(NULL, D_player->name, ICE_Vect_New(0, 0), D_player->size_text, ICE_LABELTYPE_WORLD);
	ICE_Label_SetString(ICE_Label_Get(NULL, D->hello_world), D_player->name);
}

void GAME_Player_Update(ICE_Entity*  this_)
{
	GAME_DATA * D = ICE_Data_Get(NULL, 0);
	ICE_Vect vect = ICE_Entity_GetPosition(ICE_Entity_Get(NULL, D->player));
	vect.y -= 50;
	ICE_Label_SetPos(ICE_Label_Get(NULL, D->hello_world), vect);
	
	GAME_Control();


}

void GAME_Player_Destroy(ICE_Entity*  this_)
{
	GAME_DATA_PLAYER * D_player = ICE_Entity_DataGet(this_, 0);
	ICE_String_Delete(D_player->name);
}

void GAME_Player_Init()
{
	GAME_DATA * D = ICE_Data_Get(NULL, 0);
	D->player = ICE_Entity_Create(NULL, ICE_Box_New(0, 0, 64, 64));
	ICE_Entity_SetFunction(ICE_Entity_Get(NULL, D->player), GAME_Player_Create, GAME_Player_Update, GAME_Player_Destroy);
}
