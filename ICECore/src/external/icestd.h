#ifndef DEF_ICE_STD
#define DEF_ICE_STD

#include <math.h>

void icestd_sup(char* temp);
char* icestd_ext(char *filename);
void icestd_tnc(FILE* fichier, int character);
// Move point to an other point from a r distance in float
void move_from_angle(float *x, float *y, double angle, float r);
// Calculate the angle for two point in degree
double angle_calculate_degree(float x1, float y1, float x2, float y2);
// Calculate the angle for two point in radiant
double angle_calculate_radiant(float x1, float y1, float x2, float y2);
void move_position_r(float *x1, float *y1, float x2, float y2, float r);
int rect_align_collision(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2);

#endif
