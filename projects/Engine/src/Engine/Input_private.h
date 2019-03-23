#ifndef DEF_ICE_INPUT_PRIVATE
#define DEF_ICE_INPUT_PRIVATE

#include "../Framework/String_.h"

/**
 * \brief Input struct where every key state are kept
 */
struct ICE_Input
{

	ICE_Bool				Pressed[512];
	ICE_Bool				OnPress[512];
	ICE_Bool				OnRelease[512];
	ICE_BOOL_BITFIELD		(wheelup);
	ICE_BOOL_BITFIELD		(wheeldown);
	ICE_BOOL_BITFIELD		(quit);

	ICE_BOOL_BITFIELD		(leftclic_pressed);
	ICE_BOOL_BITFIELD		(rightclic_pressed);
	ICE_BOOL_BITFIELD		(leftclic_OnPress);
	ICE_BOOL_BITFIELD		(rightclic_OnPress);
	ICE_BOOL_BITFIELD		(leftclic_OnRelease);
	ICE_BOOL_BITFIELD		(rightclic_OnRelease);

	ICE_BOOL_BITFIELD		(focus);
	unsigned int			mousex;
	unsigned int			mousey;
	ICE_String				filedrop;

}; typedef struct ICE_Input ICE_Input;

ICE_Input* ICE_Input_GetPtr();

/**
 * \brief Where SDL_Event are made and update the input structure of the engine
 */
void ICE_Input_Return();

#endif
