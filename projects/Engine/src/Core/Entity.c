#include "Entity.h"

#include "TypesCore.h"

#include "../Framework/Memory_.h"
#include "../Framework/Log.h"
#include "../Maths/Maths.h"
#include "../Graphics/Sprite.h"
#include "../Graphics/Texture.h"
#include "../Framework/Assert_.h"

#define _POLAR_MOVEMENT_TYPE_1

extern ICE_Game GAME;

/* ENTITY MANAGER */

void ICE_EntityManager_Init(ICE_State* state)
{
	if (!state)
		state = GAME.current;

	ICE_EntityManager entity_manager = { 0 };
	entity_manager.entity_size = ICE_DEFAULT_ENTITY_MNGR_SIZE;
	entity_manager.entity = ICE_Calloc(entity_manager.entity_size, sizeof(ICE_Entity));

	state->object.entity_mngr = entity_manager;

	ICE_Log(ICE_LOGTYPE_SUCCES, "Create EntityManager");
}

void ICE_EntityManager_Destroy(ICE_State * state)
{
	if (!state)
		state = GAME.current;

	ICE_EntityManager *manager = &state->object.entity_mngr;

	for (ICE_ID i = 0; i < manager->entity_contain; i++)
	{
		//Free everything to free in Entity
		ICE_Entity_Destroy(&manager->entity[i]);
	}

	ICE_Free(manager->entity);
	ICE_Log(ICE_LOGTYPE_SUCCES, "Destroy EntityManager");
}

/* ENTITY */

ICE_Entity ICE_Entity_Build(ICE_Box pos)
{
	ICE_Entity entity = { 0 };

	// Assigne
	entity.active = ICE_True;
	entity.exist = ICE_True;
	entity.timestamp = SDL_GetTicks();
	entity.x = pos.x;
	entity.y = pos.y;
	entity.w = pos.w;
	entity.h = pos.h;

	return entity;
}

ICE_ID ICE_Entity_Create(ICE_State * state, ICE_Box pos)
{
	if (!state)
		state = GAME.current;

	ICE_EntityID avaible_slot = 0;
	ICE_Bool no_avaible_slot = ICE_False;

	for(ICE_EntityID i = 0; i < state->object.entity_mngr.entity_contain; i++)
	{
		if(state->object.entity_mngr.entity[i].exist == ICE_False)
		{		
			avaible_slot = i;
			no_avaible_slot = ICE_True;
			break;
		}	
	}
	if (!no_avaible_slot)
	{
		avaible_slot = state->object.entity_mngr.entity_contain;
		state->object.entity_mngr.entity_contain++;
	}
		

	state->object.entity_mngr.entity[avaible_slot] = ICE_Entity_Build(pos);
	state->object.entity_mngr.entity[avaible_slot].id = avaible_slot;
		
	ICE_Log(ICE_LOGTYPE_SUCCES, "Create Entity %d in state %s", avaible_slot, state->name);

	// Resize Manager
	if (state->object.entity_mngr.entity_size <= state->object.entity_mngr.entity_contain) 
	{
		ICE_Entity* tmp = ICE_Realloc(state->object.entity_mngr.entity, sizeof(ICE_Entity)*(state->object.entity_mngr.entity_size * 2));
		state->object.entity_mngr.entity = tmp;
		state->object.entity_mngr.entity_size *= 2;
	}

	return avaible_slot;
}

void ICE_Entity_Clear(ICE_Entity * entity)
{
	memset(entity, 0, sizeof(ICE_Entity));
}

void ICE_Entity_Destroy(ICE_Entity * ptr)
{
	if(ptr->exist)
	{
		ptr->active = ICE_False;
		ptr->exist = ICE_False;

		ptr->func_create = NULL;
		ptr->func_update = NULL;
		if (ptr->func_destroy != NULL)
			ptr->func_destroy(ptr);

		ICE_Entity_DataDestroyAll(ptr);

		ptr->haveFunctionDefined = ICE_False;
		ptr->func_destroy = NULL;
	}
}

/* ENTITY GET FUNCTION */

