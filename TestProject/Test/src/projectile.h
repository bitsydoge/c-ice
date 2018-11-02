#ifndef GAME_PROJECTILE_H
#define GAME_PROJECTILE_H

typedef struct
{
	int dx, dy;
	int speed;
	ICE_Float timer;

} GAME_DATA_PROJECTILE;


void GAME_Projectile_Create(ICE_Entity * this_);
void GAME_Projectile_Update(ICE_Entity * this_);
void GAME_Projectile_Destroy(ICE_Entity * this_);

#endif