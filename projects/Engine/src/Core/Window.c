#include "Window.h"
#include "TypesCore.h"
#include ICE_INCLUDE_SDL2
#include "../External/stb/SDL_stbimage.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../External/stb/stb_image_write.h"
#include "../Framework/Log.h"
#include "../Framework/Memory_.h"

extern ICE_Game GAME;
extern ICE_Core CORE;

void ICE_Window_SetSize(int w, int h)
{
	SDL_SetWindowSize(CORE.window.handle, w, h);
	CORE.window.w = w; CORE.window.h = h;
}

void ICE_Window_SetResizable(ICE_Bool yn)
{
	SDL_SetWindowResizable(CORE.window.handle, yn);
}

void ICE_Window_SetFullscreen(int yn)
{
	SDL_SetWindowFullscreen(CORE.window.handle, yn);
}

void ICE_Window_SetTitle(const char *title)
{
	SDL_SetWindowTitle(CORE.window.handle, title);
}

void ICE_Window_SetIcon(char * path)
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

		SDL_Surface* icon = SDL_CreateRGBSurfaceFrom((void*)ice_raw_img_icon.pixel_data, ice_raw_img_icon.width,
			ice_raw_img_icon.height, ice_raw_img_icon.bytes_per_pixel * 8, ice_raw_img_icon.bytes_per_pixel*ice_raw_img_icon.width,
			rmask, gmask, bmask, amask);

		SDL_SetWindowIcon(CORE.window.handle, icon);

		SDL_FreeSurface(icon);
	}
	else
	{
		SDL_Surface *icon = STBIMG_Load(path);

		if (icon == NULL)
			ICE_Log(ICE_LOGTYPE_ERROR, "ICE_Window_SetIcon : %s", SDL_GetError);
		
		SDL_SetWindowIcon(CORE.window.handle, icon);
		SDL_FreeSurface(icon);
	}
}

int ICE_Window_GetW()
{
	return (int)CORE.window.w;
}
int ICE_Window_GetH()
{
	return (int)CORE.window.h;
}

//void ICE_Window_ScreenshotB(ICE_StringStd path_)
//{
//#if SDL_BYTEORDER == SDL_BIG_ENDIAN
//    Uint32 rmask = 0xff000000;
//    Uint32 gmask = 0x00ff0000;
//    Uint32 bmask = 0x0000ff00;
//    Uint32 amask = 0x000000ff;  
//#else
//    Uint32 rmask = 0x000000ff;
//    Uint32 gmask = 0x0000ff00;
//    Uint32 bmask = 0x00ff0000;
//    Uint32 amask = 0xff000000;
//#endif
//	SDL_Surface * surface = SDL_CreateRGBSurface(0,CORE.window.w,CORE.window.h,32,rmask,gmask,bmask,amask);
//	SDL_LockSurface(surface);
//	SDL_RenderReadPixels(CORE.window.render,NULL,surface->format->format,surface->pixels,surface->pitch);
//	if(SDL_SaveBMP(surface,path_))
//		ICE_Log_Error("Error with SDL_SaveBMP(screen_surface, \"%s\") : %s", path_, SDL_GetError());
//	else
//		ICE_Log_Succes("Screenshot created in : %s", path_);
//	SDL_UnlockSurface(surface);
//	SDL_FreeSurface(surface);
//}

void _ICE_Screenshot_Thread_Init()
{
	
}

void _ICE_Screenshot_Thread_SaveFile()
{
	
}

typedef struct
{
	ICE_String filepath;
	unsigned char * data_pixels;
	int w ,h;
	ICE_Uint8 BytesPerPixel;
	int pitch;

} _ICE_Image_Saver_Data;

int _ICE_Image_Saver(void * data_)
{
	// Cast the void ptr
	_ICE_Image_Saver_Data * data = (_ICE_Image_Saver_Data*)data_;

	// Get Extension and upper it
	ICE_String extension = ICE_String_GetExtension(data->filepath);
	ICE_String_ToUpper(extension);
	
	// Choose the extension and write the file
	if(SDL_strcmp(extension, "PNG"))
		stbi_write_png(data->filepath, data->w, data->h, data->BytesPerPixel, data->data_pixels, data->pitch);
	else if(SDL_strcmp(extension, "JPG"))
		stbi_write_jpg(data->filepath, data->w, data->h, data->BytesPerPixel, data->data_pixels, 100);
	else if(SDL_strcmp(extension, "TGA"))
		stbi_write_tga(data->filepath, data->w, data->h, data->BytesPerPixel, data->data_pixels);
	else if(SDL_strcmp(extension, "PNG"))
		stbi_write_hdr(data->filepath, data->w, data->h, data->BytesPerPixel, data->data_pixels);
	else if(SDL_strcmp(extension, "BMP"))
		stbi_write_bmp(data->filepath, data->w, data->h, data->BytesPerPixel, data->data_pixels);
	else
	{
		ICE_String path_update = ICE_String_Init("%s.jpg", data->filepath);
		stbi_write_jpg(path_update, data->w, data->h, data->BytesPerPixel, data->data_pixels, 100);
	}

	//Free
	ICE_String_Destroy(&extension);
	ICE_String_Destroy(&data->filepath);
	ICE_Free(data->data_pixels);
	ICE_Free(data);
	return 0;
}

_ICE_Image_Saver_Data * _ICE_Image_Saver_Data_Create(ICE_String path_)
{
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    Uint32 rmask = 0xff000000;
    Uint32 gmask = 0x00ff0000;
    Uint32 bmask = 0x0000ff00;
    Uint32 amask = 0x000000ff;  
#else
    Uint32 rmask = 0x000000ff;
    Uint32 gmask = 0x0000ff00;
    Uint32 bmask = 0x00ff0000;
    Uint32 amask = 0xff000000;
#endif

	// Get the screen surface
	SDL_Surface * surface = SDL_CreateRGBSurface(0,CORE.window.w,CORE.window.h,32,rmask,gmask,bmask,amask);
	if(surface == NULL || surface->w < 1 || surface->h < 1)
       		ICE_Log_Error("%s : Error", __func__);
	SDL_LockSurface(surface);
	SDL_RenderReadPixels(CORE.window.render,NULL,surface->format->format,surface->pixels,surface->pitch);
	SDL_UnlockSurface(surface);
	
	// Malloc data ptr
	_ICE_Image_Saver_Data * data_thread = ICE_Malloc(sizeof(_ICE_Image_Saver_Data));
	
	// Fill the struct
	data_thread->filepath = ICE_String_Init(path_);
	data_thread->BytesPerPixel = surface->format->BytesPerPixel;
	data_thread->w = surface->w;
	data_thread->h = surface->h;
	data_thread->pitch = surface->pitch;
	data_thread->data_pixels = ICE_Malloc(sizeof(unsigned char)*data_thread->pitch*data_thread->h);
	memcpy(data_thread->data_pixels, surface->pixels, data_thread->h*data_thread->pitch);
    
	return data_thread;
}

void ICE_Window_Screenshot(ICE_StringStd path_)
{
	_ICE_Image_Saver_Data * data_thread = _ICE_Image_Saver_Data_Create(path_);	
	// Create the thread
	SDL_Thread * saver = SDL_CreateThread(_ICE_Image_Saver, "ICE Image Saver", data_thread);
}