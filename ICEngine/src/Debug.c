#include "hdr/Debug.h"
#include "hdr/TypesCore.h"
#include "hdr/Window.h"
#include "hdr/Vector.h"
#include "hdr/Font.h"
#include "hdr/Camera.h"
#include <stdio.h>
#include "hdr/Core.h"

extern ICE_Game game;

void ICE_Debug(const ICE_Bool yn)
{
	game.debug = yn;
}

void ICE_DebugMouseCoordinate()
{
	char coo[20];
	ICE_Box coordinate = { game.window.input.mousex, game.window.input.mousey };
	if (game.window.input.leftclic)
		coordinate = ICE_CameraScreenWorld(coordinate);
	sprintf(coo, "%0.1f, %0.1f", coordinate.x, coordinate.y);

	ICE_Vect vect = { game.window.input.mousex + 10, game.window.input.mousey + 10 };
	ICE_DebugFontDraw(coo, vect);
}

void ICE_DebugShowFps()
{
	char gh[100];
	sprintf(gh, "%.1f", game.time.fps);

	ICE_DebugFontDraw(gh, ICE_VectNull);
}

void ICE_DebugShowFpsTitle()
{
	char buffer[25];
	sprintf(buffer, "FPS : [%0.1f]", game.time.fps);
	ICE_WindowTitle(buffer);
}

SDL_Color font_color_background_set = { 255,0,0,255 };
SDL_Color font_color_foreground_set = { 255,255,255,255 };

void ICE_DebugFontDrawBgColor(int r, int g, int b)
{
	font_color_background_set.r = r; font_color_background_set.b = b; font_color_background_set.g = g; font_color_background_set.a = 255;
}

void ICE_DebugFontDrawFgColor(int r, int g, int b)
{
	font_color_foreground_set.r = r; font_color_foreground_set.b = b; font_color_foreground_set.g = g; font_color_foreground_set.a = 255;
}

// DEBUG
void ICE_DebugFontDraw(char* text, ICE_Vect vect) {
	SDL_Surface *surf = TTF_RenderText_Shaded(game.font.size[ICE_WindowGetH() / 32], text, font_color_foreground_set, font_color_background_set);
	SDL_Rect rect; rect.x = vect.x; rect.y = vect.y;
	rect.w = surf->w; rect.h = surf->h;
	SDL_Texture *texture = SDL_CreateTextureFromSurface(game.window.render, surf);
	SDL_RenderCopy(game.window.render, texture, NULL, &rect);
	SDL_FreeSurface(surf);
	SDL_DestroyTexture(texture);
}