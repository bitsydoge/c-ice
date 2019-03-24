#include "../Framework/BasicTypes.h"
#include "Primitive.h"
#include "Window.h"
#include "Input_private.h"
#include "Time_private.h"

#include "SDL2_Includer_private.h"
#include ICE_INCLUDE_SDL2_TTF
#include "FontManager_private.h"
#include "Resources_private.h"
#include "Renderer_private.h"

ICE_Bool ICE_Debug_Get_Linked()
{
#if defined(_DEBUG)
	return ICE_True;
#else
	return ICE_False;
#endif
}

#if defined(_DEBUG)

#include "Debug.h"

#include <SDL2/SDL.h>
#include "Box.h"
#include "Color.h"
#include "Game.h"
#include "SDL2_Converter_private.h"
#include "Font.h"
#include "Input.h"
#include "Camera.h"
#include <stdio.h>

void(*ICE_GLOBJ_DEBUG_LATEDRAW)() = NULL;

void (*ICE_Debug_LateDraw_Get())()
{
	return ICE_GLOBJ_DEBUG_LATEDRAW;
}

ICE_Color font_color_background_set = 0xFF0000FF;
ICE_Color font_color_foreground_set = 0xFFFFFFFF;

void ICE_Debug_DrawCoordinate()
{
	if (SDL_GetMouseFocus())
	{
		char coo[20];
		ICE_Vect2D coordinate_vect = { ICE_Input_GetPtr()->mousex, ICE_Input_GetPtr()->mousey };
		if (ICE_Input_GetPtr()->leftclic_pressed)
		{
			ICE_Box coordinate_box = ICE_Camera_Screen_to_World(ICE_Box_New(coordinate_vect.x, coordinate_vect.y, 0,0));
			coordinate_vect = ICE_Vect2D_New(coordinate_box.x, coordinate_box.y);
		}
			
		sprintf(coo, "%0.0f, %0.0f", coordinate_vect.x, coordinate_vect.y);

		const ICE_Vect2D vect = { ICE_Input_GetPtr()->mousex + 10, ICE_Input_GetPtr()->mousey + 10 };
		ICE_Font_Draw(coo, vect, ICE_Color_New(255,255,255), ICE_Color_New(0,0,0));
	}
}

void ICE_Debug_DrawFps(int y_pos)
{
	char gh[20];
	sprintf(gh, " FPS : [%.0f] ", ICE_Time_GetPtr()->fps);
	ICE_Debug_FontDraw(y_pos, gh);
}

void ICE_Debug_TitleFps()
{
	char buffer[20];
	sprintf(buffer, "FPS : [%.0f]", ICE_Time_GetPtr()->fps);
	ICE_Window_SetTitle(buffer);
}

void ICE_Debug_FontSetColorBg(int r, int g, int b)
{
		font_color_background_set = ICE_Color_New(r,g,b);
}

void ICE_Debug_FontSetColorFg(int r, int g, int b)
{
	font_color_foreground_set = ICE_Color_New(r, g, b);
}

void ICE_Debug_FontDraw(int y, const char* format, ...) 
{
	char buffer[512];
	va_list args;
	va_start(args, format);
	vsprintf(buffer, format, args);
	int size = (int)((ICE_Float)ICE_Window_GetH() / 50.0);
	
	if (size < 12)
		size = 12;

	SDL_Surface *surf = TTF_RenderText_Shaded(
		ICE_FontManager_GetPtr()->font_array[ICE_Resources_Get()->font_default].size[size],
		buffer, 
		ICE_Color_ToSdl(font_color_foreground_set), 
		ICE_Color_ToSdl(font_color_background_set)
	
	);

	SDL_Rect rect; rect.x = 0; rect.y = surf->h * y;
	rect.w = surf->w; rect.h = surf->h;
	SDL_Texture *texture = SDL_CreateTextureFromSurface(ICE_Renderer_GetPtr()->handle, surf);
	SDL_RenderCopy(ICE_Renderer_GetPtr()->handle, texture, NULL, &rect);
	SDL_FreeSurface(surf);
	SDL_DestroyTexture(texture);
	va_end(args);
}

void ICE_Debug_CameraControl()
{
	if (ICE_Input_Pressed(ICE_KEY_KP_PLUS))
		ICE_Camera_AddScale(ICE_Vect2D_Scale(ICE_Vect2D_Scale(ICE_Camera_GetScale(), 1), ICE_Game_GetDelta()));
	if (ICE_Input_Pressed(ICE_KEY_KP_MINUS))
		ICE_Camera_AddScale(ICE_Vect2D_Scale(ICE_Vect2D_Scale(ICE_Camera_GetScale(), -1), ICE_Game_GetDelta()));
	if (ICE_Input_Pressed(ICE_KEY_KP_ENTER))
		ICE_Camera_SetScale(ICE_Vect2D_New(1, 1));
	if (ICE_Input_Pressed(ICE_KEY_W))
		ICE_Camera_AddPosition(ICE_Vect2D_New(0, -1000 * ICE_Game_GetDelta()));
	if (ICE_Input_Pressed(ICE_KEY_S))
		ICE_Camera_AddPosition(ICE_Vect2D_New(0, 1000 * ICE_Game_GetDelta()));
	if (ICE_Input_Pressed(ICE_KEY_A))
		ICE_Camera_AddPosition(ICE_Vect2D_New(-1000 * ICE_Game_GetDelta(), 0));
	if (ICE_Input_Pressed(ICE_KEY_D))
		ICE_Camera_AddPosition(ICE_Vect2D_New(1000 * ICE_Game_GetDelta(), 0));
	if (ICE_Input_Pressed(ICE_KEY_SPACE))
		ICE_Camera_MoveTo(ICE_Vect2D_Zero, 1000 * ICE_Game_GetDelta());
}

void ICE_Debug_CameraDraw()
{
	char coo[96];
	sprintf(coo, "Camera [ Pos(%0.2f, %0.2f) Scale(%0.2f, %0.2f) ]", ICE_Camera_GetPositionX(), ICE_Camera_GetPositionY(), ICE_Camera_GetScaleW(), ICE_Camera_GetScaleH());

	const ICE_Vect2D vect = { ICE_Window_GetW()/2, 0};
	ICE_Font_Draw(coo, vect, ICE_Color_New(255, 255, 255), ICE_Color_New(0, 0, 0));

	ICE_Draw_Line(ICE_Vect2D_New(ICE_Window_GetW() / 2, 0), ICE_Vect2D_New(ICE_Window_GetW() / 2, ICE_Window_GetH()), ICE_Color_New(255, 0, 0));
	ICE_Draw_Line(ICE_Vect2D_New(0, ICE_Window_GetH() / 2), ICE_Vect2D_New(ICE_Window_GetW(), ICE_Window_GetH() / 2), ICE_Color_New(255, 0, 0));
}

void ICE_Debug_CallbackDraw(void(*callback)())
{
	ICE_GLOBJ_DEBUG_LATEDRAW = callback;
}

#endif