#include "hdr/Physics.h"
#include "hdr/TypesCore.h"
#include "hdr/Game.h"

extern iceGame game;

/// return 1 if it colide
iceBool icePhysicsBoxCollision(const iceBox box1, const iceBox box2)
{
	if (
		box1.p.x<(box2.p.x + box2.w) && 
		box1.p.x + box1.w>box2.p.x &&
		box1.p.y<box2.p.y + box2.h &&
		box1.h + box1.p.y>box2.p.y
		)
		return iceTrue;
	return iceFalse;
}

void icePhysicsSetGravity(iceVect vect)
{
	cpSpaceSetGravity(game.physicsmanager.space, iceVect_to_cpVect(vect));
	game.physicsmanager.gravity = iceVect_to_cpVect(vect);
}

void icePhysicsSpaceStep()
{
	cpSpaceStep(game.physicsmanager.space, (float)(1.0/iceGameFps()));
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
				if(game.entitymanager[i].entity[j].physics.body_types == ICE_PHYSICS_RIGID_BODY)
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