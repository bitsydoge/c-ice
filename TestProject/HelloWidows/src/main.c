#include <Core.h>
#include "Memory_.h"

ICE_PRELOAD() // Load assets here, if the game "restart" they are not gonna be reload
{
	ICE_Font_Load("res//ttf//FiraSans-Medium.ttf");
}

ICE_CREATE()
{
	ICE_Render_Color( ICE_Color_New( 200, 200, 200 ) );

	ICE_Debug_FontSetColorBg(100, 100, 100);
	ICE_Debug_FontSetColorFg(0, 0, 50);

	ICE_Label_Insert(0, ICE_Vect_New(50, 50), "Annyeong");
	ICE_Label_Insert(0, ICE_Vect_New(50, 50), "Gengu");
	ICE_Label_Insert(0, ICE_Vect_New(50, 50), "Gengu");
	ICE_Label_Insert(0, ICE_Vect_New(50, 50), "Gengu");
	ICE_Label_Insert(0, ICE_Vect_New(50, 50), "Gengu");
	ICE_Label_Insert(0, ICE_Vect_New(50, 50), "Gengu");
	ICE_Label_Insert(0, ICE_Vect_New(50, 50), "Gengu");
	ICE_Label_Insert(0, ICE_Vect_New(50, 50), "Gengu");

	ICE_Label_ManagerCreate();
	ICE_Label_Insert(1, ICE_Vect_New(51, 51), "Annyeong");
	ICE_Label_Insert(1, ICE_Vect_New(51, 51), "Gengu");
	ICE_Label_Insert(1, ICE_Vect_New(51, 51), "Gengu");
	ICE_Label_Insert(1, ICE_Vect_New(51, 51), "Gengu");
	ICE_Label_Insert(1, ICE_Vect_New(51, 51), "Gengu");
	ICE_Label_Insert(1, ICE_Vect_New(51, 51), "Gengu");
	ICE_Label_Insert(1, ICE_Vect_New(51, 51), "Gengu");
	ICE_Label_Insert(1, ICE_Vect_New(51, 51), "Gengu");

	ICE_Label_ManagerCreate();
	ICE_Label_Insert(2, ICE_Vect_New(52, 52), "Annyeong");
	ICE_Label_Insert(2, ICE_Vect_New(52, 52), "Gengu");
	ICE_Label_Insert(2, ICE_Vect_New(52, 52), "Gengu");
	ICE_Label_Insert(2, ICE_Vect_New(52, 52), "Gengu");
	ICE_Label_Insert(2, ICE_Vect_New(52, 52), "Gengu");
	ICE_Label_Insert(2, ICE_Vect_New(52, 52), "Gengu");
	ICE_Label_Insert(2, ICE_Vect_New(52, 52), "Gengu");
	ICE_Label_Insert(2, ICE_Vect_New(52, 52), "Gengu");

	ICE_Label_ManagerCreate();
	ICE_Label_Insert(3, ICE_Vect_New(53, 53), "Annyeong");
	ICE_Label_Insert(3, ICE_Vect_New(53, 53), "Gengu");
	ICE_Label_Insert(3, ICE_Vect_New(53, 53), "Gengu");
	ICE_Label_Insert(3, ICE_Vect_New(53, 53), "Gengu");
	ICE_Label_Insert(3, ICE_Vect_New(53, 53), "Gengu");
	ICE_Label_Insert(3, ICE_Vect_New(53, 53), "Gengu");
	ICE_Label_Insert(3, ICE_Vect_New(53, 53), "Gengu");
	ICE_Label_Insert(3, ICE_Vect_New(53, 53), "Gengu");

	ICE_Label_ManagerCreate();
	ICE_Label_Insert(4, ICE_Vect_New(54, 54), "Annyeong");
	ICE_Label_Insert(4, ICE_Vect_New(54, 54), "Gengu");
	ICE_Label_Insert(4, ICE_Vect_New(54, 54), "Gengu");
	ICE_Label_Insert(4, ICE_Vect_New(54, 54), "Gengu");
	ICE_Label_Insert(4, ICE_Vect_New(54, 54), "Gengu");
	ICE_Label_Insert(4, ICE_Vect_New(54, 54), "Gengu");
	ICE_Label_Insert(4, ICE_Vect_New(54, 54), "Gengu");
	ICE_Label_Insert(4, ICE_Vect_New(54, 54), "Gengu");
	
	ICE_Label_ManagerCreate();
	ICE_Label_Insert(5, ICE_Vect_New(55, 55), "Annyeong");
	ICE_Label_Insert(5, ICE_Vect_New(55, 55), "Gengu");
	ICE_Label_Insert(5, ICE_Vect_New(55, 55), "Gengu");
	ICE_Label_Insert(5, ICE_Vect_New(55, 55), "Gengu");
	ICE_Label_Insert(5, ICE_Vect_New(55, 55), "Gengu");
	ICE_Label_Insert(5, ICE_Vect_New(55, 55), "Gengu");
	ICE_Label_Insert(5, ICE_Vect_New(55, 55), "Gengu");
	ICE_Label_Insert(5, ICE_Vect_New(55, 55), "Gengu");
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