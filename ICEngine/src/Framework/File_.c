#include "File_.h"

/// Move cursor to the next character
void ICE_File_ToNextCharacter(FILE* fichier, ICE_Char character) 
{
	int charactuel;
	do {
		charactuel = fgetc(fichier);
	} while (charactuel != character);
}

