#include "Asset.h"
#include "../Framework/String_.h"
#include "../External/physfs/physfs.h"


void ICE_Asset_PackLoad(ICE_StringStd path_)
{
	PHYSFS_mount(path_, NULL, 1);
}

void ICE_Asset_LoadPackFromEmbedded__(const void * buffer, ICE_Uint64 lenght, ICE_StringStd dir_name)
{
	PHYSFS_mountMemory(buffer, lenght, NULL, dir_name, NULL, 1);
}

void ICE_Asset_PackUnload(ICE_StringStd path_)
{
	PHYSFS_unmount(path_);
}

ICE_Bool ICE_Asset_FileExistInLoadedPack(ICE_StringStd path_)
{
	return PHYSFS_exists(path_);
}

ICE_Bool ICE_Asset_StringPathLoadFromPack(ICE_StringStd string)
{
	if(ICE_String_STDSize(string) > 7)
	{
		if(string[0] == 'r')
			if(string[1] == 'e')
				if(string[2] == 's')
					if(string[3] == ':')
						if(string[4] == '/')
							if(string[5] == '/')
								return ICE_True;
	}
	return ICE_False;
}