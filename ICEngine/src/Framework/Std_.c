﻿#include "Std_.h"
#include <string.h>
#include <ctype.h>

/// String (char array) to upper
void icestd_sup(char* temp) {
	while (*temp != '\0') {
		*temp = toupper(*temp);
		temp++;
	}
}

/// Return the file extension
char* icestd_ext(char *filename) {
	char *ex = strrchr(filename, '.');
	if (!ex || ex == filename) return "";
	return ex + 1;
}

/// Move cursor to the next character
void icestd_tnc(FILE* fichier, const int character) {
	int charactuel;
	do {
		charactuel = fgetc(fichier);
	} while (charactuel != character);
}