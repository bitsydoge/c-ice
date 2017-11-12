#ifndef DEF_ICE_ENTITY
#define DEF_ICE_ENTITY

#include "Game.h"
#include <stdio.h>
#include "TerminalColor.h"
#include "../external/rlutil.h"
#include "Primitive.h"
#include "Texture.h"
#include "Camera.h"

/// Create a Entity Manager and return it's number
int ICE_CreateEntityManager(ICE_Game *game);

/// Create a Entity and return it's number in the manager
int ICE_CreateEntity(ICE_Game *game, int manager);

/// Set a texture to a entity
void ICE_SetTextureEntity(ICE_Game *game, int entity_manager, int entity_nb, int texture_manager, int texture_nb);

/// Set a texture size
void ICE_SetEntitySize(ICE_Game *game, int entity_manager, int entity_nb, int w, int h);

/// Instant move entity to a position
void ICE_SetEntityPosition(ICE_Game *game, int manager, int entity, int x, int y);

/// Shift position from dX / dY
void ICE_ShiftEntityPosition(ICE_Game *game, int manager, int entity, int x, int y);

/// Move to a position using Polar coordinate
void ICE_MoveEntityPosition(ICE_Game *game, int manager, int entity, int x, int y, int r);

/// Set the entity Angle
void ICE_SetEntityAngle(ICE_Game *game, int manager, int entity, float angle);

/// Add to the entity Angle
void ICE_AddEntityAngle(ICE_Game *game, int manager, int entity, float angle);

/// Link a Data struct to a Entity
void ICE_DataToEntity(ICE_Game *game, int manager, int entity, size_t size);

/// Draw every Entity to screen
void ICE_DrawEntity(ICE_Game *game);

#endif