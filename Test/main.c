#include <Core.h>

ICE_Game GameCreate(void)
{
	ICE_Game game = ICE_CreateApp("ICE : Indie \"C\" Engine", 768, 768);
	ICE_CreateTextureManager(&game);
	for(int i = 0; i < 1; i++)
		ICE_CreateTexture(&game, &game.tex_man[0], "res/img/logo.png", 0);
	return game;
}

void GameUpdate(ICE_Game *game)
{
	for (int i = 0; i < 1; i++)
			ICE_TextureRender(game->render, &game->tex_man[0].texturepack[i], NULL, NULL);
}

void GameDestroy(ICE_Game *game)
{
	ICE_DestroyGame(game);
}

int main(int argc, char* args[])
{
	return ICE_GameLoop(GameCreate, GameUpdate, GameDestroy);
}