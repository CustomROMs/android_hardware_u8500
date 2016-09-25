#ifndef _NMF_TYPE_H_
#define _NMF_TYPE_H_

#include <inc/typedef.h>

PUBLIC IMPORT_SHARED void NMF_LOG(const char* fmt, ...);
PUBLIC IMPORT_SHARED void NMF_PANIC(const char* fmt, ...);

#define NMF_ASSERT(cond)  do { if(!(cond)) NMF_PANIC("NMF_ASSERT at %s:%d\n", (int)__FILE__, (int)__LINE__); } while(0)

#ifndef EXPORT_NMF_COMPONENT
    #define EXPORT_NMF_COMPONENT    EXPORT_SHARED
#endif

#ifndef IMPORT_NMF_COMPONENT
    #define IMPORT_NMF_COMPONENT    IMPORT_SHARED
#endif

#endif /* _NMF_TYPE_H_ */
