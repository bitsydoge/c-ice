#ifndef DEF_ICE_TAGMANAGER_PRIVATE_H
#define DEF_ICE_TAGMANAGER_PRIVATE_H

#define STRPOOL_U64 size_t
#include "../External/libs/strpool.h"

#include "TagManager.h"
#include "Tag_private.h"

struct ICE_TagManager
{
	strpool_t pool;
	ICE_TagID contain;
	ICE_TagID size;
	ICE_Tag * array;
};

//:PRIVATE
ICE_TagManager* ICE_TagManager_Get();
void ICE_TagManager_Init();
void ICE_TagManager_Destroy();

#endif