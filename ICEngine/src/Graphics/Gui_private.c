#include "Gui_private.h"
#include "Gui.h"
#include "../Core/TypesCore.h"
#include "../Graphics/TypesGraphics.h"
#include "../Graphics/Texture.h"
#include "Texture_private.h"

extern ICE_Game GAME;
extern ICE_Core CORE;

void ICE_Gui_UpdateTexture(ICE_ID man, ICE_ID gui)
{
	ICE_Texture texture = { 0 };
	texture.handle = SDL_CreateTexture(CORE.window.render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, (int)GAME.current->object.gui_mngr[man].gui[gui].box.w, (int)GAME.current->object.gui_mngr[man].gui[gui].box.h);
	SDL_SetRenderTarget(CORE.window.render, texture.handle);
	SDL_SetTextureBlendMode(texture.handle, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(CORE.window.render, 0, 0, 0, 0);
	SDL_RenderClear(CORE.window.render);
	ICE_Box box2 = GAME.current->object.gui_mngr[man].gui[gui].box;
	box2.x = 0; box2.y = 0;

	// TYPE DRAW

	if(GAME.current->object.gui_mngr[man].gui[gui].type == ICE_GUITYPE_RECTANGLE)
		ICE_Gui_Rect(ICE_Texture_Get(GAME.current->object.gui_mngr[man].gui[gui].texturemanager_index, GAME.current->object.gui_mngr[man].gui[gui].texture_index), box2);

	if (GAME.current->object.gui_mngr[man].gui[gui].type == ICE_GUITYPE_IMAGE)
		ICE_Texture_RenderEx(
			ICE_Texture_Get(GAME.current->object.gui_mngr[man].gui[gui].texturemanager_index, GAME.current->object.gui_mngr[man].gui[gui].texture_index),
			NULL,
			&GAME.current->object.gui_mngr[man].gui[gui].box,
			0
		);
	
	SDL_SetRenderTarget(CORE.window.render, NULL);
	if (GAME.current->object.gui_mngr[man].gui[gui].texture_cache.handle)
		SDL_DestroyTexture(GAME.current->object.gui_mngr[man].gui[gui].texture_cache.handle);
	GAME.current->object.gui_mngr[man].gui[gui].texture_cache = texture;
}

// Deprecated
// Unoptimized function
void ICE_Gui_Rect(ICE_Texture * texture, ICE_Box rect)
{
	ICE_Box src, dst;
	int wtext3 = texture->w / 3;
	int htext3 = texture->h / 3;

	src.w = wtext3; src.h = htext3;

	// CENTER

	src.x = wtext3; src.y = htext3;
	dst.x = rect.x + wtext3; dst.y = rect.y + htext3;
	dst.w = rect.w - (wtext3) * 2; dst.h = rect.h - (htext3) * 2;

	ICE_Texture_RenderEx(texture, &src, &dst, 0);

	dst.w = wtext3; dst.h = htext3;

	// UPMID

	src.x = wtext3; src.y = 0; dst.y = rect.y; dst.x = rect.x + wtext3;
	dst.w = rect.w - (wtext3 * 2);

	ICE_Texture_RenderEx(texture, &src, &dst, 0);

	dst.w = wtext3; dst.h = htext3;

	// LEFTMID

	src.x = 0; src.y = htext3;
	dst.x = rect.x; dst.y = rect.y + htext3;
	dst.h = rect.h - (htext3 * 2);

	ICE_Texture_RenderEx(texture, &src, &dst, 0);

	dst.w = wtext3; dst.h = htext3;

	// RIGHT MID

	src.x = wtext3 * 2; src.y = htext3;
	dst.x = rect.x + rect.w - wtext3; dst.y = rect.y + htext3;
	dst.h = rect.h - (htext3 * 2);

	ICE_Texture_RenderEx(texture, &src, &dst, 0);

	dst.w = wtext3; dst.h = htext3;


	// DOWNMID

	src.x = wtext3; src.y = htext3 * 2; dst.y = rect.y + rect.h - htext3; dst.x = rect.x + wtext3;
	dst.w = rect.w - (wtext3 * 2);

	ICE_Texture_RenderEx(texture, &src, &dst, 0);

	dst.w = wtext3; dst.h = htext3;

	// UPLEFT

	src.x = 0; src.y = 0;
	dst.x = rect.x; dst.y = rect.y;

	ICE_Texture_RenderEx(texture, &src, &dst, 0);

	dst.w = wtext3;

	// UPRIGHT

	src.x = wtext3 * 2; src.y = 0;
	dst.x = rect.x + rect.w - wtext3; dst.y = rect.y;

	ICE_Texture_RenderEx(texture, &src, &dst, 0);

	dst.h = htext3;

	// DOWNLEFT

	src.x = 0; src.y = htext3 * 2;
	dst.x = rect.x; dst.y = rect.y + rect.h - htext3;

	ICE_Texture_RenderEx(texture, &src, &dst, 0);

	// DOWNRIGHT

	src.x = wtext3 * 2; src.y = htext3 * 2;
	dst.x = rect.x + rect.w - wtext3; dst.y = rect.y + rect.h - htext3;

	ICE_Texture_RenderEx(texture, &src, &dst, 0);
}