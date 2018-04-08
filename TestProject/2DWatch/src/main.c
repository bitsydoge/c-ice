#include <ICE.h>
#include "Core/Entity.h"

struct Game_Weapon
{
	ICE_String name;
	ICE_Float damage;
	ICE_Float speed;
	ICE_Float weight;
};

struct DATA1
{
	int			life, speed;
	ICE_State	inventory;
	struct Game_Weapon current_weapon;

}; typedef struct DATA1 DATA1;

struct Game_Weapon Game_Weapon_Init(char * name, ICE_Float damage, ICE_Float speed, ICE_Float weight)
{
	struct Game_Weapon weapon = { ICE_String_Init(name), damage, speed, weight };
	return weapon;
}

void Game_Weapon_Destroy(struct Game_Weapon *weapon)
{
	ICE_String_Delete(weapon->name);
}

// STATE ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

void inventory_create()
{
	ICE_Render_Color( ICE_Color_New( 50, 50, 50 ) );

	DATA1 * data = ICE_Data_Get(ICE_State_GetParent(NULL), 0);
	unsigned int man = ICE_LabelManager_Insert(NULL);
	unsigned int nb = ICE_Label_Insert(NULL, 0, "", ICE_Vect_New(50, 20));
	ICE_Label_SetString(ICE_Label_Get(NULL, man, nb), "Name : %s     Damage : %.1f     Speed : %.1f", data->current_weapon.name, data->current_weapon.damage, data->current_weapon.speed);
	ICE_Label_SetSize(ICE_Label_Get(NULL, man, nb), 12);
	ICE_Label_SetWrapWidth(ICE_Label_Get(NULL, man, nb), 100);
	ICE_GuiManager_Insert(NULL);
	ICE_Gui_Insert(
		NULL,
		0,
		ICE_Box_New(
			ICE_Label_GetX(ICE_Label_Get(NULL, man, nb))-5,
			ICE_Label_GetY(ICE_Label_Get(NULL, man, nb)), 
			ICE_Label_GetWidth(ICE_Label_Get(NULL, man, nb))+10, 
			ICE_Label_GetHeight(ICE_Label_Get(NULL, man, nb)+2)
		), 
		0, 
		1
	);
}

void inventory_update()
{
	ICE_Debug_DrawFps(5);

	ICE_Label_SetPos(ICE_Label_Get(NULL, 0, 0), ICE_Vect_New(ICE_Input_MouseX()+15, ICE_Input_MouseY()-10));
	DATA1 * data = ICE_Data_Get(ICE_State_GetParent(NULL), 0);
	ICE_Gui_SetSize(
		ICE_Gui_Get(NULL, 0, 0),
		ICE_Vect_New(
			ICE_Label_GetWidth(ICE_Label_Get(NULL, 0, 0))+10,
			ICE_Label_GetHeight(ICE_Label_Get(NULL, 0, 0))+2
		)
	);

	ICE_Gui_SetPos(
		ICE_Gui_Get(NULL, 0, 0),
		ICE_Vect_New(
			ICE_Label_GetX(ICE_Label_Get(NULL, 0, 0)) - 5,
			ICE_Label_GetY(ICE_Label_Get(NULL, 0, 0))
		)
	);
	ICE_Debug_CameraControl();

	if(ICE_Input_Key(ICE_KEY_ESCAPE))
		ICE_State_Pause();
}

void inventory_destroy()
{

}

// MAIN //////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

enum
{

	texture_Pic = 0,
	texture_Gui = 1,
	texture_Widow = 2,
	texture_Sprite = 3, 
	texture_Logo = 4

};

