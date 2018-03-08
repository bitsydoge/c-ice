#include <Core.h>
#include "Memory_.h"

ICE_PRELOAD() // Load assets here, if the game "restart" they are not gonna be reload
{
	ICE_FontLoad("res//ttf//FiraSans-Medium.ttf");
}

ICE_CREATE()
{
	ICE_RenderBgColor( ICE_ColorNew( 200, 200, 200 ) );

	ICE_DebugFontDrawBgColor(100, 100, 100);
	ICE_DebugFontDrawFgColor(0, 0, 50);

	ICE_LabelCreate(0, ICE_VectNew(50, 50), "Annyeong");
	ICE_LabelCreate(0, ICE_VectNew(50, 50), "Gengu");
	ICE_LabelCreate(0, ICE_VectNew(50, 50), "Gengu");
	ICE_LabelCreate(0, ICE_VectNew(50, 50), "Gengu");
	ICE_LabelCreate(0, ICE_VectNew(50, 50), "Gengu");
	ICE_LabelCreate(0, ICE_VectNew(50, 50), "Gengu");
	ICE_LabelCreate(0, ICE_VectNew(50, 50), "Gengu");
	ICE_LabelCreate(0, ICE_VectNew(50, 50), "Gengu");

	ICE_LabelManagerCreate();
	ICE_LabelCreate(1, ICE_VectNew(51, 51), "Annyeong");
	ICE_LabelCreate(1, ICE_VectNew(51, 51), "Gengu");
	ICE_LabelCreate(1, ICE_VectNew(51, 51), "Gengu");
	ICE_LabelCreate(1, ICE_VectNew(51, 51), "Gengu");
	ICE_LabelCreate(1, ICE_VectNew(51, 51), "Gengu");
	ICE_LabelCreate(1, ICE_VectNew(51, 51), "Gengu");
	ICE_LabelCreate(1, ICE_VectNew(51, 51), "Gengu");
	ICE_LabelCreate(1, ICE_VectNew(51, 51), "Gengu");

	ICE_LabelManagerCreate();
	ICE_LabelCreate(2, ICE_VectNew(52, 52), "Annyeong");
	ICE_LabelCreate(2, ICE_VectNew(52, 52), "Gengu");
	ICE_LabelCreate(2, ICE_VectNew(52, 52), "Gengu");
	ICE_LabelCreate(2, ICE_VectNew(52, 52), "Gengu");
	ICE_LabelCreate(2, ICE_VectNew(52, 52), "Gengu");
	ICE_LabelCreate(2, ICE_VectNew(52, 52), "Gengu");
	ICE_LabelCreate(2, ICE_VectNew(52, 52), "Gengu");
	ICE_LabelCreate(2, ICE_VectNew(52, 52), "Gengu");

	ICE_LabelManagerCreate();
	ICE_LabelCreate(3, ICE_VectNew(53, 53), "Annyeong");
	ICE_LabelCreate(3, ICE_VectNew(53, 53), "Gengu");
	ICE_LabelCreate(3, ICE_VectNew(53, 53), "Gengu");
	ICE_LabelCreate(3, ICE_VectNew(53, 53), "Gengu");
	ICE_LabelCreate(3, ICE_VectNew(53, 53), "Gengu");
	ICE_LabelCreate(3, ICE_VectNew(53, 53), "Gengu");
	ICE_LabelCreate(3, ICE_VectNew(53, 53), "Gengu");
	ICE_LabelCreate(3, ICE_VectNew(53, 53), "Gengu");

	ICE_LabelManagerCreate();
	ICE_LabelCreate(4, ICE_VectNew(54, 54), "Annyeong");
	ICE_LabelCreate(4, ICE_VectNew(54, 54), "Gengu");
	ICE_LabelCreate(4, ICE_VectNew(54, 54), "Gengu");
	ICE_LabelCreate(4, ICE_VectNew(54, 54), "Gengu");
	ICE_LabelCreate(4, ICE_VectNew(54, 54), "Gengu");
	ICE_LabelCreate(4, ICE_VectNew(54, 54), "Gengu");
	ICE_LabelCreate(4, ICE_VectNew(54, 54), "Gengu");
	ICE_LabelCreate(4, ICE_VectNew(54, 54), "Gengu");
	
	ICE_LabelManagerCreate();
	ICE_LabelCreate(5, ICE_VectNew(55, 55), "Annyeong");
	ICE_LabelCreate(5, ICE_VectNew(55, 55), "Gengu");
	ICE_LabelCreate(5, ICE_VectNew(55, 55), "Gengu");
	ICE_LabelCreate(5, ICE_VectNew(55, 55), "Gengu");
	ICE_LabelCreate(5, ICE_VectNew(55, 55), "Gengu");
	ICE_LabelCreate(5, ICE_VectNew(55, 55), "Gengu");
	ICE_LabelCreate(5, ICE_VectNew(55, 55), "Gengu");
	ICE_LabelCreate(5, ICE_VectNew(55, 55), "Gengu");
}

ICE_UPDATE()
{

	// Primitive
	// -------------------------
	if (ICE_Debug(ICE_BoolNone))
	{
		ICE_DrawLineAA(ICE_VectNull, ICE_VectScreen, ICE_ColorRed);
		ICE_DrawLineAA(ICE_VectNew(0, ICE_WindowGetH()), ICE_VectNew(ICE_WindowGetW(), 0), ICE_ColorRed);
		ICE_DrawRectangleFill(ICE_CameraWorldScreen(ICE_BoxNew(-10, -10, 20, 20)), ICE_ColorRed);
	}
	// Debug Drawing
	// -------------------------

		ICE_DebugMoveCamera();
		ICE_DebugShowFps();
		ICE_DebugFontDraw(2, " Version %s ", ICE_VERSION);		

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
	ICE_TermWait();
	return 0;
}