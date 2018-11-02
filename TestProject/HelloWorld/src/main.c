#include <ICE.h>

#define ICE_CONFIG_TITLE "Hello World"

ICE_Game_Create()
{
	ICE_Font_Load("res\\ttf\\FiraSans-Medium.ttf");
	ICE_ID man = ICE_LabelManager_Create(NULL);
	ICE_ID nbr = ICE_Label_Create
	(
		NULL, 
		"Hello World",
		ICE_Vect_Zero,
		50, 
		ICE_LABELTYPE_WORLD
	);
}

ICE_Game_Update()
{
	if (ICE_Input_Pressed(ICE_KEY_ESCAPE)) 
		ICE_Input_Quit();
}

ICE_Game_Destroy() {}