#include "Resources_private.h"

#include "Renderer_private.h"
#include "Texture_private.h"

ICE_Resources ICE_GLOBJ_RESOURCES = { 0 };
extern ICE_Renderer ICE_GLOBJ_RENDERER;

void ICE_Texture_ErrorInit()
{
	SDL_RendererInfo info_renderer;
	SDL_GetRendererInfo(ICE_GLOBJ_RENDERER.render, &info_renderer);
	if (info_renderer.max_texture_width >= 1024 && info_renderer.max_texture_height >= 1024)
	{
#include "../Ressources/bin/err1024_png.c"
		ICE_GLOBJ_RESOURCES.texture_error = ICE_Texture_LoadFromFile_RW(SDL_RWFromMem((void*)ICE_Ressource_err1024_png, ICE_Ressource_err1024_png_length));
	}
	else
	{
#include "../Ressources/bin/err512_png.c"
		ICE_GLOBJ_RESOURCES.texture_error = ICE_Texture_LoadFromFile_RW(SDL_RWFromMem((void*)ICE_Ressource_err512_png, ICE_Ressource_err512_png_length));
	}
}

void ICE_Texture_DefaultGuiInit()
{
#include "../Ressources/bin/gui27_png.c"
	ICE_GLOBJ_RESOURCES.texture_gui_default = ICE_Texture_LoadFromFile_RW(SDL_RWFromMem((void*)ICE_Ressource_gui27_png, ICE_Ressource_gui27_png_length));
}

void ICE_Texture_LogoInit()
{
#include "../Ressources/bin/logo_png.c"
	ICE_GLOBJ_RESOURCES.texture_logo = ICE_Texture_LoadFromFile_RW(SDL_RWFromMem((void*)ICE_Ressource_logo_png, ICE_Ressource_logo_png_length));
}

void ICE_Texture_DefaultGuiFree()
{
	ICE_Texture_Free(&ICE_GLOBJ_RESOURCES.texture_gui_default);
}

void ICE_Texture_ErrorFree()
{
	ICE_Texture_Free(&ICE_GLOBJ_RESOURCES.texture_error);
}

void ICE_Texture_LogoFree()
{
	ICE_Texture_Free(&ICE_GLOBJ_RESOURCES.texture_error);
}

void ICE_Texture_DefaultAllFree()
{
	ICE_Texture_DefaultGuiFree();
	ICE_Texture_ErrorFree();
	ICE_Texture_LogoFree();
}