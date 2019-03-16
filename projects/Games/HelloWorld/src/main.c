#include <ICE.h>
#include "Engine/Font.h"
#include "Engine/Input.h"

#define ICE_CONFIG_TITLE "Hello World"

void ICE_Game_Create()
{
	ICE_Font_Load("res\\ttf\\FiraSans-Medium.ttf");
}

void ICE_Game_Update()
{
	if (ICE_Input_Pressed(ICE_KEY_ESCAPE)) 
		ICE_Input_Quit();
}

void ICE_Game_Destroy() {}