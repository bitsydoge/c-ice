#include <ICE.h>
#include "inventory.h"
#include "data.h"

void inventory_create()
{
	ICE_Render_Color(ICE_Color_New(50, 50, 50));
	DATA1 * data = ICE_Data_Get(ICE_State_GetParent(NULL), 0);
	ICE_ID nb = ICE_Label_Create
	(
		NULL, 
		"", 
		ICE_Vect_New(50, 20), 
		12, 
		ICE_LABELTYPE_SCREEN
	);
	ICE_Label_SetString
	(
		ICE_Label_Get(NULL, nb), 
		"Name : %s     Damage : %.1f     Speed : %.1f", 
		data->current_weapon.name, 
		data->current_weapon.damage, 
		data->current_weapon.speed
	);
	ICE_Label_SetWrapWidth(ICE_Label_Get(NULL, nb), 100);
	ICE_Gui_Create
	(
		NULL,
		ICE_Box_New
		(
			ICE_Label_GetX(ICE_Label_Get(NULL, nb)) - 5,
			ICE_Label_GetY(ICE_Label_Get(NULL, nb)),
			ICE_Label_GetWidth(ICE_Label_Get(NULL, nb)) + 10,
			ICE_Label_GetHeight(ICE_Label_Get(NULL, nb) + 2)
		),
		ICE_GUITYPE_9PATCH
	);
}

void inventory_update()
{
	ICE_Debug_DrawFps(5);

	ICE_Label_SetPos(ICE_Label_Get(NULL, 0), ICE_Vect_New(ICE_Input_MouseX() + 15, ICE_Input_MouseY() - 10));
	DATA1 * data = ICE_Data_Get(ICE_State_GetParent(NULL), 0);
	ICE_Gui_SetSize
	(
		ICE_Gui_Get(NULL, 0),
		ICE_Vect_New
		(
			ICE_Label_GetWidth(ICE_Label_Get(NULL, 0)) + 10,
			ICE_Label_GetHeight(ICE_Label_Get(NULL, 0)) + 2
		)
	);

	ICE_Gui_SetPos
	(
		ICE_Gui_Get(NULL, 0),
		ICE_Vect_New
		(
			ICE_Label_GetX(ICE_Label_Get(NULL, 0)) - 5,
			ICE_Label_GetY(ICE_Label_Get(NULL, 0))
		)
	);
	ICE_Debug_CameraControl();

	if (ICE_Input_Pressed(ICE_KEY_ESCAPE))
		ICE_State_Pause();
}

void inventory_destroy()
{

}