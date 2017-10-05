#include <string.h>
#include <ctype.h>
#include "icestd.h"

/// String (char array) to upper
void icestd_sup(char* temp)
{
	const short nb_char = strlen(temp);
	for(int i = 0;i<nb_char;i++)
		temp[i] = toupper(temp[i]);
}

/// Return the file extension
char* icestd_ext(char *filename)
{
	char *ex = strrchr(filename, '.');
	if (!ex || ex == filename) return "";
	return ex + 1;
}

