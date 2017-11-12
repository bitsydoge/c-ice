#include "hdr/Map.h"


void map_load(ICE_Map *map, char *path)
{
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

int tile_on_this_pos(int x, int y, ICE_Map *map)
{
	const int tile_nb_x = 0;// (x + (MAP_WIDTH / 2 * TCASE)) / TCASE;
	const int tile_nb_y = 0;// (y + (MAP_HEIGHT / 2 * TCASE)) / TCASE;

	return 0;//map->tile[tile_nb_y][tile_nb_x];
}