#define STRPOOL_IMPLEMENTATION
#include "../External/libs/strpool.h"

#include "Tag_private.h"

ICE_TagManager ICE_GLOBJ_TAGMANAGER = { 0 };

ICE_TagManager* ICE_TagManager_Get()
{
	return &ICE_GLOBJ_TAGMANAGER;
}

void ICE_TagManager_Init()
{
	strpool_config_t conf = strpool_default_config;
	conf.ignore_case = 1;
	strpool_init(&ICE_TagManager_Get()->pool, &conf);
}

void ICE_TagManager_Destroy()
{
	
}

