#include "hdr/Primitive.h"

// RECT

ICE_Rect NewRect(int x, int y, int w, int h){
	ICE_Rect rect = { x,y,w,h };
	return rect;
}

void EditRect(ICE_Rect * rect, int x, int y, int w, int h) {
	rect->x = x; rect->y = y; rect->w = w; rect->h = h;
}

void MoveRect(ICE_Rect * rect, int x, int y)
{
	rect->x = x; rect->y = y;
}

void ResizeRect(ICE_Rect *rect, int w, int h)
{
	rect->w = w; rect->h = h;
}

void ShiftRect(ICE_Rect *rect, int x, int y)
{
	rect->x += x; rect->y += y;
}

// POINT

ICE_Point NewPoint(int x, int y) {
	ICE_Point point = {x,y};
	return point;
}

void MovePoint(ICE_Point * point, int x, int y) {
	point->x = x; point->y = y;
}

void ShiftPoint(ICE_Point *point, int x, int y)
{
	point->x += x; point->y += y;
}

// RAW

int ICE_DrawPoint(ICE_Game *game, int x, int y, const ICE_Color color){
	ICE_SetRenderClearColor(game->render, color);
	return SDL_RenderDrawPoint(game->render, x, y);
}

int ICE_DrawLine(ICE_Game *game, int x1, int y1, int x2, int y2, const ICE_Color color){
	ICE_SetRenderClearColor(game->render, color);
	return SDL_RenderDrawLine(game->render, x1, y1, x2, y2);
}

int ICE_DrawRectangle(ICE_Game *game, ICE_Rect rect, const ICE_Color color){
	ICE_SetRenderClearColor(game->render, color);
	return SDL_RenderDrawRect(game->render, &rect);
}

int ICE_DrawRectangleFill(ICE_Game *game, const ICE_Rect rect, const ICE_Color color){
	ICE_SetRenderClearColor(game->render, color);
	return SDL_RenderFillRect(game->render, &rect);
}

// OPENGL LIKE

int ICE_DrawPointGL(ICE_Game *game, int x, int y, const ICE_Color color) {
	ICE_SetRenderClearColor(game->render, color);
	return SDL_RenderDrawPoint(game->render, x, y);
}

int ICE_DrawLineGL(ICE_Game *game, int x1, int y1, int x2, int y2, const ICE_Color color) {
	ICE_SetRenderClearColor(game->render, color);
	return SDL_RenderDrawLine(game->render, x1, y1, x2, y2);
}

int ICE_DrawRectangleGL(ICE_Game *game, ICE_Rect rect, const ICE_Color color) {
	ICE_SetRenderClearColor(game->render, color);
	return SDL_RenderDrawRect(game->render, &rect);
}

int ICE_DrawRectangleFillGL(ICE_Game *game, const ICE_Rect rect, const ICE_Color color) {
	ICE_SetRenderClearColor(game->render, color);
	return SDL_RenderFillRect(game->render, &rect);
}