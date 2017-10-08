#ifndef DEF_ICE_INPUT
#define DEF_ICE_INPUT

#include "Type.h"

struct ICE_Input
{
	char key[512];
	int wheelup;
	int wheeldown;
	int quit;
	int leftclic;
	int leftclic_position_x;
	int leftclic_position_y;
	int leftclic_position_x_old;
	int leftclic_position_y_old;
	int leftclic_trigger;
	int rightclic;
	int rightclic_position_x;
	int rightclic_position_y;
	int rightclic_position_x_old;
	int rightclic_position_y_old;
	int rightclic_trigger;
	int mousex;
	int mousey;
	int focus;
	char *filedrop;

};

int ICE_InputReturn(ICE_Input *input);
void ICE_InputReset(ICE_Input *input);

#endif