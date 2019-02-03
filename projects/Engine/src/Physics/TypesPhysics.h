#ifndef DEF_ICE_TYPESPHYSICS
#define DEF_ICE_TYPESPHYSICS

#ifndef ICE_BOOL_DEFINED
#define ICE_BOOL_DEFINED
typedef _Bool ICE_Bool;
#define ICE_True 1
#define ICE_TRUE 1
#define ICE_true 1
#define ICE_False 0
#define ICE_FALSE 0
#define ICE_false 0
#define ICE_BOOL_BITFIELD(S) ICE_Bool S : 1
#endif

#endif