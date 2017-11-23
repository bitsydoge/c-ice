#ifndef DEF_ICE_ENTITY
#define DEF_ICE_ENTITY

#include "Game.h"
#include <stdio.h>
#include "Terminal.h"
#include "../external/rlutil.h"
#include "Primitive.h"
#include "Texture.h"
#include "Camera.h"

/// Create a Entity Manager and return it's number
int ICE_EntityManagerCreate(ICE_Game *game);

/// Create a Entity and return it's number in the manager
int ICE_EntityCreate(ICE_Game *game, int manager);

/// Set a texture to a entity
void ICE_EntitySetTexture(ICE_Game *game, int entity_manager, int entity_nb, int texture_manager, int texture_nb);

/// Remove a texture
void ICE_EntityRemoveTexture(ICE_Game *game, int entity_manager, int entity_nb);

/// Set Entity size for the texture
void ICE_EntitySetSize(ICE_Game *game, int entity_manager, int entity_nb, float w, float h);

/// Instant move entity to a position
void ICE_EntitySetPos(ICE_Game *game, int manager, int entity, float x, float y);

/// Shift position from dX / dY
void ICE_EntityShiftPos(ICE_Game *game, int manager, int entity, float x, float y);

/// Move to a position using Polar coordinate
void ICE_EntityMovePos(ICE_Game *game, int manager, int entity, float x, float y, float r);

/// Set the entity Angle
void ICE_EntitySetAngle(ICE_Game *game, int manager, int entity, float angle);

/// Add to the entity Angle
void ICE_EntityAddAngle(ICE_Game *game, int manager, int entity, float angle);

/// Link a Data struct to a Entity
void ICE_EntityAddData(ICE_Game *game, int manager, int entity, size_t size);

/// Draw every Entity to screen
void ICE_EntityDrawAll(ICE_Game *game);

iceRect ICE_EntityGetRect(ICE_Game *game, int manager, int entity);

#endif