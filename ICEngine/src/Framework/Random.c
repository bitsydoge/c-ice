#include "Random.h"

#include <time.h>
#include <stdlib.h>

#include "TypesFramework.h"
#include "Log.h"

void ICE_Random_Init()
{
	static ICE_Bool triggered = ICE_False;
	if (!triggered)
	{
		srand((unsigned int)time(NULL));
		ICE_Log(ICE_LOG_SUCCES, "Init ICE_Random");
		triggered = ICE_True;
	}
}

int ICE_Random_Int(int min, int max)
{
	int lowest, highest;
	if (min < max)
	{
		lowest = min;
		highest = max + 1;
	}
	else {
		lowest = max + 1;
		highest = min;
	}
	return (rand() % (highest - lowest)) + lowest;
}

// Return a random float between 0 and 1;
ICE_Float ICE_Random_Float()
{
	return (ICE_Float)rand() / (ICE_Float)RAND_MAX;
}