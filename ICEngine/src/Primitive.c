#include "hdr/Primitive.h"
#include "hdr/Draw.h"
#include "hdr/Converter_private.h"
#include "hdr/Draw_private.h"

extern iceGame game;

// RAW

int iceDrawPoint(const iceVect vect, const iceColor color){
	iceDrawClearColor(color);
	return SDL_RenderDrawPoint(game.drawer.render, vect.x, vect.y);
}

int iceDrawLine(const iceVect vect1, const iceVect vect2, const iceColor color){
	iceDrawClearColor(color);
	return SDL_RenderDrawLine(game.drawer.render, vect1.x, vect1.y, vect2.x, vect2.y);
}

int iceDrawRectangle(iceBox rect, const iceColor color){
	iceDrawClearColor(color);
	return SDL_RenderDrawRect(game.drawer.render, (SDL_Rect[]) { iceConvertBoxToSdl(&rect) });
}

int iceDrawRectangleFill(iceBox rect, const iceColor color){
	iceDrawClearColor(color);
	return SDL_RenderFillRect(game.drawer.render, (SDL_Rect[]) { iceConvertBoxToSdl(&rect)});
}