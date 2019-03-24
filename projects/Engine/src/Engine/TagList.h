#ifndef DEF_ICE_TAGLIST_H
#define DEF_ICE_TAGLIST_H

typedef struct ICE_TagList ICE_TagList;

//:PUBLIC
void ICE_TagList_Add(ICE_TagList* tag_list_, ICE_TagID tag_id_);
void ICE_TagList_Remove(ICE_TagList* tag_list_, ICE_TagID tag_id_);
ICE_Bool ICE_TagList_Have(ICE_TagList* tag_list_, ICE_TagID tag_id_);
ICE_TagID* ICE_TagList_GetAllTag(ICE_TagList* tag_list_, ICE_Index * size_array_);
void ICE_TagList_GetAllTag_Free(ICE_TagID* tag_array_to_free_);

#endif