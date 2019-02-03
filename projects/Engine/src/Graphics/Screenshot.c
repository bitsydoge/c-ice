#include "Screenshot.h"
#include "../Framework/TypesFramework.h"
#include "../Framework/Memory_.h"

#include "../Core/SDL2_Includer.h"
#include ICE_INCLUDE_SDL2

#include "../External/stb/stb_image_write.h"
#include "../Framework/Log.h"

#include "../Core/TypesCore.h"
#include <stdio.h>
#include <time.h>
#include "../ICE.h"

extern ICE_Core CORE;

// QOGHQSPOGHQSGHMSQLKGHMQSXVJNZS%MOZIH¨%ZBN% THIS IS HOW I FEEL AFTER TRYING TO DO A MULTI THREADED SCREENSHOT SAVER ! 
// First try and multi thread suck 

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

//#define _ICE_DEFAULT_SAVER_ARRAY_SIZE 8
//
//typedef struct
//{
//	ICE_String filepath;
//	unsigned char * data_pixels;
//	int w ,h;
//	ICE_Uint8 BytesPerPixel;
//	int pitch;
//
//} P_ICE_Image_Saver_Data;
//
//// Global
//
//SDL_Thread * thread_image_saver = NULL;
//
//// Transfer cond
//SDL_mutex * mutex_transfer_info = NULL;
//SDL_cond * cond_transfer_info = NULL;
//ICE_Bool bool_transfer_info = ICE_False;
//int waiting_transfer_info = 0;
//
//// Array Wait Queue
//SDL_mutex * mutex_data_array = NULL;
//P_ICE_Image_Saver_Data ** image_saver_data_array = NULL;
//int image_saver_data_array_tofill = 0;
//int image_saver_data_array_size = 0;
//int image_saver_data_array_next_to_treat = 0;
//int image_saver_data_array_waiting = 0;
//
//// Treat data
//SDL_mutex * mutex_data_to_treat = NULL;
//P_ICE_Image_Saver_Data * image_data_to_treat;
//
//void _ICE_Screenshot_Thread_SaveFile(P_ICE_Image_Saver_Data * data_)
//{
//	// Cast the void ptr
//	P_ICE_Image_Saver_Data * data = (P_ICE_Image_Saver_Data*)data_;
//
//	// Get Extension and upper it
//	ICE_String extension = ICE_String_GetExtension(data->filepath);
//	ICE_String_ToUpper(extension);
//	
//	// Choose the extension and write the file
//	if(SDL_strcmp(extension, "PNG"))
//		stbi_write_png(data->filepath, data->w, data->h, data->BytesPerPixel, data->data_pixels, data->pitch);
//	else if(SDL_strcmp(extension, "JPG"))
//		stbi_write_jpg(data->filepath, data->w, data->h, data->BytesPerPixel, data->data_pixels, 100);
//	else if(SDL_strcmp(extension, "TGA"))
//		stbi_write_tga(data->filepath, data->w, data->h, data->BytesPerPixel, data->data_pixels);
//	else if(SDL_strcmp(extension, "PNG"))
//		stbi_write_hdr(data->filepath, data->w, data->h, data->BytesPerPixel, data->data_pixels);
//	else if(SDL_strcmp(extension, "BMP"))
//		stbi_write_bmp(data->filepath, data->w, data->h, data->BytesPerPixel, data->data_pixels);
//	else
//	{
//		ICE_String path_update = ICE_String_Init("%s.jpg", data->filepath);
//		stbi_write_jpg(path_update, data->w, data->h, data->BytesPerPixel, data->data_pixels, 100);
//	}
//
//	//Free
//	ICE_String_Destroy(&extension);
//	ICE_String_Destroy(&data->filepath);
//	ICE_Free(data->data_pixels);
//	ICE_Free(data);
//}
//
//void _ICE_Screenshot_Thread_Upload(P_ICE_Image_Saver_Data * data_)
//{
//	SDL_LockMutex(mutex_data_array);
//	/////////////////////////////////////////////////////////////////////
//	
//	if(image_saver_data_array[image_saver_data_array_tofill] == NULL)
//	{
//		image_saver_data_array[image_saver_data_array_tofill] = data_;
//	}
//	else // No space avaible avaible
//	{
//		// Set the tofill to the first case of the new allocated memory
//		image_saver_data_array_tofill = image_saver_data_array_size;
//		// Make the array twice bigger
//		image_saver_data_array_size *=2;
//		image_saver_data_array = ICE_Realloc(image_saver_data_array, sizeof(P_ICE_Image_Saver_Data*)*image_saver_data_array_size);
//		// Set to 0 new data
//		for(int i = image_saver_data_array_tofill; i < image_saver_data_array_size; i++)
//			image_saver_data_array[i] = NULL;
//		// Add the data to the new space
//		image_saver_data_array[image_saver_data_array_tofill] = data_;
//	}
//	// One more sc is waiting
//	image_saver_data_array_waiting++;
//	// we fill the next one the next time
//	image_saver_data_array_tofill++;
//	// Reset the size to 0 if the array is ender
//	if(image_saver_data_array_tofill == image_saver_data_array_size)
//		image_saver_data_array_tofill = 0;
//
//	ICE_Log_Succes("Screenshot added to the array -> \n\tsize : %d\n\ttofill : %d\n\tnb_waiting : %d\n\tnext_to_treat : %d", 
//		image_saver_data_array_size, image_saver_data_array_tofill, image_saver_data_array_waiting, image_saver_data_array_next_to_treat);
//
//	//////////////////////////////////////////////////////////////////
//	SDL_UnlockMutex(mutex_data_array);
//}
//
//int _ICE_Screenshot_Thread_Saver(void * data_)
//{
//	ICE_Log_Info("Entering Saving Thread");
//	SDL_LockMutex(mutex_data_to_treat);
//	_ICE_Screenshot_Thread_SaveFile(image_data_to_treat);
//	SDL_UnlockMutex(mutex_data_to_treat);
//	return 0;
//}
//
//void _ICE_Screenshot_Thread_MoveNextToTreat()
//{
//	SDL_LockMutex(mutex_data_array);
//	SDL_LockMutex(mutex_data_to_treat);
//	if(image_saver_data_array[image_saver_data_array_next_to_treat] != NULL)
//	{
//		image_data_to_treat = image_saver_data_array[image_saver_data_array_next_to_treat];
//		image_saver_data_array[image_saver_data_array_next_to_treat] = NULL;
//	}
//	else
//		ICE_Log_Error("Error, no image to save from %d", image_saver_data_array_next_to_treat);
//
//	image_saver_data_array_next_to_treat++;
//	if(image_saver_data_array_next_to_treat >= image_saver_data_array_size)
//		image_saver_data_array_next_to_treat = 0;
//	SDL_UnlockMutex(mutex_data_array);
//	SDL_UnlockMutex(mutex_data_to_treat);
//}
//
//P_ICE_Image_Saver_Data * P_ICE_Image_Saver_Data_Create(ICE_String path_)
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
//
//	// Get the screen surface
//	SDL_Surface * surface = SDL_CreateRGBSurface(0,CORE.window.w,CORE.window.h,32,rmask,gmask,bmask,amask);
//	if(surface == NULL || surface->w < 1 || surface->h < 1)
//       		ICE_Log_Error("%s : Error", __func__);
//	SDL_LockSurface(surface);
//	SDL_RenderReadPixels(CORE.window.render,NULL,surface->format->format,surface->pixels,surface->pitch);
//	SDL_UnlockSurface(surface);
//	
//	// Malloc data ptr
//	P_ICE_Image_Saver_Data * data_thread = ICE_Malloc(sizeof(P_ICE_Image_Saver_Data));
//	
//	// Fill the struct
//	data_thread->filepath = ICE_String_Init(path_);
//	data_thread->BytesPerPixel = surface->format->BytesPerPixel;
//	data_thread->w = surface->w;
//	data_thread->h = surface->h;
//	data_thread->pitch = surface->pitch;
//	data_thread->data_pixels = ICE_Malloc(sizeof(unsigned char)*data_thread->pitch*data_thread->h);
//	memcpy(data_thread->data_pixels, surface->pixels, data_thread->h*data_thread->pitch);
//    
//	return data_thread;
//}
//
//ICE_Bool thread_run = ICE_True;
//
//int _ICE_Screenshot_Thread_CounterSignal(void * data_)
//{
//	ICE_Log_Info("Entering Counter Thread");
//	while(thread_run)
//	{
//		SDL_LockMutex(mutex_transfer_info);
//		while (!bool_transfer_info) 
//		{
//			SDL_CondWait(cond_transfer_info, mutex_transfer_info);
//			ICE_Log_Info("There is a screenshot to save (queue : %d)", waiting_transfer_info);
//		}
//		bool_transfer_info = ICE_False;
//		_ICE_Screenshot_Thread_MoveNextToTreat();
//		SDL_CreateThread(_ICE_Screenshot_Thread_Saver, "ICE_Image_Saver_Worker", NULL);
//		SDL_UnlockMutex(mutex_transfer_info);
//	}
//
//	return 0;
//}
//
//
//
//void _ICE_Screenshot_Thread_Init()
//{
//	mutex_data_array = SDL_CreateMutex();
//	mutex_data_to_treat = SDL_CreateMutex();
//	mutex_transfer_info = SDL_CreateMutex();
//	cond_transfer_info = SDL_CreateCond();
//	thread_image_saver = SDL_CreateThread(_ICE_Screenshot_Thread_CounterSignal, "ICE_Image_Saver_Counter", NULL);
//
//	image_saver_data_array_size = _ICE_DEFAULT_SAVER_ARRAY_SIZE;
//	image_saver_data_array = ICE_Calloc(image_saver_data_array_size, sizeof(P_ICE_Image_Saver_Data*));
//	image_data_to_treat = ICE_Malloc(sizeof(P_ICE_Image_Saver_Data));
//}
//
//void _ICE_Screenshot_Thread_Free()
//{
//	SDL_DestroyMutex(mutex_data_array);
//	SDL_DestroyMutex(mutex_data_to_treat);
//	SDL_DestroyMutex(mutex_transfer_info);
//	SDL_DestroyCond(cond_transfer_info);
//
//	ICE_Free(image_saver_data_array);
//	ICE_Free(image_data_to_treat);
//}
//
//void ICE_Screenshot_Custom(ICE_StringStd path_)
//{
//	static ICE_Bool is_init = ICE_False; // TEMP INIT
//	if(!is_init)
//	{
//		_ICE_Screenshot_Thread_Init();
//		is_init = ICE_True;
//	}
//		
//	// Screenshot data
//	P_ICE_Image_Saver_Data * data_thread = P_ICE_Image_Saver_Data_Create(path_);	
//	// Upload data
//	_ICE_Screenshot_Thread_Upload(data_thread);
//
//	SDL_LockMutex(mutex_transfer_info);
//    bool_transfer_info = ICE_True;
//	waiting_transfer_info++;
//    SDL_CondSignal(cond_transfer_info);
//    SDL_UnlockMutex(mutex_transfer_info);
//}

