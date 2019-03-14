#ifndef DEF_ICE_PACK
#define DEF_ICE_PACK

#include "../Framework/String_.h"
#include "../Framework/BasicTypes.h"
#include "Types.h"
#include "../Framework/Macrotools.h"

// Pack Loader/Unloader
#define ICE_Pack_Load_MEM(S) ICE_Pack_Load_MEM__(S, S##_length, ICE_MACROTOOLS_STRINGIZE(FROMMEMORY_##S));
#define ICE_Pack_Unload_MEM(S) ICE_Pack_Load_MEM__(S, S##_length, ICE_MACROTOOLS_STRINGIZE(FROMMEMORY_##S));
void ICE_Pack_Load(ICE_StringStd path_);
void ICE_Pack_Load_MEM__(const void* buffer, ICE_Uint64 lenght, ICE_StringStd dir_name);
void ICE_Pack_Unload(ICE_StringStd path_);

// Pack Tools

/**
 * \brief Return ICE_True if the file exist in loaded pak. ICE_False if not.
 * \param path_ path and filename to the file.
 * \return
 */
ICE_Bool ICE_Pack_FileExist(ICE_StringStd path_);

/**
 * \brief Return ICE_True if the path contain res:// and point something in pak. ICE_False if not
 * \param path_ string to check
 * \return
 */
ICE_Bool ICE_Pack_isPathFromPak(ICE_StringStd path_);

#endif