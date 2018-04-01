#include <ICE.h>

ICE_PRELOAD()
{
	ICE_Font_Load("res//ttf//FiraSans-Medium.ttf");
}

ICE_CREATE()
{	
	ICE_Debug_FontSetColorBg( 100, 100, 100 );
	ICE_Debug_FontSetColorFg( 0, 0, 50 );

	unsigned int manager = 0;

	manager = ICE_LabelManager_Insert(NULL);
	ICE_Label_Insert(NULL, manager, "Hello ", ICE_Vect_New(0,0));
	ICE_Label_Insert(NULL, manager, "World !", ICE_Vect_New(30, 0));

	manager = ICE_LabelManager_Insert(NULL);
	ICE_Label_Insert(NULL, manager, "Hello ", ICE_Vect_New(0, 0));
	ICE_Label_Insert(NULL, manager, "World !", ICE_Vect_New(30, 0));

	manager = ICE_LabelManager_Insert(NULL);
	ICE_Label_Insert(NULL, manager, "Hello ", ICE_Vect_New(0, 0));
	ICE_Label_Insert(NULL, manager, "World !", ICE_Vect_New(30, 0));

	manager = ICE_LabelManager_Insert(NULL);
	ICE_Label_Insert(NULL, manager, "Hello ", ICE_Vect_New(0, 0));
	ICE_Label_Insert(NULL, manager, "World !", ICE_Vect_New(30, 0));

	manager = ICE_LabelManager_Insert(NULL);
	ICE_Label_Insert(NULL, manager, "Hello ", ICE_Vect_New(0, 0));
	ICE_Label_Insert(NULL, manager, "World !", ICE_Vect_New(30, 0));
}

ICE_UPDATE()
{
	static float amount = 0; float result;
	if (amount <= 5.0f)
		result = ICE_Interpolate(0, 255, amount / 5.0f, ICE_Interpolate_CubicIn);
	else
		result = ICE_Interpolate(0, 255, 1 - ( (amount-5) / 5.0f ), ICE_Interpolate_CubicOut);
	
	ICE_Render_Color(ICE_Color_New(result, result, result));
	ICE_Draw_RectangleFill(ICE_Camera_WorldScreen(ICE_Box_New(-10, -10, 20, 20)), ICE_Color_Red);
	
	ICE_Debug_CameraControl();
	ICE_Debug_DrawFps(0);
	ICE_Debug_FontDraw(2, " Version %s ", ICE_VERSION);
	
	amount += ICE_Game_GetDelta();
	if (amount >= 10.0f)
		amount = 0;
}

ICE_DESTROY()
{

}

int main()
{
	ICE_Debug(ICE_True);
	ICE_START( "Hello World", 500, 500 );
	ICE_Term_Wait();
	return 0;
}