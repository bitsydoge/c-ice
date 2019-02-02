#ifndef DEF_ICE_ASSET
#define DEF_ICE_ASSET
#include "../Framework/String_.h"
#include "../Framework/TypesFramework.h"
#include <stddef.h>

void ICE_Asset_PackLoad(ICE_StringStd path_);
void ICE_Asset_PackUnload(ICE_StringStd path_);
ICE_Bool ICE_Asset_FileExistInLoadedPack(ICE_StringStd path_);

#endif