#ifndef DEF_ICE_CROSSPLATFORM_H
#define DEF_ICE_CROSSPLATFORM_H

#include <stdarg.h>

#ifdef _MSC_VER
int ICE_Crossplat_vasprintf(char **strp, const char *format, va_list ap);
int ICE_Crossplat_asprintf(char **strp, const char *format, ...);
#elif
#define ICE_Crossplat_vasprintf vasprintf
#define ICE_Crossplat_asprintf asrpintf
#endif

#endif