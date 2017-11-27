#include <Core.h>

enum // Label in manager 0
{
	labelTest1 = 0,
	labelFPS
};

enum // Texture in manager 0
{
	textWidow = 0,
	textIcon
};

enum // Gui in manager 0
{
	guiTest = 0
};

enum // Entity in manager 0
{
	entityWidow = 0
};

typedef struct
{
	iceVect direction;

} DATA_WIDOW;

ICE_CREATE {

	iceGame game = iceGameCreate("ICE : Hello World", 800, 480);
	SDL_DisplayMode dm;
	SDL_GetCurrentDisplayMode(0, &dm);
	//iceWindowSetSize(&game, dm.w, dm.h);

	// Properties
	iceDrawSetColor(&game, iceColorNew(50, 40, 30));// 
	//iceWindowFullscreen(&game, iceTrue); // Widows is not resizable

	// Manager
	iceTextureManagerCreate(&game);
	iceSoundManagerCreate(&game);
	iceEntityManagerCreate(&game);
	iceLabelManagerCreate(&game);
	iceGuiManagerCreate(&game);
	
	// Texture Create
	iceTextureCreate(&game, 0, "res/img/pic.png");
	iceTextureCreate(&game, 0, "res/img/gui.png");
	
	// Font Create
	iceFontLoad(&game, "res/ttf/FiraSans-Medium.ttf");

	// Entity Create
	for (int i = 0; i <1; i++)
	{
		int actual = iceEntityCreate(&game, 0);
		iceEntitySetTexture(&game, 0, actual, 0, textWidow);
		iceEntitySetSize(&game, 0, actual, 30, 50);
		iceEntitySetPos(&game, 0, actual, iceRandomInt(-10000,10000), iceRandomInt(-10000, 10000));
		DATA_WIDOW *data = iceDataEntityAdd(&game, 0, actual, sizeof(DATA_WIDOW));
		data->direction = iceVectNew(iceRandomInt(-10000, 10000), iceRandomInt(-10000, 10000));
	}
	
	// Label Create 
	  //Label 1
	iceLabelCreate(&game, 0, iceVectNew(400,240),"OnWorld");
	iceLabelSetText(&game, 0, labelTest1, "One Shot, One kill !");
	iceLabelSetColor(&game, 0, labelTest1, iceColorNew(200, 0, 100));
	iceLabelSetSize(&game, 0, labelTest1, 50);
	iceLabelSetPos(&game, 0, labelTest1, iceVectNew(0, -270));
	iceLabelIsInWorld(&game, 0, labelTest1, 1);
	  // Label 2
	iceLabelCreate(&game, 0, iceVectNew(30, 10), "OnScreen");
	iceLabelSetSize(&game, 0, labelFPS, 10);

	// Gui Create
	iceGuiCreate(&game, 0);
	iceGuiSetBox(&game, 0, guiTest, iceBoxNew(0, 0, game.camera.w, 40));
	iceGuiSetTexture(&game, 0, guiTest, 0, textIcon);
	//iceGuiCreateTextureCache(&game, 0, 0);
	return game;
}

ICE_UPDATE {
	//iceDebugShowFpsTitle(game);
	iceGuiSetBox(game, 0, guiTest, iceBoxNew(0, 0, game->camera.w, 40));

for (int i = 0; i < game->entitymanager[0].nb_existing; i++)
{
	DATA_WIDOW *data = iceDataEntityGet(game, 0, i, 0);
	iceEntityMovePos(game, 0, i, data->direction.x, data->direction.y, 100 * game->time.delta);
}
	

	if (game->input->key[SDL_SCANCODE_D] || game->input->key[SDL_SCANCODE_RIGHT]) iceCameraShiftPos(game, iceVectNew(1000 * game->time.delta, 0));
	if (game->input->key[SDL_SCANCODE_A] || game->input->key[SDL_SCANCODE_LEFT]) iceCameraShiftPos(game, iceVectNew(-1000 * game->time.delta, 0));
	if (game->input->key[SDL_SCANCODE_S] || game->input->key[SDL_SCANCODE_DOWN]) iceCameraShiftPos(game, iceVectNew(0, 1000 * game->time.delta));
	if (game->input->key[SDL_SCANCODE_W] || game->input->key[SDL_SCANCODE_UP]) iceCameraShiftPos(game, iceVectNew(0, -1000 * game->time.delta));
	if (game->input->key[SDL_SCANCODE_SPACE]) iceCameraMovePos(game, iceVectNew(0, 0), 100 * game->time.delta);
}

ICE_DESTROY {
}

int main(){
	ICE_GAME_RUN;
	return 0;
}