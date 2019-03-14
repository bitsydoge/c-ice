#ifndef DEF_ICE_RANDOM
#define DEF_ICE_RANDOM

#include "BasicTypes.h"

/**
 * \brief Init the random system
 */
void ICE_Random_Init();

/**
 * \brief Get a random int between min and max value
 * \param min Minimal random value
 * \param max Maximal random value
 * \return Random Int 
 */
int ICE_Random_Int(int min, int max);

/**
 * \brief Get a random float between 0 and 1
 * \return 
 */
ICE_Float ICE_Random_Float();

#endif