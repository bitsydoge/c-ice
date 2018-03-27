#include <Core.h>
#include "Memory_.h"

extern ICE_Game game;

ICE_PRELOAD() // Load assets here, if the game "restart" they are not gonna be reload
{
	ICE_Font_Load("res//ttf//FiraSans-Medium.ttf");
}

ICE_CREATE()
{
	ICE_Render_Color( ICE_Color_New( 200, 200, 200 ) );
	
	ICE_Debug_FontSetColorBg(100, 100, 100);
	ICE_Debug_FontSetColorFg(0, 0, 50);

	// Keep data as you want
	ICE_Label test = ICE_Label_Create("Test", ICE_Vect_New(20, 20));
	ICE_Label_Select(&test);

	ICE_LabelManager_Create(); // Create manager if you prefer
	ICE_Label_Insert(0, "Annyeong", ICE_Vect_New(50, 50));
	ICE_Label_Insert(0, "Gengu", ICE_Vect_New(50, 50));
	ICE_Label_Insert(0, "Gengu", ICE_Vect_New(50, 50));
	ICE_Label_Insert(0, "Gengu", ICE_Vect_New(50, 50));
	ICE_Label_Insert(0, "Gengu", ICE_Vect_New(50, 50));
	ICE_Label_Select(0, 3);

	ICE_LabelManager_Create(); // Create as much as you want
	ICE_Label_Insert(1, "Annyeong", ICE_Vect_New(50, 50));
	ICE_Label_Insert(1, "Gengu", ICE_Vect_New(50, 50));
	ICE_Label_Select(1, 1);

	ICE_Label_Destroy(&test);
}

ICE_UPDATE()
{

	// Primitive
	// -------------------------
	if (ICE_Debug(ICE_BoolNone))
	{
		ICE_Draw_LineAA(ICE_Vect_Null, ICE_Vect_Screen, ICE_Color_Red);
		ICE_Draw_LineAA(ICE_Vect_New(0, ICE_Window_GetH()), ICE_Vect_New(ICE_Window_GetW(), 0), ICE_Color_Red);
		ICE_Draw_RectangleFill(ICE_Camera_WorldScreen(ICE_Box_New(-10, -10, 20, 20)), ICE_Color_Red);
	}
	// Debug Drawing
	// -------------------------

		ICE_Debug_CameraControl();
		ICE_Debug_DrawFps();
		ICE_Debug_FontDraw(2, " Version %s ", ICE_VERSION);		

	// -------------------------

}

ICE_DESTROY()
{

}

int main()
{
	ICE_Debug(ICE_True);
	ICE_START( "Hello World", 800, 480 );
	
	ICE_ThingToFree();
	ICE_Term_Wait();
	return 0;
}