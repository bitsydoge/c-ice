#include "Render.h"

#include "../Core/TypesCore.h"

extern ICE_Game GAME;

void ICE_Render_Color(const ICE_Color rgba_hex) {
	GAME.current->background = rgba_hex;
}