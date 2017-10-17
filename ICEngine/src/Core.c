#include <SDL2/SDL.h>
#include "hdr/Core.h"
#include "hdr/TerminalColor.h"
#include "hdr/Game.h"
#include "hdr/Render.h"
#include "hdr/Input.h"

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

int ICE_GameLoop(ICE_Game(*call_create)(void), void(*call_update)(ICE_Game*), void(*call_destroy)(ICE_Game*))
{
	ICE_InitGameEngine();
	ICE_Game game = call_create();
	while (!game.input->quit)
	{
		ICE_RenderClear(game.render);
		ICE_InputReturn(game.input);
		call_update(&game);
		ICE_RenderPresent(game.render);
	}
	call_destroy(&game);
	ICE_CloseGameEngine();

	return 0;
}
