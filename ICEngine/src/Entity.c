#include "hdr/Entity.h"

extern iceGame game;

//				  //
//				  //
//ENTITY CREATION //
//                //
//                //

int iceEntityManagerCreate(){
	iceEntityManager entity_manager = { 0 };
	entity_manager.array_size = 4;
	entity_manager.entity = calloc(entity_manager.array_size, sizeof(iceEntity));
	game.entitymanager_size++;
	game.entitymanager = realloc(game.entitymanager, game.entitymanager_size * sizeof(iceEntityManager));
	game.entitymanager[game.entitymanager_size - 1] = entity_manager;
	printf("EntityManager number %d created \n", game.texturemanager_size - 1);
	return game.entitymanager_size-1; // Return the entitymanager number
}

int iceEntityCreate(int manager){
	printf("Entity number %d created in manager %d \n", game.entitymanager[manager].nb_existing, manager);
	iceEntity entity = {0};
	entity.exist = iceTrue;
	game.entitymanager[manager].entity[game.entitymanager[manager].nb_existing] = entity;
	game.entitymanager[manager].nb_existing++;

	if (game.entitymanager[manager].array_size <= game.entitymanager[manager].nb_existing) {
		iceTermSetColor(iceLIGHTCYAN);
		printf("Extending entity manager size to %d \n", game.entitymanager[manager].array_size * 2);
		iceTermResetColor();
		game.entitymanager[manager].entity = realloc(game.entitymanager[manager].entity, sizeof(iceEntity)*(game.entitymanager[manager].array_size * 2));
		game.entitymanager[manager].array_size *= 2;
	}
	return game.entitymanager->nb_existing - 1;
}


//				  //
//				  //
// ENTITY TEXTURE //
//                //
//                //

// Define Texture for the entity
void iceEntitySetTexture(int entity_manager, int entity_nb, int texture_manager, int texture_nb){
	game.entitymanager[entity_manager].entity[entity_nb].man = texture_manager; game.entitymanager[entity_manager].entity[entity_nb].text = texture_nb;
	game.entitymanager[entity_manager].entity[entity_nb].have_texture = iceTrue;
}

void iceEntityRemoveTexture(int entity_manager, int entity_nb) {
	game.entitymanager[entity_manager].entity[entity_nb].have_texture = iceFalse;
}

//				  //
//				  //
//  ENTITY VALUE  //
//                //
//                //

// Instant move entity to a position
void iceEntitySetPos(int manager, int entity, iceFloat x, iceFloat y) {
	game.entitymanager[manager].entity[entity].x = x; game.entitymanager[manager].entity[entity].y = y;
}

// Shift position from dX / dY
void iceEntityShiftPos(int manager, int entity, iceFloat x, iceFloat y) {
	game.entitymanager[manager].entity[entity].x += x; game.entitymanager[manager].entity[entity].y += y;
}



// Move to a position using Polar coordinate
void iceEntityMovePos(int manager, int entity, iceFloat x, iceFloat y, iceFloat r) {
	
#ifdef _POLAR_MOVEMENT_TYPE_1

	// Check if it's a new movement
	if (!game.entitymanager[manager].entity[entity].already_moved_polar		   || 
		 game.entitymanager[manager].entity[entity].x_polar_destination_move != x ||
		 game.entitymanager[manager].entity[entity].y_polar_destination_move != y   
		)
	{
		// Calculate the movement
		iceFloat xdif = x - game.entitymanager[manager].entity[entity].x; iceFloat ydif = y - game.entitymanager[manager].entity[entity].y;
		iceFloat angle = atan2(ydif, xdif);
		game.entitymanager[manager].entity[entity].x_polar_shift_move = cos(angle); 
		game.entitymanager[manager].entity[entity].y_polar_shift_move = sin(angle);
		game.entitymanager[manager].entity[entity].polar_distance_r_r = xdif*xdif + ydif*ydif;

		// Save for later check
		game.entitymanager[manager].entity[entity].already_moved_polar = 1;
		game.entitymanager[manager].entity[entity].r_polar_destination_move = r;
		game.entitymanager[manager].entity[entity].x_polar_destination_move = x; 
		game.entitymanager[manager].entity[entity].y_polar_destination_move = y;
	}

	// Movement
	game.entitymanager[manager].entity[entity].x += r * game.entitymanager[manager].entity[entity].x_polar_shift_move;
	game.entitymanager[manager].entity[entity].y += r * game.entitymanager[manager].entity[entity].y_polar_shift_move;

	// Check if is close to destination
	if (game.entitymanager[manager].entity[entity].polar_distance_r_r < r)
	{
		game.entitymanager[manager].entity[entity].x = x;
		game.entitymanager[manager].entity[entity].y = y;
	}

#endif

#ifdef _POLAR_MOVEMENT_TYPE_2

	float xdif = x - game->entitymanager[manager].entity[entity].x; float ydif = y - game->entitymanager[manager].entity[entity].y;
	float angle = atan2(ydif, xdif);
	float distance_r_r = xdif*xdif + ydif*ydif;
	game->entitymanager[manager].entity[entity].x += r * cos(angle); game->entitymanager[manager].entity[entity].y += r * sin(angle);
	if (distance_r_r < r)
	{
		game->entitymanager[manager].entity[entity].x = x;
		game->entitymanager[manager].entity[entity].y = y;
	}

#endif

}

void iceEntitySetSize(int entity_manager, int entity_nb, iceFloat w, iceFloat h){
	game.entitymanager[entity_manager].entity[entity_nb].w = w; game.entitymanager[entity_manager].entity[entity_nb].h = h;
}


void iceEntitySetAngle(int manager, int entity, iceFloat angle)
{
	
}

void iceEntityAddAngle(int manager, int entity, iceFloat angle)
{
	game.entitymanager[manager].entity[entity].angle += angle;
	if (game.entitymanager[manager].entity[entity].angle >= 360)
		game.entitymanager[manager].entity[entity].angle = 0;
	if (game.entitymanager[manager].entity[entity].angle < 0)
		game.entitymanager[manager].entity[entity].angle = 0;
}

iceBox iceEntityGetBox(int manager, int entity)
{
	iceBox rect =
	{
		game.entitymanager[manager].entity[entity].x,
		game.entitymanager[manager].entity[entity].y,
		game.entitymanager[manager].entity[entity].w,
		game.entitymanager[manager].entity[entity].h
	};
	return rect;
}



// Get value

int iceEntityGetNumber(int manager)
{
	return game.entitymanager[manager].nb_existing;
}

int iceEntityManagerGetNumber()
{
	return game.entitymanager_size;
}