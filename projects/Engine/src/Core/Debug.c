#include "Debug.h"

ICE_Bool ICE_Debug_Get_Linked()
{
#if defined(_DEBUG)
	return ICE_True;
#else
	return ICE_False;
#endif
}

#if defined(_DEBUG)

#include "TypesCore.h"
#include "Window.h"
#include "Input.h"
#include "Game.h"

#include "../Graphics/Font.h"
#include "../Graphics/Camera.h"
#include "../Graphics/Color.h"
#include "../Graphics/Color_private.h"
#include "../Maths/Vector.h"

#include <stdio.h>

extern ICE_Core CORE;
extern ICE_Game GAME;
extern ICE_Asset ASSET;

void ICE_Debug_DrawCoordinate()
{
	if (SDL_GetMouseFocus())
	{
		char coo[20];
		ICE_Box coordinate = { CORE.window.input.mousex, CORE.window.input.mousey };
		if (CORE.window.input.leftclic_pressed)
			coordinate = ICE_Camera_ScreenWorld(coordinate);
		sprintf(coo, "%0.0f, %0.0f", coordinate.x, coordinate.y);

		const ICE_Vect vect = { CORE.window.input.mousex + 10, CORE.window.input.mousey + 10 };
		ICE_Font_Draw(coo, vect, ICE_Color_New(255,255,255), ICE_Color_New(0,0,0));
	}
}

void ICE_Debug_DrawFps(int y_pos)
{
	char gh[20];
	sprintf(gh, " FPS : [%.0f] ", CORE.time.fps);
	ICE_Debug_FontDraw(y_pos, gh);
}

void ICE_Debug_TitleFps()
{
	char buffer[20];
	sprintf(buffer, "FPS : [%.0f]", CORE.time.fps);
	ICE_Window_SetTitle(buffer);
}

ICE_Color font_color_background_set = 0xFF0000FF;
ICE_Color font_color_foreground_set = 0xFFFFFFFF;

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
	SDL_Surface *surf = TTF_RenderText_Shaded(ASSET.font.size[size], buffer, ICE_Color_ToSdl(font_color_foreground_set), ICE_Color_ToSdl(font_color_background_set));
	SDL_Rect rect; rect.x = 0; rect.y = surf->h * y;
	rect.w = surf->w; rect.h = surf->h;
	SDL_Texture *texture = SDL_CreateTextureFromSurface(CORE.window.render, surf);
	SDL_RenderCopy(CORE.window.render, texture, NULL, &rect);
	SDL_FreeSurface(surf);
	SDL_DestroyTexture(texture);
	va_end(args);
}

void ICE_Debug_CameraControl()
{
	if (ICE_Input_Pressed(ICE_KEY_W))
		ICE_Camera_ShiftPos(ICE_Vect_New(0, -1000 * ICE_Game_GetDelta()));
	if (ICE_Input_Pressed(ICE_KEY_S))
		ICE_Camera_ShiftPos(ICE_Vect_New(0, 1000 * ICE_Game_GetDelta()));
	if (ICE_Input_Pressed(ICE_KEY_A))
		ICE_Camera_ShiftPos(ICE_Vect_New(-1000 * ICE_Game_GetDelta(), 0));
	if (ICE_Input_Pressed(ICE_KEY_D))
		ICE_Camera_ShiftPos(ICE_Vect_New(1000 * ICE_Game_GetDelta(), 0));
	if (ICE_Input_Pressed(ICE_KEY_SPACE))
		ICE_Camera_MovePos(ICE_Vect_Zero, 1000 * ICE_Game_GetDelta());
}

void ICE_Debug_CallbackDraw(void(*callback)())
{
	CORE.lateDrawDebug = callback;
}

#endif