#ifndef DEF_ICE_DEBUG
#define DEF_ICE_DEBUG

void iceDebugMouseCoordinate();
void iceDebugShowFps();
void iceDebugShowFpsTitle();

#define ICE_DEBUG_GET_GAME_OBJECT extern iceGame game;

#ifndef NDEBUG
#   define iceAssert(Expr, Msg) \
	iceAssert_(#Expr, Expr, __FILE__, __LINE__, Msg)
#else
#   define iceAssert(Expr, Msg) ;
#endif

void iceAssert_(const char* expr_str, int expr, const char* file, int line, const char* msg);

#endif