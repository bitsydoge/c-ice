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

void ICE_Label_Select_ptr(ICE_Label * set_this);
void ICE_Label_Select_mgr(const unsigned int man, const unsigned int nb);
void ICE_LabelManager_Create();
ICE_Label ICE_Label_Create(char* text, ICE_Vect pos);
void ICE_Label_Insert(unsigned int man, char *text, ICE_Vect pos);
void ICE_Label_Clear(const unsigned int man, const unsigned int label);
void ICE_LabelManager_Destroy(const unsigned int man);
void ICE_LabelManager_DestroyAll();

ICE_Label * ICE_Label_ReturnPtr(unsigned int man, unsigned int nb);
void ICE_Label_Destroy(ICE_Label * ptr);

#endif
