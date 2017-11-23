#include <Core.h>
#include <chipmunk/chipmunk.h>

ICE_CREATE {
	iceGame game = iceGameCreate("ICE : Hello World", 800, 480);
	iceFontLoad(&game, "res/ttf/FiraSans-Medium.ttf");
	iceTextureCreate(&game, 0, "res/img/pic.png");
	iceTextureCreate(&game, 0, "res/img/backxc.jpg");
	return game;
}

ICE_UPDATE {
	iceFontDraw(game, "Hello World", 80, iceVectNew(0,0));
	iceTextureRenderCentered(game, 0, 0, NULL, (iceRect[]) { iceCameraWorldScreen(RectNew(0, 0, 500, 750), &game->camera) });
	iceTextureRenderCentered(game, 0, 1, NULL, (iceRect[]) { iceCameraWorldScreen(RectNew(0, 0, iceTextureGetWidth(game, 0, 1), iceTextureGetHeight(game, 0, 1)), &game->camera) });

		
}

ICE_DESTROY {

}

int main(){
	return ICE_GAME_RUN;
}
