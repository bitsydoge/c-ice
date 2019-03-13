#include "Crossplatform_.h"
#include <stdarg.h>
#include "Memory_.h"
#include <stdio.h>

#ifdef _MSC_VER
#define vscprintf _vscprintf
#endif

#ifdef __GNUC__
int vscprintf(const char *format, va_list ap)
{
    va_list ap_copy;
    va_copy(ap_copy, ap);
    int retval = vsnprintf(NULL, 0, format, ap_copy);
    va_end(ap_copy);
    return retval;
}
#endif

#ifdef _MSC_VER

int ICE_Xplat_vasprintf(char **strp, const char *format, va_list ap)
{
    int len = vscprintf(format, ap);
    if (len == -1)
        return -1;
    char *str = (char*)ICE_Malloc((size_t) len + 1);
    if (!str)
        return -1;
    int retval = vsnprintf(str, len + 1, format, ap);
    if (retval == -1) {
        ICE_Free(str);
        return -1;
    }
    *strp = str;
    return retval;
}

int ICE_Xplat_asprintf(char **strp, const char *format, ...)
{
    va_list ap;
    va_start(ap, format);
    int retval = ICE_Xplat_vasprintf(strp, format, ap);
    va_end(ap);
    return retval;
}

#endif