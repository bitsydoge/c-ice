#include <Core.h>
#include "hdr/data.h"
#include "hdr/control.h"
#include "Texture_private.h"
#include "Draw_private.h"

ICE_CREATE{
	iceGameCreate("ICE : Indie \"C\" Engine", 500, 500);



	// Load Assets
	iceTextureCreate(0, "res/img/logo.png");
	iceTextureCreate(0, "res/img/gui.png");
	iceTextureCreate(0, "res/img/sprite.png");
	iceMusicCreate("res/snd/music.ogg");
	iceSoundCreate("res/snd/laser.wav");
	iceMusicPlay(0, 1);
	iceFontLoad("res/ttf/FiraMono-Medium.ttf");

	// Load Data and Variables
	DATA0 *data = iceDataAdd(sizeof(DATA0)); // Add DATA0
	iceDataAdd(sizeof(DATA1)); // Add DATA1
	data->speed_camera = 250;
	// Creating Entity
	int manager_nb = iceEntityManagerCreate();
	for(int i = 0; i<10000; i++){
		int entity_nb = iceEntityCreate(0);
		iceEntitySetTexture(manager_nb, entity_nb, 0, 2);
		iceEntitySetPos(manager_nb, entity_nb, iceRandomInt(-5000, 5000), iceRandomInt(-5000, 5000));
		int nb = iceRandomInt(20, 100);
		iceEntitySetSize(manager_nb, entity_nb, nb, nb);
	}
}

ICE_UPDATE{
	// Logical
	Control();
	for (int i = 0; i < iceEntityManagerGetNumber(); i++) // Move every entity from every manager
		for (int j = 0; j < iceEntityGetNumber(i); j++) // the center of the map
			iceEntityMovePos(i, j, 0, 0, 70 * iceGameDelta());
	// Graphical
	iceTextureRenderCentered(0, 0, NULL, (iceBox[]) { iceCameraWorldScreen(iceBoxNew(0, 0, 500, 500)) });
	iceDrawAllEntity(); // Draw every Entity
	iceGuiRect(0, 1, iceBoxNew(0, 0, iceCameraGetW(), 32));
	iceDebugShowFps();
}

ICE_DESTROY{ 
}

int main(){
	ICE_GAME_RUN;
	return 0;
}
