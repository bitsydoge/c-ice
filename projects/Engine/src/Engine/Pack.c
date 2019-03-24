#include "../Framework/BasicTypes.h"
#include "../Framework/String_.h"
#include "../External/physfs/physfs.h"
#include <stddef.h>

void ICE_Pack_Load(ICE_StringStd path_)
{
	PHYSFS_mount(path_, NULL, 1);
}

void ICE_Pack_Load_MEM__(const void* buffer, ICE_Uint64 lenght, ICE_StringStd dir_name)
{
	PHYSFS_mountMemory(buffer, lenght, NULL, dir_name, NULL, 1);
}

void ICE_Pack_Unload(ICE_StringStd path_)
{
	PHYSFS_unmount(path_);
}

ICE_Bool ICE_Pack_FileExist(ICE_StringStd path_)
{
	return PHYSFS_exists(path_);
}

ICE_Bool ICE_Pack_isPathFromPak(ICE_StringStd path_)
{
	if (ICE_StringStd_Size(path_) > 7)
	{
		if (path_[0] == 'r')
			if (path_[1] == 'e')
				if (path_[2] == 's')
					if (path_[3] == ':')
						if (path_[4] == '/')
							if (path_[5] == '/')
								return ICE_True;
	}
	return ICE_False;
}