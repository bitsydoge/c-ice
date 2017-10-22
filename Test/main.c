#include <Core.h>
#include <TextureManager.h>

ICE_Game GameCreate(void)
{
	ICE_Game game = ICE_CreateApp("ICE : Indie \"C\" Engine", 768, 768); // Create the Game Manager
	ICE_CreateTextureManager(&game); // Create a Texture Manager
	ICE_CreateTexture(&game, &game.tex_man[0], "res/img/logo.png", 0); // Create a Texture in the First Manager
	return game;
}

void GameUpdate(ICE_Game *game)
{
	ICE_TextureRender(game->render, &game->tex_man[0].texturepack[0], NULL, NULL); // Render the Texture Loaded
}

void GameDestroy(ICE_Game *game)
{
	ICE_DestroyGame(game);
}

int main(int argc, char* args[])
{
	return ICE_GameLoop(GameCreate, GameUpdate, GameDestroy);
}