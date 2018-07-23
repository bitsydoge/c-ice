#include <ICE.h>

ICE_Main_Create()
{
	ICE_Font_Load("res//ttf//SoukouMincho.ttf");
	ICE_Index man =		ICE_LabelManager_Insert(NULL);
	ICE_Index nb  =		ICE_Label_Insert(NULL, man, L"Hello World こんにちは世界", ICE_Vect_Null, 30);
}

ICE_Main_Update()
{
	if (ICE_Input_Key(ICE_KEY_ESCAPE))
		ICE_Input_Quit();
}

ICE_Main_Destroy() {}

int main()
{
	ICE_Start("Hello World", 800, 480);
	return 0;
}