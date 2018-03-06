#include "hdr/Primitive.h"
#include "hdr/Converter_private.h"
#include "hdr/TypesCore.h"
#include "hdr/Render_private.h"
#include "external/SDL2_gfxPrimitives.h"

extern ICE_Game game;

// ClassicShit

int ICE_DrawPoint(const ICE_Vect vect, const ICE_Color color) {
	ICE_RenderSetColor(color);
	return SDL_RenderDrawPoint(game.window.render, vect.x, vect.y);
}

int ICE_DrawLine(const ICE_Vect vect1, const ICE_Vect vect2, const ICE_Color color) {
	ICE_RenderSetColor(color);
	return SDL_RenderDrawLine(game.window.render, vect1.x, vect1.y, vect2.x, vect2.y);
}

int ICE_DrawRectangle(ICE_Box rect, const ICE_Color color) {
	ICE_RenderSetColor(color);
	return SDL_RenderDrawRect(game.window.render, (SDL_Rect[]){ICE_ConvertBoxToSDL(&rect)});
}

int ICE_DrawRectangleFill(ICE_Box rect, const ICE_Color color) {
	ICE_RenderSetColor(color);
	return SDL_RenderFillRect(game.window.render, (SDL_Rect[]) {ICE_ConvertBoxToSDL(&rect) });
}

// AntiAliased SDL_GFX powa

int ICE_DrawLineAA(const ICE_Vect vect1, const ICE_Vect vect2, const ICE_Color color) {
	return aalineColor(game.window.render, vect1.x, vect1.y, vect2.x, vect2.y, color);
}

int ICE_DrawCircleAA(ICE_Vect vect, ICE_Float r, ICE_Color color){	
	return aacircleColor(game.window.render, vect.x, vect.y, r, color);
}