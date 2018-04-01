#ifndef DEF_ICE_TYPESMATHS
#define DEF_ICE_TYPESMATHS

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
#define ICE_false 0
#define ICE_BOOLNONE -1	
#define ICE_BoolNone -1
#define ICE_boolnone -1

#endif

#ifndef ICE_FLOAT_DEFINED
#define ICE_FLOAT_DEFINED
typedef double ICE_Float;
#endif

/**
 * \brief Vector2D
 */
struct ICE_Vect
{
	ICE_Float x;
	ICE_Float y;

}; typedef struct ICE_Vect ICE_Vect;

/**
 * \brief Box (or Rectangle)
 */
struct ICE_Box
{
	ICE_Float x;
	ICE_Float y;
	ICE_Float w;
	ICE_Float h;

}; typedef struct ICE_Box ICE_Box;

#endif