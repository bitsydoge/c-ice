#include "hdr/Primitive.h"

// RAW

int iceDrawPoint(iceGame *game, iceVect vect, const iceColor color){
	iceRenderClearColor(game->drawer.render, color);
	return SDL_RenderDrawPoint(game->drawer.render, vect.x, vect.y);
}

int iceDrawLine(iceGame *game, iceVect vect1, iceVect vect2, const iceColor color){
	iceRenderClearColor(game->drawer.render, color);
	return SDL_RenderDrawLine(game->drawer.render, vect1.x, vect1.y, vect2.x, vect2.y);
}

int iceDrawRectangle(iceGame *game, iceBox rect, const iceColor color){
	iceRenderClearColor(game->drawer.render, color);
	return SDL_RenderDrawRect(game->drawer.render, (SDL_Rect[]) { iceConvertBoxToSdl(&rect) });
}

int iceDrawRectangleFill(iceGame *game, iceBox rect, const iceColor color){
	iceRenderClearColor(game->drawer.render, color);
	return SDL_RenderFillRect(game->drawer.render, (SDL_Rect[]) { iceConvertBoxToSdl(&rect)});
}

// OPENGL LIKE

int iceDrawPointGL(iceGame *game, int x, int y, const iceColor color) {
	iceRenderClearColor(game->drawer.render, color);
	return SDL_RenderDrawPoint(game->drawer.render, x, y);
}

int iceDrawLineGL(iceGame *game, int x1, int y1, int x2, int y2, const iceColor color) {
	iceRenderClearColor(game->drawer.render, color);
	return SDL_RenderDrawLine(game->drawer.render, x1, y1, x2, y2);
}

int iceDrawRectangleGL(iceGame *game, iceBox rect, const iceColor color) {
	iceRenderClearColor(game->drawer.render, color);
	return SDL_RenderDrawRect(game->drawer.render, (SDL_Rect[]) { iceConvertBoxToSdl(&rect) });
}

int iceDrawRectangleFillGL(iceGame *game, iceBox rect, const iceColor color) {
	iceRenderClearColor(game->drawer.render, color);
	return SDL_RenderFillRect(game->drawer.render, (SDL_Rect[]) { iceConvertBoxToSdl(&rect) });
}