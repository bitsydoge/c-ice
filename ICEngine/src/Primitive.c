#include "hdr/Primitive.h"

// Rect

iceRect RectNew(iceFloat x, iceFloat y, iceFloat w, iceFloat h){
	iceRect rect = { x,y,w,h };
	return rect;
}

void RectEdit(iceRect * rect, iceFloat x, iceFloat y, iceFloat w, iceFloat h) {
	rect->x = x; rect->y = y; rect->w = w; rect->h = h;
}

void RectMove(iceRect * rect, iceFloat x, iceFloat y)
{
	rect->x = x; rect->y = y;
}

void RectResize(iceRect *rect, iceFloat w, iceFloat h)
{
	rect->w = w; rect->h = h;
}

void RectShift(iceRect *rect, iceFloat x, iceFloat y)
{
	rect->x += x; rect->y += y;
}

// Vecto

// RAW

int ICE_DrawPoint(ICE_Game *game, iceVect vect, const iceColor color){
	ICE_RenderSetClearColor(game->render, color);
	return SDL_RenderDrawPoint(game->render, vect.x, vect.y);
}

int ICE_DrawLine(ICE_Game *game, iceVect vect1, iceVect vect2, const iceColor color){
	ICE_RenderSetClearColor(game->render, color);
	return SDL_RenderDrawLine(game->render, vect1.x, vect1.y, vect2.x, vect2.y);
}

int ICE_DrawRectangle(ICE_Game *game, iceRect rect, const iceColor color){
	ICE_RenderSetClearColor(game->render, color);
	return SDL_RenderDrawRect(game->render, &rect);
}

int ICE_DrawRectangleFill(ICE_Game *game, const iceRect rect, const iceColor color){
	ICE_RenderSetClearColor(game->render, color);
	return SDL_RenderFillRect(game->render, &rect);
}

// OPENGL LIKE

int ICE_DrawPointGL(ICE_Game *game, int x, int y, const iceColor color) {
	ICE_RenderSetClearColor(game->render, color);
	return SDL_RenderDrawPoint(game->render, x, y);
}

int ICE_DrawLineGL(ICE_Game *game, int x1, int y1, int x2, int y2, const iceColor color) {
	ICE_RenderSetClearColor(game->render, color);
	return SDL_RenderDrawLine(game->render, x1, y1, x2, y2);
}

int ICE_DrawRectangleGL(ICE_Game *game, iceRect rect, const iceColor color) {
	ICE_RenderSetClearColor(game->render, color);
	return SDL_RenderDrawRect(game->render, &rect);
}

int ICE_DrawRectangleFillGL(ICE_Game *game, const iceRect rect, const iceColor color) {
	ICE_RenderSetClearColor(game->render, color);
	return SDL_RenderFillRect(game->render, &rect);
}