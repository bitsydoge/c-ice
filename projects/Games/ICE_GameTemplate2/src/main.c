#include "Engine/Core.h"
#include "Engine/Entity.h"
#include "Engine/Debug.h"
#include "Engine/Renderer.h"
#include "Engine/Input.h"
#include "Engine/Screenshot.h"
#include "Engine/Texture.h"
#include "Framework/Random.h"
#include <stdio.h>

#define ICE_CONFIG_WINDOW_H 720
#define ICE_CONFIG_WINDOW_W 1280
#define ICE_CONFIG_FULLSCREEN 0

void Debug_Draw()
{
	ICE_Debug_CameraDraw();
	ICE_Debug_DrawFps(2);
	ICE_Debug_DrawCoordinate();
	ICE_Debug_CameraControl();
}

ICE_EntityID entity_test = 0;
ICE_TextureID texture = 0;
ICE_TextureID texture2 = 0;

void ICE_Game_Create()
{
	SDL_Cursor * cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_IBEAM);//init_system_cursor(arrow);
	SDL_SetCursor(cursor);

	ICE_Render_Color(ICE_Color_New(50, 70, 150));
	ICE_Debug_CallbackDraw(Debug_Draw);

	texture = ICE_Texture_Load("res\\entity_test.png");
	texture2 = ICE_Texture_Load("res\\space.jpg");

	ICE_Graphics2D * graphics2d;
	ICE_Control2D * control2d;

	entity_test = ICE_Entity_Create(ICE_Vect_New(0, 0));
	graphics2d = ICE_Entity_GetGraphics2D(entity_test);
	control2d = ICE_Entity_GetControl2D(entity_test);

	ICE_Graphics2D_SetType(graphics2d, ICE_GRAPHICS2D_TYPES_TEXTURE);
	ICE_Graphics2D_SetData_Texture(graphics2d, texture2);
	ICE_Graphics2D_SetData_Texture(graphics2d, texture2);
	ICE_Control2D_SetRotation(control2d, ICE_Random_Float() * 360.00);

	entity_test = ICE_Entity_Create(ICE_Vect_New(0, 0));
	graphics2d = ICE_Entity_GetGraphics2D(entity_test);
	ICE_Graphics2D_SetType(graphics2d, ICE_GRAPHICS2D_TYPES_TEXTURE);
	ICE_Graphics2D_SetData_Texture(graphics2d, texture);

	entity_test = ICE_Entity_Create(ICE_Vect_New(100, 100));
	graphics2d = ICE_Entity_GetGraphics2D(entity_test);
	ICE_Graphics2D_SetType(graphics2d, ICE_GRAPHICS2D_TYPES_TEXTURE);
	ICE_Graphics2D_SetData_Texture(graphics2d, texture);

	entity_test = ICE_Entity_Create(ICE_Vect_New(-100, -100));
	graphics2d = ICE_Entity_GetGraphics2D(entity_test);
	ICE_Graphics2D_SetType(graphics2d, ICE_GRAPHICS2D_TYPES_TEXTURE);
	ICE_Graphics2D_SetData_Texture(graphics2d, texture);
	ICE_Graphics2D_SetScale(graphics2d, ICE_Vect_New(1.5, 0.8));

	entity_test = ICE_Entity_Create(ICE_Vect_New(100, -100));
	graphics2d = ICE_Entity_GetGraphics2D(entity_test);
	ICE_Graphics2D_SetType(graphics2d, ICE_GRAPHICS2D_TYPES_TEXTURE);
	ICE_Graphics2D_SetData_Texture(graphics2d, texture);

	entity_test = ICE_Entity_Create(ICE_Vect_New(-100, 100));
	graphics2d = ICE_Entity_GetGraphics2D(entity_test);
	ICE_Graphics2D_SetType(graphics2d, ICE_GRAPHICS2D_TYPES_TEXTURE);
	ICE_Graphics2D_SetData_Texture(graphics2d, texture);
}

void ICE_Game_Update()
{
	if (ICE_Input_OnPress(ICE_KEY_K))
	{
		ICE_Screenshot(NULL, "png");
	}
}

void ICE_Game_Destroy()
{
	
}