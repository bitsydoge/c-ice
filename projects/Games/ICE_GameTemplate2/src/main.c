#include "Engine/Core.h"
#include "Engine/Control2D.h"
#include "Engine/Entity.h"
#include "Engine/Debug.h"
#include "Engine/Renderer.h"
#include "Engine/Input.h"
#include "Engine/Screenshot.h"
#include "Engine/Texture.h"
#include "Framework/Log.h"
#include "Engine/Camera.h"
#include "Engine/Game.h"

#define ICE_CONFIG_WINDOW_H 720
#define ICE_CONFIG_WINDOW_W 1280
#define ICE_CONFIG_RESIZABLE 1

void Debug_Draw()
{
	ICE_Debug_DrawFps(2);
	ICE_Debug_DrawCoordinate();

}

ICE_EntityID entity = 0;
ICE_TextureID texture = 0;

void ICE_Game_Create()
{
	ICE_Render_Color(ICE_Color_New(50, 70, 150));
	ICE_Debug_CallbackDraw(Debug_Draw);

	texture = ICE_Texture_Load("res\\entity.png");

	ICE_Graphics2D* graphics2d;
	entity = ICE_Entity_Create(ICE_Vect_New(0, 0));
	graphics2d = ICE_Entity_GetGraphics2D(entity);
	ICE_Graphics2D_SetType(graphics2d, ICE_GRAPHICS2D_TYPES_TEXTURE);
	ICE_Graphics2D_SetData_Texture(graphics2d, texture);

	entity = ICE_Entity_Create(ICE_Vect_New(100, 100));
	graphics2d = ICE_Entity_GetGraphics2D(entity);
	ICE_Graphics2D_SetType(graphics2d, ICE_GRAPHICS2D_TYPES_TEXTURE);
	ICE_Graphics2D_SetData_Texture(graphics2d, texture);

	entity = ICE_Entity_Create(ICE_Vect_New(-100, -100));
	graphics2d = ICE_Entity_GetGraphics2D(entity);
	ICE_Graphics2D_SetType(graphics2d, ICE_GRAPHICS2D_TYPES_TEXTURE);
	ICE_Graphics2D_SetData_Texture(graphics2d, texture);
	ICE_Graphics2D_SetScale(graphics2d, ICE_Vect_New(1.5, 0.8));

	entity = ICE_Entity_Create(ICE_Vect_New(100, -100));
	graphics2d = ICE_Entity_GetGraphics2D(entity);
	ICE_Graphics2D_SetType(graphics2d, ICE_GRAPHICS2D_TYPES_TEXTURE);
	ICE_Graphics2D_SetData_Texture(graphics2d, texture);

	entity = ICE_Entity_Create(ICE_Vect_New(-100, 100));
	graphics2d = ICE_Entity_GetGraphics2D(entity);
	ICE_Graphics2D_SetType(graphics2d, ICE_GRAPHICS2D_TYPES_TEXTURE);
	ICE_Graphics2D_SetData_Texture(graphics2d, texture);
}

void ICE_Game_Update()
{
	if (ICE_Input_OnPress(ICE_KEY_K))
	{
		ICE_Screenshot(NULL, "png");
	}

	if(ICE_Input_Pressed(ICE_KEY_KP_PLUS))
	{
		ICE_Vect temp = ICE_Vect_Scale(ICE_Vect_Scale(ICE_Camera_GetScale(), 1), ICE_Game_GetDelta());
		ICE_Camera_AddScale(temp);
	}
	if (ICE_Input_Pressed(ICE_KEY_KP_MINUS))
	{
		ICE_Vect temp = ICE_Vect_Scale(ICE_Vect_Scale(ICE_Camera_GetScale(), -1), ICE_Game_GetDelta());
		ICE_Camera_AddScale(temp);
	}

	if(ICE_Input_Pressed(ICE_KEY_KP_8))
	{
		ICE_Camera_AddPositionY(-1 + ICE_Game_GetDelta());
	}
	if (ICE_Input_Pressed(ICE_KEY_KP_2))
	{
		ICE_Camera_AddPositionY(1 + ICE_Game_GetDelta());
	}
	if (ICE_Input_Pressed(ICE_KEY_KP_4))
	{
		ICE_Camera_AddPositionX(-1 + ICE_Game_GetDelta());
	}
	if (ICE_Input_Pressed(ICE_KEY_KP_6))
	{
		ICE_Camera_AddPositionX(1 + ICE_Game_GetDelta());
	}
}

void ICE_Game_Destroy()
{
	
}