#include "Render.h"

#include "../Core/TypesCore.h"

extern ICE_Game game;

void ICE_Render_Color(const ICE_Color rgba_hex) {
	game.current->background = rgba_hex;
}