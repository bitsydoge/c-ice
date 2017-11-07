#include <Core.h>

#include "hdr/menu.h"
#include "hdr/data.h"


ICE_Game GameCreate(void){
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
	for(int i = 0; i<20000; i++){
		int entity_nb = ICE_CreateEntity(&game, 0);
		ICE_SetTextureEntity(&game, manager_nb, entity_nb, 0, 2);
		ICE_SetEntityPosition(&game, manager_nb, entity_nb, ICE_Random(-5000, 5000), ICE_Random(-5000, 5000));
		int nb = ICE_Random(20, 100);
		ICE_SetEntitySize(&game, manager_nb, entity_nb, nb, nb);
	}

	// End
	return game;
}

void Control(ICE_Game *game){
	DATA0 *data = ICE_GetData(game, 0); // Make DATA0 avaible in the scope
	if (game->input->key[SDL_SCANCODE_D] || game->input->key[SDL_SCANCODE_RIGHT]) ICE_ShiftCamera(game, data->speed_camera, 0);
	if (game->input->key[SDL_SCANCODE_A] || game->input->key[SDL_SCANCODE_LEFT]) ICE_ShiftCamera(game, -data->speed_camera, 0);
	if (game->input->key[SDL_SCANCODE_S] || game->input->key[SDL_SCANCODE_DOWN]) ICE_ShiftCamera(game, 0, data->speed_camera);
	if (game->input->key[SDL_SCANCODE_W] || game->input->key[SDL_SCANCODE_UP]) ICE_ShiftCamera(game, 0, -data->speed_camera);
	if (game->input->key[SDL_SCANCODE_SPACE]) ICE_MoveCamera(game, 0, 0, data->speed_camera);
	if (game->input->key[SDL_SCANCODE_ESCAPE]) ICE_SubstateLoop(game, menu_create, menu_update, menu_destroy);
}

void GameUpdate(ICE_Game *game){
	Control(game);
	ICE_TextureRender(game, 0, 0, NULL,(ICE_Rect[]){position_to_screen(NewRect(0, 0, 500, 500), &game->camera)});
	ICE_FontDraw(game, "*", 20, position_to_screen(NewRect(-500, -750, 0, 0), &game->camera));
	
	ICE_DrawEntity(game);
	
	ICE_GuiRect(game, 0, 1, NewRect(0, 0, game->camera.w, 32));
	char gh[100];
	sprintf(gh, "%f", game->time.fps);
	ICE_FontDraw(game, gh, 20, NewRect(100, 50, 0, 0));


	for (int i = 0; i < game->entitymanager_size; i++)
		for (int j = 0; j < game->entitymanager[i].nb_existing; j++)
		{
			ICE_MoveEntityPosition(game, i, j, 0, 0, 70);
		}
}

void GameDestroy(ICE_Game *game){
	ICE_DestroyGame(game);
}

int main(int argc, char* args[]){
	return ICE_GameLoop(GameCreate, GameUpdate, GameDestroy);
}