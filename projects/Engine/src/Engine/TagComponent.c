#include "../Framework/Memory_.h"
#include "Types.h"

#include "TagComponent_private.h"
#include "../Framework/Log.h"

///////////////////////////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------------------------- //
// ------------------------------------   TagManager    -------------------------------- //
// ------------------------------------------------------------------------------------- //
///////////////////////////////////////////////////////////////////////////////////////////

//:PRIVATE
ICE_TagComponent ICE_TagComponent_Init()
{
	ICE_TagComponent tag_manager = { 0 };
	tag_manager.size = 4;
	tag_manager.nb_really_inside = 0;
	tag_manager.array = ICE_Calloc(4, sizeof(ICE_TagID));
	return tag_manager;
}

void ICE_TagComponent_Destroy(ICE_TagComponent* tag_manager_)
{
	ICE_Free(tag_manager_->array);
}

//:PUBLIC
void ICE_TagComponent_Add(ICE_TagComponent* tag_manager_, ICE_TagID tag_id_)
{
	ICE_TagID number_avaible_slot = 0;
	ICE_Bool avaible_slot = ICE_False;

	//Check if it doesn't already have that tag
	if (!ICE_TagComponent_Have(tag_manager_, tag_id_))
	{
		for (ICE_TagID i = 0; i < tag_manager_->contain; i++)
		{
			if (tag_manager_->array[i] == 0)
			{
				number_avaible_slot = i;
				avaible_slot = ICE_True;
				break;
			}
		}
		if (!avaible_slot)
		{
			number_avaible_slot = tag_manager_->contain;
			tag_manager_->contain++;
		}

		// Put it in
		tag_manager_->array[number_avaible_slot] = tag_id_;
		tag_manager_->nb_really_inside++;
		if (tag_manager_->size <= tag_manager_->contain)
		{
			tag_manager_->array = ICE_Realloc(tag_manager_->array, sizeof(ICE_TagID) * (tag_manager_->size * 2));
			tag_manager_->size *= 2;
		}
	}
	else
		ICE_Log_Succes("This TagManager already have that tag");
}

void ICE_TagComponent_Remove(ICE_TagComponent* tag_manager_, ICE_TagID tag_id_)
{
	for (ICE_TagID i = 0; i < tag_manager_->size; i++)
	{
		if (tag_manager_->array[i] == tag_id_)
		{
			tag_manager_->array[i] = 0;
			tag_manager_->nb_really_inside--;
			break;
		}
	}
}

ICE_Bool ICE_TagComponent_Have(ICE_TagComponent* tag_component_, ICE_TagID tag_id_)
{
	for (ICE_TagID i = 0; i < tag_component_->size; i++)
	{
		if (tag_component_->array[i] == tag_id_)
		{
			return ICE_True;
		}
	}
	return ICE_False;
}

ICE_TagID* ICE_TagComponent_GetAllTag(ICE_TagComponent* tag_component_, ICE_Index *size_array_)
{
	*size_array_ = tag_component_->nb_really_inside;
	ICE_TagID* array = ICE_Calloc(*size_array_, sizeof(ICE_TagID));
	for(ICE_TagID i = 0; i < *size_array_; i++)
	{
		if(tag_component_->array[i] != 0)
		{
			array[i] = tag_component_->array[i];
		}
	}
	return array;
}

void ICE_TagComponent_GetAllTag_Free(ICE_TagID* tag_array_to_free_)
{
	ICE_Free(tag_array_to_free_);
}