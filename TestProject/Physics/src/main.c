#include <Core.h>
#include <chipmunk/chipmunk.h>

typedef struct{
	cpBody *textBody;
	cpShape *textShape;
} DATA;

ICE_CREATE {
	iceGameCreate("ICE : Hello World", 800, 480);
	iceFontLoad("res/ttf/FiraSans-Medium.ttf");
	DATA *data = iceDataAdd(sizeof(DATA));
	data->textBody = cpSpaceAddBody(icePhysicsGetSpace(), cpBodyNew(1, cpMomentForCircle(1, 0, 5, cpvzero)));
	cpBodySetPosition(data->textBody, cpv(20, 20));

	data->textShape = cpSpaceAddShape(icePhysicsGetSpace(), cpCircleShapeNew(data->textBody, 5, cpvzero));
	cpShapeSetFriction(data->textShape, 0.9);

	icePhysicsSetGravity(iceVectNew(0, 20));
}

ICE_UPDATE {
	DATA *data = iceDataGet(0);
	cpVect vect = cpBodyGetPosition(data->textBody);
	iceFontDraw("O", 50, iceVectNew(vect.x, vect.y));
}

ICE_DESTROY {
}

int main(){
	return ICE_GAME_RUN;
}
