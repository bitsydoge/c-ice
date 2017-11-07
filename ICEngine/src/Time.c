#include "hdr/Time.h"

int ICE_Random(int min, int max)
{
	int result = 0, lowest = 0, highest = 0;

	if (min < max)
	{
		lowest = min;
		highest = max + 1;
	}
	else {
		lowest = max + 1;
		highest = min;
	}

	result = (rand() % (highest - lowest)) + lowest;
	return result;
}
