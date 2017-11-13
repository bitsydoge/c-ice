#include <Core.h>

ICE_CREATE {
	ICE_Game game = ICE_CreateGame("ICE : Indie \"C\" Engine", 500, 500); 
	ICE_Assert(&game == 0, "Game creation failed");
	return game;
}

ICE_UPDATE {
	game;
}

ICE_DESTROY {
	ICE_DestroyGame(game);
}

int main(){
	return ICE_GAME_RUN;
}
