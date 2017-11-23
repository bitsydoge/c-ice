#include "hdr/Entity.h"


//				  //
//				  //
//ENTITY CREATION //
//                //
//                //

int ICE_EntityManagerCreate(ICE_Game *game){
	ICE_EntityManager entity_manager = { 0 };
	entity_manager.array_size = 4;
	entity_manager.entity = calloc(entity_manager.array_size, sizeof(ICE_Entity));
	game->entitymanager_size++;
	game->entitymanager = realloc(game->entitymanager, game->entitymanager_size * sizeof(ICE_EntityManager));
	game->entitymanager[game->entitymanager_size - 1] = entity_manager;
	printf("EntityManager number %d created \n", game->texturemanager_size - 1);
	return game->entitymanager_size-1; // Return the entitymanager number
}

int ICE_EntityCreate(ICE_Game *game, int manager){
	printf("Entity number %d created in manager %d \n", game->entitymanager[manager].nb_existing, manager);
	ICE_Entity entity = {0};
	entity.exist = 1;
	game->entitymanager[manager].entity[game->entitymanager[manager].nb_existing] = entity;
	game->entitymanager[manager].nb_existing++;

	if (game->entitymanager[manager].array_size <= game->entitymanager[manager].nb_existing) {
		ICE_TermSetColor(LIGHTCYAN);
		printf("Extending entity manager size to %d \n", game->entitymanager[manager].array_size * 2);
		ICE_TermResetColor();
		game->entitymanager[manager].entity = realloc(game->entitymanager[manager].entity, sizeof(ICE_Entity)*(game->entitymanager[manager].array_size * 2));
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
void ICE_EntitySetTexture(ICE_Game *game, int entity_manager, int entity_nb, int texture_manager, int texture_nb){
	game->entitymanager[entity_manager].entity[entity_nb].man = texture_manager; game->entitymanager[entity_manager].entity[entity_nb].text = texture_nb;
	game->entitymanager[entity_manager].entity[entity_nb].has_texture = 1;
}

void ICE_EntityRemoveTexture(ICE_Game *game, int entity_manager, int entity_nb) {
	game->entitymanager[entity_manager].entity[entity_nb].has_texture = 0;
}

//				  //
//				  //
//  ENTITY VALUE  //
//                //
//                //

// Instant move entity to a position
void ICE_EntitySetPos(ICE_Game *game, int manager, int entity, iceFloat x, iceFloat y) {
	game->entitymanager[manager].entity[entity].x = x; game->entitymanager[manager].entity[entity].y = y;
}

// Shift position from dX / dY
void ICE_EntityShiftPos(ICE_Game *game, int manager, int entity, iceFloat x, iceFloat y) {
	game->entitymanager[manager].entity[entity].x += x * game->time.delta; game->entitymanager[manager].entity[entity].y += y * game->time.delta;
}

// Move to a position using Polar coordinate
void ICE_EntityMovePos(ICE_Game *game, int manager, int entity, iceFloat x, iceFloat y, iceFloat r) {
	float xdif = x - game->entitymanager[manager].entity[entity].x; float ydif = y - game->entitymanager[manager].entity[entity].y;
	float angle = atan2(ydif, xdif);
	float distance_r_r = xdif*xdif + ydif*ydif;
	game->entitymanager[manager].entity[entity].x += r * cos(angle) * game->time.delta; game->entitymanager[manager].entity[entity].y += r * sin(angle) * game->time.delta;
	if (distance_r_r < r*game->time.delta)
	{
		game->entitymanager[manager].entity[entity].x = x;
		game->entitymanager[manager].entity[entity].y = y;
	}
}

void ICE_EntitySetSize(ICE_Game *game, int entity_manager, int entity_nb, iceFloat w, iceFloat h){
	game->entitymanager[entity_manager].entity[entity_nb].w = w; game->entitymanager[entity_manager].entity[entity_nb].h = h;
}


void ICE_EntitySetAngle(ICE_Game *game, int manager, int entity, iceFloat angle)
{
	
}

void ICE_EntityAddAngle(ICE_Game *game, int manager, int entity, iceFloat angle)
{

}

iceRect ICE_EntityGetRect(ICE_Game *game, int manager, int entity)
{
	iceRect rect =
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
void ICE_EntityAddData(ICE_Game *game, int manager, int entity, size_t size){
	
}

// Return pointer of a Data from a Entity
void ICE_EntityGetData(){
	
}


//				  //
//				  //
//  ENTITY DRAW   //
//                //
//                //

void ICE_EntityDrawAll(ICE_Game *game)
{
	for (int i = 0; i < game->entitymanager_size; i++)
		for(int j = 0; j < game->entitymanager[i].nb_existing; j++)
		{
			if(game->entitymanager[i].entity[j].has_texture && game->entitymanager[i].entity[j].exist)
			{
				iceRect rect = ICE_CameraWorldScreen(RectNew(
					game->entitymanager[i].entity[j].x,
					game->entitymanager[i].entity[j].y,
					game->entitymanager[i].entity[j].w,
					game->entitymanager[i].entity[j].h), &game->camera);

				ICE_TextureRender(
					game,
					game->entitymanager[i].entity[j].man,
					game->entitymanager[i].entity[j].text,
					NULL, &rect);
			}
		}
}

