#include "Tag_private.h"

#define STRPOOL_IMPLEMENTATION
#include "../External/libs/strpool.h"

#include "../Framework/String_.h"
#include "Types.h"

#include "TagManager_private.h"
#include "../Framework/Log.h"
#include "../Framework/Memory_.h"

ICE_Bool ICE_Tag_AlreadyHave(ICE_TagID strpool_id_)
{
	ICE_TagID size = ICE_TagManager_Get()->size;
	for(ICE_TagID i = 0; i < size; i++)
	{
		if (ICE_TagManager_Get()->array[i].strpool_id == strpool_id_)
		{
			return ICE_True;
		}
	}
	return ICE_False;
}

ICE_TagID ICE_Tag_GetIDAlreadyHave(ICE_TagID str_pool_id_)
{
	ICE_TagID size = ICE_TagManager_Get()->size;
	for (ICE_TagID i = 0; i < size; i++)
	{
		if (ICE_TagManager_Get()->array[i].strpool_id == str_pool_id_)
		{
			return ICE_TagManager_Get()->array[i].id;
		}
	}
	return 0;
}

ICE_Tag* ICE_Tag_Get(ICE_TagID tag_id_)
{
	return &ICE_TagManager_Get()->array[tag_id_ - 1];
}

void ICE_Tag_Destroy(ICE_TagID tag_id_)
{
	ICE_String_Destroy(&ICE_Tag_Get(tag_id_)->name);
	ICE_Tag_Get(tag_id_)->id = 0;
	strpool_discard(&ICE_TagManager_Get()->pool, ICE_Tag_Get(tag_id_)->strpool_id);
	ICE_Tag_Get(tag_id_)->strpool_id = 0;
}

//:PUBLIC
ICE_TagID ICE_Tag_Create(ICE_StringStd tag_name_)
{
	int size_temp = ICE_StringStd_Size(tag_name_);
	unsigned long long strpool_id_temp = strpool_inject(&ICE_TagManager_Get()->pool, tag_name_, size_temp);

	if(!ICE_Tag_AlreadyHave(strpool_id_temp))
	{
		ICE_EntityID number_avaible_slot = 0;
		ICE_Bool avaible_slot = ICE_False;

		for (ICE_EntityID i = 0; i < ICE_TagManager_Get()->contain; i++)
		{
			if (ICE_TagManager_Get()->array[i].id == ICE_False)
			{
				number_avaible_slot = i;
				avaible_slot = ICE_True;
				break;
			}
		}
		if (!avaible_slot)
		{
			number_avaible_slot = ICE_TagManager_Get()->contain;
			ICE_TagManager_Get()->contain++;
		}

		ICE_Tag temp_tag = { number_avaible_slot + 1, strpool_id_temp, ICE_String_Init(tag_name_) };
		ICE_TagManager_Get()->array[number_avaible_slot] = temp_tag;

		// Resize Manager
		if (ICE_TagManager_Get()->size <= ICE_TagManager_Get()->contain)
		{
			//ICE_Tag* tmp = ICE_Realloc(ICE_TagManager_Get()->array, sizeof(ICE_Tag) * (ICE_TagManager_Get()->size * 2));
			ICE_Tag* tmp = ICE_ReallocZero(ICE_TagManager_Get()->array, sizeof(ICE_Tag) * (ICE_TagManager_Get()->size), sizeof(ICE_Tag) * (ICE_TagManager_Get()->size * 2));
			ICE_TagManager_Get()->array = tmp;
			ICE_TagManager_Get()->size *= 2;
		}
		ICE_Log_Succes("Tag %s created with ID(%d)", tag_name_, number_avaible_slot + 1);
		return number_avaible_slot + 1;
	}
	ICE_Log_Warning("There is already a Tag (%s)", tag_name_);
	return ICE_Tag_GetIDAlreadyHave(strpool_id_temp);
}

ICE_Char const* ICE_Tag_GetName(ICE_TagID tag_id_)
{
	return ICE_Tag_Get(tag_id_)->name;
}

int ICE_Tag_GetLenght(ICE_TagID tag_id_)
{
	return ICE_String_Size(ICE_Tag_Get(tag_id_)->name);
}