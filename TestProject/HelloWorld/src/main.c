#include <ICE.h>

ICE_Game_Create("Hello World", 800, 480)
{
	ICE_Font_Load("res\\ttf\\FiraSans-Medium.ttf");
	ICE_Index man = ICE_LabelManager_Insert(NULL);
	ICE_Index nbr = ICE_Label_Insert
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
	if (ICE_Input_IsPressed(ICE_KEY_ESCAPE)) 
		ICE_Input_Quit();
}

ICE_Game_Destroy() {}