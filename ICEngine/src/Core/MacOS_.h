//
// Created by Coldragon on 30/07/2018.
//

#ifndef ICE_MACOS_H
#define ICE_MACOS_H

#include "../Framework/TypesFramework.h"
#include "../Framework/String_.h"

#if defined(__APPLE__)
#include <unistd.h>
#include <CoreFoundation/CoreFoundation.h> //
ICE_Char * ICE_MacOS_GetResourcesDirectory();
ICE_Bool ICE_MacOS_SetWorkingDirectory(ICE_StringStd path);
#else
#define ICE_MacOS_GetResourcesDirectory()
#define ICE_MacOS_SetWorkingDirectory(...)
#endif

#endif //ICENGINE_MACOS_H
