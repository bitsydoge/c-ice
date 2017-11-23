#include <Core.h>
#include <chipmunk/chipmunk.h>

ICE_CREATE {
	ICE_Game game = ICE_GameCreate("ICE : Hello World", 800, 480);
	ICE_FontLoad(&game, "res/ttf/FiraSans-Medium.ttf");
	ICE_TextureCreate(&game, 0, "res/img/pic.png");
	return game;
}

ICE_UPDATE {
	ICE_FontDraw(game, "Hello World", 80, iceVectNew(0,0));
	ICE_TextureRender(game, 0, 0, NULL, NULL);
	ICE_TextureRenderCentered(game, 0, 0, NULL, (iceRect[]) { ICE_CameraWorldScreen(RectNew(0, 0, 500, 500), &game->camera) });
}

ICE_DESTROY {

}

int main(){
	return ICE_GAME_RUN;
}
