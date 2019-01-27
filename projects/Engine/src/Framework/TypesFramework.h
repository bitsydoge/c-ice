#ifndef DEF_ICE_TYPESFRAMEWORK
#define DEF_ICE_TYPESFRAMEWORK

#include <stddef.h>
#include <stdint.h>


#ifndef ICE_BOOL_DEFINED
#define ICE_BOOL_DEFINED
/**
* \brief A special bool that can be equal to 0(ICE_False) 1(ICE_True)
*/
typedef _Bool ICE_Bool;
#define ICE_True 1
#define ICE_TRUE 1
#define ICE_true 1
#define ICE_False 0
#define ICE_FALSE 0
#define ICE_false 0

#endif

#ifndef ICE_FLOAT_DEFINED
#define ICE_FLOAT_DEFINED
typedef double ICE_Float;
#endif

#ifndef ICE_INDEX_DEFINED
#define ICE_INDEX_DEFINED
typedef size_t ICE_ID;
typedef size_t ICE_Index;
#endif



#ifndef ICE_SIZED_INT_DEFINED
#define ICE_SIZED_INT_DEFINED

typedef int8_t ICE_Int8;
typedef int16_t ICE_Int16;
typedef int32_t ICE_Int32;
typedef int64_t ICE_Int64;

typedef uint8_t ICE_Uint8;
typedef uint16_t ICE_Uint16;
typedef uint32_t ICE_Uint32;
typedef uint64_t ICE_Uint64;

#endif

#endif


