/*
 * Copyright (C) ST-Ericsson SA 2010. All rights reserved.
 * This code is ST-Ericsson proprietary and confidential.
 * Any use of the code for whatever purpose is subject to
 * specific written permission of ST-Ericsson SA.
 *
 */

/*! ****************************************************************************
 * \file uosal.h
 * utility osal declarations
 *
 * \author philippe.tribolo@stericsson.com
 *
 * *****************************************************************************/
#ifndef _UOSAL_H_
#define _UOSAL_H_

/////////////// OS headers ///////////////

// use of memcpy, memset, str(case)cmp, strn(case)cmp, strstr, NULL
#include <string.h>
// use of uint64_t (in place of long long)
#include <stdint.h>
// use of snprintf
#include <stdio.h>
// use of variadic
#include <stdarg.h>

/////////////// Gg's C++ coding-style ///////////////

// disallow copy and assign C++ operators
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
TypeName(const TypeName&); \
void operator=(const TypeName&)

/////////////// OSAL headers ///////////////

// OSAL services (mutex, timers, ..)
#include <omxilosalservices.h>

/////////////// DEBUG TRACES ///////////////
namespace rme {
class Debug {
  public:
    static int mTraceEnabled;
};
}

#if defined(SW_VARIANT_ANDROID)
//Android & LBP: trace enabled on property
#define LOG_TAG "RME"
#include "linux_utils.h"
#define RLOG_DEBUG(...)   { if (Debug::mTraceEnabled) { ALOGD(""); } }
#define RLOG_INFO(...)    { ALOGI(""); }
#define RLOG_WARNING(...) { ALOGW("WARNING "); }
#define RLOG_ERROR(...)   { ALOGE("ERROR "); }

#elif defined(__RMEUNITARYDEV__)
//unitary dev: forced logs
#define RLOG_DEBUG(...)   { printf("[RME] "); }
#define RLOG_INFO(...)    { printf("[RME] "); }
#define RLOG_WARNING(...) { printf("[RME] ""WARNING "); }
#define RLOG_ERROR(...)   { printf("[RME] ""ERROR "); }

#else
//other cases, including OSI
#define RLOG_DEBUG(...)   {}
#define RLOG_INFO(...)    {}
#define RLOG_WARNING(...) {}
#define RLOG_ERROR(...)   {}

#endif

#endif
