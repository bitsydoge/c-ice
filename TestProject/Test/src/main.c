#include <ICE.h>

#define ICE_CONFIG_EDITORNAME "coldragon"
#define ICE_CONFIG_PRODUCTNAME "test"
#define ICE_CONFIG_TITLE "Test"
#define ICE_CONFIG_WINDOW_W 1280
#define ICE_CONFIG_WINDOW_H 720
#define ICE_CONFIG_WINDOW_ICON "res//img//pic_64x64.png"

/*
 *
 * tx = Texture		sp = Sprite
 * sn = Sound		ms = Music
 * en = Entity
 * gi = Gui			lb = Label
 * 
 */

typedef struct
{
	//Assets
	ICE_ID tx_spritesheet, tx_gui, sp_main_sprite; 
	ICE_ID ms_main_theme, sn_explosion;

	//GameObject
	ICE_ID en_player;
	ICE_ID gi_rectangle;
	int player_speed;

} Data;

ICE_Game_Create()
{
	Data * D = ICE_Data_Insert(NULL, Data);

	D->tx_spritesheet = ICE_Texture_Load("res//img//spritesheet.png");
	D->tx_gui = ICE_Texture_Load("res//img//gui.png");
	D->sp_main_sprite = ICE_Sprite_Load(D->tx_spritesheet, ICE_Vect_New(64, 64));
	D->ms_main_theme = ICE_Music_Load("res//snd//music.ogg");
	D->sn_explosion = ICE_Sound_Load("res//snd//explosion.wav");

	ICE_EntityManager_Insert(NULL);
	D->en_player = ICE_Entity_Insert(NULL, 0, ICE_Box_New(0,0,64,64));
	D->player_speed = 190;

	ICE_Entity_SetSprite(ICE_Entity_Get(NULL, 0, D->en_player), D->sp_main_sprite); // Set Sprite to Entity
	ICE_Entity_SetSpriteFrame(ICE_Entity_Get(NULL, 0, D->en_player), 53); // Select Frame

	ICE_GuiManager_Insert(NULL);
	ICE_Gui_Insert(NULL, 0, ICE_Box_New(0, 0, 1280, 50), D->tx_gui);

	ICE_Music_Play(0, 0.1);
}

ICE_Game_Update()
{
	Data * D = ICE_Data_Get(NULL, 0);
	ICE_Entity * player = ICE_Entity_Get(NULL, 0, D->en_player);

	if (ICE_Input_Pressed(ICE_KEY_D))
	{
		ICE_Entity_ShiftPos(player, D->player_speed * ICE_Game_GetDelta(), 0);
		ICE_Entity_SetSpriteFrame(player, 79);
	}
	if (ICE_Input_Pressed(ICE_KEY_A))
	{
		ICE_Entity_ShiftPos(player, -D->player_speed * ICE_Game_GetDelta(), 0);
		ICE_Entity_SetSpriteFrame(player, 82);
	}	
	if (ICE_Input_Pressed(ICE_KEY_W))
	{
		ICE_Entity_ShiftPos(player, 0, -D->player_speed * ICE_Game_GetDelta());
		ICE_Entity_SetSpriteFrame(player, 56);
	}
	if (ICE_Input_Pressed(ICE_KEY_S))
	{
		ICE_Entity_ShiftPos(player, 0, D->player_speed * ICE_Game_GetDelta());
		ICE_Entity_SetSpriteFrame (player, 53);
	}
}

ICE_Game_Destroy()
{
	
}