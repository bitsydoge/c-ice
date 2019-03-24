#ifndef DEF_ICE_TAG_PRIVATE_H
#define DEF_ICE_TAG_PRIVATE_H

#include "Tag.h"
#include "../Framework/String_.h"
#include "Types.h"

struct ICE_Tag
{
	ICE_TagID id;
	size_t strpool_id;
	ICE_String name;	
};

//:PRIVATE
ICE_Tag ICE_Tag_Build(ICE_StringStd tag_name_);
ICE_Bool ICE_Tag_AlreadyHave(ICE_TagID strpool_id_);
ICE_Tag* ICE_Tag_Get(ICE_TagID tag_id_);
void ICE_Tag_Destroy(ICE_TagID tag_id_);

#endif