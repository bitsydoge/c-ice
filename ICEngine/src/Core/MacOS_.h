//
// Created by ***REMOVED*** on 30/07/2018.
//

#ifndef ICE_MACOS_H
#define ICE_MACOS_H

#include "../Framework/String_.h"

#if defined(__APPLE__)
#include <unistd.h>
#include <CoreFoundation/CoreFoundation.h> // I UNDERSTAND NO SHIT
ICE_Char * ICE_MacOS_GetResourcesDirectory();
ICE_Bool ICE_MacOS_SetWorkingDirectory();
#else
ICE_Char * ICE_MacOS_GetResourcesDirectory();
ICE_Bool ICE_MacOS_SetWorkingDirectory(ICE_StringStd path);
#endif

#endif //ICENGINE_MACOS_H