typedef struct
{
	ICE_String filepath;
	unsigned char* data_pixels;
	int w, h;
	ICE_Uint8 BytesPerPixel;
	int pitch;
} P_ICE_Image_Saver_Data;

int P_ICE_Thread_Image_Saver(void* data_)
{
	// Cast the void ptr
	P_ICE_Image_Saver_Data* data = (P_ICE_Image_Saver_Data*)data_;

	// Get Extension and upper it
	ICE_String extension = ICE_String_GetExtension(data->filepath);
	ICE_String_ToUpper(extension);

	// Choose the extension and write the file
	if (SDL_strcmp(extension, "PNG") != 0)
		stbi_write_png(data->filepath, data->w, data->h, data->BytesPerPixel, data->data_pixels, data->pitch);
	else if (SDL_strcmp(extension, "JPG") != 0)
		stbi_write_jpg(data->filepath, data->w, data->h, data->BytesPerPixel, data->data_pixels, 100);
	else if (SDL_strcmp(extension, "TGA") != 0)
		stbi_write_tga(data->filepath, data->w, data->h, data->BytesPerPixel, data->data_pixels);
	else if (SDL_strcmp(extension, "HDR") != 0)
		stbi_write_hdr(data->filepath, data->w, data->h, data->BytesPerPixel, data->data_pixels);
	else if (SDL_strcmp(extension, "BMP") != 0)
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

P_ICE_Image_Saver_Data* P_ICE_Image_Saver_Data_Create(ICE_StringStd path_)
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
	SDL_Surface* surface = SDL_CreateRGBSurface(0, CORE.window.w, CORE.window.h, 32, rmask, gmask, bmask, amask);
	if (surface == NULL || surface->w < 1 || surface->h < 1)
	{
		ICE_Log_Error("%s : Error (file : %s, line : %d)", __FUNCTION__, __FILE__, __LINE__);
		return NULL;
	}
	SDL_LockSurface(surface);
	SDL_RenderReadPixels(CORE.window.render,NULL, surface->format->format, surface->pixels, surface->pitch);
	SDL_UnlockSurface(surface);

	// Malloc data ptr
	P_ICE_Image_Saver_Data* data_thread = ICE_Malloc(sizeof(P_ICE_Image_Saver_Data));

	// Fill the struct
	data_thread->filepath = ICE_String_Init(path_);
	data_thread->BytesPerPixel = surface->format->BytesPerPixel;
	data_thread->w = surface->w;
	data_thread->h = surface->h;
	data_thread->pitch = surface->pitch;
	data_thread->data_pixels = ICE_Malloc(sizeof(unsigned char) * data_thread->pitch * data_thread->h);
	memcpy(data_thread->data_pixels, surface->pixels, data_thread->h * data_thread->pitch);

	return data_thread;
}

