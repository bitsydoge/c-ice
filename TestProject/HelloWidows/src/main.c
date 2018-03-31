#include <Core.h>

ICE_PRELOAD() // Load assets here, if the game "restart" they are not gonna be reload
{
	ICE_Font_Load("res//ttf//FiraSans-Medium.ttf");
}

ICE_CREATE()
{	
	ICE_Render_Color( ICE_Color_New( 200, 200, 200 ) );
	ICE_Debug_FontSetColorBg( 100, 100, 100 );
	ICE_Debug_FontSetColorFg( 0, 0, 50 );
	 
	ICE_Label test = ICE_Label_Create( "Test", ICE_Vect_New( 20, 20 ) );
	ICE_Label * test2 = ICE_Label_Init("Test", ICE_Vect_New(10, 10));

	ICE_LabelManager_Insert(); // Create manager if you prefer
	ICE_Label_Insert( 0, "Anneyong", ICE_Vect_New( 50, 50 ) );
	ICE_Label_Insert( 0, "Gengu", ICE_Vect_New( 50, 50) );
	ICE_Label_Insert( 0, "Gengu", ICE_Vect_New( 50, 50 ) );
	ICE_Label_Insert( 0, "Gengu", ICE_Vect_New( 50, 50 ) );
	ICE_Label_Insert( 0, "Gengu", ICE_Vect_New( 50, 50 ) );

	ICE_LabelManager_Insert();
	ICE_Label_Insert( 1, "Annyeong", ICE_Vect_New( 50, 50 ) );
	ICE_Label_Insert( 1, "Gengu", ICE_Vect_New( 50, 50 ) );
	ICE_Label_Destroy(&test);
	ICE_Label_Destroy(test2);
}

ICE_UPDATE()
{
	static float amount = 0;
	float result = ICE_Interpolate(0, 255, amount / 5.0f, ICE_Interpolate_QuadraticIn);
	ICE_Render_Color(ICE_Color_New(result, result, result));
	ICE_Draw_RectangleFill( ICE_Camera_WorldScreen( ICE_Box_New( -10, -10, 20, 20 ) ), ICE_Color_Red );
	ICE_Debug_CameraControl();
	ICE_Debug_DrawFps(0);
	ICE_Debug_FontDraw( 2, " Version %s ", ICE_VERSION );	
	amount += ICE_Game_GetDelta();
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