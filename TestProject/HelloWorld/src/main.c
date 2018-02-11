#include <Core.h>
#include <stdio.h>

extern iceGame game;

typedef struct
{
	iceVect direction;
	iceFloat rotation;
} DATA_WIDOW;

ICE_CREATE
{
	iceGameCreate("ICE : Hello World", 800, 480);
	iceDrawSetColor(iceColorNew(100, 100, 100));

	//Texture
	iceTextureCreate(0, "res/img/pic.png");
	iceTextureCreate(0, "res/img/gui.png");
	//Font
	iceFontLoad("res/ttf/FiraSans-Medium.ttf");

	//Entity
	for (int i = 0; i < 50; i++)
	{
		int actual = iceEntityCreate(0);
		iceEntitySetTexture(0, actual, 0, 0);
		iceEntitySetSize(0, actual, 32, 32);
		iceEntitySetPos(0, actual, iceRandomInt(-1000, 1000), iceRandomInt(-1000, 1000));
		iceEntitySetAngle(0, i, 1);

		iceEntityPhysicSetBodyTypes(0, i, ICE_PHYSICS_RIGID_BODY);
		iceEntityPhysicSetShapeTypes(0, i, ICE_PHYSICS_SHAPE_CIRCLE);
		iceEntityPhysicSetFriction(0, i, iceRandomInt(9, 9) / 10.0f);
		iceEntityPhysicSetMass(0, i, iceRandomInt(1, 5));
		iceEntityPhysicSetRadius(0, i, 16);
		iceEntityPhysicGenerate(0, i); // Generate the body
		}

	iceLabelManagerCreate();

	// Label
	// Label 1
	iceLabelCreate(1, iceVectNew(400, 240), "OnWorld");
	iceLabelSetText(1, 0, "One Shot");
	iceLabelSetColor(1, 0, iceColorNew(200, 0, 100));
	iceLabelSetSize(1, 0, 50);
	iceLabelSetPos(1, 0, iceVectNew(0, -270));
	iceLabelIsInWorld(1, 0, 1);

	// Label 2
	iceLabelCreate(1, iceVectNew(30, 10), "OnScreen");
	iceLabelSetSize(1, 1, 10);


	icePhysicsSetGravity(iceVectNew(0, 0));

	// Gui Create
	iceGuiCreate(0);
	iceGuiSetTexture(0, 0, 0, 1);
}

ICE_UPDATE
{
	iceDebugShowFpsTitle();
	iceGuiSetBox(0, 0, iceBoxNew(0, 0, iceCameraGetW(), 40));
	static iceBool trigger = iceFalse;
	// INPUT
	if (iceInputButton(ICE_INPUT_D)) iceCameraShiftPos(iceVectNew(1000 * iceGameDelta(), 0));
	if (iceInputButton(ICE_INPUT_A)) iceCameraShiftPos(iceVectNew(-1000 * iceGameDelta(), 0));
	if (iceInputButton(ICE_INPUT_S)) iceCameraShiftPos(iceVectNew(0, 1000 * iceGameDelta()));
	if (iceInputButton(ICE_INPUT_W)) iceCameraShiftPos(iceVectNew(0, -1000 * iceGameDelta()));
	if (iceInputButton(ICE_INPUT_SPACE)) iceCameraMovePos(iceVectNew(0, 0), 1000 * iceGameDelta());
	if (iceInputButton(ICE_INPUT_RETURN))
	{
		if (!trigger)
		{
			iceCameraAttachToEntity(0, 20);
			trigger = iceTrue;
		}
		else
		{
			iceCameraDetach();
			trigger = iceFalse;
		}
		iceInputReset();
	}


	if (iceInputButton(ICE_INPUT_UP))
	{
			iceEntityPhysicAddForce(0, 20, iceVectNew(0, -100000 * iceGameDelta()));

	}
	if (iceInputButton(ICE_INPUT_DOWN))
	{
			iceEntityPhysicAddForce(0, 20, iceVectNew(0, 100000 * iceGameDelta()));
	}
	if (iceInputButton(ICE_INPUT_LEFT))
	{
			iceEntityPhysicAddForce(0, 20, iceVectNew(-100000 * iceGameDelta(), 0 ));
	}
	if (iceInputButton(ICE_INPUT_RIGHT))
	{
			iceEntityPhysicAddForce(0, 20, iceVectNew(100000 * iceGameDelta(), 0));
	}


	if (trigger)
	{
		iceVect pos = iceEntityGetPosition(0, 20);

		printf("<%lf,%lf>\n", pos.x, pos.y);
	}

	// ENTITY
	/*
	for (int i = 0; i < iceEntityGetNumber(0)-2; i++){
		DATA_WIDOW *data = iceDataEntityGet(0, i, 0);
		iceVect pos_label = iceEntityGetPosition(0, i);
		pos_label.y += 60;
		iceLabelSetPos(0, i, iceVectNew(pos_label.x, pos_label.y));
		//iceEntityMovePos(0, i, data->direction.x, data->direction.y, 100 * iceGameDelta());
		//iceEntityAddAngle(0, i, 45 * iceGameDelta() * data->rotation);
	}*/
}

ICE_DESTROY
{
}

int main()
{
	return iceCoreLoop(GameCreate, GameUpdate, GameDestroy);
}
