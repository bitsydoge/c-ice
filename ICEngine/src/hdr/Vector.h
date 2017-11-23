#ifndef DEF_iceVECTOR
#define DEF_iceVECTOR

#include "Types.h"

iceVect iceVectNew(iceFloat x, iceFloat y);
void iceVectAdd(iceVect *point, iceVect vect);
void iceVectSub(iceVect *point, iceVect vect);

#endif
