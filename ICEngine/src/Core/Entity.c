#include "Entity.h"

#include "TypesCore.h"

#include "../Framework/Memory_.h"
#include "../Framework/Log.h"
#include "../Maths/Maths.h"

#define _POLAR_MOVEMENT_TYPE_1

extern ICE_Game game;

/* ENTITY MANAGER */

size_t ICE_EntityManager_Insert(ICE_State * state)
{
	if (!state)
		state = game.current;

	ICE_EntityManager text_manager = { 0 };
	text_manager.entity_size = ICE_DEFAULT_ENTITY_MNGR_SIZE;
	text_manager.entity = ICE_Calloc(text_manager.entity_size, sizeof(ICE_Entity)); // Entity Array

	state->object.entity_mngr_nb++;
	state->object.entity_mngr = ICE_Realloc(state->object.entity_mngr, state->object.entity_mngr_nb * sizeof(ICE_EntityManager)); // Manager Array
	state->object.entity_mngr[state->object.entity_mngr_nb - 1] = text_manager;

	ICE_Log(ICE_LOG_SUCCES, "EntityManager]::[%d]::[Create", state->object.entity_mngr_nb - 1);
	return state->object.entity_mngr_nb - 1;
}

void ICE_EntityManager_Destroy(ICE_State * state, const size_t man)
{
	if (!state)
		state = game.current;

	ICE_EntityManager *manager = &state->object.entity_mngr[man];

	for (size_t i = 0; i < manager->entity_contain; i++)
	{
		//Free everything to free in Entity
		ICE_Entity_Destroy(&manager->entity[i]);
	}

	ICE_Free(manager->entity);
	ICE_Log(ICE_LOG_SUCCES, "EntityManager]::[%d]::[Free", man);
}

void ICE_EntityManager_DestroyAll(ICE_State * state)
{
	if (!state)
		state = game.current;

	ICE_EntityManager *manager = state->object.entity_mngr;
	size_t nb_manager = state->object.entity_mngr_nb;

	for (size_t i = 0; i < nb_manager; i++)
	{
		if (!manager[i].isFree)
		{
			ICE_EntityManager_Destroy(state, i);
			manager[i].isFree = ICE_True;
		}
	}
	free(manager);
}

/* ENTITY */

ICE_Entity ICE_Entity_Create(ICE_Box pos)
{
	ICE_Entity entity = { 0 };

	// Assigne
	entity.active = ICE_True;
	entity.x = pos.x;
	entity.y = pos.y;
	entity.w = pos.w;
	entity.h = pos.h;

	return entity;
}

size_t ICE_Entity_Insert(ICE_State * state, const size_t man, ICE_Box pos)
{
	if (!state)
		state = game.current;

	// Insert entity in array
	state->object.entity_mngr[man].entity[state->object.entity_mngr[man].entity_contain] = ICE_Entity_Create(pos);
	state->object.entity_mngr[man].entity_contain++;

	ICE_Log(ICE_LOG_SUCCES, "EntityManager]::[%d]::[Entity]::[%d]::[Create", man, state->object.entity_mngr[man].entity_contain - 1);

	// Test size to realloc more space
	if (state->object.entity_mngr[man].entity_size <= state->object.entity_mngr[man].entity_contain) {
		ICE_Entity* tmp = ICE_Realloc(state->object.entity_mngr[man].entity, sizeof(ICE_Entity)*(state->object.entity_mngr[man].entity_size * 2));
		// Test if realloc succes
		ICE_Log(ICE_LOG_WARNING, "EntityManager]::[%d]::[Resized]::[%d", man, state->object.entity_mngr[man].entity_size * 2);
		state->object.entity_mngr[man].entity = tmp;
		state->object.entity_mngr[man].entity_size *= 2;
	}

	return state->object.entity_mngr[man].entity_contain - 1;
}

void ICE_Entity_Clear(ICE_Entity * entity)
{
	memset(entity, 0, sizeof(ICE_Entity));
}

void ICE_Entity_Destroy(ICE_Entity * ptr)
{

}

/* ENTITY GET FUNCTION */

