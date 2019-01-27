//
// Created by Coldragon on 30/07/2018.
//

#include "MacOS_.h"

#if defined(__APPLE__)
#include <unistd.h>
#include <CoreFoundation/CoreFoundation.h> 
ICE_StringStd ICE_MacOS_GetResourcesDirectory()
{
	CFURLRef url = CFBundleCopyResourcesDirectoryURL(CFBundleGetMainBundle());
	char * returner = (char*)malloc(sizeof(char)*PATH_MAX);
	CFURLGetFileSystemRepresentation(url, true, (UInt8*)returner, sizeof(sizeof(char)*PATH_MAX));
	//chdir(path) != 0)
	CFRelease(url);
	return returner;
}
ICE_Bool ICE_MacOS_SetWorkingDirectory(ICE_StringStd path)
{
	return chdir(path);
}
#endif