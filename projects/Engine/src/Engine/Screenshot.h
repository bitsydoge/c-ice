#ifndef DEF_ICE_SCREENSHOT_H
#define DEF_ICE_SCREENSHOT_H

#include "../Framework/String_.h"


/**
 * \brief 
 * \param path_to_save_ NULL to save beside the executable
 * \param filetype 
 */
void ICE_Screenshot(ICE_StringStd path_to_save_, ICE_StringStd filetype);
void ICE_Screenshot_Custom(ICE_StringStd path_);

#endif