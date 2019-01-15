#include "Primitive.h"

#include "Render_private.h"

#include "../Core/Converter_private.h"
#include "../Core/TypesCore.h"
#include "../Maths/TypesMaths.h"

extern ICE_Game GAME;
extern ICE_Core CORE;

// ClassicShit

int ICE_Draw_Point(const ICE_Vect vect, const ICE_Color color) {
	ICE_Render_SetColor(color);
	return SDL_RenderDrawPoint(CORE.window.render, (int)vect.x, (int)vect.y);
}

int ICE_Draw_Line(const ICE_Vect vect1, const ICE_Vect vect2, const ICE_Color color) {
	ICE_Render_SetColor(color);
	return SDL_RenderDrawLine(CORE.window.render, (int)vect1.x, (int)vect1.y, (int)vect2.x, (int)vect2.y);
}

int ICE_Draw_Rectangle(ICE_Box box, const ICE_Color color) {
	ICE_Render_SetColor(color);
	return SDL_RenderDrawRect(CORE.window.render, (SDL_Rect[]){ICE_Convert_BoxToSDL(&box)});
}

int ICE_Draw_RectangleFill(ICE_Box box, const ICE_Color color) {
	ICE_Render_SetColor(color);
	return SDL_RenderFillRect(CORE.window.render, (SDL_Rect[]) {ICE_Convert_BoxToSDL(&box) });
}