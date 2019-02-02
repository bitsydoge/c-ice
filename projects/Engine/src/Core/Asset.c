#include "Asset.h"
#include "../Framework/String_.h"
#include "../External/physfs/physfs.h"


void ICE_Asset_PackLoad(ICE_StringStd path_)
{
	PHYSFS_mount(path_, NULL, 1);
}

void ICE_Asset_PackUnload(ICE_StringStd path_)
{
	PHYSFS_unmount(path_);
}

ICE_Bool ICE_Asset_FileExistInLoadedPack(ICE_StringStd path_)
{
	return PHYSFS_exists(path_);
}