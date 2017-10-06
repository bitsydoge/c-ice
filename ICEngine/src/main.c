#include "hdr/Texture.h"
#include "hdr/Render.h"
#include "hdr/App.h"
#include "hdr/Init.h"
#include "hdr/TextureManager.h"

int main(int argc, char* args[])
{
	ICE_InitGameEngine();
	ICE_App app = ICE_CreateApp("ICE", 500, 500);
	//ICE_Texture *texture = ICE_LoadPNG(app.render, "res/img/logo.png");
	//ICE_Texture *texture2 = ICE_LoadBMPAlpha(app.render, "res/img/error.bmp", ICE_Rgba(0, 200, 255, 105));
	ICE_TextureManager text = ICE_CreateTextureManager();	



	while(!app.input->quit)
	{
		while(1)
		{
			ICE_CreateTexture(&app, &text, "res/img/logo.pnggg", 0);	
			printf("%d\n", text.nb_existing_texture);
			SDL_Delay(50);	
		}
		ICE_InputReturn(app.input);
		ICE_RenderClear(app.render);		
		ICE_TextureRender(app.render, &text.texturepack[0], NULL, NULL);
		ICE_RenderPresent(app.render);
	}

	ICE_DestroyApp(&app);
	ICE_CloseGameEngine();

	return 0;
}
