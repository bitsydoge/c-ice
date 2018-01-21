#include <Core.h>

ICE_DEBUG_GET_GAME_OBJECT

ICE_CREATE {
	iceGameCreate("ICE : Hello World", 800, 480);
	iceFontLoad("res/ttf/FiraSans-Medium.ttf");
	iceEntityCreate(0);
	iceEntitySetPos(0, 0, 50, 50);
	icePhysicsSetGravity(iceVectNew(0, 20));
}

ICE_UPDATE {
	iceVect vector = iceEntityGetPosition(0,0);
	iceFontDraw("O", 50, iceVectNew(vector.x, vector.y));
}

ICE_DESTROY {
}

int main(){
	return ICE_GAME_RUN;
}