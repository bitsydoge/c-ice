#ifndef DEF_ICE_GUI
#define DEF_ICE_GUI

#include "TypesGraphics.h"
#include "../Maths/TypesMaths.h"
#include "../Core/State.h"

#define ICE_DEFAULT_GUI_MNGR_SIZE 4

/* GUIMANAGER */

ICE_Id ICE_GuiManager_Insert(ICE_State * state);
void ICE_GuiManager_Destroy(ICE_State * state, const ICE_Id man);
void ICE_GuiManager_DestroyAll(ICE_State * state);

/* GUI */

ICE_Gui ICE_Gui_Create(ICE_Box box, ICE_Id man_texture, ICE_Id nb_texture);
ICE_Id ICE_Gui_Insert(ICE_State * state, const ICE_Id man, const ICE_Box box, ICE_Id texture_manager, ICE_Id texture_nb);
void ICE_Gui_Clear(ICE_Gui * label);
void ICE_Gui_Destroy(ICE_Gui * ptr);

/* GUI GET */

ICE_Gui * ICE_Gui_Get(ICE_State *state, int man, int gui);

/* GUI SET */

void ICE_Gui_SetTexture(ICE_Gui * gui, int texture_man, int texture);
void ICE_Gui_SetBox(ICE_Gui * gui, ICE_Box box);
void ICE_Gui_SetPos(ICE_Gui * gui, ICE_Vect pos);
void ICE_Gui_SetSize(ICE_Gui * gui, ICE_Vect vect);
void ICE_Gui_SetType(ICE_Gui * gui, ICE_GuiType type);
#endif
