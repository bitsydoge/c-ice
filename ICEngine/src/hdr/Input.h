#ifndef DEF_ICE_INPUT
#define DEF_ICE_INPUT
#include <SDL2/SDL.h>

typedef struct
{
	char key[SDL_NUM_SCANCODES];
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
	int window_maximize;
	SDL_Rect window_maximize_old;
	char *filedrop;

} ICE_Input;

int ICE_InputReturn(ICE_Input *input);
void ICE_InputReset(ICE_Input *input);

#endif