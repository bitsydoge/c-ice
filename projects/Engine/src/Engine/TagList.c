#include "../Framework/Memory_.h"
#include "Types.h"

#include "TagList_private.h"
#include "../Framework/Log.h"

///////////////////////////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------------------------- //
// ------------------------------------   TagList       -------------------------------- //
// ------------------------------------------------------------------------------------- //
///////////////////////////////////////////////////////////////////////////////////////////

//:PRIVATE
ICE_TagList ICE_TagList_Init()
{
	ICE_TagList tag_list = { 0 };
	tag_list.size = 4;
	tag_list.nb_inside = 0;
	tag_list.array = ICE_Calloc(4, sizeof(ICE_TagID));
	return tag_list;
}

void ICE_TagList_Destroy(ICE_TagList* tag_list_)
{
	ICE_Free(tag_list_->array);
}

//:PUBLIC
void ICE_TagList_Add(ICE_TagList* tag_list_, ICE_TagID tag_id_)
{
	ICE_TagID number_avaible_slot = 0;
	ICE_Bool avaible_slot = ICE_False;

	//Check if it doesn't already have that tag
	if (!ICE_TagList_Have(tag_list_, tag_id_))
	{
		for (ICE_TagID i = 0; i < tag_list_->tofill; i++)
		{
			if (tag_list_->array[i] == 0)
			{
				number_avaible_slot = i;
				avaible_slot = ICE_True;
				break;
			}
		}
		if (!avaible_slot)
		{
			number_avaible_slot = tag_list_->tofill;
			tag_list_->tofill++;
		}

		// Put it in
		tag_list_->array[number_avaible_slot] = tag_id_;
		tag_list_->nb_inside++;
		if (tag_list_->size <= tag_list_->tofill)
		{
			tag_list_->array = ICE_Realloc(tag_list_->array, sizeof(ICE_TagID) * (tag_list_->size * 2));
			tag_list_->size *= 2;
		}
	}
	else
		ICE_Log_Succes("This TagManager already have that tag");
}

void ICE_TagList_Remove(ICE_TagList* tag_list_, ICE_TagID tag_id_)
{
	for (ICE_TagID i = 0; i < tag_list_->size; i++)
	{
		if (tag_list_->array[i] == tag_id_)
		{
			tag_list_->array[i] = 0;
			tag_list_->nb_inside--;
			break;
		}
	}
}

ICE_Bool ICE_TagList_Have(ICE_TagList* tag_list_, ICE_TagID tag_id_)
{
	for (ICE_TagID i = 0; i < tag_list_->size; i++)
	{
		if (tag_list_->array[i] == tag_id_)
		{
			return ICE_True;
		}
	}
	return ICE_False;
}

ICE_TagID* ICE_TagList_GetAllTag(ICE_TagList* tag_list_, ICE_Index *size_array_)
{
	*size_array_ = tag_list_->nb_inside;
	ICE_TagID* array = ICE_Calloc(*size_array_, sizeof(ICE_TagID));
	for(ICE_TagID i = 0; i < *size_array_; i++)
	{
		if(tag_list_->array[i] != 0)
		{
			array[i] = tag_list_->array[i];
		}
	}
	return array;
}

void ICE_TagList_GetAllTag_Free(ICE_TagID* tag_array_to_free_)
{
	ICE_Free(tag_array_to_free_);
}