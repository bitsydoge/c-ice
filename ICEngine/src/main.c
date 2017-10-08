#include <stdio.h>
#include "hdr/Core.h"

void GameCreate()
{
	printf("Hello from GameCreate \n");
}

void GameUpdate()
{
	printf("Hello from GameUpdate \n");

}

void GameDestroy()
{
	printf("Hello from GameDestroy \n");
}

int main(int argc, char* args[])
{
	ICE_GameLoop(GameCreate, GameUpdate, GameDestroy);

	return 0;
}
