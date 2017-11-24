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
int iceEntityManagerCreate(iceGame *game);

/// Create a Entity and return it's number in the manager
int iceEntityCreate(iceGame *game, int manager);

/// Set a texture to a entity
void iceEntitySetTexture(iceGame *game, int entity_manager, int entity_nb, int texture_manager, int texture_nb);

/// Remove a texture
void iceEntityRemoveTexture(iceGame *game, int entity_manager, int entity_nb);

/// Set Entity size for the texture
void iceEntitySetSize(iceGame *game, int entity_manager, int entity_nb, iceFloat w, iceFloat h);

/// Instant move entity to a position
void iceEntitySetPos(iceGame *game, int manager, int entity, iceFloat x, iceFloat y);

/// Shift position from dX / dY
void iceEntityShiftPos(iceGame *game, int manager, int entity, iceFloat x, iceFloat y);

/// Move to a position using Polar coordinate
void iceEntityMovePos(iceGame *game, int manager, int entity, iceFloat x, iceFloat y, iceFloat r);

/// Set the entity Angle
void iceEntitySetAngle(iceGame *game, int manager, int entity, iceFloat angle);

/// Add to the entity Angle
void iceEntityAddAngle(iceGame *game, int manager, int entity, iceFloat angle);

/// Link a Data struct to a Entity
void iceEntityAddData(iceGame *game, int manager, int entity, size_t size);

/// Draw every Entity to screen
void iceEntityDrawAll(iceGame *game);

iceRect iceEntityGetRect(iceGame *game, int manager, int entity);

#endif