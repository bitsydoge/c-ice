#ifndef DEF_ICE_ASSERT
#define DEF_ICE_ASSERT

#define ICE_DEBUG_GET_GAME_OBJECT extern ICE_Game game;

#if defined(_DEBUG)
	#define ICE_Assert(Expr, Msg) ICE_Assert_(#Expr, Expr, __FILE__, __LINE__, Msg)
#else
	#define ICE_Assert(Expr, Msg) ;
#endif

#if defined(_DEBUG)
void ICE_Assert_(const char* expr_str, int expr, const char* file, int line, const char* msg);
#endif

#endif