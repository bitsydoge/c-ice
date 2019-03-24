#ifndef DEF_ICE_TAG_H
#define DEF_ICE_TAG_H
#include "../Framework/String_.h"
#include "Types.h"

typedef struct ICE_Tag ICE_Tag;

ICE_TagID ICE_Tag_Create(ICE_StringStd tag_name_);
ICE_Char const* ICE_Tag_GetName(ICE_TagID tag_id_);
int ICE_Tag_GetLenght(ICE_TagID tag_id_);

#endif