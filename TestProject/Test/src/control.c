#include "hdr/control.h"

void Control() {
	DATA0 *data = iceDataGet(0); // Make DATA0 avaible in the scope
	if (iceInputButton(SDL_SCANCODE_D) || iceInputButton(SDL_SCANCODE_RIGHT)) iceCameraShiftPos(iceVectNew(data->speed_camera * iceGameDelta(), 0));
	if (iceInputButton(SDL_SCANCODE_A) || iceInputButton(SDL_SCANCODE_LEFT)) iceCameraShiftPos(iceVectNew (-data->speed_camera * iceGameDelta(), 0));
	if (iceInputButton(SDL_SCANCODE_S) || iceInputButton(SDL_SCANCODE_DOWN)) iceCameraShiftPos(iceVectNew(0, data->speed_camera * iceGameDelta()));
	if (iceInputButton(SDL_SCANCODE_W) || iceInputButton(SDL_SCANCODE_UP)) iceCameraShiftPos(iceVectNew(0, -data->speed_camera * iceGameDelta()));
	if (iceInputButton(SDL_SCANCODE_SPACE)) iceCameraMovePos(iceVectNew(0,0), data->speed_camera * iceGameDelta());
	if (iceInputButton(SDL_SCANCODE_ESCAPE)) iceSubstateLoop(menu_create, menu_update, menu_destroy);
}
