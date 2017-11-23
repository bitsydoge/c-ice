#include <Core.h>
#include <chipmunk/chipmunk.h>

ICE_CREATE {
	ICE_Game game = ICE_GameCreate("ICE : Hello World", 800, 480);
	ICE_FontLoad(&game, "res/ttf/FiraSans-Medium.ttf");
	ICE_TextureCreate(&game, 0, "res/img/pic.png");
	ICE_TextureCreate(&game, 0, "res/img/backxc.jpg");
	return game;
}

ICE_UPDATE {
	ICE_FontDraw(game, "Hello World", 80, iceVectNew(0,0));
	ICE_TextureRenderCentered(game, 0, 0, NULL, (iceRect[]) { ICE_CameraWorldScreen(RectNew(0, 0, 500, 750), &game->camera) });
	ICE_TextureRenderCentered(game, 0, 1, NULL, (iceRect[]) { ICE_CameraWorldScreen(RectNew(0, 0, ICE_TextureGetWidth(game, 0, 1), ICE_TextureGetHeight(game, 0, 1)), &game->camera) });

		
}

ICE_DESTROY {

}

int main(){
	return ICE_GAME_RUN;
}
