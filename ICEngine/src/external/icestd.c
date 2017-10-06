#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "icestd.h"

/// String (char array) to upper
void icestd_sup(char* temp)
{
	while (*temp != '\0')     // until we reach the end of the string
	{
		*temp = toupper(*temp);  // upcase the character currently pointed to by 'p'
		temp++;               // advance to the next character
	}
}

/// Return the file extension
char* icestd_ext(char *filename)
{
	char *ex = strrchr(filename, '.');
	if (!ex || ex == filename) return "";
	return ex + 1;
}

