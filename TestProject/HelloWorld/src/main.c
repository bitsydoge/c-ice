#include <Core.h>

ICE_CREATE {
	iceGame game = iceGameCreate("ICE : Hello World", 800, 480);
	iceFontLoad(&game, "res/ttf/FiraSans-Medium.ttf");
	iceTextureCreate(&game, 0, "res/img/pic.png");
	iceTextureCreate(&game, 0, "res/img/backxc.jpg");
	iceDrawSetColor(&game, iceColorNew(200, 40, 30));
	iceTextManagerCreate(&game);
	
	iceTextCreate(&game, 0, iceVectNew(400,240),"Hello");
	iceTextSetLabel(&game, 0, 0, "Hello_Deux");
	iceTextSetColor(&game, 0, 0, iceColorNew(100, 0, 200));
	iceTextSetSize(&game, 0, 0, 100);
	iceTextSetPos(&game, 0, 0, iceVectNew(0, 0));
	iceTextIsFixedToWorld(&game, 0, 0, 0);

	return game;
}

ICE_UPDATE {
	static int test;
	//iceTextureRenderCentered(game, 0, 0, NULL, (iceBox[]) { iceCameraWorldScreen(iceBoxNew(0, 0, 500, 750), &game->camera) });
	//iceTextureRenderCentered(game, 0, 1, NULL, (iceBox[]) { iceCameraWorldScreen(iceBoxNew(0, 0, iceTextureGetWidth(game, 0, 1), iceTextureGetHeight(game, 0, 1)), &game->camera) });
	//iceFontDraw(game, "Hello World", 80, iceVectNew(0, 0));
	iceDrawAllText(game);
	
	if (game->input->key[SDL_SCANCODE_D] || game->input->key[SDL_SCANCODE_RIGHT]) iceCameraShiftPos(game, iceVectNew(100 * game->time.delta, 0));
	if (game->input->key[SDL_SCANCODE_A] || game->input->key[SDL_SCANCODE_LEFT]) iceCameraShiftPos(game, iceVectNew(-100 * game->time.delta, 0));
	if (game->input->key[SDL_SCANCODE_S] || game->input->key[SDL_SCANCODE_DOWN]) iceCameraShiftPos(game, iceVectNew(0, 100 * game->time.delta));
	if (game->input->key[SDL_SCANCODE_W] || game->input->key[SDL_SCANCODE_UP]) iceCameraShiftPos(game, iceVectNew(0, -100 * game->time.delta));
	if (game->input->key[SDL_SCANCODE_SPACE]) iceCameraMovePos(game, iceVectNew(0, 0), 100 * game->time.delta);


	iceDrawAllEntity(game);

}

ICE_DESTROY {
}

int main(){
	return ICE_GAME_RUN;
}