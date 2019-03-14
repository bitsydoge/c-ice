#include "Random.h"

#include <time.h>
#include <stdlib.h>

#include "BasicTypes.h"
#include "Log.h"

#if defined(__linux__) || defined(_POSIX_VERSION)
#include <unistd.h>
#define GET_PID_ getpid
#elif defined(_WIN32) || defined(_WIN64) || defined(_MSC_VER)
#include <process.h>
#define GETPID_ _getpid
#endif

unsigned long mix(unsigned long a, unsigned long b, unsigned long c)
{
    a=a-b;  a=a-c;  a=a^(c >> 13);
    b=b-c;  b=b-a;  b=b^(a << 8);
    c=c-a;  c=c-b;  c=c^(b >> 13);
    a=a-b;  a=a-c;  a=a^(c >> 12);
    b=b-c;  b=b-a;  b=b^(a << 16);
    c=c-a;  c=c-b;  c=c^(b >> 5);
    a=a-b;  a=a-c;  a=a^(c >> 3);
    b=b-c;  b=b-a;  b=b^(a << 10);
    c=c-a;  c=c-b;  c=c^(b >> 15);
    return c;
}

void ICE_Random_Init()
{
	static ICE_Bool triggered = ICE_False;
	if (!triggered)
	{
		const unsigned int seed = mix(clock(), time(NULL), GETPID_());
		srand(seed);
		ICE_Log(ICE_LOGTYPE_SUCCES, "Init ICE_Random");
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