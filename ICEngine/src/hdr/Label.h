#ifndef DEF_ICE_LABEL
#define DEF_ICE_LABEL

#include "TypesMaths.h"
#include "TypesCore.h"

#define ICE_DEFAULT_LABEL_MNGR_SIZE 4

ICE_Label * ICE_Label_Get(unsigned int man, unsigned int nb);

/**
 * \brief Insert a new LabelManager in the Game
 */
unsigned int ICE_LabelManager_Insert();

/**
 * \brief Create a New Label
 * \param text The text of the Label
 * \param pos The position of the Label 
 * \return The new Label
 */
ICE_Label ICE_Label_Create(char* text, ICE_Vect pos);

/**
 * \brief Insert a new Label in a manager
 * \param man The manager where label must be added
 * \param text The text of the Label
 * \param pos The position of the Label
 */
unsigned int ICE_Label_Insert(unsigned int man, char *text, ICE_Vect pos);

/**
 * \brief Clear a Label and put everything to 0
 * \param man The manager number
 * \param label The label number
 */
void ICE_Label_Clear();


/**
 * \brief Destroy a manager
 * \param man The manager number
 */
void ICE_LabelManager_Destroy(const unsigned int man);

void ICE_LabelManager_DestroyGlobal(const unsigned int man);


/**
 * \brief Destroy all manager
 */
void ICE_LabelManager_DestroyAll();

void ICE_LabelManager_DestroyAllGlobal();


/**
 * \brief Destroy a label with it's pointer
 * \param ptr The pointer of the Label
 */
void ICE_Label_Destroy(ICE_Label * ptr);

ICE_String ICE_Label_GetString(ICE_Label * ptr);

#endif
