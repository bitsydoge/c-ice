#include "Window_private.h"
#include "../External/stb/SDL_stbimage.h"
#include "../Framework/Log.h"

ICE_Window ICE_GLOBJ_WINDOW = {0};


#include "GlobalData_private.h"
ICE_GLOBALDATA_WINDOW
#include "Config_private.h"
ICE_GLOBALDATA_CONFIG

void ICE_Window_Config()
{
	if (ICE_GLOBJ_CONFIG.resizable)
		ICE_Window_SetResizable(1);

	if (ICE_GLOBJ_CONFIG.fullscreen == 1)
		ICE_Window_SetFullscreen(SDL_WINDOW_FULLSCREEN);

	if (ICE_GLOBJ_CONFIG.fullscreen == 2)
	{
		int display_index = SDL_GetWindowDisplayIndex(ICE_GLOBJ_WINDOW.handle);
		SDL_Rect screen_size;
		SDL_GetDisplayBounds(display_index, &screen_size);
		ICE_Window_SetSize(screen_size.w, screen_size.h);
		ICE_Window_SetFullscreen(SDL_WINDOW_FULLSCREEN_DESKTOP);
	}
	ICE_Window_SetIcon(ICE_GLOBJ_CONFIG.window_icon);
	SDL_ShowWindow(ICE_GLOBJ_WINDOW.handle);
}

void ICE_Window_SetSize(int w, int h)
{
	SDL_SetWindowSize(ICE_GLOBJ_WINDOW.handle, w, h);
	ICE_GLOBJ_WINDOW.w = w; ICE_GLOBJ_WINDOW.h = h;
}

void ICE_Window_SetResizable(ICE_Bool yn)
{
	SDL_SetWindowResizable(ICE_GLOBJ_WINDOW.handle, yn);
}

void ICE_Window_SetFullscreen(int yn)
{
	SDL_SetWindowFullscreen(ICE_GLOBJ_WINDOW.handle, yn);
}

void ICE_Window_SetTitle(const char* title)
{
	SDL_SetWindowTitle(ICE_GLOBJ_WINDOW.handle, title);
}

void ICE_Window_SetIcon(char* path)
{
	if (!path)
	{
#include "../Ressources/raw/Icon.c"

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
		int shift = (ice_raw_img_icon.bytes_per_pixel == 3) ? 8 : 0;
		Uint32 rmask = 0xff000000 >> shift;
		Uint32 gmask = 0x00ff0000 >> shift;
		Uint32 bmask = 0x0000ff00 >> shift;
		Uint32 amask = 0x000000ff >> shift;
#else // little endian, like x86
		Uint32 rmask = 0x000000ff;
		Uint32 gmask = 0x0000ff00;
		Uint32 bmask = 0x00ff0000;
		Uint32 amask = (ice_raw_img_icon.bytes_per_pixel == 3) ? 0 : 0xff000000;
#endif

		SDL_Surface * icon = SDL_CreateRGBSurfaceFrom((void*)ice_raw_img_icon.pixel_data, ice_raw_img_icon.width,
			ice_raw_img_icon.height, ice_raw_img_icon.bytes_per_pixel * 8, ice_raw_img_icon.bytes_per_pixel * ice_raw_img_icon.width,
			rmask, gmask, bmask, amask);

		SDL_SetWindowIcon(ICE_GLOBJ_WINDOW.handle, icon);

		SDL_FreeSurface(icon);
	}
	else
	{

		SDL_Surface* icon = STBIMG_Load(path);

		if (icon == NULL)
			ICE_Log(ICE_LOGTYPE_ERROR, "ICE_Window_SetIcon : %s", SDL_GetError);

		SDL_SetWindowIcon(ICE_GLOBJ_WINDOW.handle, icon);
		SDL_FreeSurface(icon);
	}
}

int ICE_Window_GetW()
{
	return (int)ICE_GLOBJ_WINDOW.w;
}
int ICE_Window_GetH()
{
	return (int)ICE_GLOBJ_WINDOW.h;
}