ICE_Entity * ICE_Entity_Get(ICE_State * state, const unsigned man, const unsigned nb)
{
	if (state)
		return &state->object.entity_mngr[man].entity[nb];
	return &game.current->object.entity_mngr[man].entity[nb];
}

size_t ICE_Entity_GetNumber(ICE_State * state, size_t manager)
{
	if (!state)
		state = game.current;

	return state->object.entity_mngr[manager].entity_contain;
}

size_t ICE_EntityManager_GetNumber(ICE_State * state)
{
	if (!state)
		state = game.current;

	return state->object.entity_mngr_nb;
}

ICE_Vect ICE_Entity_GetPosition(ICE_Entity * entity)
{
	ICE_Vect vect = { entity->x , entity->y };
	return vect;
}

/* ENTITY SET FUNCTION */

void ICE_Entity_SetTexture(ICE_Entity * entity, size_t texture_manager, size_t texture_nb)
{
	entity->graphics_mngr_index = texture_manager;
	entity->graphics_index = texture_nb;
	entity->have_graphics = ICE_True;
}

void ICE__Entity_RemoveTexture(ICE_Entity * entity)
{
	entity->have_graphics = ICE_False;
}

void ICE_Entity_SetPos(ICE_Entity * entity, ICE_Float x, ICE_Float y)
{
	entity->x = x;
	entity->y = y;
}

// Shift position from dX / dY
void ICE_Entity_ShiftPos(ICE_Entity * entity, ICE_Float x, ICE_Float y)
{
	entity->x += x;
	entity->y += y;
}

void ICE_Entity_MovePos(ICE_Entity * entity, ICE_Vect pos, ICE_Float r)
{
#ifdef _POLAR_MOVEMENT_TYPE_1

	// Check if it's a new movement
	if (!entity->already_moved_polar ||
		entity->x_polar_destination_move != pos.x ||
		entity->y_polar_destination_move != pos.y
		)
	{
		// Calculate the movement
		ICE_Float xdif = pos.x - entity->x;
		ICE_Float ydif = pos.y - entity->y;
		ICE_Float angle = atan2(ydif, xdif);
		entity->x_polar_shift_move = cos(angle);
		entity->y_polar_shift_move = sin(angle);
		entity->polar_distance_r_r = xdif * xdif + ydif * ydif;

		// Save for later check
		entity->already_moved_polar = 1;
		entity->r_polar_destination_move = r;
		entity->x_polar_destination_move = pos.x;
		entity->y_polar_destination_move = pos.y;
	}

	// Movement
	entity->x += r * entity->x_polar_shift_move;
	entity->y += r * entity->y_polar_shift_move;

	// Check if is close to destination
	if (entity->polar_distance_r_r < r)
	{
		entity->x = pos.x;
		entity->y = pos.y;
	}

#endif

#ifdef _POLAR_MOVEMENT_TYPE_2

	float xdif = pos.x - entity->x; float ydif = pos.y - entity->y;
	float angle = atan2(ydif, xdif);
	float distance_r_r = xdif * xdif + ydif * ydif;
	entity->x += r * cos(angle); entity->y += r * sin(angle);
	if (distance_r_r < r)
	{
		entity->x = pos.x;
		entity->y = pos.y;
	}

#endif
}

void ICE_Entity_SetSize(ICE_Entity * entity, ICE_Vect size)
{
	entity->w = size.x;
	entity->h = size.y;
}


void ICE_Entity_SetAngle(ICE_Entity * entity, ICE_Float angle)
{
	entity->angle = angle;
}

void ICE_Entity_AddAngle(ICE_Entity * entity, ICE_Float angle)
{
	entity->angle += angle;
	if (entity->angle >= 360)
		entity->angle = 0;
	if (entity->angle < 0)
		entity->angle = 0;
}

void ICE_Entity_LookAt(ICE_Entity * entity, ICE_Vect pos)
{
	ICE_Float result = ICE_Maths_AngleCalculatDegree(entity->x,
		entity->y, pos.x, pos.y);
	entity->angle = result;
}

ICE_Box ICE_Entity_GetBox(ICE_Entity * entity)
{
	ICE_Box rect =
	{
		entity->x,
		entity->y,
		entity->w,
		entity->h
	};
	return rect;
}