#ifndef DEF_ICE_DEBUG_PRIVATE
#define DEF_ICE_DEBUG_PRIVATE

#define ICE_DEBUG_GET_GAME_OBJECT extern iceGame game;

#ifndef NDEBUG
#   define iceAssert(Expr, Msg) \
	iceAssert_(#Expr, Expr, __FILE__, __LINE__, Msg)
#else
#   define iceAssert(Expr, Msg) ;
#endif

void iceAssert_(const char* expr_str, int expr, const char* file, int line, const char* msg);

#endif