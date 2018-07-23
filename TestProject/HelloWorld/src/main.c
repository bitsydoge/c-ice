


#include <ICE.h>

void ICE_Game_Create("Hello World", 800, 480)
{
	ICE_Font_Load("res//ttf//SoukouMincho.ttf");
	const ICE_Index man	= ICE_LabelManager_Insert(NULL);
	const ICE_Index nbr	= ICE_Label_Insert(NULL, man, L"Hello World こんにちは世界", ICE_Vect_Null, 50, ICE_LabelType_World);
}

void ICE_Game_Update()
{
	if (ICE_Input_Key(ICE_KEY_ESCAPE)) ICE_Input_Quit();
}

void ICE_Game_Destroy() {}