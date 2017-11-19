// Pong exemple without physic engine WIP (Help me learn how to structurate the engine)

#include <Core.h>

typedef struct{

	struct{
		int shift_y;
		double speed;
		int speed_max;
	} player;
	
	struct{
		int shift_y;
		double speed;
		int speed_max;
	} ennemy;

	struct{
		double speed;
		int dx;
		int dy;
	} ball;

} DATA0;

ICE_CREATE {
	ICE_Game game = ICE_GameCreate("ICE : Pong", 1280, 720); ICE_GameResizable(&game, ICE_False);
	DATA0 *data = ICE_AddData(&game, sizeof(DATA0));

	ICE_EntityManagerCreate(&game);
	ICE_EntityCreate(&game, 0);
	ICE_EntityCreate(&game, 0);
	ICE_EntityCreate(&game, 0);

	// Player
	ICE_EntitySetSize(&game, 0, 0, 20, 70);
	ICE_EntitySetPos(&game,0,0,20,game.camera.h/2-35);
	data->player.speed_max = 500;
	
	// Ennemy
	ICE_EntitySetSize(&game, 0, 1, 20, 70);
	ICE_EntitySetPos(&game, 0, 1, game.camera.w - 40, game.camera.h / 2 - 35);
	data->ennemy.speed_max = 500;
	
	// Ball
	ICE_EntitySetSize(&game, 0, 2, 20, 20);
	ICE_EntitySetPos(&game, 0, 2, game.camera.w / 2 - 10, game.camera.h / 2 - 10);
	data->ball.speed = 150;

	// Randomize ball movement
	while(data->ball.dx == 0)
	{
		data->ball.dx = ICE_Random(-1, 1);
		data->ball.dy = ICE_Random(-1, 1);
	}

	return game;
}

void Collision_Ball(ICE_Game *game)
{
	DATA0 *data = ICE_GetData(game, 0);
	ICE_Rect ballrect = ICE_EntityGetRect(game, 0, 2);
	
	// Top Bottom
	if (ballrect.y > game->camera.h-20 || ballrect.y < 0)
		data->ball.dy = -data->ball.dy;
}

void Player_Movement(ICE_Game *game){
	DATA0 *data = ICE_GetData(game, 0);
	
	// Player
	if (game->input->key[SDL_SCANCODE_S]) data->player.speed += 1000 * game->time.delta;
	if (game->input->key[SDL_SCANCODE_W]) data->player.speed += -1000 * game->time.delta;
	// Ennemy
	if (game->input->key[SDL_SCANCODE_UP]) data->ennemy.speed += -1000 * game->time.delta;
	if (game->input->key[SDL_SCANCODE_DOWN]) data->ennemy.speed += 1000 * game->time.delta;

	// Max Speed
	if (data->player.speed > data->player.speed_max)
		data->player.speed = data->player.speed_max;
	if (data->ennemy.speed > data->ennemy.speed_max)
		data->ennemy.speed = data->ennemy.speed_max;

	// Deceleration
	if (data->player.speed >= 1)
		data->player.speed -= 300 * game->time.delta;
	else if (data->player.speed <= -1)
		data->player.speed += 300 * game->time.delta;
	else
		data->player.speed = 0;

	if (data->ennemy.speed >= 1)
		data->ennemy.speed -= 300 * game->time.delta;
	else if (data->ennemy.speed <= -1)
		data->ennemy.speed += 300 * game->time.delta;
	else
		data->ennemy.speed = 0;

	ICE_EntityShiftPos(game, 0, 0, 0, data->player.speed);
	ICE_EntityShiftPos(game, 0, 1, 0, data->ennemy.speed);
	ICE_EntityShiftPos(game, 0, 2, data->ball.dx*data->ball.speed, data->ball.dy*data->ball.speed);
}

ICE_UPDATE {
	Player_Movement(game);
	Collision_Ball(game);
	ICE_DrawRectangleFill(game, ICE_EntityGetRect(game, 0,0), NewColor(255, 255, 255)); // Player
	ICE_DrawRectangleFill(game, ICE_EntityGetRect(game, 0, 1), NewColor(255, 255, 255)); // Ennemy
	ICE_DrawRectangleFill(game, ICE_EntityGetRect(game, 0, 2), NewColor(255, 255, 255)); // Ball
	ICE_DebugShowFpsTitle(game); 
}

ICE_DESTROY {

}

int main(){
	return ICE_GAME_RUN;
}
