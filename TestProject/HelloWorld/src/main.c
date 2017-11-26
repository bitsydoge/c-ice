#include <Core.h>
#define _CRTDBG_MAP_ALLOC 
#include <stdlib.h> 
#include <crtdbg.h>  

enum // Txt1
{
	txtHelloWorld = 0,
	txtFps
};

ICE_CREATE {
	iceGame game = iceGameCreate("ICE : Hello World", 800, 480);
	iceEntityManagerCreate(&game);
	iceFontLoad(&game, "res/ttf/FiraSans-Medium.ttf");
	iceTextureCreate(&game, 0, "res/img/pic.png");
	iceTextureCreate(&game, 0, "res/img/backxc.jpg");
	iceDrawSetColor(&game, iceColorNew(200, 40, 30));
	
	int actual = 0;
	for (int i = 0; i < 1; i++)
	{
		actual = iceEntityCreate(&game, 0);
		iceEntitySetTexture(&game, 0, actual, 0, 0);
		iceEntitySetSize(&game, 0, actual, 300, 500);
		iceEntitySetPos(&game, 0, actual, 0, 0);
	}
	iceLabelManagerCreate(&game);
	iceLabelCreate(&game, 0, iceVectNew(400,240),"Hello");
	iceLabelCreate(&game, 0, iceVectNew(50, 50), "Hello");

	// txtHelloWorld
	iceLabelSetText(&game, 0, txtHelloWorld, "Hello_Deux");
	iceLabelSetColor(&game, 0, txtHelloWorld, iceColorNew(100, 0, 200));
	iceLabelSetSize(&game, 0, txtHelloWorld, 100);
	iceLabelSetPos(&game, 0, txtHelloWorld, iceVectNew(0, 0));
	iceLabelIsInWorld(&game, 0, txtHelloWorld, 1);

	iceLabelSetSize(&game, 0, txtFps, 10);

	return game;
}

ICE_UPDATE {
	char buffer[256];
	sprintf(buffer, "FPS : %f", game->time.fps);
	iceLabelSetText(game, 0, txtFps, buffer);
	//iceTextureRenderCentered(game, 0, 0, NULL, (iceBox[]) { iceCameraWorldScreen(iceBoxNew(0, 0, 500, 750), &game->camera) });
	//iceTextureRenderCentered(game, 0, 1, NULL, (iceBox[]) { iceCameraWorldScreen(iceBoxNew(0, 0, iceTextureGetWidth(game, 0, 1), iceTextureGetHeight(game, 0, 1)), &game->camera) });
	//iceFontDraw(game, "Hello World", 80, iceVectNew(0, 0));
	
	iceDrawAllText(game);
	iceDrawAllEntity(game);

	if (game->input->key[SDL_SCANCODE_D] || game->input->key[SDL_SCANCODE_RIGHT]) iceCameraShiftPos(game, iceVectNew(100 * game->time.delta, 0));
	if (game->input->key[SDL_SCANCODE_A] || game->input->key[SDL_SCANCODE_LEFT]) iceCameraShiftPos(game, iceVectNew(-100 * game->time.delta, 0));
	if (game->input->key[SDL_SCANCODE_S] || game->input->key[SDL_SCANCODE_DOWN]) iceCameraShiftPos(game, iceVectNew(0, 100 * game->time.delta));
	if (game->input->key[SDL_SCANCODE_W] || game->input->key[SDL_SCANCODE_UP]) iceCameraShiftPos(game, iceVectNew(0, -100 * game->time.delta));
	if (game->input->key[SDL_SCANCODE_SPACE]) iceCameraMovePos(game, iceVectNew(0, 0), 100 * game->time.delta);


	

}

ICE_DESTROY {
}

int main(){
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	ICE_GAME_RUN;
	_CrtDumpMemoryLeaks();
	return 0;
}