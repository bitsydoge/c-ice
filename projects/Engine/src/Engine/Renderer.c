#include "Renderer_private.h"

#include "../Framework/Log.h"
#include <stdio.h>
#include "Color.h"
#include "Texture_private.h"

#include "Scene_private.h"
#include "Resources_private.h"
#include "Config.h"
#include "Window_private.h"
#include "GlobalData_private.h"

ICE_GLOBALDATA_RESOURCES
ICE_GLOBALDATA_SCENE_CURRENT
ICE_GLOBALDATA_CONFIG
ICE_GLOBALDATA_WINDOW
ICE_GLOBALDATA_DEBUG_LATEDRAW

ICE_Renderer ICE_GLOBJ_RENDERER = { 0 };

void ICE_Render_Color(const ICE_Color rgba_hex) 
{
	ICE_GLOBJ_SCENE_CURRENT->background_color = rgba_hex;
}

int ICE_Renderer_SetColor(const ICE_Color rgba_hex) {
	const int r = rgba_hex >> 24 & 255;
	const int g = rgba_hex >> 16 & 255;
	const int b = rgba_hex >> 8 & 255;
	const int a = rgba_hex & 255;
	return SDL_SetRenderDrawColor(ICE_GLOBJ_RENDERER.handle, r, g, b, a);
}

int ICE_Renderer_Clear()
{
	return SDL_RenderClear(ICE_GLOBJ_RENDERER.handle);
}
void ICE_Renderer_Now()
{
	SDL_RenderPresent(ICE_GLOBJ_RENDERER.handle);
}

void ICE_Renderer_SplashScreen()
{
	ICE_Renderer_SetColor(ICE_Color_New(0, 0, 0));
	ICE_Renderer_Clear();
	ICE_Texture_RenderEx2(&ICE_GLOBJ_RESOURCES.texture_logo, NULL, (ICE_Box[]) { ICE_Box_New(ICE_GLOBJ_CONFIG.window_w / 2, ICE_GLOBJ_CONFIG.window_h / 2, ICE_GLOBJ_RESOURCES.texture_logo.w, ICE_GLOBJ_RESOURCES.texture_logo.h) }, 0);
	ICE_Renderer_Now();

}

void ICE_Renderer_Init()
{
	ICE_Log_Line();
	ICE_Log(ICE_LOGTYPE_RUNNING, "Render init ...");

	// Window and Render
	ICE_GLOBJ_WINDOW.handle = SDL_CreateWindow(
		ICE_GLOBJ_CONFIG.title,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		ICE_GLOBJ_CONFIG.window_w,
		ICE_GLOBJ_CONFIG.window_h,
		SDL_WINDOW_HIDDEN
	);

	if (ICE_GLOBJ_WINDOW.handle)
		ICE_Log(ICE_LOGTYPE_SUCCES, "Window create");
	else
		ICE_Log(ICE_LOGTYPE_CRITICAL, "Window create : %s", SDL_GetError());
	if (ICE_GLOBJ_CONFIG.vsync)
		ICE_GLOBJ_RENDERER.handle = SDL_CreateRenderer(ICE_GLOBJ_WINDOW.handle, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	else
		ICE_GLOBJ_RENDERER.handle = SDL_CreateRenderer(ICE_GLOBJ_WINDOW.handle, -1, SDL_RENDERER_ACCELERATED);

	if (ICE_GLOBJ_RENDERER.handle)
		ICE_Log(ICE_LOGTYPE_SUCCES, "Render create");
	else
		ICE_Log(ICE_LOGTYPE_CRITICAL, "Render create : %s", SDL_GetError());

	if (SDL_SetRenderDrawBlendMode(ICE_GLOBJ_RENDERER.handle, SDL_BLENDMODE_BLEND) == -1)
		ICE_Log(ICE_LOGTYPE_ERROR, "SDL_SetRenderDrawBlendMode : %s", SDL_GetError());

#if defined(_DEBUG)
	ICE_GLOBJ_DEBUG_LATEDRAW = NULL;
#endif

	ICE_GLOBJ_WINDOW.w = ICE_GLOBJ_CONFIG.window_w; ICE_GLOBJ_WINDOW.h = ICE_GLOBJ_CONFIG.window_h;

	ICE_Resources_TextureLogoInit();

	ICE_Window_Config();

	ICE_Renderer_SplashScreen();

	ICE_Renderer_Info();

	ICE_Log(ICE_LOGTYPE_FINISH, "Render init");
	ICE_Log_Line();
}

void ICE_Renderer_Quit()
{
	ICE_Resources_FreeAll();

	ICE_Log_Line();
	ICE_Log(ICE_LOGTYPE_RUNNING, "Render Quit ...");

	SDL_DestroyWindow(ICE_GLOBJ_WINDOW.handle);
	ICE_Log(ICE_LOGTYPE_SUCCES, "Window destroy");

	SDL_DestroyRenderer(ICE_GLOBJ_RENDERER.handle);
	ICE_Log(ICE_LOGTYPE_SUCCES, "Render destroy");


	ICE_Log(ICE_LOGTYPE_FINISH, "Render Quit");
	ICE_Log_Line();
}

#if defined(_DEBUG)

void ICE_Renderer_Info()
{
	ICE_Log(ICE_LOGTYPE_INFO, "Render Info");
	SDL_RendererInfo info_renderer;
	SDL_GetRendererInfo(ICE_GLOBJ_RENDERER.handle, &info_renderer);
	puts("");
	ICE_Log_printf(" Renderer : %s \n", info_renderer.name);
	ICE_Log_printf(" Max Texture Size : %dx%d\n", info_renderer.max_texture_width, info_renderer.max_texture_height);
	ICE_Log_printf(" Renderer option : \n");
	if (info_renderer.flags |= SDL_RENDERER_ACCELERATED)
		ICE_Log_printf("  - Accelerated\n");
	if (info_renderer.flags |= SDL_RENDERER_SOFTWARE)
		ICE_Log_printf("  - Software\n");
	if (info_renderer.flags |= SDL_RENDERER_PRESENTVSYNC)
		ICE_Log_printf("  - VSYNC\n");
	if (info_renderer.flags |= SDL_RENDERER_TARGETTEXTURE)
		ICE_Log_printf("  - Target Texture\n");

	int display_index = SDL_GetWindowDisplayIndex(ICE_GLOBJ_WINDOW.handle);
	ICE_Log_printf(" Window on Screen : %d", display_index);
	int screen_count = SDL_GetNumVideoDisplays();
	for (int i = 0; i < screen_count; i++)
	{
		SDL_Rect screen_size;
		SDL_GetDisplayBounds(i, &screen_size);
		ICE_Log_printf(" Screen %d : %d x %d\n", i, screen_size.w, screen_size.h);
	}
	puts("");
}
#endif