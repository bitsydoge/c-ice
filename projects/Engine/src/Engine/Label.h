#ifndef DEF_ICE_LABEL_H
#define DEF_ICE_LABEL_H
#include "../Framework/String_.h"


struct ICE_Label
{
	ICE_FontID font_id;
	ICE_String text;
	ICE_Color color;
	int size;
	int warp_size;
}; typedef struct ICE_Label ICE_Label;


#endif