#include "hdr/State.h"

#include "hdr/TypesCore.h"
#include "hdr/Memory_.h"
#include "hdr/Log.h"

extern ICE_Game game;

void ICE_StateManagerCreate()
{
	ICE_StateManager state_manager = { 0 };
	state_manager.state_size = ICE_DEFAULT_STATE_MNGR_SIZE;
	state_manager.state = ICE_Calloc(state_manager.state_size, sizeof(ICE_State)); // Label Array
	game.state_mngr_nb++;
	game.state_mngr = ICE_Realloc(game.state_mngr, game.state_mngr_nb * sizeof(ICE_StateManager)); // Manager Array
	game.state_mngr[game.state_mngr_nb - 1] = state_manager;

	ICE_Log(ICE_LOG_SUCCES, "StateManager]::[%d]::[Create", game.state_mngr_nb - 1);
}

void ICE_StateCreate(const unsigned int man)
{
	ICE_State state = { 0 };

	// Insert state in array
	game.state_mngr[man].state[game.state_mngr[man].state_contain] = state;
	//ICE_LabelUpdateTexture(man, game.label_mngr[man].label_contain);
	game.state_mngr[man].state_contain++;

	ICE_Log(ICE_LOG_SUCCES, "StateManager]::[%d]::[State]::[%d]::[Create", man, game.state_mngr[man].state_contain - 1);

	// Test size to realloc more space
	if (game.state_mngr[man].state_size <= game.state_mngr[man].state_contain) {
		ICE_State* tmp = ICE_Realloc(game.label_mngr[man].label, sizeof(ICE_Label)*(game.label_mngr[man].label_size * 2));
		// Test if realloc succes
		ICE_Log(ICE_LOG_WARNING, "StateManager]::[%d]::[Resized]::[%d", man, game.state_mngr[man].state_size * 2);
		game.state_mngr[man].state = tmp;
		game.state_mngr[man].state_size *= 2;
	}
}

void ICE_StateClear(const unsigned int man, const unsigned int label)
{
	ICE_String temp = game.label_mngr[man].label[label].text;
	ICE_String temp2 = game.label_mngr[man].label[label].old_text;
	memset(&game.label_mngr[man].label[label], 0, sizeof(ICE_Label));
	game.label_mngr[man].label[label].text = temp;
	game.label_mngr[man].label[label].old_text = temp2;
	ICE_StringResize(&temp, 1);
	ICE_StringResize(&temp2, 1);
}

void ICE_StateManagerDestroy(const unsigned int man)
{
	ICE_StateManager *manager = &game.state_mngr[man];
	for (unsigned int i = 0; i < manager->state_contain; i++)
	{
		//Free everything to free in State
		
	}
	ICE_Free(manager->state);
	ICE_Log(ICE_LOG_SUCCES, "StateManager]::[%d]::[Free", man);
}

void ICE_StateManagerDestroyAll()
{
	ICE_StateManager *manager = game.state_mngr;
	unsigned int nb_manager = game.state_mngr_nb;
	for (unsigned int i = 0; i < nb_manager; i++)
	{
		if (!manager[i].isFree)
		{
			ICE_StateManagerDestroy(i);
			manager[i].isFree = ICE_True;
		}
	}
	free(manager);
}
