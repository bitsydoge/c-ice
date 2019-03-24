#ifndef DEF_ICE_TAGCOMPONENT_PRIVATE_H
#define DEF_ICE_TAGCOMPONENT_PRIVATE_H

#include "Types.h"
#include "TagComponent.h"

struct ICE_TagComponent
{
	ICE_TagID nb_really_inside;
	ICE_TagID contain;
	ICE_TagID size;
	ICE_TagID* array;
};

//:PRIVATE
ICE_TagComponent ICE_TagComponent_Init();
void ICE_TagComponent_Destroy(ICE_TagComponent* tag_manager_);

#endif