void ICE_Screenshot(ICE_StringStd path_to_save_, ICE_StringStd filetype)
{
	time_t now = time(NULL);
	struct tm* t = localtime(&now);
	ICE_String temp = NULL;

	if(filetype == NULL)
		filetype = "jpg";

	if (path_to_save_ == NULL || SDL_strcmp(path_to_save_, "") != 0)
		temp = ICE_String_Init("screenshot_%04d%02d%02d_%02d%02d%02d_%d.%s", t->tm_year + 1900, t->tm_mon + 1,
		                       t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec, ICE_Time_GetMS() % 1000, filetype);
	else
		temp = ICE_String_Init("%s/screenshot_%04d%02d%02d_%02d%02d%02d_%d.%s", path_to_save_, t->tm_year + 1900,
		                       t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec, ICE_Time_GetMS() % 1000, filetype);

	ICE_Screenshot_Custom(temp);
	ICE_String_Destroy(&temp);
}

void ICE_Screenshot_Custom(ICE_StringStd path_)
{
	P_ICE_Image_Saver_Data* data_thread = P_ICE_Image_Saver_Data_Create(path_);
	// Create the thread
	SDL_Thread* saver = SDL_CreateThread(P_ICE_Thread_Image_Saver, "ICE Image Saver", data_thread);
	SDL_DetachThread(saver);
}
