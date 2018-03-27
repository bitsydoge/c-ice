#include "hdr/Primitive.h"
#include "hdr/Converter_private.h"
#include "hdr/TypesCore.h"
#include "hdr/Render_private.h"
#include "external/SDL2_gfxPrimitives.h"

extern ICE_Game game;

// ClassicShit

int ICE_Draw_Point(const ICE_Vect vect, const ICE_Color color) {
	ICE_Render_SetColor(color);
	return SDL_RenderDrawPoint(game.window.render, vect.x, vect.y);
}

int ICE_Draw_Line(const ICE_Vect vect1, const ICE_Vect vect2, const ICE_Color color) {
	ICE_Render_SetColor(color);
	return SDL_RenderDrawLine(game.window.render, vect1.x, vect1.y, vect2.x, vect2.y);
}

int ICE_Draw_Rectangle(ICE_Box rect, const ICE_Color color) {
	ICE_Render_SetColor(color);
	return SDL_RenderDrawRect(game.window.render, (SDL_Rect[]){ICE_Convert_BoxToSDL(&rect)});
}

int ICE_Draw_RectangleFill(ICE_Box rect, const ICE_Color color) {
	ICE_Render_SetColor(color);
	return SDL_RenderFillRect(game.window.render, (SDL_Rect[]) {ICE_Convert_BoxToSDL(&rect) });
}

// AntiAliased SDL_GFX powa

int ICE_Draw_LineAA(const ICE_Vect vect1, const ICE_Vect vect2, const ICE_Color color) {
	return aalineColor(game.window.render, vect1.x, vect1.y, vect2.x, vect2.y, color);
}

int ICE_Draw_CircleAA(ICE_Vect vect, ICE_Float r, ICE_Color color){	
	return aacircleColor(game.window.render, vect.x, vect.y, r, color);
}