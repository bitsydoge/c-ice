#ifndef DEF_ICE_CONFIG
#define DEF_ICE_CONFIG

#include "Config.h"

ICE_Config ICE_GLOBJ_CONFIG = { 0 };

ICE_Config* ICE_Config_GetPtr()
{
	return &ICE_GLOBJ_CONFIG;
}

#endif