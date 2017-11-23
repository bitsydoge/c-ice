// Pong exemple without physic engine WIP (Help me learn how to structurate the engine)

#include <Core.h>

enum winner { NONE, PLAYER, ENNEMY };

typedef struct{

	struct{
		int shift_y;
		double speed;
		int speed_max;
		int score;
	} player;
	
	struct{
		int shift_y;
		double speed;
		int speed_max;
		int score;
	} ennemy;

	struct{
		double speed;
		float dx;
		float dy;
	} ball;

	enum winner win;

} DATA0;

ICE_CREATE {
	iceGame game = iceGameCreate("ICE : Pong", 960, 480); iceGameResizable(&game, iceFalse);
	DATA0 *data = iceAddData(&game, sizeof(DATA0));
	// Entity Create
	iceEntityManagerCreate(&game);
	iceEntityCreate(&game, 0);
	iceEntityCreate(&game, 0);
	iceEntityCreate(&game, 0);
	// Player
	iceEntitySetSize(&game, 0, 0, 20, 70);
	iceEntitySetPos(&game,0,0,20,game.camera.h/2-35);
	data->player.speed_max = 300;
	// Ennemy
	iceEntitySetSize(&game, 0, 1, 20, 70);
	iceEntitySetPos(&game, 0, 1, game.camera.w - 40, game.camera.h / 2 - 35);
	data->ennemy.speed_max = 300;
	// Ball
	iceEntitySetSize(&game, 0, 2, 20, 20);
	iceEntitySetPos(&game, 0, 2, game.camera.w / 2 - 10, game.camera.h / 2 - 10);
	data->ball.speed = 100;
	// Randomize ball movement
	while(data->ball.dx == 0){
		data->ball.dx = iceRandom(-30000, 30000)/10000.0f;
		data->ball.dy = iceRandom(-20000, 20000)/10000.0f;
	}
	return game;
}

void Collision_Ball(iceGame *game){
	DATA0 *data = iceGetData(game, 0);
	iceRect ballrect = iceEntityGetRect(game, 0, 2);
	// Top Bottom
	if (ballrect.y > game->camera.h-20 || ballrect.y < 0)
		data->ball.dy = -data->ball.dy;
	// Win 
	if (ballrect.x < 0)
		data->win = ENNEMY;
	if (ballrect.x > game->camera.w+20)
		data->win = PLAYER;
	// Collision players
	iceRect ballplayer = iceEntityGetRect(game, 0, 0);
	iceRect ballennemy = iceEntityGetRect(game, 0, 1);
	if (rect_align_collision(ballplayer.x, ballplayer.y, ballplayer.w, ballplayer.h, ballrect.x, ballrect.y, ballrect.w, ballrect.h)){
		data->ball.dx = -data->ball.dx;
		data->ball.dy = iceRandom(-2000, 2000)/1000.0f;
		data->ball.speed += iceRandom(1, 25);
	}
	if (rect_align_collision(ballennemy.x, ballennemy.y, ballennemy.w, ballennemy.h, ballrect.x, ballrect.y, ballrect.w, ballrect.h)){
		data->ball.dx = -data->ball.dx;
		data->ball.dy = iceRandom(-2000, 2000) / 1000.0f;
		data->ball.speed += iceRandom(1, 25);
	}
}

void Player_Movement(iceGame *game){
	DATA0 *data = iceGetData(game, 0);
	// Player
	if (game->input->key[SDL_SCANCODE_S]) data->player.speed += 2000 * game->time.delta;
	if (game->input->key[SDL_SCANCODE_W]) data->player.speed -= 2000 * game->time.delta;
	// Ennemy
	if (game->input->key[SDL_SCANCODE_UP]) data->ennemy.speed -= 2000 * game->time.delta;
	if (game->input->key[SDL_SCANCODE_DOWN]) data->ennemy.speed += 2000 * game->time.delta;
	// Reset
	if (game->input->key[SDL_SCANCODE_SPACE]) 
		iceEntitySetPos(game, 0, 2, game->camera.w / 2 - 10, game->camera.h / 2 - 10);
	// Max Speed
	if (data->player.speed > data->player.speed_max)
		data->player.speed = data->player.speed_max;
	if (data->ennemy.speed > data->ennemy.speed_max)
		data->ennemy.speed = data->ennemy.speed_max;
	// Deceleration
	if (data->player.speed >= 1)
		data->player.speed -= 500 * game->time.delta;
	else if (data->player.speed <= -1)
		data->player.speed += 500 * game->time.delta;
	else
		data->player.speed = 0;
	if (data->ennemy.speed >= 1)
		data->ennemy.speed -= 500 * game->time.delta;
	else if (data->ennemy.speed <= -1)
		data->ennemy.speed += 500 * game->time.delta;
	else
		data->ennemy.speed = 0;
	iceEntityShiftPos(game, 0, 0, 0, data->player.speed);
	iceEntityShiftPos(game, 0, 1, 0, data->ennemy.speed);
	iceEntityShiftPos(game, 0, 2, data->ball.dx*data->ball.speed, data->ball.dy*data->ball.speed);
}

void Victory_Condition(iceGame *game){
	DATA0 *data = iceGetData(game, 0);
	char buffer[200];
	sprintf(buffer, "Player : %d, Ennemy : %d", data->player.score, data->ennemy.score);
	iceGameTitle(game, buffer);
	if (data->win){
		iceEntitySetPos(game, 0, 2, game->camera.w / 2 - 10, game->camera.h / 2 - 10);
		data->ball.speed = 150;
		if (data->win == PLAYER)
			data->player.score++;
		if (data->win == ENNEMY)
			data->ennemy.score++;
		data->win = NONE;
	}
}

ICE_UPDATE {
	Player_Movement(game);
	Collision_Ball(game);
	Victory_Condition(game);
	iceDrawRectangleFill(game, iceEntityGetRect(game, 0,0), NewColor(255, 255, 255)); // Player
	iceDrawRectangleFill(game, iceEntityGetRect(game, 0, 1), NewColor(255, 255, 255)); // Ennemy
	iceDrawRectangleFill(game, iceEntityGetRect(game, 0, 2), NewColor(255, 255, 255)); // Ball
}

ICE_DESTROY {

}

int main(){
	return ICE_GAME_RUN;
}
