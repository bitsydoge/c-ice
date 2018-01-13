#ifndef DEF_ICE_MAP
#define DEF_ICE_MAP

#include <stdio.h>
#include "TypesCore.h"

void iceMapLoad(iceMap *map, char *path);
int iceMapTileType(int x, int y, iceMap *map);

#endif
