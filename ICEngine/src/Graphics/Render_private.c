#include "Render_private.h"

#include "../Core/TypesCore.h"
#include "../Framework/Log.h"
#include "../Core/Window.h"
#include <stdio.h>

extern ICE_Core core;
extern ICE_Config config;
int ICE_Render_SetColor(const ICE_Color rgba_hex) {
	const int r = rgba_hex >> 24 & 255;
	const int g = rgba_hex >> 16 & 255;
	const int b = rgba_hex >> 8 & 255;
	const int a = rgba_hex & 255;
	return SDL_SetRenderDrawColor(core.window.render, r, g, b, a);
}

int ICE_Render_Clear() 
{
	return SDL_RenderClear(core.window.render);
}
void ICE_Render_Now() 
{
	SDL_RenderPresent(core.window.render);
}

void ICE_Render_Init()
{
	ICE_Log_Line();
	ICE_Log(ICE_LOG_RUNNING, "Render init ...");

	// Window and Render
	core.window.handle = SDL_CreateWindow(
		config.title,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		config.window_w,
		config.window_h,
		SDL_WINDOW_OPENGL | SDL_RENDERER_PRESENTVSYNC | SDL_WINDOW_RESIZABLE
	);

	if (core.window.handle)
		ICE_Log(ICE_LOG_SUCCES, "Window create");
	else
		ICE_Log(ICE_LOG_CRITICAL, "Window create : %s", SDL_GetError());

	core.window.render = SDL_CreateRenderer(core.window.handle, -1, SDL_RENDERER_ACCELERATED);
	if (core.window.render)
		ICE_Log(ICE_LOG_SUCCES, "Render create");
	else
		ICE_Log(ICE_LOG_CRITICAL, "Render create : %s", SDL_GetError());

	if (SDL_SetRenderDrawBlendMode(core.window.render, SDL_BLENDMODE_BLEND) == -1)
		ICE_Log(ICE_LOG_ERROR, "SDL_SetRenderDrawBlendMode : %s", SDL_GetError());

#if defined(_DEBUG)
	core.lateDrawDebug = NULL;
#endif

	core.window.w = (ICE_Float)config.window_w; core.window.h = (ICE_Float)config.window_h;


	ICE_Window_SetIcon(0);

	ICE_Render_Info();

	ICE_Log(ICE_LOG_FINISH, "Render init");
	ICE_Log_Line();
}

void ICE_Render_Quit()
{
	ICE_Log_Line();
	ICE_Log(ICE_LOG_RUNNING, "Render Quit ...");

	SDL_DestroyWindow(core.window.handle);
	ICE_Log(ICE_LOG_SUCCES, "Window destroy");

	SDL_DestroyRenderer(core.window.render);
	ICE_Log(ICE_LOG_SUCCES, "Render destroy");


	ICE_Log(ICE_LOG_FINISH, "Render Quit");
	ICE_Log_Line();
}

#if defined(_DEBUG)
void ICE_Render_Info()
{
	ICE_Log(ICE_LOG_INFO, "Render Info");
	SDL_RendererInfo info_renderer;
	SDL_GetRendererInfo(core.window.render, &info_renderer);
	puts("");
	ICE_Log_Printf(" Renderer : %s \n", info_renderer.name);
	ICE_Log_Printf(" Max Texture Size : %dx%d\n", info_renderer.max_texture_width, info_renderer.max_texture_height);
	ICE_Log_Printf(" Renderer option : \n")
	if (info_renderer.flags |= SDL_RENDERER_ACCELERATED)
		ICE_Log_Printf("  - Accelerated\n");
	if (info_renderer.flags |= SDL_RENDERER_SOFTWARE)
		ICE_Log_Printf("  - Software\n");
	if (info_renderer.flags |= SDL_RENDERER_PRESENTVSYNC)
		ICE_Log_Printf("  - VSYNC\n");
	if (info_renderer.flags |= SDL_RENDERER_TARGETTEXTURE)
		ICE_Log_Printf("  - Target Texture\n");

	puts("");
}
#endif