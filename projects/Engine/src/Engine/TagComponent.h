#ifndef DEF_ICE_TAGCOMPONENT_H
#define DEF_ICE_TAGCOMPONENT_H

typedef struct ICE_TagComponent ICE_TagComponent;

//:PUBLIC
void ICE_TagComponent_Add(ICE_TagComponent* tag_manager_, ICE_TagID tag_id_);
void ICE_TagComponent_Remove(ICE_TagComponent* tag_manager_, ICE_TagID tag_id_);
ICE_Bool ICE_TagComponent_Have(ICE_TagComponent* tag_component_, ICE_TagID tag_id_);
ICE_TagID* ICE_TagComponent_GetAllTag(ICE_TagComponent* tag_component_, ICE_Index * size_array_);
void ICE_TagComponent_GetAllTag_Free(ICE_TagID* tag_array_to_free_);

#endif