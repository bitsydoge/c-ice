#ifndef DEF_ICE_TYPESMATHS
#define DEF_ICE_TYPESMATHS

#ifndef ICE_BOOL_DEFINED
#define ICE_BOOL_DEFINED
	typedef int iceBool;
	#define iceTrue 1
	#define iceTRUE 1
	#define icetrue 1
	#define iceFalse 0
	#define iceFALSE 0
	#define icefalse 0
#endif

#ifndef ICE_FLOAT_DEFINED
	#define ICE_FLOAT_DEFINED
	typedef double iceFloat;
#endif

typedef struct iceVect
{
	iceFloat x;
	iceFloat y;

} iceVect;

typedef struct iceRect
{
	iceVect p;
	iceFloat w;
	iceFloat h;

} iceBox;

#endif