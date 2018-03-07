#ifndef DEF_ICE_LABEL
#define DEF_ICE_LABEL

#include "TypesMaths.h"

#define ICE_DEFAULT_LABEL_MNGR_SIZE 4

void ICE_LabelManagerCreate();
void ICE_LabelCreate(unsigned int man, ICE_Vect pos, char *text);
void ICE_LabelClear(const unsigned int man, const unsigned int label);
void ICE_LabelManagerDestroy(const unsigned int man);
void ICE_LabelManagerDestroyAll();

#endif
