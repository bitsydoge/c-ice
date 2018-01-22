#include <chipmunk/chipmunk.h>
#include "hdr/Game.h"

extern iceGame game;

void icePhysicsSpaceStep()
{
	cpSpaceStep(game.physicsmanager.space, (float)(1.0 / iceGameFps()));
}

cpSpace* icePhysicsGetSpace()
{
	return game.physicsmanager.space;
}

void icePhysicsUpdateEntity()
{
	for (int i = 0; i < game.entitymanager_nb; i++)
		for (int j = 0; j < game.entitymanager[i].nb_existing; j++)
		{
			if (game.entitymanager[i].entity[j].exist)
			{
				if (game.entitymanager[i].entity[j].physics.body_types == ICE_PHYSICS_RIGID_BODY)
				{
					// Update pos of the entity
					cpVect vect = cpBodyGetPosition(game.entitymanager[i].entity[j].physics.body);
					game.entitymanager[i].entity[j].x = vect.x;
					game.entitymanager[i].entity[j].y = vect.y;

					// Update angle of the entity
					game.entitymanager[i].entity[j].angle = cpBodyGetAngle(game.entitymanager[i].entity[j].physics.body);
				}
			}
		}
}