#include <SDL2/SDL.h>
#include "hdr/Texture.h"
#include "hdr/Input.h"
#include "hdr/Render.h"
#include "hdr/App.h"

int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_VIDEO);
	ICE_App app = ICE_CreateApp("ICE", 800, 480);	
	//SDL_SetRenderDrawColor(app.render, 25, 200, 79, 255);
	//int ICE_SetRenderClearColor(SDL_Renderer *render, Uint32 rgba_hex)

	ICE_SetRenderClearColor(app.render, ICE_Rgba(25, 200, 79, 255));
	ICE_Texture* texture = ICE_LoadPNG(app.render, "res/img/test.png");
	ICE_Input *input = (ICE_Input*)malloc(sizeof(ICE_Input));
	ICE_InputReset(input);
	//ICE_Texture* texture2 = ICE_LoadBMPAlpha(render, "res/img/error.bmp", 0xff00c8ff);
	ICE_Texture* texture2 = ICE_LoadBMPAlpha(app.render, "res/img/error.bmp", ICE_Rgba(0, 200, 255, 105));

	while(!input->quit)
	{
		ICE_RenderClear(app.render);		
		ICE_InputReturn(input);
		ICE_TextureRender(app.render, texture, NULL, NULL);
		ICE_TextureRender(app.render, texture2, NULL, NULL);
		ICE_RenderPresent(app.render);
	}

	return 0;
}
