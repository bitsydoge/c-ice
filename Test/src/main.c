#include <Core.h>
#include <Sound.h>
#include <Texture.h>
#include <Primitive.h>
#include <Camera.h>
#include "hdr/menu.h"

ICE_Game GameCreate(void){
	ICE_Game game = ICE_CreateGame("ICE : Indie \"C\" Engine", 500, 500); 
	ICE_CreateTexture(&game, 0, "res/img/logo.png");
	ICE_CreateTexture(&game, 0, "res/img/icon.png");
	ICE_CreateMusic(&game, "res/snd/music.ogg"); 
	ICE_CreateSound(&game, "res/snd/laser.wav");
	game.camera.x = 0; game.camera.y = 0; game.camera.w = 500; game.camera.h = 500;
	return game;
}

void MovementCamera(ICE_Game *game){
	if (game->input->key[SDL_SCANCODE_D])
		ICE_ShiftCamera(game, 50, 0);
	if (game->input->key[SDL_SCANCODE_A])
		ICE_ShiftCamera(game, -50, 0);
	if (game->input->key[SDL_SCANCODE_S])
		ICE_ShiftCamera(game, 0, 50);
	if (game->input->key[SDL_SCANCODE_W])
		ICE_ShiftCamera(game, 0, -50);
}

void GameUpdate(ICE_Game *game){
	// Substate menu test
	if (game->input->key[SDL_SCANCODE_ESCAPE])
		ICE_SubstateLoop(game, menu_create, menu_update, menu_destroy);

	// Camera Move
	MovementCamera(game);

	// Song / Sound test
	if (game->input->leftclic) {
		ICE_PlaySound(game, 0, 1);
		ICE_PlayMusic(game, 0);
	}

	// Background render
	ICE_Rect back = position_to_screen(NewRect(0, 0, 500, 500), &game->camera);
	ICE_TextureRender(game, 0, 0, NULL, &back);

	// Raw primitive test
	ICE_DrawRectangleFill(game, 
		position_to_screen(NewRect(0, 0, 200, 200), &game->camera), 
		NewColorA(100, 40, 180, 100));
	
	// Draw icon on the mouse
	ICE_Rect rect = {game->input->mousex, game->input->mousey, 100, 100};
	ICE_TextureRender(game, 0, 1, NULL, &rect);

	// Show icon on the center
	ICE_Rect rect2 = position_to_screen(NewRect(0, 0, 100, 100), &game->camera);
	ICE_TextureRender(game, 0, 1, NULL, &rect2);
}

void GameDestroy(ICE_Game *game){
	ICE_DestroyGame(game);
}

int main(int argc, char* args[]){
	return ICE_GameLoop(GameCreate, GameUpdate, GameDestroy);
}