ICE_Entity * ICE_Entity_Get(ICE_State * state, ICE_EntityID entity_id)
{
	if (state)
		return &state->object.entity_mngr.entity[entity_id];
	return &GAME.current->object.entity_mngr.entity[entity_id];
}

ICE_ID ICE_Entity_GetQuantity(ICE_State * state, ICE_ID manager)
{
	if (!state)
		state = GAME.current;

	return state->object.entity_mngr.entity_contain;
}

ICE_Vect ICE_Entity_GetPosition(ICE_Entity * entity)
{
	const ICE_Vect vect = { entity->x , entity->y };
	return vect;
}

ICE_Box ICE_Entity_GetBox(ICE_Entity * entity)
{
	const ICE_Box rect =
	{
		entity->x,
		entity->y,
		entity->w,
		entity->h
	};
	return rect;
}

/* ENTITY SET FUNCTION */

// TEXTURE

extern ICE_Asset ASSET;

void ICE_Entity_SetTexture(ICE_Entity * entity_ptr, ICE_TextureID texture_id)
{
	entity_ptr->graphics_index = texture_id;
	entity_ptr->graphics_type = ICE_ENTITYGRAPHICSTYPES_TEXTURE;
	entity_ptr->graphics_box_render.x = 0;
	entity_ptr->graphics_box_render.y = 0;
	entity_ptr->graphics_box_render.w = ASSET.texture_mngr.texture[texture_id].w;
	entity_ptr->graphics_box_render.h = ASSET.texture_mngr.texture[texture_id].h;
}

void ICE_Entity_RemoveGraphics(ICE_Entity * entity)
{
	entity->graphics_type = ICE_ENTITYGRAPHICSTYPES_NONE;
}

// POSITION

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
		const ICE_Float xdif = pos.x - entity->x;
		const ICE_Float ydif = pos.y - entity->y;
		const ICE_Float angle = atan2(ydif, xdif);
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

// ROTATION	

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
	const ICE_Float result = ICE_Maths_AngleCalculatDegree(entity->x,
		entity->y, pos.x, pos.y);
	entity->angle = result;
}

// SIZE

void ICE_Entity_SetSize(ICE_Entity * entity, ICE_Vect size)
{
	entity->w = size.x;
	entity->h = size.y;
}

void ICE_Entity_Scale(ICE_Entity * entity, ICE_Float scale)
{
	entity->w = entity->w * scale;
	entity->h = entity->h * scale;
}

// SPRITE

void ICE_Entity_SetSprite(ICE_Entity * entity_, ICE_ID sprite_)
{
	ICE_Sprite * sprite = ICE_Sprite_Get(sprite_);
	entity_->graphics_type = ICE_ENTITYGRAPHICSTYPES_SPRITE;
	entity_->graphics_index = sprite->index;
	entity_->sprite_frame = 0;
	entity_->graphics_box_render.x = 0;
	entity_->graphics_box_render.y = 0;
	entity_->graphics_box_render.w = sprite->size_w;
	entity_->graphics_box_render.h = sprite->size_h;
}

void ICE_Entity_SetSpriteFrame(ICE_Entity * entity, ICE_ID frame)
{
	if (entity->graphics_type == ICE_ENTITYGRAPHICSTYPES_SPRITE)
	{
		ICE_Sprite * sprite = ICE_Sprite_Get(entity->graphics_index);
		frame--;
		entity->sprite_frame = frame;

		const ICE_ID size_in_w = (frame) % sprite->number_frame_w;
		const ICE_ID size_in_h = (frame) / sprite->number_frame_w;

		entity->graphics_box_render.x = size_in_w * sprite->size_w;
		entity->graphics_box_render.y = size_in_h * sprite->size_h;
	}
	else
		ICE_Log(ICE_LOGTYPE_ERROR, "This entity doesn't have a Sprite graphics");
}

ICE_Sprite * ICE_Entity_GetSprite(ICE_Entity * _entity)
{
	if(_entity->graphics_type == ICE_ENTITYGRAPHICSTYPES_SPRITE)
		return ICE_Sprite_Get(_entity->graphics_index);

	ICE_Log(ICE_LOGTYPE_WARNING, "This entity doesn't have Sprite graphics");
	return NULL;
}

