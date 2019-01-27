#ifndef DEF_ICE_LABEL
#define DEF_ICE_LABEL


#include "TypesCore.h"
#include "../Framework/String_.h"
#include "../Framework/TypesFramework.h"
#include "../Maths/TypesMaths.h"

#define ICE_DEFAULT_LABEL_MNGR_SIZE 4

/////////////////////// * LABEL MANAGER * //////////////////////////

/**
 * \brief Insert a new LabelManager in the Game
 */
void ICE_LabelManager_Init(ICE_State* state);

/**
* \brief Destroy a manager
* \param state The state to destroy manager
*/
void ICE_LabelManager_Destroy(ICE_State * state);

/////////////////////// * LABEL * //////////////////////////

/**
 * \brief Create a New Label
 * \param text The text of the Label
 * \param pos The position of the Label 
 * \return The new Label
 */
ICE_Label ICE_Label_Build(ICE_StringStd text, ICE_Vect pos, int size, enum ICE_LabelType type);

/**
 * \brief Insert a new Label in a manager
 * \param state The state where the manager is
 * \param text The text of the Label
 * \param pos The position of the Label
 */
ICE_ID ICE_Label_Create(ICE_State * state, ICE_StringStd text, const ICE_Vect pos, int size, enum ICE_LabelType type);

/**
 * \brief Clear a Label and put everything to 0
 * \param label ptr to clear
 */
void ICE_Label_Clear(ICE_Label * label);

/**
 * \brief Destroy a label with it's pointer
 * \param ptr The pointer of the Label
 */
void ICE_Label_Destroy(ICE_Label * ptr);

/////////////////////// * LABEL GET * //////////////////////////

ICE_String ICE_Label_GetString(ICE_Label* ptr);
ICE_Label * ICE_Label_Get(ICE_State * state, const ICE_ID nb);
unsigned ICE_Label_GetWidth(ICE_Label* label);
unsigned ICE_Label_GetHeight(ICE_Label* label);
ICE_Float ICE_Label_GetX(ICE_Label * label);
ICE_Float ICE_Label_GetY(ICE_Label * label);

/////////////////////// * LABEL SET * //////////////////////////

void ICE_Label_SetSize(ICE_Label *label, int size);
void ICE_Label_SetString(ICE_Label * label, ICE_StringStd format, ...);
void ICE_Label_SetPos(ICE_Label * label, ICE_Vect vect);
void ICE_Label_SetColor(ICE_Label * label, ICE_Color color);
void ICE_Label_SetWrapWidth(ICE_Label * label, int wrap_width);
void ICE_Label_SetAngle(ICE_Label * label, ICE_Float angle);
void ICE_Label_FixToWorld(ICE_Label * label, ICE_Bool yn);

#endif
