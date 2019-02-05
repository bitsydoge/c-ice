#ifndef DEF_ICE_UNITTEST_H
#define DEF_ICE_UNITTEST_H

#include "Terminal_private.h"
#include "Macrotools.h"

#define ICE_UT_EQUAL(X, Z) if(X != Z)\
	{ ICE_Log_Error("Error at line %d in file %s", __LINE__, __FILE__); ICE_Log_printf(ICE_MACROTOOLS_STRINGIZE(X## != ##Z##\n)); global_status_ut = ICE_True; global_number_error_happened++;}\

#define ICE_UT_COMPARE(X, Y, Z) if(!(X Y Z))\
	{ ICE_Log_Error("Error at line %d in file %s", __LINE__, __FILE__); ICE_Log_printf(ICE_MACROTOOLS_STRINGIZE(X##Y##Z##\n)); global_status_ut = ICE_True; global_number_error_happened++;}\

#define ICE_UT_MAIN() global_status_ut = ICE_False;\
	int global_number_error_happened = 0;\
	int ICE_UT_MAIN___(int argc, char ** argv);\
	int main(int argc, char ** argv)\
	{\
		ICE_Term_SaveColor();\
		ICE_Log_Line();\
		ICE_UT_MAIN___(argc, argv);\
		ICE_Log_printf("\n");\
		if(ICE_Memory_NbFreeToDo() != 0)\
			{global_status_ut = ICE_True; global_number_error_happened++;}\
		if(!global_status_ut)\
			{ICE_Log_Succes("No error happened");}\
		else\
			ICE_Log_Error("There are %d error in that UT", global_number_error_happened);\
		ICE_Log_Line();\
		ICE_Log_printf("\n");\
		return global_number_error_happened;\
	}\
	int ICE_UT_MAIN___(int argc, char ** argv)


#define ICE_UT_LOOP_STEP STEP
#define ICE_UT_LOOP(X) for(int ICE_UT_LOOP_STEP = 0; ICE_UT_LOOP_STEP < X; ICE_UT_LOOP_STEP++)\


#endif
