#ifndef DEF_ICE_ASSET
#define DEF_ICE_ASSET
#include "../Framework/String_.h"
#include "../Framework/TypesFramework.h"
#include "../Framework/Macrotools.h"

// AssetPak Loader/Unloader
#define ICE_AssetPak_Load_MEM(S) ICE_AssetPak_Load_MEM__(S, S##_length, ICE_MACROTOOLS_STRINGIZE(FROMMEMORY_##S));
#define ICE_AssetPak_Unload_MEM(S) ICE_AssetPak_Load_MEM__(S, S##_length, ICE_MACROTOOLS_STRINGIZE(FROMMEMORY_##S));
void ICE_AssetPak_Load(ICE_StringStd path_);
void ICE_AssetPak_Load_MEM__(const void * buffer, ICE_Uint64 lenght, ICE_StringStd dir_name);
void ICE_AssetPak_Unload(ICE_StringStd path_);

// AssetPak Tools

/**
 * \brief Return ICE_True if the file exist in loaded pak. ICE_False if not.
 * \param path_ path and filename to the file.
 * \return 
 */
ICE_Bool ICE_AssetPak_FileExist(ICE_StringStd path_);

/**
 * \brief Return ICE_True if the path contain res:// and point something in pak. ICE_False if not
 * \param path_ string to check
 * \return 
 */
ICE_Bool ICE_AssetPak_isPathFromPak(ICE_StringStd path_);

#endif