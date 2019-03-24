#include "TagManager_private.h"

#include "Types.h"
#include "../Framework/Memory_.h"
#include "../Framework/Log.h"

ICE_TagManager ICE_GLOBJ_TAGMANAGER = {0};

///////////////////////////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------------------------- //
// ------------------------------------   TagManager    -------------------------------- //
// ------------------------------------------------------------------------------------- //
///////////////////////////////////////////////////////////////////////////////////////////

#define ICE_DEFAULT_TAG_SIZE 4 

//:PRIVATE
ICE_TagManager * ICE_TagManager_Get()
{
	return &ICE_GLOBJ_TAGMANAGER;
}

void ICE_TagManager_Init()
{
	ICE_TagManager tag_manager_temp = { 0 };
	tag_manager_temp.size = ICE_DEFAULT_TAG_SIZE;
	tag_manager_temp.array = ICE_Calloc(ICE_DEFAULT_TAG_SIZE, sizeof(ICE_Tag));
	
	strpool_config_t conf = strpool_default_config;
	conf.ignore_case = 1;
	strpool_init(&tag_manager_temp.pool, &conf);

	ICE_GLOBJ_TAGMANAGER = tag_manager_temp;
	ICE_Log(ICE_LOGTYPE_SUCCES, "Init TagManager");
}

void ICE_TagManager_Destroy()
{
	for(ICE_TagID i = 1; i <= ICE_GLOBJ_TAGMANAGER.size; i++)
	{
		if(ICE_Tag_Get(i)->id != 0)
			ICE_Tag_Destroy(i);
	}
	strpool_term(&ICE_GLOBJ_TAGMANAGER.pool);
}