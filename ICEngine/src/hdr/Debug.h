#ifndef DEF_iceDEBUG
#define DEF_iceDEBUG

#include "Camera.h"
#include "Entity.h"
#include "Vector.h"
#include "Font.h"
#include <stdio.h>

void iceDebugMouseCoordinate(iceGame *game);
void iceDebugShowFps(iceGame *game);
void iceDebugShowFpsTitle(iceGame *game);

#ifndef NDEBUG
#   define iceAssert(Expr, Msg) \
	_iceAssert_(#Expr, Expr, __FILE__, __LINE__, Msg)
#else
#   define iceAssert(Expr, Msg) ;
#endif

void _iceAssert_(const char* expr_str, int expr, const char* file, int line, const char* msg);

#endif