#ifndef DEF_ICE_CROSSPLATFORM_H
#define DEF_ICE_CROSSPLATFORM_H

#include <stdarg.h>

#ifdef _MSC_VER
int ICE_Xplat_vasprintf(char **strp, const char *format, va_list ap);
int ICE_Xplat_asprintf(char **strp, const char *format, ...);
#elif
#define ICE_Xplat_vasprintf vasprintf
#define ICE_Xplat_asprintf asrpintf
#endif

#endif