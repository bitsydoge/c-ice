#include <ICE.h>
#include "Audio/Sound.h"

void hello_create()
{
	ICE_Render_Color(ICE_Color_New(55, 20, 10));
	ICE_LabelManager_Insert(NULL);
	unsigned int nb = ICE_Label_Insert(ICE_State_GetParent(NULL), 0, "HELLO GIRL FROM STATE", ICE_Vect_New(100, 100));
	ICE_Label_SetColor(ICE_Label_Get(ICE_State_GetParent(NULL), 0, nb), ICE_Color_New(100, 255, 2));
	ICE_Label_SetSize(ICE_Label_Get(ICE_State_GetParent(NULL), 0, nb), 100);
	ICE_Label_FixToWorld(ICE_Label_Get(ICE_State_GetParent(NULL), 0, nb), ICE_True);

	nb = ICE_Label_Insert(NULL, 0, "HELLO GIRL", ICE_Vect_New(100, 100));
	ICE_Label_SetColor(ICE_Label_Get(NULL, 0, nb), ICE_Color_New(100, 255, 2));
	ICE_Label_SetSize(ICE_Label_Get(NULL, 0, nb), 100);
	ICE_Label_FixToWorld(ICE_Label_Get(NULL, 0, nb), ICE_True);
}

void hello_update()
{
	ICE_Debug_CameraControl();
	ICE_Debug_DrawFps(3);
	ICE_Debug_FontDraw(4, " Version %s ", ICE_VERSION);
	ICE_Draw_RectangleFill(ICE_Camera_WorldScreen(ICE_Box_New(-25, -25, 50, 50)), ICE_Color_Blue);

	if(ICE_Input_Key(ICE_KEY_ESCAPE))
	{
		ICE_State_Pause();
	}

	ICE_Label * the_string = ICE_Label_Get(ICE_State_GetParent(NULL), 0, 0);
	ICE_Debug_FontDraw(5, "RESULT = %s", ICE_Label_GetString(the_string));
}

void hello_destroy()
{

}

ICE_State hello;

ICE_PRELOAD()
{
	unsigned int man = 0;

	man = ICE_TextureManager_Insert();
	ICE_Texture_Insert(man, "res//img//pic.png");
	ICE_Texture_Insert(man, "res//img//gui.png");

	man = ICE_SoundManager_Insert();
	ICE_Sound_Insert(man, "res//snd//explosion.wav");

	man = ICE_MusicManager_Insert();
	ICE_Music_Insert(man, "res//snd//music.ogg");

	ICE_Font_Load("res//ttf//FiraSans-Medium.ttf");
}

ICE_CREATE()
{	
	ICE_Debug_FontSetColorBg( 100, 100, 100 );
	ICE_Debug_FontSetColorFg( 0, 0, 50 );

	unsigned int manager = 0;
	unsigned int label = 0;

	ICE_GuiManager_Insert(NULL);
	ICE_Gui_Insert(NULL, 0, ICE_Box_New(0, 0, ICE_Window_GetW(), 50), 0, 1);

	manager = ICE_LabelManager_Insert(NULL);
	label = ICE_Label_Insert(NULL, manager, "It is a me", ICE_Vect_New(0,0));
	ICE_Label_SetSize(ICE_Label_Get(NULL, manager ,label), 30);
	ICE_Label_FixToWorld(ICE_Label_Get(NULL, manager, label), ICE_True);
	ICE_Label_SetAngle(ICE_Label_Get(NULL, manager, label), 30);

	label = ICE_Label_Insert(NULL, manager, "It is a not a me !", ICE_Vect_New(5, 5));
	ICE_Label_SetSize(ICE_Label_Get(NULL, manager, label), 30);

	hello = ICE_State_Create(hello_create, hello_update, hello_destroy);

	ICE_Music_Play(ICE_Music_Get(0, 0), 50);
}

ICE_UPDATE()
{
	ICE_Gui_SetSize(ICE_Gui_Get(NULL, 0, 0), ICE_Vect_New(ICE_Window_GetW(), 50));

	static float amount = 0; float result;
	if (amount <= 5.0f)
		result = ICE_Interpolate(0, 255, amount / 5.0f, ICE_Interpolate_CubicIn);
	else
		result = ICE_Interpolate(0, 255, 1 - ( (amount-5) / 5.0f ), ICE_Interpolate_CubicOut);
	
	ICE_Render_Color(ICE_Color_New(result/5, result/2.5f+20, result/1.5f+20));
	ICE_Draw_RectangleFill(ICE_Camera_WorldScreen(ICE_Box_New(-10, -10, 20, 20)), ICE_Color_Red);

	ICE_Debug_CameraControl();
	ICE_Debug_DrawFps(4);
	ICE_Debug_FontDraw(5, " Version %s ", ICE_VERSION);

	if(ICE_Input_Key(ICE_KEY_ESCAPE))
	{
		ICE_Sound_Play(ICE_Sound_Get(0, 0), 64);
		ICE_Substate_Start(&hello);
	}

	if(ICE_Input_Key(ICE_KEY_SPACE))
	{
		ICE_Label_SetString(ICE_Label_Get(NULL, 0, 0), "IT IS THE END OF THE WORLD");
		ICE_Label_SetSize(ICE_Label_Get(NULL, 0, 0), 50);
		ICE_Label_SetColor(ICE_Label_Get(NULL, 0, 0), ICE_Color_Red);
		ICE_Label_SetPos(ICE_Label_Get(NULL, 0, 0), ICE_Vect_New( 0, 0 ));
	}

	if(ICE_Input_Key(ICE_KEY_RETURN))
	{
		ICE_Camera_SetPos(ICE_Vect_New(0,0));
	}

	amount += ICE_Game_GetDelta();
	if (amount >= 10.0f)
		amount = 0;
}

ICE_DESTROY()
{
	ICE_State_Destroy(&hello);
}

int main()
{
	ICE_Debug_Set(ICE_True);
	ICE_START( "Hello World", 500, 500 );
	return 0;
}