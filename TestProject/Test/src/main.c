#include <Core.h>
#include "hdr/data.h"
#include "hdr/control.h"

ICE_CREATE {
	iceGame game = iceGameCreate("ICE : Indie \"C\" Engine", 500, 500);

	// Load Assets
	iceTextureCreate(&game, 0, "res/img/logo.png");
	iceTextureCreate(&game, 0, "res/img/gui.png");
	iceTextureCreate(&game, 0, "res/img/sprite.png");
	iceMusicCreate(&game, "res/snd/music.ogg");
	iceSoundCreate(&game, "res/snd/laser.wav");
	iceMusicPlay(&game, 0, 1);
	iceFontLoad(&game, "res/ttf/FiraMono-Medium.ttf");

	// Load Data and Variables
	DATA0 *data = iceAddData(&game, sizeof(DATA0)); // Add DATA0
	iceAddData(&game, sizeof(DATA1)); // Add DATA1
	data->speed_camera = 250;
	// Creating Entity
	int manager_nb = iceEntityManagerCreate(&game);
	for(int i = 0; i<10000; i++){
		int entity_nb = iceEntityCreate(&game, 0);
		iceEntitySetTexture(&game, manager_nb, entity_nb, 0, 2);
		iceEntitySetPos(&game, manager_nb, entity_nb, iceRandomInt(-5000, 5000), iceRandomInt(-5000, 5000));
		int nb = iceRandomInt(20, 100);
		iceEntitySetSize(&game, manager_nb, entity_nb, nb, nb);
	}
	return game;
}

ICE_UPDATE {
	// Logical
	Control(game);
	for (int i = 0; i < game->entitymanager_size; i++) // Move every entity from every manager
		for (int j = 0; j < game->entitymanager[i].nb_existing; j++) // the center of the map
			iceEntityMovePos(game, i, j, 0, 0, 70 * game->time.delta);
	// Graphical
	iceTextureRenderCentered(game, 0, 0, NULL, (iceBox[]) { iceCameraWorldScreen(iceBoxNew(0, 0, 500, 500), &game->camera) });
	iceEntityDrawAll(game); // Draw every Entity
	iceGuiRect(game, 0, 1, iceBoxNew(0, 0, game->camera.w, 32));
	iceDebugShowFps(game);
}

ICE_DESTROY {

}

int main(){
	return ICE_GAME_RUN;
}
