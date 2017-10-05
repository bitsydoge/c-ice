#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "icestd.h"

/// String (char array) to upper
void icestd_sup(char* temp)
{
	const int nb_char = strlen(temp);
	printf("taille : %d\n", nb_char);
	for(int i = 0;i<nb_char;i++)
	{
		temp[i] = toupper(temp[i]);	
		printf("%d", i);
	}
}

/// Return the file extension
char* icestd_ext(char *filename)
{
	char *ex = strrchr(filename, '.');
	if (!ex || ex == filename) return "";
	return ex + 1;
}

