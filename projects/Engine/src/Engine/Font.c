#include "Font.h"

#include "../Framework/Log.h"

#include "Types.h"
#include "Vector.h"
#include "Color.h"
#include "Pack.h"
#include "SDL2_Converter_private.h"

#include "../External/physfs/physfs.h"
#include "../External/physfs/physfsrwops.h"

#include "IO_private.h"

// SDL
#include "SDL2_Includer_private.h"
#include ICE_INCLUDE_SDL2_TTF

// GLOBAL OBJ
#include "GlobalData_private.h"
#include "Renderer_private.h"
#include "../Framework/Memory_.h"
#include "Window_private.h"
ICE_GLOBALDATA_RENDERER
#include "FontManager_private.h"
ICE_GLOBALDATA_FONTMANAGER
#include "Resources_private.h"
ICE_GLOBALDATA_RESOURCES


ICE_FontID last_loaded_font = (ICE_FontID)-1;

/* FONT */

ICE_FontID ICE_Font_GetLastLoaded()
{
	return last_loaded_font;
}

ICE_FontID ICE_Font_Load(ICE_StringStd path_)
{
	ICE_IO ops = NULL;

	if (ICE_Pack_isPathFromPak(path_))
	{
		PHYSFS_File* ph_file = PHYSFS_openRead(path_ + 6);
		ops = (ICE_IO)ICE_IO_MakeFromSDL2((void*)PHYSFSRWOPS_makeRWops(ph_file));
	}
	else
	{
		ops = (ICE_IO)ICE_IO_MakeFromSDL2((void*)SDL_RWFromFile(path_, "rb"));
	}

	ICE_FontID temp_id = ICE_Font_Load_RW(ops);

	if (temp_id != (ICE_FontID)-1)
		ICE_Log_Succes("Font loaded from path : ID(%ld), Path(\"%s\")", temp_id, path_);
	else
		ICE_Log_Error("Font didn't loaded from file : %s", path_);

	return temp_id;
}

ICE_Font ICE_Font_Build_RW(ICE_IO rwops_)
{
	ICE_Font font_temp = { 0 };

	font_temp.exist = 1;
	for (int i = 0; i < 256; i++)
	{
		Sint64 offset = SDL_RWtell((SDL_RWops*)rwops_);
		font_temp.size[i] = TTF_OpenFontRW(rwops_, 0, i);
		SDL_RWseek((SDL_RWops*)rwops_, offset, RW_SEEK_SET);
		if (font_temp.size[i] == NULL)
			ICE_Log(ICE_LOGTYPE_CRITICAL, "ICE_Font : Size : %d, %s", i, TTF_GetError());
	}

	return font_temp;
}

ICE_FontID ICE_Font_Load_RW(ICE_IO rwops_)
{
	ICE_Font temp = ICE_Font_Build_RW(rwops_);
	if (1) // ICE_Font error check
	{
		ICE_FontID avaible_slot = 0;
		ICE_Bool no_avaible_slot = ICE_False;

		for (ICE_FontID i = 0; i < ICE_GLOBJ_FONTMANAGER.font_contain; i++)
		{
			if (ICE_GLOBJ_FONTMANAGER.font_array[i].exist == ICE_False)
			{
				avaible_slot = i;
				no_avaible_slot = ICE_True;
				break;
			}
		}
		if (!no_avaible_slot)
		{
			avaible_slot = ICE_GLOBJ_FONTMANAGER.font_contain;
			ICE_GLOBJ_FONTMANAGER.font_contain++;
		}

		ICE_GLOBJ_FONTMANAGER.font_array[avaible_slot] = temp;
		ICE_GLOBJ_FONTMANAGER.font_array[avaible_slot].id = avaible_slot;

		//ICE_Log(ICE_LOGTYPE_SUCCES, "Load Font %d succes", avaible_slot);

		if (ICE_GLOBJ_FONTMANAGER.font_size <= ICE_GLOBJ_FONTMANAGER.font_contain)
		{
			ICE_GLOBJ_FONTMANAGER.font_array = ICE_Realloc(ICE_GLOBJ_FONTMANAGER.font_array, sizeof(ICE_Font) * (ICE_GLOBJ_FONTMANAGER.font_size * 2));
			ICE_GLOBJ_FONTMANAGER.font_size *= 2;
		}

		last_loaded_font = avaible_slot;
		return avaible_slot;
	}

	return (ICE_FontID)-1; // ERROR ID
}

void ICE_Font_Destroy(ICE_FontID font_)
{
	ICE_GLOBJ_FONTMANAGER.font_array[font_].exist = ICE_False;

	for(int i = 0; i < 256; i++)
	{
		TTF_CloseFont(ICE_GLOBJ_FONTMANAGER.font_array[font_].size[i]);
	}
	

	ICE_Log(ICE_LOGTYPE_SUCCES, "Destroy Font %d", font_);
}


#if defined(_DEBUG)
void ICE_Font_Draw(ICE_StringStd text, ICE_Vect vect, ICE_Color fg, ICE_Color bg) 
{
	int size = (int)((ICE_Float)ICE_Window_GetH() / 50.0);
	if (size < 12)
		size = 12;
	SDL_Surface *surf = TTF_RenderText_Shaded(ICE_GLOBJ_FONTMANAGER.font_array[ICE_GLOBJ_RESOURCES.font_default].size[size], text, ICE_Color_ToSdl(fg), ICE_Color_ToSdl(bg));
	SDL_Rect rect; rect.x = (int)vect.x; rect.y = (int)vect.y;
	rect.w = surf->w; rect.h = surf->h;
	SDL_Texture *texture = SDL_CreateTextureFromSurface(ICE_GLOBJ_RENDERER.handle, surf);
	SDL_RenderCopy(ICE_GLOBJ_RENDERER.handle, texture, NULL, &rect);
	SDL_FreeSurface(surf);
	SDL_DestroyTexture(texture);
}
#endif