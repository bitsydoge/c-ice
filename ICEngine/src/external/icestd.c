#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "icestd.h"

/// String (char array) to upper
void icestd_sup(char* temp)
{
	while (*temp != '\0')     
	{
		*temp = toupper(*temp);  
		temp++;
	}
}

/// Return the file extension
char* icestd_ext(char *filename)
{
	char *ex = strrchr(filename, '.');
	if (!ex || ex == filename) return "";
	return ex + 1;
}

/// Move cursor to the next character
void icestd_tnc(FILE* fichier, int character)
{
	int charactuel = 0;
	do
	{
		charactuel = fgetc(fichier);
	} while (charactuel != character);
}

// Move point to an other point from a r distance in float
void move_from_angle(float *x, float *y, double angle, float r) {
	*x += r * cos(angle); *y += r * sin(angle);
}

// Calculate the angle for two point in degree
double angle_calculate_degree(float x1, float y1, float x2, float y2) {
	float xdif = x2 - x1; float ydif = y2 - y1;
	return 57.29*atan2(ydif, xdif);
}

// Calculate the angle for two point in radiant
double angle_calculate_radiant(float x1, float y1, float x2, float y2) {
	float xdif = x2 - x1; float ydif = y2 - y1;
	return atan2(ydif, xdif);
}

void move_position_r(float *x1, float *y1, float x2, float y2, float r) {
	float xdif = x2 - *x1; float ydif = y2 - *y1;
	float angle = atan2(ydif, xdif);
	float distance_r_r = xdif*xdif + ydif*ydif;
	*x1 += r * cos(angle); *y1 += r * sin(angle);
	if (distance_r_r < r*r) {
		*x1 = x2;
		*y1 = y2;
	}
}

// return 1 if it colide

int rect_align_collision(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2)
{
	if(x1<(x2+w2)&&x1+w1>x2&&y1<y2+h2&&h1+y1>y2)
		return 1;
	return 0;
}