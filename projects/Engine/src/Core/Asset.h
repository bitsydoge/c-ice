#ifndef DEF_ICE_ASSET
#define DEF_ICE_ASSET
#include "../Framework/String_.h"
#include "../Framework/TypesFramework.h"
#include "../Framework/Macrotools.h"

#define ICE_Asset_LoadPackFromEmbedded(S) ICE_Asset_LoadPackFromEmbedded__(S, S##_length, ICE_MACROTOOLS_STRINGIZE(S));

void ICE_Asset_PackLoad(ICE_StringStd path_);
void ICE_Asset_PackUnload(ICE_StringStd path_);
ICE_Bool ICE_Asset_FileExistInLoadedPack(ICE_StringStd path_);
ICE_Bool ICE_Asset_StringPathLoadFromPack(ICE_StringStd string);
void ICE_Asset_LoadPackFromEmbedded__(const void * buffer, ICE_Uint64 lenght, ICE_StringStd dir_name);
#endif