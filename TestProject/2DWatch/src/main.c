#include <ICE.h>

ICE_PRELOAD()
{
	ICE_Font_Load("res//ttf//FiraSans-Medium.ttf");
}

ICE_CREATE()
{
	ICE_Render_Color(ICE_Color_New(100, 200, 80));

	size_t man = ICE_LabelManager_Insert(NULL);
	size_t nb = ICE_Label_Insert(NULL, man, "Hello World", ICE_Vect_New(0, 0));

	ICE_Label_SetSize(ICE_Label_Get(NULL, man, nb), 30);
	ICE_Label_FixToWorld(ICE_Label_Get(NULL, man, nb), ICE_True);
}

ICE_UPDATE()
{
	if (ICE_Input_Key(ICE_KEY_ESCAPE))
		ICE_Input_Quit();
}

ICE_DESTROY() {}

int main()
{
	ICE_START("Hello World", 800, 480);
	return 0;
}