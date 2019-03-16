#ifndef DEF_ICE_IO_H
#define DEF_ICE_IO_H
#include "../Framework/String_.h"

typedef struct ICE_RWops ICE_IO;

ICE_IO* ICE_IO_FromConstMem(const void* mem_, int size_);
ICE_IO* ICE_IO_FromFile(ICE_StringStd path_, ICE_StringStd mode);
void ICE_IO_Destroy(ICE_IO* rwops_);

#endif