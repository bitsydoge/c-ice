#ifndef DEF_ICE_TYPESMATHS
#define DEF_ICE_TYPESMATHS

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