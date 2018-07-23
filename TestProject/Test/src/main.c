#include <ICE.h>

struct DATA
{
	ICE_Index main_texture_manager;
	ICE_Index spritesheet_texture;

	int w_spritesheet;
	int h_spritesheet;

	ICE_Index main_entity_manager;
	ICE_Index entity_test;
};
typedef struct DATA DATA;

void ICE_Debug_Update()
{
	ICE_Debug_FontDraw(1, "%s :: Sprite Implement", ICE_VERSION);
	ICE_Debug_CameraControl();
	ICE_Debug_DrawFps(2);

	DATA * data = ICE_Data_Get(NULL, 0);
	const ICE_Box converter = ICE_Camera_WorldScreen(ICE_Box_New(-(data->w_spritesheet/2), -(data->h_spritesheet/2), data->w_spritesheet, data->h_spritesheet));
	ICE_Draw_Rectangle(converter, ICE_Color_Red);
}

ICE_Main_Create()
{
	// Debug

	ICE_Debug_CallbackDraw(ICE_Debug_Update);

	// Font

	ICE_Font_Load("res//ttf//FiraSans-Medium.ttf");

	// Data

	DATA * data = ICE_Data_Insert(NULL, sizeof(DATA));

	// Texture

	data->main_texture_manager = ICE_TextureManager_Insert();
	data->spritesheet_texture = ICE_Texture_Load(data->main_texture_manager, "res//img//spritesheet.png");

	data->w_spritesheet = ICE_Texture_GetW(ICE_Texture_Get(data->main_texture_manager, data->spritesheet_texture));
	data->h_spritesheet = ICE_Texture_GetH(ICE_Texture_Get(data->main_texture_manager, data->spritesheet_texture));

	// Entity

	data->main_entity_manager = ICE_EntityManager_Insert(NULL);
	data->entity_test = ICE_Entity_Insert(NULL, data->main_entity_manager, ICE_Box_New(0, 0, data->w_spritesheet, data->h_spritesheet));

	ICE_Entity_SetTexture(ICE_Entity_Get(NULL, data->main_entity_manager, data->entity_test), data->main_texture_manager, data->spritesheet_texture);
}

ICE_Main_Update()
{
	if (ICE_Input_Key(ICE_KEY_ESCAPE))
		ICE_Input_Quit();
}

ICE_Main_Destroy() {}

int main(int argc, char* argv[])
{
	ICE_Start("Spritesheet", 1280, 720);
	return 0;
}