#include "hdr/Vector.h"
#include "hdr/Camera.h"
#include "hdr/TypesCore.h"

extern iceGame game;

void iceCameraUpdateAttach()
{
	if (game.camera.isAttachedToEntity)
	{
		iceCameraSetPos(iceVectNew(game.entitymanager[game.camera.entity_manager_attached].entity[game.camera.entity_attached].x, game.entitymanager[game.camera.entity_manager_attached].entity[game.camera.entity_attached].y));
	}
}
