#include "Engine/Core.h"
#include "Engine/Renderer.h"
#include "Engine/Input.h"
#include "Engine/Screenshot.h"
#include "Engine/Texture.h"
#include "Engine/Entity.h"


ICE_TextureID texture_test;

void ICE_Game_Create()
{
	ICE_Render_Color(ICE_Color_New(50, 70, 150));
	texture_test = ICE_Texture_Load("res\\woodenui\\frame_c2_01.png");
	ICE_Entity_Create(NULL, ICE_Vect_New(50, 50));
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