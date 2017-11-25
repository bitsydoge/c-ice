#ifndef DEF_ICE_TYPESGRAPHICS
#define DEF_ICE_TYPESGRAPHICS

#include <stdint.h>

#ifndef _ICE_BOOL_DEFINED
#define _ICE_BOOL_DEFINED
typedef char iceBool;
#define iceTrue 1
#define iceFalse 0
#endif

#ifndef _ICE_FLOAT_DEFINED
#define _ICE_FLOAT_DEFINED
typedef double iceFloat;
#endif

typedef SDL_Window iceWindow;
typedef SDL_Renderer iceRenderer;
typedef uint32_t iceColor;

#endif