ICE_PRELOAD()
{
	unsigned int man = 0;

	// Texture
	man = ICE_TextureManager_Insert();
	ICE_Texture_Insert(man, "res//img//pic.png");
	ICE_Texture_Insert(man, "res//img//gui.png");
	ICE_Texture_Insert(man, "res//img//widow.png");
	ICE_Texture_Insert(man, "res//img//sprite.png");
	ICE_Texture_Insert(man, "res//img//ice_logo.png");

	// Sound
	man = ICE_SoundManager_Insert();
	ICE_Sound_Insert(man, "res//snd//explosion.wav");

	// Music
	man = ICE_MusicManager_Insert();
	ICE_Music_Insert(man, "res//snd//music.ogg");

	// Font
	ICE_Font_Load("res//ttf//FiraSans-Medium.ttf");
}

ICE_CREATE()
{	
	ICE_Debug_FontSetColorBg( 100, 100, 100 );
	ICE_Debug_FontSetColorFg( 255, 255, 255 );

	unsigned int manager = 0;
	unsigned int nb = 0;

	// Entity
	manager = ICE_EntityManager_Insert(NULL);
	nb = ICE_Entity_Insert(NULL, manager, ICE_Box_New(0,0,375,250));
	ICE_Entity_SetTexture(ICE_Entity_Get(NULL, 0, 0), 0, texture_Widow);

	// Gui
	manager = ICE_GuiManager_Insert(NULL);
	nb = ICE_Gui_Insert(NULL, manager, ICE_Box_New(0, 0, ICE_Window_GetW(), 50), 0, 1);
	nb = ICE_Gui_Insert(NULL, manager, ICE_Box_New(0, 0, 50, 70), 0, texture_Logo);
	ICE_Gui_SetType(ICE_Gui_Get(NULL, 0, nb), ICE_GUI_IMAGE);

	// Label
	manager = ICE_LabelManager_Insert(NULL);
		// 1
	nb = ICE_Label_Insert(NULL, manager, "It is a me", ICE_Vect_New(0,0));
	ICE_Label_SetSize(ICE_Label_Get(NULL, manager ,nb), 30);
	ICE_Label_FixToWorld(ICE_Label_Get(NULL, manager, nb), ICE_True);
	ICE_Label_SetAngle(ICE_Label_Get(NULL, manager, nb), 30);
		// 2
	nb = ICE_Label_Insert(NULL, manager, "It is a not a me !", ICE_Vect_New(5, 5));
	ICE_Label_SetSize(ICE_Label_Get(NULL, manager, nb), 30);

	// Data
	DATA1 * data = ICE_Data_Insert(NULL, sizeof(DATA1));
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

ICE_UPDATE()
{
	Screen_Update();

	ICE_Debug_DrawFps(5);

	// Gui Resize
	ICE_Gui_SetSize(ICE_Gui_Get(NULL, 0, 0), ICE_Vect_New(ICE_Window_GetW(), 50));
	
	DATA1 * data = ICE_Data_Get(NULL, 0);
	ICE_Debug_CameraControl();

	if(ICE_Input_Key(ICE_KEY_ESCAPE))
	{
		ICE_Sound_Play(ICE_Sound_Get(0, 0), 16);
		ICE_Substate_Start(&data->inventory);
	}

	if(ICE_Input_Key(ICE_KEY_SPACE))
	{
		ICE_Label_SetString(ICE_Label_Get(NULL, 0, 0), "IT IS THE END OF THE WORLD");
		ICE_Label_SetSize(ICE_Label_Get(NULL, 0, 0), 50);
		ICE_Label_SetColor(ICE_Label_Get(NULL, 0, 0), ICE_Color_Red);
		ICE_Label_SetPos(ICE_Label_Get(NULL, 0, 0), ICE_Vect_New( 0, 0 ));
	}

	if(ICE_Input_Key(ICE_KEY_RETURN))
		ICE_Camera_SetPos(ICE_Vect_New(0,0));
}

ICE_DESTROY()
{
	DATA1 * data = ICE_Data_Get(NULL, 0);
	ICE_State_Destroy(&data->inventory);
	Game_Weapon_Destroy(&data->current_weapon);
}

int main()
{
	ICE_Debug_Set(ICE_True);
	ICE_START( "Hello World", 500, 500 );
	return 0;
}