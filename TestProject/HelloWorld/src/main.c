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
	for (int i = 0; i < 500; i++)
	{
		int actual = iceEntityCreate(0);
		iceEntitySetTexture(0, actual, 0, 0);
		iceEntitySetSize(0, actual, 32, 32);
		iceEntitySetPos(0, actual, iceRandomInt(-1000, 1000), iceRandomInt(-1000, 1000));
		iceEntitySetAngle(0, i, 1);

		iceEntityPhysicSetBodyTypes(0, i, ICE_PHYSICS_RIGID_BODY);
		iceEntityPhysicSetShapeTypes(0, i, ICE_PHYSICS_SHAPE_CIRCLE);
		iceEntityPhysicSetFriction(0, i, 1);
		iceEntityPhysicSetMass(0, i, 1);
		iceEntityPhysicSetRadius(0, i, 16);
		iceEntityPhysicGenerate(0, i); // Generate the body
		}

	iceLabelManagerCreate();

	// Label
	// Label 1
	iceLabelCreate(1, iceVectNew(400, 240), "OnWorld");
	iceLabelSetText(1, 0, "Romain");
	iceLabelSetColor(1, 0, iceColorNew(200, 0, 100));
	iceLabelSetSize(1, 0, 50);
	iceLabelSetPos(1, 0, iceVectNew(0, -270));
	iceLabelIsInWorld(1, 0, 1);

	// Label 2
	iceLabelCreate(1, iceVectNew(50, 10), "Fixed Entity");
	iceLabelSetSize(1, 1, 10);

	// Label 2
	iceLabelCreate(1, iceVectNew(50, 30), "<x,x>");
	iceLabelSetSize(1, 2, 10);

	// Label Player Name
	iceVect pos_player = iceEntityGetPosition(0, 20);
	pos_player.y += 20;
	iceLabelCreate(1, pos_player, "Player");
	iceLabelIsInWorld(1, 3, iceTrue);
	iceLabelSetSize(1, 3, 10);

	// Gui Create
	iceGuiCreate(0);
	iceGuiSetTexture(0, 0, 0, 1);

	// Physics
	icePhysicsSetGravity(iceVectNew(0, 0));
}

ICE_UPDATE
{
	iceDebugShowFpsTitle();
	iceGuiSetBox(0, 0, iceBoxNew(0, 0, 100, 40));

	iceVect pos_player = iceEntityGetPosition(0, 20);
	pos_player.y += 20;
	iceLabelSetPos(1, 3, pos_player);


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


	if (trigger)
	{
		iceVect pos = iceEntityGetPosition(0, 20);
		char buffer[256];
		sprintf(buffer, "<%.1f,%.1f>", pos.x, pos.y);
		iceLabelSetText(1, 2, buffer);
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
}

ICE_DESTROY
{
}

int main()
{
	return iceCoreLoop(GameCreate, GameUpdate, GameDestroy);
}