ICE_Texture * ICE_Entity_GetTexture(ICE_Entity * _entity)
{
	if(_entity->graphics_type == ICE_ENTITYGRAPHICSTYPES_TEXTURE)
		return ICE_Texture_Get(_entity->graphics_mngr_index);
	
	ICE_Log(ICE_LOGTYPE_WARNING, "This entity doesn't have Texture graphics");
	return NULL;
}

ICE_ID ICE_Entity_GetSpriteFrame(ICE_Entity * entity)
{
	if (entity->graphics_type == ICE_ENTITYGRAPHICSTYPES_SPRITE)
		return entity->sprite_frame+1;
	ICE_Log(ICE_LOGTYPE_ERROR, "This entity doesn't have a Sprite graphics");
	return 0;
}

void ICE_Entity_SetFunction(ICE_Entity * entity, void(*call_create)(ICE_Entity*), void(*call_update)(ICE_Entity*), void(*call_destroy)(ICE_Entity*))
{
	entity->haveFunctionDefined = ICE_True;
	entity->func_create = call_create;
	entity->func_update = call_update;
	entity->func_destroy = call_destroy;
}

void ICE_Entity_FunctionUpdate(ICE_State * state)
{
	if (state == NULL)
		state = GAME.current;

	for(ICE_ID i = 0; i < state->object.entity_mngr.entity_contain; i++)
	{
		if(state->object.entity_mngr.entity[i].active)
		{
			if (state->object.entity_mngr.entity[i].haveFunctionDefined)
			{           
				if (!state->object.entity_mngr.entity[i].alreadyRunnedCreate)
				{
					state->object.entity_mngr.entity[i].func_create(&state->object.entity_mngr.entity[i]);
					state->object.entity_mngr.entity[i].alreadyRunnedCreate = ICE_True;
				}
				else
				{
					state->object.entity_mngr.entity[i].func_update(&state->object.entity_mngr.entity[i]);
				}
			}
				
		}
	}
}

void * ICE_Entity_DataAdd_(ICE_Entity * entity_, ICE_ID size_)
{
	entity_->data_nb++;
	entity_->data = ICE_Realloc(entity_->data, sizeof(void*)*(entity_->data_nb));
	entity_->data[entity_->data_nb - 1] = ICE_Calloc(1, size_);
	void * _pointer = entity_->data[entity_->data_nb - 1];
	return _pointer;
}

void * ICE_Entity_DataGet(ICE_Entity * entity_, ICE_DataID id_data_)
{
	void * _pointer;

	if (id_data_ <= entity_->data_nb)
		_pointer = entity_->data[id_data_];

	////////////////////////////////////////////
	//                                        //
	// If you see this assert, you choosed    //
	// a data that doesn't exist              //
	//                                        //
	////////////////////////////////////////////

	else
	{
		_pointer = NULL;
		//assert(("Pointer is null so there is no data at this number", _pointer));
		ICE_Assert(_pointer != NULL, "Pointer is null so there is no data at this number");
	}

	return _pointer;
}

void ICE_Entity_DataDestroy(ICE_Entity * entity_, ICE_DataID id_data_)
{
	void * _pointer;

	if (id_data_ <=entity_->data_nb)
		_pointer = entity_->data[id_data_];

	////////////////////////////////////////////
	//                                        //
	// If you see this assert, you choosed    //
	// a data that doesn't exist              //
	//                                        //
	////////////////////////////////////////////

	else
	{
		_pointer = NULL;
		//assert("Pointer is null so there is no data at this number", _pointer);
		ICE_Assert(_pointer != NULL, "Pointer is null so there is no data at this number");
	}

	ICE_Free(_pointer);
}

void ICE_Entity_DataDestroyAll(ICE_Entity * entity_)
{
	for (ICE_ID i = 0; i < entity_->data_nb; i++)
	{
		if(entity_->data)
			if(entity_->data[i])
			{
				ICE_Free(entity_->data[i]);
				entity_->data[i] = NULL;
			}
	}
	if(entity_->data)
	{
		ICE_Free(entity_->data);
		entity_->data = NULL;
	}
}

ICE_EntityID ICE_Entity_GetID(ICE_Entity * entity_)
{
	return entity_->id;
}