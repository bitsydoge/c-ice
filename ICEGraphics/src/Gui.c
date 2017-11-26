#include "hdr/Gui.h"

// Create GUI Object

void iceGuiCreateManager(iceGame *game)
{
	iceGuiManager gui_manager = { 0 };
	gui_manager.array_size = ICE_DEFAULT_GUI_SIZE;
	gui_manager.gui = calloc(gui_manager.array_size, sizeof(iceGui));
	game->guimanager_size++;
	game->guimanager = realloc(game->guimanager, game->guimanager_size * sizeof(iceGuiManager));
	game->guimanager[game->guimanager_size - 1] = gui_manager;
	printf("GuiManager number %d created \n", game->guimanager_size - 1);
}

void iceGuiCreate(iceGame *game, int man)
{
	iceGui gui = { 0 };

	

	game->guimanager[man].gui[game->guimanager[man].nb_existing] = gui;
	game->guimanager[man].nb_existing++;


	if (game->guimanager[man].array_size <= game->guimanager[man].nb_existing) {
		iceTermSetColor(iceLIGHTCYAN);
		printf("Extending GuiManager size to %d \n", game->guimanager[man].array_size * 2);
		iceTermResetColor();
		game->guimanager[man].gui = realloc(game->guimanager[man].gui, sizeof(iceGui)*(game->guimanager[man].array_size * 2));
		game->guimanager[man].array_size *= 2;
	}
}

void iceGuiSetTexture(iceGame *game, int man, int gui, int texture_man, int texture)
{
	game->guimanager[man].gui[gui].texture_nb = texture;
	game->guimanager[man].gui[gui].texturemanager = texture_man;
}

void iceGuiSetBox(iceGame *game, int man, int gui, iceBox box)
{
	game->guimanager[man].gui[gui].box = box;
}

void iceGuiSetPos(iceGame *game, int man, int gui, iceVect pos)
{
	game->guimanager[man].gui[gui].box.p = pos;
}

void iceGuiSetSize(iceGame *game, int man, int gui, iceFloat w, iceFloat h)
{
	game->guimanager[man].gui[gui].box.w = w;
	game->guimanager[man].gui[gui].box.h = h;
}

// Deprecated
// Unoptimized function
void iceGuiRect(iceGame *game, int man, int text, iceBox rect)
{
	iceBox src, dst;
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
