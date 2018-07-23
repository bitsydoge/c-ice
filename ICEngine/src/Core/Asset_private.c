#include "Asset_private.h"

#include "TypesCore.h"

#include "../External/physfs/physfs.h"

ICE_Asset asset = { 0 };
extern ICE_Game game;

void ICE_Asset_Init()
{
	PHYSFS_init(game.argv[0]);
}

void ICE_Asset_Quit()
{
	PHYSFS_deinit();
}
