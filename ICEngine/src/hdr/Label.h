#ifndef DEF_ICE_LABEL
#define DEF_ICE_LABEL

#include "TypesMaths.h"
#include "TypesCore.h"

#define ICE_DEFAULT_LABEL_MNGR_SIZE 4

void ICE_Label_ManagerCreate();
void ICE_Label_Insert(unsigned int man, ICE_Vect pos, char *text);
void ICE_Label_Clear(const unsigned int man, const unsigned int label);
void ICE_LabelManager_Destroy(const unsigned int man);
void ICE_LabelManager_DestroyAll();

ICE_Label * ICE_Label_ReturnPtr(unsigned int man, unsigned int nb);

#define LABEL_SELECT(X, Y) ICE_Label_ReturnPtr(X, Y)

#endif
