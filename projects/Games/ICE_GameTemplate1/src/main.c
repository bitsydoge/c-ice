#include <ICE.h>
#include "config.h"
#include "button.h"

ICE_TextureID texture_frame_main;
ICE_GuiID gui_frame_main;

ICE_TextureID texture_button;
ICE_TextureID texture_button_hover;
ICE_TextureID texture_button_hover_pressed;

ICE_TextureID texture_skull;
ICE_GuiID gui_button_skull;

struct GG_Button button1;
struct GG_Button button2;

///////////// SKULL ENTITY ////////////////

struct GG_Skull_Data
{
	ICE_Float timer;
	ICE_Float speed_rotation;
	ICE_Bool direction_rotation;
};

void GG_Skull_Create(ICE_Entity * this_)
{
	struct GG_Skull_Data* D = ICE_Entity_DataAdd(this_, struct GG_Skull_Data);
	D->timer = 3.0f;
	ICE_Entity_SetAngle(this_, ICE_Random_Int(0, 360));
	D->speed_rotation = ICE_Random_Int(5, 15);
	D->direction_rotation = ICE_Random_Int(0, 1);
}

void GG_Skull_Update(ICE_Entity * this_)
{
	struct GG_Skull_Data* D = ICE_Entity_DataGet(this_, 0);
	D->timer -= ICE_Game_GetDelta();
	ICE_Entity_AddAngle(this_, D->direction_rotation ? ICE_Game_GetDelta() * D->speed_rotation : -(ICE_Game_GetDelta() * D->speed_rotation));
	if (D->timer <= 0.0f)
		ICE_Entity_Destroy(this_);
}

void GG_Button1_Action(struct GG_Button* _this)
{
	ICE_EntityID entity_temp = ICE_Entity_Create(ICE_State_Current, ICE_Box_New(ICE_Random_Int(-ICE_Window_GetW() / 2, ICE_Window_GetW() / 2), ICE_Random_Int(-ICE_Window_GetH() / 2, ICE_Window_GetH() / 2), 64, 64));
	ICE_Entity_SetTexture(ICE_Entity_Get(ICE_State_Current, entity_temp), texture_skull); // Set Sprite to Entity
	ICE_Entity_SetFunction(ICE_Entity_Get(ICE_State_Current, entity_temp), GG_Skull_Create, GG_Skull_Update, NULL);
}

void GG_Button2_Action(struct GG_Button* _this)
{
	ICE_Log_Info("Button 2");
}

void GG_Debug_Draw()
{
	ICE_Debug_DrawFps(4);
	ICE_Debug_CameraControl();
}

void ICE_Game_Create()
{
	ICE_Render_Color(ICE_Color_New(0, 64, 128));
	texture_frame_main = ICE_Texture_Load("res\\woodenui\\frame_c2_01.png");
	gui_frame_main = ICE_Gui_Create(ICE_State_Current, ICE_Box_New(0,ICE_Window_GetH()-128, ICE_Window_GetW(), 128), ICE_GUITYPE_9PATCH);
	ICE_Gui_SetTexture(ICE_Gui_Get(ICE_State_Current, gui_frame_main), texture_frame_main);
	
	texture_button = ICE_Texture_Load("res\\woodenui\\plank_15.png");
	texture_button_hover = ICE_Texture_Load("res\\woodenui\\plank_15_hover.png");
	texture_button_hover_pressed = ICE_Texture_Load("res\\woodenui\\plank_15_hover_pressed.png");
	
	texture_skull = ICE_Texture_Load("res\\woodenui\\skull_01.png");
	gui_button_skull = ICE_Gui_Create(ICE_State_Current, ICE_Box_New(32, ICE_Window_GetH()-90, 50, 55), ICE_GUITYPE_IMAGE);
	ICE_Gui_SetTexture(ICE_Gui_Get(ICE_State_Current, gui_button_skull), texture_skull);

	ICE_Font_Load("res\\code2000.ttf");

	button1 = GG_Button_Create
	(
		texture_button, 
		texture_button_hover, 
		texture_button_hover_pressed, 
		ICE_Box_New(0,0, 342, 135), 
		"Skull", 
		70,
		GG_Button1_Action
	);

	button2 = GG_Button_Create
	(
		texture_button,
		texture_button_hover,
		texture_button_hover_pressed,
		ICE_Box_New(500, 190, 342, 135),
		"Not Skull",
		70,
		GG_Button2_Action
	);

	ICE_Debug_CallbackDraw(GG_Debug_Draw);
}

void ICE_Game_Update()
{
	if (ICE_Input_Pressed(ICE_KEY_ESCAPE)) 
		ICE_Input_Quit();

	GG_Button_Update(&button1);
	GG_Button_Update(&button2);
}

void ICE_Game_Destroy()
{
	
}