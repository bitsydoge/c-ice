// Engine
#include <ICE.h>

// Game
#include "weapon.h"
#include "data.h"
#include "inventory.h"
#include "Engine/Texture.h"
#include "Engine/Sound.h"
#include "Engine/Music.h"
#include "Engine/Font.h"
#include "Engine/Debug.h"
#include "Engine/Entity.h"
#include "Engine/Window.h"
#include "Engine/Interpolate.h"
#include "Engine/Renderer.h"
#include "Engine/Game.h"
#include "Engine/Data.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Engine/Core.h"

enum
{
	texture_Pic = 0,
	texture_Gui = 1,
	texture_Widow = 2,
	texture_Sprite = 3,
	texture_Logo = 4
};

#define ICE_CONFIG_TITLE "2DWatch"
#define ICE_CONFIG_WINDOW_W 800
#define ICE_CONFIG_WINDOW_H 480

void ICE_Game_Create()
{
	// Texture
	ICE_Texture_Load("res//img//pic.png");
	ICE_Texture_Load("res//img//gui.png");
	ICE_Texture_Load("res//img//widow.png");
	ICE_Texture_Load("res//img//sprite.png");
	ICE_Texture_Load("res//img//ice_logo.png");

	// Sound
	ICE_Sound_Load("res//snd//explosion.wav");

	// Music
	ICE_Music_Load("res//snd//music.ogg");

	// FNT
	ICE_Font_Load("res//ttf//FiraSans-Medium.ttf");

	// Debug

	ICE_Debug_FontSetColorBg(100, 100, 100);
	ICE_Debug_FontSetColorFg(255, 255, 255);

	// Entity

	// Entity
	ICE_ID entity_id = ICE_Entity_Create(ICE_Vect_New(0, 0));

	ICE_Graphics2D * graphics2d = ICE_Entity_GetGraphics2D(entity_id);
	ICE_Graphics2D_SetType(graphics2d, ICE_GRAPHICS2D_TYPES_TEXTURE);
	ICE_Graphics2D_SetData_Texture(graphics2d,2);
	ICE_Graphics2D_SetScale(graphics2d, ICE_Vect_New(0.5,0.5));

	//// Gui
	//nb = ICE_Gui_Create(ICE_State_Current, ICE_Box_New(0, 0, ICE_Window_GetW(), 50), ICE_GUITYPE_9PATCH);
	//nb = ICE_Gui_Create(ICE_State_Current, ICE_Box_New(0, 0, 50, 70), ICE_GUITYPE_9PATCH);
	//ICE_Gui_SetType(ICE_Gui_Get(ICE_State_Current, nb), ICE_GUITYPE_IMAGE);

	//// 1
	//nb = ICE_Label_Create(ICE_State_Current, "It is a me", ICE_Vect_New(0, 0), 30, ICE_LABELTYPE_WORLD);
	//ICE_Label_SetAngle(ICE_Label_Get(ICE_State_Current, nb), 30);
	//// 2
	//nb = ICE_Label_Create(ICE_State_Current, "Russian Pawa", ICE_Vect_New(5, 5), 30, ICE_LABELTYPE_SCREEN);

	// Data
	ICE_DataID data_id = ICE_Data_Add(sizeof(DATA1));
	DATA1 * data = ICE_Data_Get(data_id);

	data->current_weapon = Game_Weapon_Init("Big Sword", 100, 1.2, 50);

	// Music
	ICE_Music_Play(0, 16);
}

void Screen_Update()
{
	// Update background color
	static float amount = 0; float result;
	if (amount <= 5.0f)
		result = ICE_Interpolate(0, 255, amount / 5.0f, ICE_Interpolate_CubicIn);
	else
		result = ICE_Interpolate(0, 255, 1.0f - ((amount - 5) / 5.0f), ICE_Interpolate_CubicOut);
	ICE_Render_Color(ICE_Color_New(result / 5, result / 2.5f + 20, result / 1.5f + 20));
	amount += ICE_Game_GetDelta();
	if (amount >= 10.0f)
		amount = 0;

	ICE_Control2D* control2d = ICE_Entity_GetControl2D(0);
	ICE_Control2D_AddRotation(control2d, 50 * ICE_Game_GetDelta());
}

void ICE_Game_Update()
{
	Screen_Update();

	ICE_Debug_DrawFps(5);

	//// Gui Resize
	//ICE_Gui * gui_main = ICE_Gui_Get(NULL, 0);
	//ICE_Gui_SetSize(gui_main, ICE_Vect_New(ICE_Window_GetW(), 50));

	DATA1 * data = ICE_Data_Get(0);
	ICE_Debug_CameraControl();

	if (ICE_Input_Pressed(ICE_KEY_ESCAPE))
	{
		ICE_Sound_Play(0, 16);
		//ICE_Substate_Start(&data->inventory);
	}
	if (ICE_Input_Pressed(ICE_KEY_SPACE))
	{
		/*ICE_Label_SetString(ICE_Label_Get(NULL, 0), "IT IS THE END OF THE WORLD");
		ICE_Label_SetSize(ICE_Label_Get(NULL, 0), 50);
		ICE_Label_SetColor(ICE_Label_Get(NULL, 0), ICE_Color_Red);
		ICE_Label_SetPos(ICE_Label_Get(NULL, 0), ICE_Vect_New(0, 0));*/
	}
	if (ICE_Input_Pressed(ICE_KEY_RETURN))
		ICE_Camera_SetPosition(ICE_Vect_New(0, 0));
}

void ICE_Game_Destroy()
{
	DATA1 * data = ICE_Data_Get(0);
	//ICE_State_Destroy(&data->inventory);
	Game_Weapon_Destroy(&data->current_weapon);
}