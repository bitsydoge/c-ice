#include "hdr/Debug.h"
#include "hdr/TypesCore.h"
#include "hdr/Window.h"
#include "hdr/Vector.h"
#include "hdr/Font.h"
#include "hdr/Camera.h"
#include <stdio.h>
#include "hdr/Color.h"
#include "hdr/Color_private.h"
#include "hdr/Terminal.h"

extern ICE_Game game;

ICE_Bool ICE_Debug(const ICE_Bool yn)
{
	if(yn != -1)
		game.debug = yn;
	return game.debug;
}

void ICE_DebugMouseCoordinate()
{
	if (game.debug && SDL_GetMouseFocus())
	{
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
		sprintf(gh, "FPS : [%.1f]", game.time.fps);

		ICE_DebugFontDraw(0, gh);
	}
}

void ICE_DebugShowFpsTitle()
{
	if (game.debug)
	{
		char buffer[25];
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

// DEBUG
void ICE_DebugFontDraw(int y, const char* format, ...) {
	if(game.debug)
	{
		char buffer[512];
		va_list args;
		va_start(args, format);
		vsprintf(buffer, format, args);
		int size = (int)((ICE_Float)ICE_WindowGetH() / 40.0);
		if (size < 10)
			size = 10;
		SDL_Surface *surf = TTF_RenderText_Shaded(game.font.size[size], buffer, ICE_ColorToSdl(font_color_foreground_set), ICE_ColorToSdl(font_color_background_set));
		SDL_Rect rect; rect.x = 0; rect.y = surf->h * y;
		rect.w = surf->w; rect.h = surf->h;
		SDL_Texture *texture = SDL_CreateTextureFromSurface(game.window.render, surf);
		SDL_RenderCopy(game.window.render, texture, NULL, &rect);
		SDL_FreeSurface(surf);
		SDL_DestroyTexture(texture);

		va_end(args);
	}
}

void ICE_Log(ICE_LogTypes type, const char * format, ...)
{
	if (game.debug)
	{
		va_list args;
		va_start(args, format);
		
		switch (type)
		{
		case ICE_LOG_SUCCES:
			ICE_TermClock();
			ICE_TermSetColor(iceLIGHTGREEN);
			printf("[SUCCES]");
			break;
		case ICE_LOG_NONE:
			ICE_TermClock();
			printf("[LOG]");
			break;
		case ICE_LOG_WARNING:
			ICE_TermClock();
			ICE_TermSetColor(iceYELLOW);
			printf("[WARNING]");
			break;
		case ICE_LOG_ERROR:
			ICE_TermClock();
			ICE_TermSetColor(iceLIGHTRED);

			printf("[ERROR]");
			break;
		case ICE_LOG_CRITICAL:
			ICE_TermClock();
			ICE_TermSetColor(iceRED);
			printf("[CRITICAL]");
			break;
		default:
			ICE_TermClock();
			printf("[NOLOGTYPE]");
			break;
		}
		ICE_TermResetColor();
		printf("::[");
		vprintf(format, args);
		printf("]");
		printf("\n");
		va_end(args);
	}
}

void ICE_Log_no_n(ICE_LogTypes type, const char * format, ...)
{
	if (game.debug)
	{
		va_list args;
		va_start(args, format);

		switch (type)
		{
		case ICE_LOG_SUCCES:
			ICE_TermClock();
			ICE_TermSetColor(iceLIGHTGREEN);
			printf("[SUCCES]");
			break;
		case ICE_LOG_NONE:
			ICE_TermClock();
			printf("[LOG]");
			break;
		case ICE_LOG_WARNING:
			ICE_TermClock();
			ICE_TermSetColor(iceYELLOW);
			printf("[WARNING]");
			break;
		case ICE_LOG_ERROR:
			ICE_TermClock();
			ICE_TermSetColor(iceLIGHTRED);

			printf("[ERROR]");
			break;
		case ICE_LOG_CRITICAL:
			ICE_TermClock();
			ICE_TermSetColor(iceRED);
			printf("[CRITICAL]");
			break;
		default:
			ICE_TermClock();
			printf("[NOLOGTYPE]");
			break;
		}
		ICE_TermResetColor();
		printf("::[");
		vprintf(format, args);
		printf("]");
		va_end(args);
	}
}