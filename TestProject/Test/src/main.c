#include <ICE.h>

#define ICE_CONFIG_EDITORNAME "coldragon"
#define ICE_CONFIG_PRODUCTNAME "test"
#define ICE_CONFIG_TITLE "Test"
#define ICE_CONFIG_WINDOW_W 1280
#define ICE_CONFIG_WINDOW_H 720
#define ICE_CONFIG_WINDOW_ICON "res//img//pic_64x64.png"

typedef struct
{
	//Assets
	ICE_TextureID spritesheet, texture_gui, main_sprite; 
	ICE_MusicID main_theme;
	ICE_SoundID explosion;

	//GameObject
	
	ICE_GuiID rectangle;
	ICE_LabelID hello_world;

	//Variable
	struct
	{
		ICE_EntityID id;
		int speed;
		int dx, dy;

		int frame_up, frame_down, 
		frame_left, frame_right;

	} player;
	

} GAME_DATA;

ICE_Game_Create()
{
	GAME_DATA * D = ICE_Data_Insert(NULL, GAME_DATA);

	D->spritesheet = ICE_Texture_Load("res//img//spritesheet.png");
	D->texture_gui = ICE_Texture_Load("res//img//gui.png");
	D->main_sprite = ICE_Sprite_Load(D->spritesheet, ICE_Vect_New(64, 64));
	D->main_theme = ICE_Music_Load("res//snd//music.ogg");
	D->explosion = ICE_Sound_Load("res//snd//explosion.wav");
	ICE_Font_Load("res//ttf//FiraSans-Medium.ttf");

	D->player.id = ICE_Entity_Create(NULL, ICE_Box_New(0,0,64,64));
	
	D->player.speed = 190;
	ICE_Entity_SetSprite(ICE_Entity_Get(NULL, D->player.id), D->main_sprite); // Set Sprite to Entity
	ICE_Entity_SetSpriteFrame(ICE_Entity_Get(NULL, D->player.id), 53); // Select Frame
	D->player.frame_down = 53;
	D->player.frame_up = 56;
	D->player.frame_left = 82;
	D->player.frame_right = 79;

	D->rectangle = ICE_Gui_Insert(NULL, 0, ICE_Box_New(0, 0, 1280, 50), D->texture_gui);
	D->hello_world = ICE_Label_Create(NULL, "Player", ICE_Vect_Zero, 15, ICE_LABELTYPE_WORLD);

	ICE_Music_Play(0, 0.1);
}

typedef struct
{
	int dx, dy;
	int speed;

} GAME_DATA_PROJECTILE;

void GAME_Projectile_Create(ICE_Entity * this_)
{
	GAME_DATA_PROJECTILE * D_entity = ICE_Entity_DataAdd(this_, GAME_DATA_PROJECTILE);
	GAME_DATA * D = ICE_Data_Get(NULL, 0);
	ICE_Entity * player = ICE_Entity_Get(NULL, D->player.id);

	ICE_Entity_SetSprite(this_, D->spritesheet);
	ICE_Entity_SetSpriteFrame(this_, 39);
	ICE_Sound_Play(D->explosion, 0.105);
	D_entity->speed = 600;
	D_entity->dx = D->player.dx;
	D_entity->dy = D->player.dy;
}

void GAME_Projectile_Update(ICE_Entity * this_)
{
	GAME_DATA_PROJECTILE * D_entity = ICE_Entity_DataGet(this_, 0);

	ICE_Entity_ShiftPos(this_, 
		D_entity->dx * D_entity->speed * ICE_Game_GetDelta(), 
		D_entity->dy * D_entity->speed * ICE_Game_GetDelta()
	);
}

void GAME_Projectile_Destroy(ICE_Entity * this_)
{
	
}

ICE_Game_Update()
{
	GAME_DATA * D = ICE_Data_Get(NULL, 0);
	ICE_Entity * player = ICE_Entity_Get(NULL, D->player.id);
	ICE_Label * label = ICE_Label_Get(NULL, D->hello_world);

	ICE_Vect vect = ICE_Entity_GetPosition(player);
	vect.y -= 50;
	ICE_Label_SetPos(label, vect);

	if (ICE_Entity_GetSpriteFrame(player) == D->player.frame_down)
	{
		D->player.dx = 0;
		D->player.dy = 1;
	}
	if (ICE_Entity_GetSpriteFrame(player) == D->player.frame_up)
	{
		D->player.dx = 0;
		D->player.dy = -1;
	}
	if (ICE_Entity_GetSpriteFrame(player) == D->player.frame_left)
	{
		D->player.dx = -1;
		D->player.dy = 0;
	}
	if (ICE_Entity_GetSpriteFrame(player) == D->player.frame_right)
	{
		D->player.dx = 1;
		D->player.dy = 0;
	}
	if (ICE_Input_Pressed(ICE_KEY_D))
	{
		ICE_Entity_ShiftPos(player, D->player.speed * ICE_Game_GetDelta(), 0);
		ICE_Entity_SetSpriteFrame(player, D->player.frame_right);
		D->player.dx = 1;
	}
	if (ICE_Input_Pressed(ICE_KEY_A))
	{
		ICE_Entity_ShiftPos(player, -D->player.speed * ICE_Game_GetDelta(), 0);
		ICE_Entity_SetSpriteFrame(player, D->player.frame_left);
		D->player.dx = -1;
	}
	if (ICE_Input_Pressed(ICE_KEY_W))
	{
		ICE_Entity_ShiftPos(player, 0, -D->player.speed * ICE_Game_GetDelta());
		ICE_Entity_SetSpriteFrame(player, D->player.frame_up);
		D->player.dy = -1;
	}
	if (ICE_Input_Pressed(ICE_KEY_S))
	{
		ICE_Entity_ShiftPos(player, 0, D->player.speed * ICE_Game_GetDelta());
		ICE_Entity_SetSpriteFrame(player, D->player.frame_down);
		D->player.dy = 1;
	}

	if (ICE_Input_OnPress(ICE_KEY_RETURN))
	{
		vect = ICE_Entity_GetPosition(player);
		const ICE_Box box = { vect.x, vect.y, 32, 32 };
		ICE_Entity * fireball = ICE_Entity_Get(NULL, ICE_Entity_Create(NULL, box));
		ICE_Entity_SetFunction(fireball, GAME_Projectile_Create, GAME_Projectile_Update, GAME_Projectile_Destroy);
	}
}

ICE_Game_Destroy(){}