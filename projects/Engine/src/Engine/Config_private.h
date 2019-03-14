#ifndef DEF_ICE_CONFIG_PRIVATE_H
#define DEF_ICE_CONFIG_PRIVATE_H

#include "../Framework/String_.h"

struct ICE_Config
{
	unsigned int window_w, window_h;

	unsigned int refresh_rate;

	ICE_Uint8 fullscreen;
	ICE_Bool resizable;
	ICE_Bool vsync;

	ICE_StringStd editor_name;
	ICE_StringStd product_name;
	ICE_StringStd title;
	ICE_StringStd window_icon;
	ICE_StringStd game_version;

	int argc;
	char** argv;

}; typedef struct ICE_Config ICE_Config;

#endif