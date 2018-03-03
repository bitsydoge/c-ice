#include <Core.h>
#include <stdio.h>

ICE_PRELOAD() // Load asset here, if the game "restart" they are not gonna be reload
{
	
}

ICE_CREATE()
{
	ICE_Debug( ICE_True );
	ICE_RenderSetColor( ICE_ColorNew( 200, 200, 200 ) );
}

ICE_UPDATE()
{
	ICE_Float clock = ICE_TimeClock();
	if ( clock > 5 )
		ICE_InputQuit();
	ICE_TermClock();
	printf( "\n" );
}

ICE_DESTROY()
{
	
}

int main()
{
	ICE_START( "Hello World", 800, 480 );
	return 0;
}