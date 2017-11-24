#include "hdr/Gui.h"


void iceGuiRect(iceGame *game, int man, int text, iceRect rect)
{
	iceRect src, dst;
	int wtext3 = game->texturemanager[man].texture[text].w / 3;
	int htext3 = game->texturemanager[man].texture[text].h / 3;

	src.w = wtext3; src.h = htext3;

	// CENTER

	src.p.x = wtext3; src.p.y = htext3;
	dst.p.x = rect.p.x + wtext3; dst.p.y = rect.p.y + htext3;
	dst.w = rect.w - (wtext3) * 2; dst.h = rect.h - (htext3) * 2;

	iceTextureRender(game, man, text, &src, &dst);

	dst.w = wtext3; dst.h = htext3;

	// UPMID

	src.p.x = wtext3; src.p.y = 0; dst.p.y = rect.p.y; dst.p.x = rect.p.x + wtext3;
	dst.w = rect.w - (wtext3 * 2);

	iceTextureRender(game, man, text, &src, &dst);

	dst.w = wtext3; dst.h = htext3;

	// LEFTMID

	src.p.x = 0; src.p.y = htext3;
	dst.p.x = rect.p.x; dst.p.y = rect.p.y + htext3;
	dst.h = rect.h - (htext3 * 2);

	iceTextureRender(game, man, text, &src, &dst);

	dst.w = wtext3; dst.h = htext3;

	// RIGHT MID

	src.p.x = wtext3 * 2; src.p.y = htext3;
	dst.p.x = rect.p.x + rect.w - wtext3; dst.p.y = rect.p.y + htext3;
	dst.h = rect.h - (htext3 * 2);

	iceTextureRender(game, man, text, &src, &dst);

	dst.w = wtext3; dst.h = htext3;


	// DOWNMID

	src.p.x = wtext3; src.p.y = htext3 * 2; dst.p.y = rect.p.y + rect.h - htext3; dst.p.x = rect.p.x + wtext3;
	dst.w = rect.w - (wtext3 * 2);

	iceTextureRender(game, man, text, &src, &dst);

	dst.w = wtext3; dst.h = htext3;

	// UPLEFT

	src.p.x = 0; src.p.y = 0;
	dst.p.x = rect.p.x; dst.p.y = rect.p.y;

	iceTextureRender(game, man, text, &src, &dst);

	dst.w = wtext3;

	// UPRIGHT

	src.p.x = wtext3 * 2; src.p.y = 0;
	dst.p.x = rect.p.x + rect.w - wtext3; dst.p.y = rect.p.y;

	iceTextureRender(game, man, text, &src, &dst);

	dst.h = htext3;

	// DOWNLEFT

	src.p.x = 0; src.p.y = htext3 * 2;
	dst.p.x = rect.p.x; dst.p.y = rect.p.y + rect.h - htext3;

	iceTextureRender(game, man, text, &src, &dst);

	// DOWNRIGHT

	src.p.x = wtext3 * 2; src.p.y = htext3 * 2;
	dst.p.x = rect.p.x + rect.w - wtext3; dst.p.y = rect.p.y + rect.h - htext3;

	iceTextureRender(game, man, text, &src, &dst);
}
