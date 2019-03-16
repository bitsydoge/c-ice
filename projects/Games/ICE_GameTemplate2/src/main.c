#include "Engine/Core.h"
#include "Engine/Control2D.h"
#include "Engine/Entity.h"
#include "Engine/Debug.h"
#include "Engine/Renderer.h"
#include "Engine/Input.h"
#include "Engine/Screenshot.h"

#define ICE_CONFIG_WINDOW_H 720
#define ICE_CONFIG_WINDOW_W 1280
#define ICE_CONFIG_RESIZABLE 1

void Debug_Draw()
{
	ICE_Debug_DrawFps(2);
}

ICE_EntityID entity = 0;

void ICE_Game_Create()
{
	ICE_Render_Color(ICE_Color_New(50, 70, 150));
	ICE_Debug_CallbackDraw(Debug_Draw);

	entity = ICE_Entity_Create(ICE_Vect_New(0, 0));

	ICE_Control2D * control2d = ICE_Entity_GetControl2D(entity);
	ICE_Control2D_PositionShift(control2d, 50, 25);

	ICE_Graphics2D * graphics2d = ICE_Entity_GetGraphics2D(entity);
	ICE_Graphics2D_SetType(graphics2d, ICE_GRAPHICS2D_TYPES_TEXTURE);
	ICE_Graphics2D_SetScale(graphics2d, ICE_Vect_New(2, 1));

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