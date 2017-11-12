#ifndef DEF_ICE_DEBUG
#define DEF_ICE_DEBUG

#include "Camera.h"
#include "Entity.h"
#include "Font.h"
#include <stdio.h>

void ICE_DebugMouseCoordinate(ICE_Game *game);
void ICE_DebugShowFps(ICE_Game *game);

#ifndef NDEBUG
#   define ICE_Assert(Expr, Msg) \
	_ICE_Assert_(#Expr, Expr, __FILE__, __LINE__, Msg)
#else
#   define ICE_Assert(Expr, Msg) ;
#endif

void _ICE_Assert_(const char* expr_str, int expr, const char* file, int line, const char* msg);

#endif