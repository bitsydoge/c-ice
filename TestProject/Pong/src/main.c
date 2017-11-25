// Pong exemple without physic engine WIP (Help me learn how to structurate the engine)
// To Redo

#include <Core.h>

ICE_CREATE {
	iceGame game = iceGameCreate("ICE : Pong", 960, 480);
	iceRenderSetColor(&game, iceColorNew(100, 200, 50));
	return game;
}

ICE_UPDATE {

}

ICE_DESTROY {

}

int main(){
	return ICE_GAME_RUN;
}
