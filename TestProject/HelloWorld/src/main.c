#include <ICE.h>

#define ICE_CONFIG_TITLE "Hello World"
#define ICE_CONFIG_WINDOW_W 840
#define ICE_CONFIG_WINDOW_H 480

ICE_Game_Create()
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
	if (ICE_Input_Pressed(ICE_KEY_ESCAPE)) 
		ICE_Input_Quit();
}

ICE_Game_Destroy() {}