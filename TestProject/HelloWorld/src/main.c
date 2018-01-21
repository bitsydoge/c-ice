#include <Core.h>

typedef struct{
	iceVect direction;
	iceFloat rotation;
} DATA_WIDOW;

ICE_CREATE {
	iceGameCreate("ICE : Hello World", 800, 480);
	iceDrawSetColor(iceColorNew(100, 100, 100));

	//Texture
	iceTextureCreate(0, "res/img/pic.png");
	iceTextureCreate(0, "res/img/gui.png");
	//Font
	iceFontLoad("res/ttf/FiraSans-Medium.ttf");
	//Entity
	for (int i = 0; i < 5000; i++){
		int actual = iceEntityCreate(0);
		iceEntitySetTexture(0, actual, 0, 0);
		iceEntitySetSize(0, actual, 150, 100);
		iceEntitySetPos(0, actual, iceRandomInt(-10000, 10000), iceRandomInt(-10000, 10000));
		DATA_WIDOW *data = iceDataEntityAdd(0, actual, sizeof(DATA_WIDOW));
		data->direction = iceVectNew(iceRandomInt(-10000, 10000), iceRandomInt(-10000, 10000));
		data->rotation = iceRandomInt(-1, 1);
		iceEntityLookAt(0, i, data->direction);
	}

	// Label 1
	iceLabelCreate(0, iceVectNew(400, 240), "OnWorld");
	iceLabelSetText(0, 0, "One Shot");
	iceLabelSetColor(0, 0, iceColorNew(200, 0, 100));
	iceLabelSetSize(0, 0, 50);
	iceLabelSetPos(0, 0, iceVectNew(0, -270));
	iceLabelIsInWorld(0, 0, 1);
	// Label 2
	iceLabelCreate(0, iceVectNew(30, 10), "OnScreen");
	iceLabelSetSize(0, 1, 10);
	// Gui Create
	iceGuiCreate(0);
	iceGuiSetTexture(0, 0, 0, 1);
}

ICE_UPDATE {
	iceDebugShowFpsTitle();
	iceGuiSetBox(0, 0, iceBoxNew(0, 0, iceCameraGetW(), 40));
	// INPUT
	if (iceInputButton(ICE_INPUT_D) || iceInputButton(ICE_INPUT_RIGHT)) iceCameraShiftPos(iceVectNew(1000 * iceGameDelta(), 0));
	if (iceInputButton(ICE_INPUT_A) || iceInputButton(ICE_INPUT_LEFT)) iceCameraShiftPos(iceVectNew(-1000 * iceGameDelta(), 0));
	if (iceInputButton(ICE_INPUT_S) || iceInputButton(ICE_INPUT_DOWN)) iceCameraShiftPos(iceVectNew(0, 1000 * iceGameDelta()));
	if (iceInputButton(ICE_INPUT_W) || iceInputButton(ICE_INPUT_UP)) iceCameraShiftPos(iceVectNew(0, -1000 * iceGameDelta()));
	if (iceInputButton(ICE_INPUT_SPACE)) iceCameraMovePos(iceVectNew(0, 0), 1000 * iceGameDelta());
	if (iceInputButton(ICE_INPUT_RETURN)){
		static iceBool trigger = iceFalse;
		if (!trigger) {
			iceCameraAttachToEntity(0, 500);
			trigger = iceTrue;
		}
		else {
			iceCameraDetach();
			trigger = iceFalse;
		}
		iceInputReset();
	}
	// ENTITY
	for (int i = 0; i < iceEntityGetNumber(0); i++){
		DATA_WIDOW *data = iceDataEntityGet(0, i, 0);
		iceEntityMovePos(0, i, data->direction.x, data->direction.y, 100 * iceGameDelta());
		//iceEntityAddAngle(0, i, 45 * iceGameDelta() * data->rotation);
	}
}

ICE_DESTROY {
}

int main() {
	return iceCoreLoop(GameCreate, GameUpdate, GameDestroy);
}