#include <Core.h>
#include <chipmunk/chipmunk.h>

typedef struct{
	cpSpace *space;
	cpVect gravity;
	cpBody *textBody;
	cpShape *textShape;
} DATA;

ICE_CREATE {
	iceGameCreate("ICE : Hello World", 800, 480);
	DATA *data = iceDataAdd(sizeof(DATA));
	iceFontLoad("res/ttf/FiraSans-Medium.ttf");
	data->gravity = cpv(10, 50);
	data->space = cpSpaceNew();
	cpSpaceSetGravity(data->space, data->gravity);
	cpFloat radius = 5;
	cpFloat mass = 1;
	cpFloat moment = cpMomentForCircle(mass, 0, radius, cpvzero);
	data->textBody = cpSpaceAddBody(data->space, cpBodyNew(mass, moment));
	cpBodySetPosition(data->textBody, cpv(20, 20));
	data->textShape = cpSpaceAddShape(data->space, cpCircleShapeNew(data->textBody, radius, cpvzero));
	cpShapeSetFriction(data->textShape, 0.9);
}

ICE_UPDATE {
	DATA *data = iceDataGet(0);
	cpFloat timeStep = 1.0 / iceGameFps();
	cpSpaceStep(data->space, timeStep);
	cpVect vect = cpBodyGetPosition(data->textBody);
	iceFontDraw("Hello World", 80, iceVectNew(vect.x, vect.y));
}

ICE_DESTROY {
}

int main(){
	return ICE_GAME_RUN;
}
