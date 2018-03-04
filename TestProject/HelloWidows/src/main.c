#include <Core.h>
#include <stdio.h>
#include "Debug_private.h"
#include "TypesCore.h"

ICE_PRELOAD() // Load assets here, if the game "restart" they are not gonna be reload
{
	ICE_FontLoad("res//ttf//FiraSans-Medium.ttf");
}

ICE_CREATE()
{
	ICE_Debug( ICE_True );
	ICE_RenderBgColor( ICE_ColorNew( 200, 200, 200 ) );
	ICE_DebugFontDrawBgColor(100, 100, 100);
	ICE_DebugFontDrawFgColor(0, 0, 50);
}

ICE_UPDATE()
{
	ICE_DebugMouseCoordinate();
	ICE_DebugShowFps();

	ICE_DebugFontDraw("Hello ", ICE_VectNew(0, (ICE_Float)(ICE_WindowGetH() / 32.0) * 2.0));

	ICE_Float clock = ICE_TimeClock();
	if ( clock > 15 )
		ICE_InputQuit();
	ICE_TermClock();
	puts("");

	ICE_DrawLine(ICE_VectNull, ICE_VectScreen, ICE_ColorRed);

}

ICE_DESTROY()
{
	
}

int main()
{
	ICE_START( "Hello World", 800, 480 );
	return 0;
}