#ifndef DEF_ICE_DEBUG
#define DEF_ICE_DEBUG

#include "Camera.h"
#include "Entity.h"
#include "Vector.h"
#include "Font.h"
#include "Window.h"
#include <stdio.h>

void iceDebugMouseCoordinate();
void iceDebugShowFps();
void iceDebugShowFpsTitle();

#ifndef NDEBUG
#   define iceAssert(Expr, Msg) \
	iceAssert_(#Expr, Expr, __FILE__, __LINE__, Msg)
#else
#   define iceAssert(Expr, Msg) ;
#endif

void iceAssert_(const char* expr_str, int expr, const char* file, int line, const char* msg);

#endif