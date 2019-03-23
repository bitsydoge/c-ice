#include "Primitive.h"

#include "Renderer_private.h"
#include "SDL2_Converter_private.h"

// ClassicShit

int ICE_Draw_Point(const ICE_Vect vect, const ICE_Color color) {
	ICE_Renderer_SetColor(color);
	return SDL_RenderDrawPoint(ICE_Renderer_GetPtr()->handle, (int)vect.x, (int)vect.y);
}

int ICE_Draw_Line(const ICE_Vect vect1, const ICE_Vect vect2, const ICE_Color color) {
	ICE_Renderer_SetColor(color);
	return SDL_RenderDrawLine(ICE_Renderer_GetPtr()->handle, (int)vect1.x, (int)vect1.y, (int)vect2.x, (int)vect2.y);
}

int ICE_Draw_Rectangle(ICE_Box box, const ICE_Color color) {
	ICE_Renderer_SetColor(color);
	return SDL_RenderDrawRect(ICE_Renderer_GetPtr()->handle, (SDL_Rect[]){ICE_Convert_BoxToSDL(&box)});
}

int ICE_Draw_RectangleFill(ICE_Box box, const ICE_Color color) {
	ICE_Renderer_SetColor(color);
	return SDL_RenderFillRect(ICE_Renderer_GetPtr()->handle, (SDL_Rect[]) {ICE_Convert_BoxToSDL(&box) });
}