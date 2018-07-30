//
// Created by Coldragon on 30/07/2018.
//

#include "MacOS_.h"

#if defined(__APPLE__)
#include <unistd.h>
#include <CoreFoundation/CoreFoundation.h> // I UNDERSTAND NO SHIT
ICE_Char * ICE_MacOS_GetResourcesDirectory()
{
    CFURLRef url = CFBundleCopyResourcesDirectoryURL(CFBundleGetMainBundle());
    char path[PATH_MAX];
    CFURLGetFileSystemRepresentation(url, true, (UInt8*)path, sizeof(path));
    //chdir(path) != 0)
    CFRelease(url);
    return path;
}
ICE_Bool ICE_MacOS_SetWorkingDirectory(ICE_StringStd path)
{
    return chdir(path);
}
#else
ICE_Char * ICE_MacOS_GetWorkingDirectory()
{
    return "NOT_MACOS";
}
ICE_Bool ICE_MacOS_SetWorkingDirectory()
{
    return ICE_False; // Return False caus' nothing changed
}
#endif