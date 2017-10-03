#include "hdr/Texture.h"
#include "hdr/Input.h"
#include "hdr/Render.h"
#include "hdr/App.h"
#include "hdr/Init.h"

int main(int argc, char* args[])
{
	ICE_InitGameEngine();

	ICE_App app = ICE_CreateApp("ICE", 480, 480);	

	ICE_Texture* texture = ICE_LoadPNG(app.render, "res/img/test.png");
	ICE_Texture* texture2 = ICE_LoadBMPAlpha(app.render, "res/img/error.bmp", ICE_Rgba(0, 200, 255, 105));

	ICE_Input *input = (ICE_Input*)malloc(sizeof(ICE_Input));
	ICE_InputReset(input);

	ICE_SetRenderClearColor(app.render, ICE_Rgba(25, 200, 79, 255));
	
	while(!input->quit)
	{
		ICE_InputReturn(input);
		ICE_RenderClear(app.render);		

		ICE_TextureRender(app.render, texture, NULL, NULL);
		ICE_TextureRender(app.render, texture2, NULL, NULL);
		ICE_RenderPresent(app.render);
	}

	return 0;
}
