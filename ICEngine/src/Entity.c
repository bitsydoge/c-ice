#include "hdr/Entity.h"


int ICE_CreateEntityManager(ICE_Game *game, char* name)
{
	return 0; // Return the entitymanager number
}

int ICE_CreateEntity(ICE_Game *game, int manager, char* name)
{
	return 0; // Return the entity number
}

// Instant move entity to a position
void ICE_SetEntityPosition(ICE_Game *game, int manager, int entity, int x, int y)
{
	
}

// Shift position from dX / dY
void ICE_ShiftEntityPosition(ICE_Game *game, int manager, int entity, int x, int y)
{
	
}

// Move to a position using Polar coordinate
void ICE_MoveEntityPosition(ICE_Game *game, int manager, int entity, int x, int y)
{

}

// Link a Data struct to a Entity
void ICE_DataToEntity(ICE_Game *game, int manager, int entity, size_t size)
{
	
}

