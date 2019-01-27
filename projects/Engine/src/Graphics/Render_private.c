#include "Render_private.h"

#include "../Core/TypesCore.h"
#include "../Framework/Log.h"
#include "../Core/Window.h"
#include "../Core/Window_private.h"
#include <stdio.h>

extern ICE_Core CORE;
extern ICE_Config CONFIG;
int ICE_Render_SetColor(const ICE_Color rgba_hex) {
	const int r = rgba_hex >> 24 & 255;
	const int g = rgba_hex >> 16 & 255;
	const int b = rgba_hex >> 8 & 255;
	const int a = rgba_hex & 255;
	return SDL_SetRenderDrawColor(CORE.window.render, r, g, b, a);
}

int ICE_Render_Clear() 
{
	return SDL_RenderClear(CORE.window.render);
}
void ICE_Render_Now() 
{
	SDL_RenderPresent(CORE.window.render);
}

void ICE_Render_Init()
{
	ICE_Log_Line();
	ICE_Log(ICE_LOG_RUNNING, "Render init ...");

	// Window and Render
	CORE.window.handle = SDL_CreateWindow(
		CONFIG.title,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		CONFIG.window_w,
		CONFIG.window_h,
		SDL_WINDOW_OPENGL | SDL_WINDOW_HIDDEN
	);

	if (CORE.window.handle)
		ICE_Log(ICE_LOG_SUCCES, "Window create");
	else
		ICE_Log(ICE_LOG_CRITICAL, "Window create : %s", SDL_GetError());

	if(CONFIG.vsync)
		CORE.window.render = SDL_CreateRenderer(CORE.window.handle, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	else
		CORE.window.render = SDL_CreateRenderer(CORE.window.handle, -1, SDL_RENDERER_ACCELERATED);

	if (CORE.window.render)
		ICE_Log(ICE_LOG_SUCCES, "Render create");
	else
		ICE_Log(ICE_LOG_CRITICAL, "Render create : %s", SDL_GetError());

	if (SDL_SetRenderDrawBlendMode(CORE.window.render, SDL_BLENDMODE_BLEND) == -1)
		ICE_Log(ICE_LOG_ERROR, "SDL_SetRenderDrawBlendMode : %s", SDL_GetError());

#if defined(_DEBUG)
	CORE.lateDrawDebug = NULL;
#endif

	CORE.window.w = (ICE_Float)CONFIG.window_w; CORE.window.h = (ICE_Float)CONFIG.window_h;

	ICE_Window_Config();

	ICE_Render_Info();
	
	ICE_Log(ICE_LOG_FINISH, "Render init");
	ICE_Log_Line();
}

void ICE_Render_Quit()
{
	ICE_Log_Line();
	ICE_Log(ICE_LOG_RUNNING, "Render Quit ...");

	SDL_DestroyWindow(CORE.window.handle);
	ICE_Log(ICE_LOG_SUCCES, "Window destroy");

	SDL_DestroyRenderer(CORE.window.render);
	ICE_Log(ICE_LOG_SUCCES, "Render destroy");


	ICE_Log(ICE_LOG_FINISH, "Render Quit");
	ICE_Log_Line();
}

#if defined(_DEBUG)
void ICE_Render_Info()
{
	ICE_Log(ICE_LOG_INFO, "Render Info");
	SDL_RendererInfo info_renderer;
	SDL_GetRendererInfo(CORE.window.render, &info_renderer);
	puts("");
	ICE_Log_Printf(" Renderer : %s \n", info_renderer.name);
	ICE_Log_Printf(" Max Texture Size : %dx%d\n", info_renderer.max_texture_width, info_renderer.max_texture_height);
	ICE_Log_Printf(" Renderer option : \n");
	if (info_renderer.flags |= SDL_RENDERER_ACCELERATED)
		ICE_Log_Printf("  - Accelerated\n");
	if (info_renderer.flags |= SDL_RENDERER_SOFTWARE)
		ICE_Log_Printf("  - Software\n");
	if (info_renderer.flags |= SDL_RENDERER_PRESENTVSYNC)
		ICE_Log_Printf("  - VSYNC\n");
	if (info_renderer.flags |= SDL_RENDERER_TARGETTEXTURE)
		ICE_Log_Printf("  - Target Texture\n");

	int display_index = SDL_GetWindowDisplayIndex(CORE.window.handle);
	ICE_Log_Printf(" Window on Screen : %d", display_index);
	int screen_count = SDL_GetNumVideoDisplays();
	for(int i = 0; i < screen_count; i++)
	{
		SDL_Rect screen_size;
		SDL_GetDisplayBounds(i, &screen_size);
		ICE_Log_Printf(" Screen %d : %d x %d\n", i, screen_size.w, screen_size.h);
	}
	puts("");
}
#endif