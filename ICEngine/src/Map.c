#include "hdr/Map.h"
#include "external/icestd.h"
#include <stdio.h>

extern iceGame game;

void iceMapLoad(iceMap *map, char *path){
	FILE* fichier = fopen(path, "r");

	icestd_tnc(fichier, '[');
	icestd_tnc(fichier, '[');

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			puts("Appel sans parametre.\n");
			//fscanf(fichier, "%hu,", &map->tile[i][j]);

	icestd_tnc(fichier, '[');

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			puts("Appel sans parametre.\n");
			//fscanf(fichier, "%hu,", &map->terminalspawner[i][j]);

	icestd_tnc(fichier, '[');

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			puts("Appel sans parametre.\n");
			//fscanf(fichier, "%hu,", &map->enmspawner[i][j]);
}

int iceMapTileType(int x, int y, iceMap *map){
	// (x + (MAP_WIDTH / 2 * TCASE)) / TCASE;
	// (y + (MAP_HEIGHT / 2 * TCASE)) / TCASE;
	return 0;//map->tile[tile_nb_y][tile_nb_x];
}