#include <Core.h>

ICE_CREATE {
	ICE_Game game = ICE_GameCreate("ICE : Hello World", 800, 480);
	ICE_FontLoad(&game, "res/ttf/FiraSans-Medium.ttf");
	return game;
}

ICE_UPDATE {
	ICE_FontDraw(game, "Hello World", 80, PointNew(0,0));
}

ICE_DESTROY {

}

int main(){
	return ICE_GAME_RUN;
}
