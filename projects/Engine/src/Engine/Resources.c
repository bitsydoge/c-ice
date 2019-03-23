#include "Resources_private.h"

#include "Renderer_private.h"
#include "Texture_private.h"

#include "Font.h"

ICE_Resources ICE_GLOBJ_RESOURCES = { 0 };

ICE_Resources * ICE_Resources_Get()
{
	return &ICE_GLOBJ_RESOURCES;
}



void ICE_Resources_TextureLogoInit()
{
#include "../Resources/bin/logo_png.c"
	ICE_GLOBJ_RESOURCES.texture_logo = ICE_Texture_LoadFromFile_RW(ICE_IO_FromConstMem((void*)ICE_Resource_logo_png, ICE_Resource_logo_png_length));
}

void ICE_Resources_TextureErrorInit()
{
	SDL_RendererInfo info_renderer;
	SDL_GetRendererInfo(ICE_Renderer_GetPtr()->handle, &info_renderer);
	if (info_renderer.max_texture_width >= 1024 && info_renderer.max_texture_height >= 1024)
	{
#include "../Resources/bin/err1024_png.c"
		ICE_GLOBJ_RESOURCES.texture_error = ICE_Texture_LoadFromFile_RW(ICE_IO_FromConstMem((void*)ICE_Resource_err1024_png, ICE_Resource_err1024_png_length));
	}
	else
	{
#include "../Resources/bin/err512_png.c"
		ICE_GLOBJ_RESOURCES.texture_error = ICE_Texture_LoadFromFile_RW(ICE_IO_FromConstMem((void*)ICE_Resource_err512_png, ICE_Resource_err512_png_length));
	}
}

void ICE_Resources_TextureDefaultGuiInit()
{
#include "../Resources/bin/gui27_png.c"
	ICE_GLOBJ_RESOURCES.texture_gui_default = ICE_Texture_LoadFromFile_RW(ICE_IO_FromConstMem((void*)ICE_Resource_gui27_png, ICE_Resource_gui27_png_length));
}

void ICE_Resources_FontDefault()
{
	// ID LOAD
#include "../Resources/bin/font_ttf.c"
	ICE_GLOBJ_RESOURCES.font_default = ICE_Font_Load_RW(ICE_IO_FromConstMem((void*)ICE_Resource_font_ttf, ICE_Resource_font_ttf_length));
}


///////////////////////////////////////////////////////

void ICE_Resources_TextureDefaultGuiFree()
{
	ICE_Texture_Free(&ICE_GLOBJ_RESOURCES.texture_gui_default);
}

void ICE_Resources_TextureErrorFree()
{
	ICE_Texture_Free(&ICE_GLOBJ_RESOURCES.texture_error);
}

void ICE_Resources_TextureLogoFree()
{
	ICE_Texture_Free(&ICE_GLOBJ_RESOURCES.texture_error);
}

void ICE_Resources_FreeAll()
{
	ICE_Resources_TextureDefaultGuiFree();
	ICE_Resources_TextureErrorFree();
	ICE_Resources_TextureLogoFree();
}