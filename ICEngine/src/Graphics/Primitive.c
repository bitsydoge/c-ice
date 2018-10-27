#include "Primitive.h"

#include "Render_private.h"

#include "../Core/Converter_private.h"
#include "../Core/TypesCore.h"
#include "../External/SDL2_gfx/SDL2_gfxPrimitives.h"
#include "../Maths/TypesMaths.h"

extern ICE_Game game;
extern ICE_Core core;

// ClassicShit

int ICE_Draw_Point(const ICE_Vect vect, const ICE_Color color) {
	ICE_Render_SetColor(color);
	return SDL_RenderDrawPoint(core.window.render, (int)vect.x, (int)vect.y);
}

int ICE_Draw_Line(const ICE_Vect vect1, const ICE_Vect vect2, const ICE_Color color) {
	ICE_Render_SetColor(color);
	return SDL_RenderDrawLine(core.window.render, (int)vect1.x, (int)vect1.y, (int)vect2.x, (int)vect2.y);
}

int ICE_Draw_Rectangle(ICE_Box box, const ICE_Color color) {
	ICE_Render_SetColor(color);
	return SDL_RenderDrawRect(core.window.render, (SDL_Rect[]){ICE_Convert_BoxToSDL(&box)});
}

int ICE_Draw_RectangleFill(ICE_Box box, const ICE_Color color) {
	ICE_Render_SetColor(color);
	return SDL_RenderFillRect(core.window.render, (SDL_Rect[]) {ICE_Convert_BoxToSDL(&box) });
}

// AntiAliased SDL_GFX powa

int ICE_Draw_LineAA(const ICE_Vect vect1, const ICE_Vect vect2, const ICE_Color color) {
	return aalineColor(core.window.render, (Sint16)vect1.x, (Sint16)vect1.y, (Sint16)vect2.x, (Sint16)vect2.y, color);
}

int ICE_Draw_CircleAA(ICE_Vect vect, ICE_Float r, ICE_Color color){	
	return aacircleColor(core.window.render, (Sint16)vect.x, (Sint16)vect.y, (Sint16)r, color);
}