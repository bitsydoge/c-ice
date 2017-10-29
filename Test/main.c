#include <Core.h>
#include <Sound.h>
#include <Texture.h>

ICE_Game GameCreate(void){
	ICE_Game game = ICE_CreateGame("ICE : Indie \"C\" Engine", 500, 500); 
	ICE_CreateTexture(&game, 0, "res/img/logo.png");
	ICE_CreateTexture(&game, 0, "res/img/icon.png");
	ICE_CreateMusic(&game, "res/snd/music.ogg"); 
	ICE_CreateSound(&game, "res/snd/laser.wav");
	ICE_PlayMusic(&game, 0); 
	return game;
}

void GameUpdate(ICE_Game *game){
	ICE_TextureRender(game, 0, 0, NULL, NULL); // Render background
	ICE_Rect rect = {game->input->mousex, game->input->mousey, 100, 100};
	ICE_TextureRender(game, 0, 1, NULL, &rect); // Render image on mouse
	if (game->input->leftclic)
		for (int i = 0; i < game->soundmanager.size_musicpack; i++)
			ICE_PlaySound(game, i, 1);
}

void GameDestroy(ICE_Game *game){
	ICE_DestroyGame(game);
}

int main(int argc, char* args[]){
	return ICE_GameLoop(GameCreate, GameUpdate, GameDestroy);
}