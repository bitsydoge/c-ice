#include "hdr/Debug.h"
#include "hdr/TypesCore.h"
#include "hdr/Window.h"
#include "hdr/Vector.h"
#include "hdr/Font.h"
#include "hdr/Camera.h"
#include <stdio.h>
#include "hdr/Color.h"
#include "hdr/Color_private.h"
#include "hdr/Input.h"
#include "hdr/Game.h"

extern ICE_Game game;
extern ICE_Asset asset;

ICE_Bool ICE_Debug(const ICE_Bool yn){
	if(yn != -1)
		game.debug = yn;
	return game.debug;
}

void ICE_DebugMouseCoordinate(){
	if (game.debug && SDL_GetMouseFocus()){
		char coo[20];
		ICE_Box coordinate = { game.window.input.mousex, game.window.input.mousey };
		if (game.window.input.leftclic)
			coordinate = ICE_CameraScreenWorld(coordinate);
		sprintf(coo, "%0.0f, %0.0f", coordinate.x, coordinate.y);

		ICE_Vect vect = { game.window.input.mousex + 10, game.window.input.mousey + 10 };
		ICE_FontDraw(coo, vect, ICE_ColorNew(255,255,255), ICE_ColorNew(0,0,0));
	}
}

void ICE_DebugShowFps()
{
	if (game.debug)
	{
		char gh[20];
		sprintf(gh, " FPS : [%.1f] ", game.time.fps);
		ICE_DebugFontDraw(1, gh);
	}
}

void ICE_DebugShowFpsTitle(){
	if (game.debug){
		char buffer[20];
		sprintf(buffer, "FPS : [%0.1f]", game.time.fps);
		ICE_WindowTitle(buffer);
	}
}

ICE_Color font_color_background_set = 0xFF0000FF;
ICE_Color font_color_foreground_set = 0xFFFFFFFF;

void ICE_DebugFontDrawBgColor(int r, int g, int b)
{
	if (game.debug)
	{
		font_color_background_set = ICE_ColorNew(r,g,b);
	}
}

void ICE_DebugFontDrawFgColor(int r, int g, int b)
{
	if (game.debug)
	{
		font_color_foreground_set = ICE_ColorNew(r, g, b);
	}
}

void ICE_DebugFontDraw(int y, const char* format, ...) {
	if(game.debug)
	{
		char buffer[512];
		va_list args;
		va_start(args, format);
		vsprintf(buffer, format, args);
		int size = (int)((ICE_Float)ICE_WindowGetH() / 50.0);
		if (size < 12)
			size = 12;
		SDL_Surface *surf = TTF_RenderText_Shaded(asset.font.size[size], buffer, ICE_ColorToSdl(font_color_foreground_set), ICE_ColorToSdl(font_color_background_set));
		SDL_Rect rect; rect.x = 0; rect.y = surf->h * y;
		rect.w = surf->w; rect.h = surf->h;
		SDL_Texture *texture = SDL_CreateTextureFromSurface(game.window.render, surf);
		SDL_RenderCopy(game.window.render, texture, NULL, &rect);
		SDL_FreeSurface(surf);
		SDL_DestroyTexture(texture);

		va_end(args);
	}
}

void ICE_DebugMoveCamera()
{
	if(game.debug)
	{
		if (ICE_InputKey(ICE_INPUT_W))
			ICE_CameraShiftPos(ICE_VectNew(0, -1000 * ICE_GameDelta()));
		if (ICE_InputKey(ICE_INPUT_S))
			ICE_CameraShiftPos(ICE_VectNew(0, 1000 * ICE_GameDelta()));
		if (ICE_InputKey(ICE_INPUT_A))
			ICE_CameraShiftPos(ICE_VectNew(-1000 * ICE_GameDelta(), 0));
		if (ICE_InputKey(ICE_INPUT_D))
			ICE_CameraShiftPos(ICE_VectNew(1000 * ICE_GameDelta(), 0));

	}
}