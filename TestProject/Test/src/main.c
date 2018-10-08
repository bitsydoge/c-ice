#define ICE_DEBUG_FORCE
#include <ICE.h>
#include "Graphics/Sprite.h"

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

ICE_Game_Create("Spritesheet", 1280, 720)
{
	ICE_Debug_CallbackDraw(Debug_Update);
	
	// Font
	ICE_Font_Load("res//ttf//FiraSans-Medium.ttf");

	// Data
	DATA * data = ICE_Data_Insert(NULL, DATA);

	// Texture
	data->main_texture_manager = ICE_TextureManager_Insert();
	data->spritesheet_texture = ICE_Texture_Load(
		data->main_texture_manager, 
		"res//img//spritesheet.png"
	);

	ICE_Texture * temp = ICE_Texture_Get(data->main_texture_manager, data->spritesheet_texture);
	data->w_spritesheet = ICE_Texture_GetW(temp);
	data->h_spritesheet = ICE_Texture_GetH(temp);

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
	data->entity_test = ICE_Entity_Insert(NULL, data->main_entity_manager, ICE_Box_New(0, 0, 30, 30));
	ICE_Entity_SetSprite
	(
		ICE_Entity_Get(NULL, data->main_entity_manager, data->entity_test),
		ICE_Sprite_Get(data->main_sprite_manager, data->sprite_test)
	);


}

ICE_Game_Update()
{
	if (ICE_Input_Key(ICE_KEY_ESCAPE))
		ICE_Input_Quit();
}

ICE_Game_Destroy()
{
	
}