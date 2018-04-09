#include <ICE.h>

ICE_PRELOAD()
{
	ICE_Font_Insert("res//ttf//FiraSans-Medium.ttf");
}

ICE_CREATE()
{
	
}

ICE_UPDATE()
{
	
}

ICE_DESTROY()
{
	
}

int main()
{
	ICE_Debug_Set(ICE_TRUE);
	ICE_START("2DWatch", 800, 480);
	return 0;
}