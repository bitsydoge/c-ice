#include <Core.h>
#include "hdr/menu.h"
#include "hdr/data.h"
#include "hdr/control.h"

ICE_CREATE {
	ICE_Game game = ICE_CreateGame("ICE : Indie \"C\" Engine", 500, 500); 
	
	// Load Assets
	ICE_CreateTexture(&game, 0, "res/img/logo.png");
	ICE_CreateTexture(&game, 0, "res/img/gui.png");
	ICE_CreateTexture(&game, 0, "res/img/sprite.png");
	ICE_CreateMusic(&game, "res/snd/music.ogg"); 
	ICE_CreateSound(&game, "res/snd/laser.wav");
	ICE_PlayMusic(&game, 0, 1);
	ICE_FontLoad(&game, "res/ttf/FiraMono-Medium.ttf");
	
	// Load Data and Variables
	DATA0 *data = ICE_AddData(&game, sizeof(DATA0)); // Add DATA0
	ICE_AddData(&game, sizeof(DATA1)); // Add DATA1
	data->speed_camera = 250;
	// Creating Entity
	int manager_nb = ICE_CreateEntityManager(&game);
	for(int i = 0; i<10000; i++){
		int entity_nb = ICE_CreateEntity(&game, 0);
		ICE_SetTextureEntity(&game, manager_nb, entity_nb, 0, 2);
		ICE_SetEntityPosition(&game, manager_nb, entity_nb, ICE_Random(-5000, 5000), ICE_Random(-5000, 5000));
		int nb = ICE_Random(20, 100);
		ICE_SetEntitySize(&game, manager_nb, entity_nb, nb, nb);
	}
	return game;
}

ICE_UPDATE {
	// Logical
	Control(game);
	for (int i = 0; i < game->entitymanager_size; i++) // Move every entity from every manager
		for (int j = 0; j < game->entitymanager[i].nb_existing; j++) // the center of the map
			ICE_MoveEntityPosition(game, i, j, 0, 0, 70);

	// Graphical
	ICE_TextureRender(game, 0, 0, NULL,(ICE_Rect[]){position_to_screen(NewRect(0, 0, 500, 500), &game->camera)});
	ICE_DrawEntity(game); // Draw every Entity
	ICE_GuiRect(game, 0, 1, NewRect(0, 0, game->camera.w, 32));
	ICE_DebugShowFps(game);
}

ICE_DESTROY {

}

int main(){
	return ICE_GAME_RUN;
}
