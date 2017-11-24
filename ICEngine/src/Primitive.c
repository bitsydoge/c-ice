#include "hdr/Primitive.h"

// RAW

int iceDrawPoint(iceGame *game, iceVect vect, const iceColor color){
	iceRenderSetClearColor(game->render, color);
	return SDL_RenderDrawPoint(game->render, vect.x, vect.y);
}

int iceDrawLine(iceGame *game, iceVect vect1, iceVect vect2, const iceColor color){
	iceRenderSetClearColor(game->render, color);
	return SDL_RenderDrawLine(game->render, vect1.x, vect1.y, vect2.x, vect2.y);
}

int iceDrawRectangle(iceGame *game, iceRect rect, const iceColor color){
	iceRenderSetClearColor(game->render, color);
	return SDL_RenderDrawRect(game->render, (SDL_Rect[]) { iceRectToSDL(&rect) });
}

int iceDrawRectangleFill(iceGame *game, iceRect rect, const iceColor color){
	iceRenderSetClearColor(game->render, color);
	return SDL_RenderFillRect(game->render, (SDL_Rect[]) { iceRectToSDL(&rect)});
}

// OPENGL LIKE

int iceDrawPointGL(iceGame *game, int x, int y, const iceColor color) {
	iceRenderSetClearColor(game->render, color);
	return SDL_RenderDrawPoint(game->render, x, y);
}

int iceDrawLineGL(iceGame *game, int x1, int y1, int x2, int y2, const iceColor color) {
	iceRenderSetClearColor(game->render, color);
	return SDL_RenderDrawLine(game->render, x1, y1, x2, y2);
}

int iceDrawRectangleGL(iceGame *game, iceRect rect, const iceColor color) {
	iceRenderSetClearColor(game->render, color);
	return SDL_RenderDrawRect(game->render, (SDL_Rect[]) { iceRectToSDL(&rect) });
}

int iceDrawRectangleFillGL(iceGame *game, iceRect rect, const iceColor color) {
	iceRenderSetClearColor(game->render, color);
	return SDL_RenderFillRect(game->render, (SDL_Rect[]) { iceRectToSDL(&rect) });
}