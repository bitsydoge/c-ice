#include "Engine/Core.h"
#include "Engine/Renderer.h"
#include "Engine/Input.h"
#include "Engine/Screenshot.h"

void ICE_Game_Create()
{
	ICE_Render_Color(ICE_Color_New(50, 70, 150));
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