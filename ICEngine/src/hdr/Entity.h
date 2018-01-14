#ifndef DEF_ICE_ENTITY
#define DEF_ICE_ENTITY

#include "Game.h"
#include <stdio.h>
#include "Terminal.h"
#include "Primitive.h"
#include "Texture.h"
#include "Camera.h"

#define _POLAR_MOVEMENT_TYPE_1

/// Create a Entity Manager and return it's number
int iceEntityManagerCreate();

/// Create a Entity and return it's number in the manager
int iceEntityCreate(int manager);

/// Set a texture to a entity
void iceEntitySetTexture(int entity_manager, int entity_nb, int texture_manager, int texture_nb);

/// Remove a texture
void iceEntityRemoveTexture(int entity_manager, int entity_nb);

/// Set Entity size for the texture
void iceEntitySetSize(int entity_manager, int entity_nb, iceFloat w, iceFloat h);

/// Instant move entity to a position
void iceEntitySetPos(int manager, int entity, iceFloat x, iceFloat y);

/// Shift position from dX / dY
void iceEntityShiftPos(int manager, int entity, iceFloat x, iceFloat y);

/// Move to a position using Polar coordinate
void iceEntityMovePos(int manager, int entity, iceFloat x, iceFloat y, iceFloat r);

/// Set the entity Angle
void iceEntitySetAngle(int manager, int entity, iceFloat angle);

/// Add to the entity Angle
void iceEntityAddAngle(int manager, int entity, iceFloat angle);

/// Return the Box of a Entity
iceBox iceEntityGetBox(int manager, int entity);

// Get value
int iceEntityGetNumber(int manager);
int iceEntityManagerGetNumber();

#endif