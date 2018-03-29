#ifndef DEF_ICE_LABEL
#define DEF_ICE_LABEL

#include "TypesMaths.h"
#include "TypesCore.h"

#define ICE_DEFAULT_LABEL_MNGR_SIZE 4

#define ICE_Label_Select_2(X, Y) ICE_Label_Select_mgr(X, Y)
#define ICE_Label_Select_1(X) ICE_Label_Select_ptr(X) 
#define ICE_Label_Select_0() 

#define ICE_Label_FUNC_CHOOSER(_f1, _f2, _f3, ...) _f3
#define ICE_Label_FUNC_RECOMPOSER(argsWithParentheses) ICE_Label_FUNC_CHOOSER argsWithParentheses
#define ICE_Label_CHOOSE_FROM_ARG_COUNT(...) ICE_Label_FUNC_RECOMPOSER((__VA_ARGS__, ICE_Label_Select_2, ICE_Label_Select_1, ))
#define ICE_Label_NO_ARG_EXPANDER() ,,ICE_Label_Select_0
#define ICE_Label_MACRO_CHOOSER(...) ICE_Label_CHOOSE_FROM_ARG_COUNT(ICE_Label_NO_ARG_EXPANDER __VA_ARGS__ ())
/**
 * \brief Select label to apply function on
 * \param 1_arg Pointer of a ICE_Label
 * \param 2_arg Man number and Label Number
 */
#define ICE_Label_Select(...) ICE_Label_MACRO_CHOOSER(__VA_ARGS__)(__VA_ARGS__)

/**
 * \brief Select a Label with it's pointer
 * \param set_this Ptr to a label to set it
 */
void ICE_Label_Select_ptr(ICE_Label * set_this);

/**
 * \brief Select a Label with it's Manager number and Position in the Manager
 * \param man LabelManager nb
 * \param nb Label nb
 */
void ICE_Label_Select_mgr(const unsigned int man, const unsigned int nb);

/**
 * \brief Insert a new LabelManager in the Game
 */
void ICE_LabelManager_Insert();

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
void ICE_Label_Insert(unsigned int man, char *text, ICE_Vect pos);

/**
 * \brief Clear a Label and put everything to 0
 * \param man The manager number
 * \param label The label number
 */
void ICE_Label_Clear(const unsigned int man, const unsigned int label);

/**
 * \brief Destroy a manager
 * \param man The manager number
 */
void ICE_LabelManager_Destroy(const unsigned int man);

/**
 * \brief Destroy all manager
 */
void ICE_LabelManager_DestroyAll();

/**
 * \brief Get the pointer of a Label	
 * \param man The manager where the label is 
 * \param nb The position of the label
 * \return The Label pointer
 */
ICE_Label * ICE_Label_ReturnPtr(unsigned int man, unsigned int nb);

/**
 * \brief Destroy a label with it's pointer
 * \param ptr The pointer of the Label
 */
void ICE_Label_Destroy(ICE_Label * ptr);

ICE_String ICE_Label_GetString();

#endif
