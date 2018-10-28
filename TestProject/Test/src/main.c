#include <ICE.h>

#define ICE_CONFIG_EDITORNAME "coldragon"
#define ICE_CONFIG_PRODUCTNAME "test"
#define ICE_CONFIG_TITLE "Test Project"
#define ICE_CONFIG_WINDOW_W 1280
#define ICE_CONFIG_WINDOW_H 720
#define ICE_CONFIG_FULLSCREEN 0
#define ICE_CONFIG_RESIZABLE 1

typedef struct
{
	ICE_Index main_texture_manager;
	ICE_Index spritesheet_texture;

	int w_spritesheet;
	int h_spritesheet;

	ICE_Index main_entity_manager;
	ICE_Index entity_test;

	ICE_Index main_sprite_manager;
	ICE_Index sprite_test;

} DATA;

void Debug_Update()
{
	ICE_Debug_FontDraw(1, "%s :: Sprite Implement", ICE_VERSION);
	ICE_Debug_DrawFps(2);

	DATA * data = ICE_Data_Get(NULL, 0);
	ICE_Box converter = ICE_Camera_WorldScreen(ICE_Box_New(-(data->w_spritesheet / 2), -(data->h_spritesheet / 2), data->w_spritesheet, data->h_spritesheet));
	ICE_Draw_Rectangle(converter, ICE_Color_Red);

	converter = ICE_Camera_WorldScreen(ICE_Box_New(-(data->w_spritesheet / 2) - 1, -(data->h_spritesheet / 2) - 1, data->w_spritesheet + 2, data->h_spritesheet + 2));
	ICE_Draw_Rectangle(converter, ICE_Color_Red);

	ICE_Debug_DrawCoordinate();
	ICE_Debug_CameraControl();
}

ICE_Game_Create()
{
	ICE_Debug_CallbackDraw(Debug_Update);

	// Font
	ICE_Font_Load("res//ttf//FiraSans-Medium.ttf");

	// Data
	DATA * data = ICE_Data_Insert(NULL, DATA);

	// Texture
	data->main_texture_manager = ICE_TextureManager_Insert();
	data->spritesheet_texture = ICE_Texture_Load (
		data->main_texture_manager,
		"res//img//spritesheet.png"
	);

	// Sprite
	data->main_sprite_manager = ICE_SpriteManager_Insert();
	data->sprite_test = ICE_Sprite_Insert
	(
		data->main_sprite_manager,
		ICE_Texture_Get(data->main_texture_manager, data->spritesheet_texture),
		ICE_Vect_New(64, 64)
	);

	// Entity
	data->main_entity_manager = ICE_EntityManager_Insert(NULL);
	data->entity_test = ICE_Entity_Insert(NULL, data->main_entity_manager, ICE_Box_New(0, 0, 64, 64));
	ICE_Entity_SetSprite
	(
		ICE_Entity_Get(NULL, data->main_entity_manager, data->entity_test),
		ICE_Sprite_Get(data->main_sprite_manager, data->sprite_test)
	);

	data->w_spritesheet = 64;
	data->h_spritesheet = 64;
}

ICE_Game_Update()
{
	static ICE_Float last = 0;
	static ICE_Float now = 0;
	now = ICE_Time_GetS();

	if (ICE_Input_OnPress(ICE_KEY_LEFTCLICK))
		ICE_Log(ICE_LOG_SUCCES, "You pressed : lectclick at position <%d,%d>", ICE_Input_MouseX_World(), ICE_Input_MouseY_World());
	if (ICE_Input_Pressed(ICE_KEY_LEFTCLICK))
		ICE_Log(ICE_LOG_SUCCES, "You are pressing : lectclick at position <%d,%d>", ICE_Input_MouseX_World(), ICE_Input_MouseY_World());
	if (ICE_Input_OnRelease(ICE_KEY_LEFTCLICK))
		ICE_Log(ICE_LOG_SUCCES, "You released : lectclick at position <%d,%d>", ICE_Input_MouseX_World(), ICE_Input_MouseY_World());
	if (ICE_Input_OnPress(ICE_KEY_RIGHTCLICK))
		ICE_Log(ICE_LOG_SUCCES, "You pressed : rightclick at position <%d,%d>", ICE_Input_MouseX(), ICE_Input_MouseY());
	if (ICE_Input_Pressed(ICE_KEY_RIGHTCLICK))
		ICE_Log(ICE_LOG_SUCCES, "You are pressing : rightclick at position <%d,%d>", ICE_Input_MouseX(), ICE_Input_MouseY());
	if (ICE_Input_OnRelease(ICE_KEY_RIGHTCLICK))
		ICE_Log(ICE_LOG_SUCCES, "You released : rightclick at position <%d,%d>", ICE_Input_MouseX(), ICE_Input_MouseY());

	DATA * data = ICE_Data_Get(NULL, 0);
	ICE_Entity * entity = ICE_Entity_Get(NULL, data->entity_test, data->entity_test);
	ICE_Sprite * sprite = ICE_Entity_GetSprite(entity);

	static int frame_number = 1;
	if (last + 0.23f < now)
	{
		ICE_Entity_SetSpriteFrame
		(
			ICE_Entity_Get(NULL, data->main_entity_manager, data->entity_test),
			frame_number
		);
		frame_number++;
		if (frame_number > ICE_Sprite_GetFrameQuantity(ICE_Entity_GetSprite(ICE_Entity_Get(NULL, data->entity_test, data->entity_test))))
			frame_number = 1;
		last = ICE_Time_GetS();
	}
}

ICE_Game_Destroy()
{
	
}
