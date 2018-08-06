#ifndef DEF_ICE_GET
#define DEF_ICE_GET

//For later use or idea

/*
#include "TypesCore.h"
#include "../Framework/Inline.h"

typedef struct
{

	ICE_State * state;
	ICE_Index manager, index;

} ICE_Object;

#define ICE_OBJ1(INDEX)					ICE_Object_New(NULL, 0, INDEX)
#define ICE_OBJ2(MANAGER, INDEX)		ICE_Object_New(NULL, MANAGER, INDEX)
#define ICE_OBJ3(STATE, MANAGER, INDEX) ICE_Object_New(STATE, MANAGER, INDEX)

#define ICE_OBJ_GET_4TH_ARG(arg1, arg2, arg3, arg4, ...) arg4
#define ICE_OBJ_MACRO_CHOOSER(...) \
    ICE_OBJ_GET_4TH_ARG(__VA_ARGS__, ICE_OBJ3, \
                ICE_OBJ2, ICE_OBJ1, )

#define ICE_OBJ(...) ICE_OBJ_MACRO_CHOOSER(__VA_ARGS__)(__VA_ARGS__)
#define ICE_GET(...) ICE_OBJ_MACRO_CHOOSER(__VA_ARGS__)(__VA_ARGS__)
#define ICE_OBJECT(...) ICE_OBJ_MACRO_CHOOSER(__VA_ARGS__)(__VA_ARGS__)

ICE_INLINE ICE_Object ICE_Object_New(ICE_State * state, const ICE_Index manager, const ICE_Index index)
{
	const ICE_Object returner = { state, manager, index };
	return returner;
}
*/
#endif