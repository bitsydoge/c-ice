#include "hdr/Core.h"
#include <SDL2/SDL.h>
#include "hdr/TerminalColor.h"
#include "hdr/Game.h"
#include "hdr/Render.h"
#include "hdr/TextureManager.h"

int ICE_InitGameEngine()
{
	ICE_TC_SaveColor();
	SDL_Init(SDL_INIT_VIDEO);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	return 0;
}

int ICE_CloseGameEngine()
{

	SDL_Quit();
	return 0;
}

void ICE_GameLoop(void(*call_create)(void), void(*call_update)(void), void(*call_destroy)(void))
{
	ICE_InitGameEngine();

	ICE_Game game = ICE_CreateApp("ICE", 500, 500);
	ICE_TextureManager text = ICE_CreateTextureManager();
	call_create();

	while (!game.input->quit)
	{
		call_update();
		while (text.nb_existing_texture<100)
			ICE_CreateTexture(&game, &text, "res/img/512.png", 0);

		ICE_InputReturn(game.input);
		ICE_RenderClear(game.render);
		for (int i = 0; i <text.nb_existing_texture; i++)
		{
			ICE_TextureRender(game.render, &text.texturepack[i], NULL, NULL);
			ICE_RenderPresent(game.render);
		}
	}

	call_destroy();

	ICE_DestroyApp(&game);

	ICE_CloseGameEngine();
}
