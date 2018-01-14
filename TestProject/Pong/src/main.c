// Pong exemple without physic engine WIP (Help me learn how to structurate the engine)
// To Redo

#include <Core.h>

ICE_CREATE {
	iceGameCreate("ICE : Pong", 960, 480);
	iceDrawSetColor(iceColorNew(100, 200, 50));
}

ICE_UPDATE {

}

ICE_DESTROY {

}

int main(){
	return ICE_GAME_RUN;
}
