#ifndef DEF_ICE_TYPESFRAMEWORK
#define DEF_ICE_TYPESFRAMEWORK

#include <stddef.h>


#ifndef ICE_BOOL_DEFINED
#define ICE_BOOL_DEFINED

/**
* \brief A special bool that can be equal to 0(ICE_False) 1(ICE_True) or -1(ICE_BoolNone).
* The last one is for some function where the use of ICE_BoolNone is documented
*/
typedef int ICE_Bool;
#define ICE_True 1
#define ICE_TRUE 1
#define ICE_true 1
#define ICE_False 0
#define ICE_FALSE 0
#define ICE_false 0²²
#endif

#ifndef ICE_FLOAT_DEFINED
#define ICE_FLOAT_DEFINED
typedef double ICE_Float;
#endif

#ifndef ICE_INDEX_DEFINED
#define ICE_INDEX_DEFINED
typedef size_t ICE_Index;
#endif

#ifndef ICE_SIZED_INT_DEFINED
#define ICE_SIZED_INT_DEFINED

typedef signed __int8 ICE_Int8;
typedef signed __int16 ICE_Int16;
typedef signed __int32 ICE_Int32;
typedef signed __int64 ICE_Int64;

typedef unsigned __int8 ICE_Uint8;
typedef unsigned __int16 ICE_Uint16;
typedef unsigned __int32 ICE_Uint32;
typedef unsigned __int64 ICE_Uint64;


#endif

#endif


