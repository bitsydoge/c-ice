#include <Core.h>

ICE_CREATE {
	iceGameCreate("ICE : Hello World", 800, 480);
	iceFontLoad("res/ttf/FiraSans-Medium.ttf");

	iceEntityCreate(0);
	iceEntitySetPos(0, 0, 50, 50);

	iceEntityPhysicSetBodyTypes(0, 0, ICE_PHYSICS_RIGID_BODY);
	iceEntityPhysicSetShapeTypes(0, 0, ICE_PHYSICS_SHAPE_CIRCLE);
	iceEntityPhysicGenerate(0, 0); // Generate the body

	icePhysicsSetGravity(iceVectNew(0, 5));
}

ICE_UPDATE {
	iceVect vector = iceEntityGetPosition(0,0); // The Font will follow the entity
	iceFontDraw("O", 50, iceVectNew(vector.x, vector.y));
}

ICE_DESTROY {
}

int main(){
	return ICE_GAME_RUN;
}