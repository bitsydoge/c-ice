#include "hdr/control.h"

void Control(iceGame *game) {
	DATA0 *data = iceGetData(game, 0); // Make DATA0 avaible in the scope
	if (game->input->key[SDL_SCANCODE_D] || game->input->key[SDL_SCANCODE_RIGHT]) iceCameraShiftPos(game, iceVectNew(data->speed_camera, 0));
	if (game->input->key[SDL_SCANCODE_A] || game->input->key[SDL_SCANCODE_LEFT]) iceCameraShiftPos(game, iceVectNew (-data->speed_camera, 0));
	if (game->input->key[SDL_SCANCODE_S] || game->input->key[SDL_SCANCODE_DOWN]) iceCameraShiftPos(game, iceVectNew(0, data->speed_camera));
	if (game->input->key[SDL_SCANCODE_W] || game->input->key[SDL_SCANCODE_UP]) iceCameraShiftPos(game, iceVectNew(0, -data->speed_camera));
	if (game->input->key[SDL_SCANCODE_SPACE]) iceCameraMovePos(game, iceVectNew(0,0), data->speed_camera);
	if (game->input->key[SDL_SCANCODE_ESCAPE]) iceSubstateLoop(game, menu_create, menu_update, menu_destroy);
}
