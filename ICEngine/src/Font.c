#include "hdr/Font.h"

#include <stdio.h>
#include <SDL2/SDL_ttf.h>
#include "hdr/TypesCore.h"
#include "hdr/Window.h"
#include "hdr/TypesGraphics.h"

extern ICE_Game game;

// Font load

void ICE_FontLoad(char *path) {
	for (int i = 0; i < 256; i++) {
		game.font.size[i] = TTF_OpenFont(path, i);
		if (!game.font.size)
			printf("%s\n", TTF_GetError());
	}
}