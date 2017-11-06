#ifndef DEF_ICE_ENTITY
#define DEF_ICE_ENTITY

#include "Game.h"

/// Create a Entity Manager and return it's number
int ICE_CreateEntityManager(ICE_Game *game, char* name);

/// Create a Entity and return it's number in the manager
int ICE_CreateEntity(ICE_Game *game, int manager, char* name);

/// Instant move entity to a position
void ICE_SetEntityPosition(ICE_Game *game, int manager, int entity, int x, int y);

/// Shift position from dX / dY
void ICE_ShiftEntityPosition(ICE_Game *game, int manager, int entity, int x, int y);

/// Move to a position using Polar coordinate
void ICE_MoveEntityPosition(ICE_Game *game, int manager, int entity, int x, int y);

/// Link a Data struct to a Entity
void ICE_DataToEntity(ICE_Game *game, int manager, int entity, size_t size);

#endif