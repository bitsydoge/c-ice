#include "hdr/Entity.h"


//				  //
//				  //
//ENTITY CREATION //
//                //
//                //

int iceEntityManagerCreate(iceGame *game){
	iceEntityManager entity_manager = { 0 };
	entity_manager.array_size = 4;
	entity_manager.entity = calloc(entity_manager.array_size, sizeof(iceEntity));
	game->entitymanager_size++;
	game->entitymanager = realloc(game->entitymanager, game->entitymanager_size * sizeof(iceEntityManager));
	game->entitymanager[game->entitymanager_size - 1] = entity_manager;
	printf("EntityManager number %d created \n", game->texturemanager_size - 1);
	return game->entitymanager_size-1; // Return the entitymanager number
}

int iceEntityCreate(iceGame *game, int manager){
	printf("Entity number %d created in manager %d \n", game->entitymanager[manager].nb_existing, manager);
	iceEntity entity = {0};
	entity.exist = iceTrue;
	game->entitymanager[manager].entity[game->entitymanager[manager].nb_existing] = entity;
	game->entitymanager[manager].nb_existing++;

	if (game->entitymanager[manager].array_size <= game->entitymanager[manager].nb_existing) {
		iceTermSetColor(iceLIGHTCYAN);
		printf("Extending entity manager size to %d \n", game->entitymanager[manager].array_size * 2);
		iceTermResetColor();
		game->entitymanager[manager].entity = realloc(game->entitymanager[manager].entity, sizeof(iceEntity)*(game->entitymanager[manager].array_size * 2));
		game->entitymanager[manager].array_size *= 2;
	}
	return game->entitymanager->nb_existing - 1;
}


//				  //
//				  //
// ENTITY TEXTURE //
//                //
//                //

// Define Texture for the entity
void iceEntitySetTexture(iceGame *game, int entity_manager, int entity_nb, int texture_manager, int texture_nb){
	game->entitymanager[entity_manager].entity[entity_nb].man = texture_manager; game->entitymanager[entity_manager].entity[entity_nb].text = texture_nb;
	game->entitymanager[entity_manager].entity[entity_nb].have_texture = iceTrue;
}

void iceEntityRemoveTexture(iceGame *game, int entity_manager, int entity_nb) {
	game->entitymanager[entity_manager].entity[entity_nb].have_texture = iceFalse;
}

//				  //
//				  //
//  ENTITY VALUE  //
//                //
//                //

// Instant move entity to a position
void iceEntitySetPos(iceGame *game, int manager, int entity, iceFloat x, iceFloat y) {
	game->entitymanager[manager].entity[entity].x = x; game->entitymanager[manager].entity[entity].y = y;
}

// Shift position from dX / dY
void iceEntityShiftPos(iceGame *game, int manager, int entity, iceFloat x, iceFloat y) {
	game->entitymanager[manager].entity[entity].x += x; game->entitymanager[manager].entity[entity].y += y;
}

// Move to a position using Polar coordinate
void iceEntityMovePos(iceGame *game, int manager, int entity, iceFloat x, iceFloat y, iceFloat r) {
	float xdif = x - game->entitymanager[manager].entity[entity].x; float ydif = y - game->entitymanager[manager].entity[entity].y;
	float angle = atan2(ydif, xdif);
	float distance_r_r = xdif*xdif + ydif*ydif;
	game->entitymanager[manager].entity[entity].x += r * cos(angle); game->entitymanager[manager].entity[entity].y += r * sin(angle);
	if (distance_r_r < r)
	{
		game->entitymanager[manager].entity[entity].x = x;
		game->entitymanager[manager].entity[entity].y = y;
	}
}

void iceEntitySetSize(iceGame *game, int entity_manager, int entity_nb, iceFloat w, iceFloat h){
	game->entitymanager[entity_manager].entity[entity_nb].w = w; game->entitymanager[entity_manager].entity[entity_nb].h = h;
}


void iceEntitySetAngle(iceGame *game, int manager, int entity, iceFloat angle)
{
	
}

void iceEntityAddAngle(iceGame *game, int manager, int entity, iceFloat angle)
{

}

iceBox iceEntityGetRect(iceGame *game, int manager, int entity)
{
	iceBox rect =
	{
		game->entitymanager[manager].entity[entity].x,
		game->entitymanager[manager].entity[entity].y,
		game->entitymanager[manager].entity[entity].w,
		game->entitymanager[manager].entity[entity].h
	};
	return rect;
}

//				  //
//				  //
//  ENTITY DATA   //
//                //
//                //

// Link a Data struct to a Entity
void iceEntityAddData(iceGame *game, int manager, int entity, size_t size){
	
}

// Return pointer of a Data from a Entity
void iceEntityGetData(){
	
}


//				  //
//				  //
//  ENTITY DRAW   //
//                //
//                //

void iceEntityDrawAll(iceGame *game)
{
	for (int i = 0; i < game->entitymanager_size; i++)
		for(int j = 0; j < game->entitymanager[i].nb_existing; j++)
		{
			if(game->entitymanager[i].entity[j].have_texture && game->entitymanager[i].entity[j].exist)
			{
				iceBox rect = iceCameraWorldScreen(iceBoxNew(
					game->entitymanager[i].entity[j].x,
					game->entitymanager[i].entity[j].y,
					game->entitymanager[i].entity[j].w,
					game->entitymanager[i].entity[j].h), &game->camera);

				iceTextureRenderCentered(
					game,
					game->entitymanager[i].entity[j].man,
					game->entitymanager[i].entity[j].text,
					NULL, &rect);
			}
		}
}

