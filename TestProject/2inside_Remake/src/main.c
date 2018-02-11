#include <Core.h>

// Manager
enum
{
	PlayerManager = 0
};

// Entity
enum
{
	Player = 0
};

typedef struct
{
	int speed;

} PlayerData;

ICE_CREATE{
	iceGameCreate("ICE : Hello World", 800, 480);

// Texture Load
iceTextureCreate(PlayerManager, "res/img/player.png");

// Entity Player
iceEntityCreate(PlayerManager);
iceEntitySetTexture(PlayerManager, Player, PlayerManager, Player);
iceEntitySetSize(PlayerManager, Player, 32.0f, 32.0f);
iceEntitySetPos(PlayerManager, Player, 0.0f, 0.0f);

PlayerData *pdata = iceDataEntityAdd(PlayerManager, Player, sizeof(PlayerData));
pdata->speed = 100;

// Camera
iceCameraAttachToEntity(PlayerManager, Player);
}

ICE_UPDATE{
	PlayerData *pdata = iceDataEntityGet(PlayerManager, Player, 0);
	//move entity
	if (iceInputButton(ICE_INPUT_W))
	{
		iceEntityShiftPos(PlayerManager, Player, 0, pdata->speed*iceGameDelta());
	}
	if (iceInputButton(ICE_INPUT_S))
	{
		iceEntityShiftPos(PlayerManager, Player, 0, -pdata->speed*iceGameDelta());
	}
	if (iceInputButton(ICE_INPUT_A))
	{
		iceEntityShiftPos(PlayerManager, Player, pdata->speed*iceGameDelta(), 0);
	}
	if (iceInputButton(ICE_INPUT_D))
	{
		iceEntityShiftPos(PlayerManager, Player, -pdata->speed*iceGameDelta(), 0);
	}
}

ICE_DESTROY{

}

int main() {
	return iceCoreLoop(GameCreate, GameUpdate, GameDestroy);
}
