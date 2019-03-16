#ifndef DEF_ICE_VERSION_H
#define DEF_ICE_VERSION_H

#include "../Framework/Inline.h"
#include "../Framework/String_.h"

#define ICE_VERSION "NXT.1903.1"

ICE_StringStd ICE_Core_GetLinkedVersion();
ICE_INLINE ICE_StringStd ICE_Core_GetCompiledVersion()
{
	return ICE_VERSION;
}

#endif