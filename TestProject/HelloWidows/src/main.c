#include <Core.h>
ICE_PRELOAD() // Load assets here, if the game "restart" they are not gonna be reload
{
	ICE_Debug(ICE_True);
	ICE_FontLoad("res//ttf//FiraSans-Medium.ttf");
}

ICE_CREATE()
{
	ICE_RenderBgColor( ICE_ColorNew( 200, 200, 200 ) );
	if(ICE_Debug(ICE_Null))
	{
		ICE_DebugFontDrawBgColor(100, 100, 100);
		ICE_DebugFontDrawFgColor(0, 0, 50);
	}
}
	

ICE_UPDATE()
{
	// Primitive
	// -------------------------

		// Croix
		ICE_DrawLine( ICE_VectNull, ICE_VectScreen, ICE_ColorRed );
		ICE_DrawLine(ICE_VectNew(0, ICE_WindowGetH()), ICE_VectNew(ICE_WindowGetW(),0), ICE_ColorRed);
		// Center
		ICE_DrawRectangleFill(ICE_CameraWorldScreen(ICE_BoxNew(-10, -10, 20, 20)), ICE_ColorRed);
	
	// Debug Drawing
	// -------------------------

		ICE_DebugMoveCamera();
		ICE_DebugShowFps();
		ICE_DebugFontDraw(2, " Version Test %s ", ICE_VERSION);
		ICE_DebugMouseCoordinate();		
}

ICE_DESTROY() {}

int main()
{
	ICE_START( "Hello World", 800, 480 );
	return 0;
}