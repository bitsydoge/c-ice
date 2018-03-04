#ifndef DEF_ICE_DEBUG_PRIVATE
#define DEF_ICE_DEBUG_PRIVATE

#define ICE_DEBUG_GET_GAME_OBJECT extern ICE_Game game;

#ifndef NDEBUG
#   define ICE_Assert(Expr, Msg) \
	iceAssert_(#Expr, Expr, __FILE__, __LINE__, Msg)
#else
#   define iceAssert(Expr, Msg) ;
#endif

void ICE_Assert_(const char* expr_str, int expr, const char* file, int line, const char* msg);

#endif