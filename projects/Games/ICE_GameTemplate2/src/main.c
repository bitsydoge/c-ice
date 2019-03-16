#include "Engine/Core.h"
#include "Engine/Renderer.h"
#include "Engine/Input.h"
#include "Engine/Screenshot.h"
#include "Engine/Texture.h"
#include "Engine/Entity.h"
#include "Engine/Debug.h"


void Debug_Draw()
{
	ICE_Debug_DrawFps(2);
}

void ICE_Game_Create()
{
	ICE_Render_Color(ICE_Color_New(50, 70, 150));
	ICE_Debug_CallbackDraw(Debug_Draw);
}

void ICE_Game_Update()
{
	if (ICE_Input_OnPress(ICE_KEY_K))
	{
		ICE_Screenshot(NULL, "jpg");
	}
}

void ICE_Game_Destroy()
{
	
}