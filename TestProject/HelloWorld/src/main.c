#include <ICE.h>

#define ICE_CONFIG_TITLE "Hello World"

ICE_Game_Create()
{
	ICE_Font_Load("res\\ttf\\FiraSans-Medium.ttf");
	ICE_Id texture = ICE_Texture_Load("res\\img\\pic.png");
	ICE_Id man = ICE_LabelManager_Insert(NULL);
	ICE_Id nbr = ICE_Label_Insert
	(
		NULL, 
		man, 
		"Hello World", 
		ICE_Vect_Null, 
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