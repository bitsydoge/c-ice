#ifndef DEF_ICE_TAGCOMPONENT_PRIVATE_H
#define DEF_ICE_TAGCOMPONENT_PRIVATE_H

#include "Types.h"
#include "TagList.h"

struct ICE_TagList
{
	ICE_TagID nb_inside;
	ICE_TagID tofill;
	ICE_TagID size;
	ICE_TagID* array;
};

//:PRIVATE
ICE_TagList ICE_TagList_Init();
void ICE_TagList_Destroy(ICE_TagList* tag_list_);

#endif