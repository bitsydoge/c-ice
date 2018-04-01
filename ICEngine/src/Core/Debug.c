#include "Debug.h"

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

extern ICE_Game game;
extern ICE_Asset asset;

ICE_Bool debug_ok = ICE_False;

ICE_Bool ICE_Debug_Set(const ICE_Bool yn){
	if(yn != -1)
		debug_ok = yn;
	return debug_ok;
}

void ICE_Debug_DrawCoordinate(){
	if (debug_ok && SDL_GetMouseFocus()){
		char coo[20];
		ICE_Box coordinate = { game.window.input.mousex, game.window.input.mousey };
		if (game.window.input.leftclic)
			coordinate = ICE_Camera_ScreenWorld(coordinate);
		sprintf(coo, "%0.0f, %0.0f", coordinate.x, coordinate.y);

		ICE_Vect vect = { game.window.input.mousex + 10, game.window.input.mousey + 10 };
		ICE_Font_Draw(coo, vect, ICE_Color_New(255,255,255), ICE_Color_New(0,0,0));
	}
}

void ICE_Debug_DrawFps(int y_pos)
{
	if (debug_ok)
	{
		char gh[20];
		sprintf(gh, " FPS : [%.0f] ", game.time.fps);
		ICE_Debug_FontDraw(y_pos, gh);
	}
}

void ICE_Debug_TitleFps(){
	if (debug_ok){
		char buffer[20];
		sprintf(buffer, "FPS : [%.0f]", game.time.fps);
		ICE_Window_SetTitle(buffer);
	}
}

ICE_Color font_color_background_set = 0xFF0000FF;
ICE_Color font_color_foreground_set = 0xFFFFFFFF;

void ICE_Debug_FontSetColorBg(int r, int g, int b)
{
	if (debug_ok)
	{
		font_color_background_set = ICE_Color_New(r,g,b);
	}
}

void ICE_Debug_FontSetColorFg(int r, int g, int b)
{
	if (debug_ok)
	{
		font_color_foreground_set = ICE_Color_New(r, g, b);
	}
}

void ICE_Debug_FontDraw(int y, const char* format, ...) {
	if(debug_ok)
	{
		char buffer[512];
		va_list args;
		va_start(args, format);
		vsprintf(buffer, format, args);
		int size = (int)((ICE_Float)ICE_Window_GetH() / 50.0);
		if (size < 12)
			size = 12;
		SDL_Surface *surf = TTF_RenderText_Shaded(asset.font.size[size], buffer, ICE_Color_ToSdl(font_color_foreground_set), ICE_Color_ToSdl(font_color_background_set));
		SDL_Rect rect; rect.x = 0; rect.y = surf->h * y;
		rect.w = surf->w; rect.h = surf->h;
		SDL_Texture *texture = SDL_CreateTextureFromSurface(game.window.render, surf);
		SDL_RenderCopy(game.window.render, texture, NULL, &rect);
		SDL_FreeSurface(surf);
		SDL_DestroyTexture(texture);
		va_end(args);
	}
}

void ICE_Debug_CameraControl()
{
	if(debug_ok)
	{
		if (ICE_Input_Press(ICE_INPUT_W))
			ICE_Camera_ShiftPos(ICE_Vect_New(0, -1000 * ICE_Game_GetDelta()));
		if (ICE_Input_Press(ICE_INPUT_S))
			ICE_Camera_ShiftPos(ICE_Vect_New(0, 1000 * ICE_Game_GetDelta()));
		if (ICE_Input_Press(ICE_INPUT_A))
			ICE_Camera_ShiftPos(ICE_Vect_New(-1000 * ICE_Game_GetDelta(), 0));
		if (ICE_Input_Press(ICE_INPUT_D))
			ICE_Camera_ShiftPos(ICE_Vect_New(1000 * ICE_Game_GetDelta(), 0));
		if (ICE_Input_Press(ICE_INPUT_SPACE))
			ICE_Camera_MovePos(ICE_Vect_Null, 1000 * ICE_Game_GetDelta());
	}
}