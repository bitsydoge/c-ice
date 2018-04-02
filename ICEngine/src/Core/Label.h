#ifndef DEF_ICE_LABEL
#define DEF_ICE_LABEL


#include "TypesCore.h"
#include "../Framework/String_.h"
#include "../Maths/TypesMaths.h"

#define ICE_DEFAULT_LABEL_MNGR_SIZE 4

/////////////////////// * LABEL MANAGER * //////////////////////////

/**
 * \brief Insert a new LabelManager in the Game
 */
unsigned int ICE_LabelManager_Insert(ICE_State * state);

/**
* \brief Destroy a manager
* \param man The manager number
*/
void ICE_LabelManager_Destroy(const unsigned int man);

/**
* \brief Destroy all manager
*/
void ICE_LabelManager_DestroyAll();

/////////////////////// * LABEL * //////////////////////////

/**
 * \brief Create a New Label
 * \param text The text of the Label
 * \param pos The position of the Label 
 * \return The new Label
 */
ICE_Label ICE_Label_Create(char* text, ICE_Vect pos);

/**
 * \brief Insert a new Label in a manager
 * \param state The state where the manager is
 * \param man The manager where label must be added
 * \param text The text of the Label
 * \param pos The position of the Label
 */
unsigned int ICE_Label_Insert(ICE_State * state, unsigned int man, char *text, ICE_Vect pos);

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
ICE_Label * ICE_Label_Get(ICE_State * state, unsigned int man, unsigned int nb);

/////////////////////// * LABEL SET * //////////////////////////

void ICE_Label_SetSize(ICE_Label *label, int size);
void ICE_Label_SetString(ICE_Label * label, ICE_String string);
void ICE_Label_SetPos(ICE_Label * label, ICE_Vect vect);
void ICE_Label_SetColor(ICE_Label * label, ICE_Color color);
void ICE_Label_SetAngle(ICE_Label * label, ICE_Float angle);
void ICE_Label_FixToWorld(ICE_Label * label, ICE_Bool yn);

#endif
