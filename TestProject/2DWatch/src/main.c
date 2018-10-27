// Engine
#include <ICE.h>

// Game
#include "weapon.h"
#include "data.h"
#include "inventory.h"

enum
{

	texture_Pic = 0,
	texture_Gui = 1,
	texture_Widow = 2,
	texture_Sprite = 3,
	texture_Logo = 4

};

ICE_Game_Create("2DWatch", 800, 480)
{
	// Texture
	ICE_Index manager = ICE_TextureManager_Insert();
	ICE_Texture_Load(manager, "res//img//pic.png");
	ICE_Texture_Load(manager, "res//img//gui.png");
	ICE_Texture_Load(manager, "res//img//widow.png");
	ICE_Texture_Load(manager, "res//img//sprite.png");
	ICE_Texture_Load(manager, "res//img//ice_logo.png");

	// Sound
	manager = ICE_SoundManager_Insert();
	ICE_Sound_Load(manager, "res//snd//explosion.wav");

	// Music
	manager = ICE_MusicManager_Insert();
	ICE_Music_Load(manager, "res//snd//music.ogg");

	// Font
	ICE_Font_Load("res//ttf//FiraSans-Medium.ttf");

	// Debug

	ICE_Debug_FontSetColorBg(100, 100, 100);
	ICE_Debug_FontSetColorFg(255, 255, 255);

	ICE_Index nb = 0;

	// Entity
	manager = ICE_EntityManager_Insert(NULL);
	nb = ICE_Entity_Insert(NULL, manager, ICE_Box_New(0, 0, 375, 250));
	ICE_Entity_SetTexture
	(
		ICE_Entity_Get(NULL, 0, 0), 
		ICE_Texture_Get(0, texture_Widow)
	);

	// Gui
	manager = ICE_GuiManager_Insert(NULL);
	nb = ICE_Gui_Insert(NULL, manager, ICE_Box_New(0, 0, ICE_Window_GetW(), 50), 0, 1);

	nb = ICE_Gui_Insert(NULL, manager, ICE_Box_New(0, 0, 50, 70), 0, texture_Logo);
	ICE_Gui_SetType(ICE_Gui_Get(NULL, 0, nb), ICE_GUITYPE_IMAGE);

	// Label
	manager = ICE_LabelManager_Insert(NULL);
	// 1
	nb = ICE_Label_Insert(NULL, manager, "It is a me", ICE_Vect_New(0, 0), 30, ICE_LABELTYPE_WORLD);
	ICE_Label_SetAngle(ICE_Label_Get(NULL, manager, nb), 30);
	// 2
	nb = ICE_Label_Insert(NULL, manager, "Russian Pawa", ICE_Vect_New(5, 5), 30, ICE_LABELTYPE_SCREEN);

	// Data
	DATA1 * data = ICE_Data_Insert_(NULL, sizeof(DATA1));
	data->inventory = ICE_State_Create(inventory_create, inventory_update, inventory_destroy);
	data->current_weapon = Game_Weapon_Init("Big Sword", 100, 1.2, 50);

	// Music
	ICE_Music_Play(ICE_Music_Get(0, 0), 16);
}

void Screen_Update()
{
	// Update background color
	static float amount = 0; float result;
	if (amount <= 5.0f)
		result = ICE_Interpolate(0, 255, amount / 5.0f, ICE_Interpolate_CubicIn);
	else
		result = ICE_Interpolate(0, 255, 1 - ((amount - 5) / 5.0f), ICE_Interpolate_CubicOut);
	ICE_Render_Color(ICE_Color_New(result / 5, result / 2.5f + 20, result / 1.5f + 20));
	amount += ICE_Game_GetDelta();
	if (amount >= 10.0f)
		amount = 0;

	ICE_Entity_AddAngle(ICE_Entity_Get(NULL, 0, 0), 50 * ICE_Game_GetDelta());
}

ICE_Game_Update()
{
	Screen_Update();

	ICE_Debug_DrawFps(5);

	// Gui Resize
	ICE_Gui * gui_main = ICE_Gui_Get(NULL, 0, 0);
	ICE_Gui_SetSize(gui_main, ICE_Vect_New(ICE_Window_GetW(), 50));

	DATA1 * data = ICE_Data_Get(NULL, 0);
	ICE_Debug_CameraControl();

	if (ICE_Input_Pressed(ICE_KEY_ESCAPE))
	{
		ICE_Sound_Play(ICE_Sound_Get(0, 0), 16);
		ICE_Substate_Start(&data->inventory);
	}
	if (ICE_Input_Pressed(ICE_KEY_SPACE))
	{
		ICE_Label_SetString(ICE_Label_Get(NULL, 0, 0), "IT IS THE END OF THE WORLD");
		ICE_Label_SetSize(ICE_Label_Get(NULL, 0, 0), 50);
		ICE_Label_SetColor(ICE_Label_Get(NULL, 0, 0), ICE_Color_Red);
		ICE_Label_SetPos(ICE_Label_Get(NULL, 0, 0), ICE_Vect_New(0, 0));
	}
	if (ICE_Input_Pressed(ICE_KEY_RETURN))
		ICE_Camera_SetPos(ICE_Vect_New(0, 0));
}

ICE_Game_Destroy()
{
	DATA1 * data = ICE_Data_Get(NULL, 0);
	ICE_State_Destroy(&data->inventory);
	Game_Weapon_Destroy(&data->current_weapon);
}