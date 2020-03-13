/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "libUMP-shim"

#include "ump.h"
#include "arch_011_udd/ump_arch.h"
#include <ump/ump_debug.h>

#include <ump/ump_uk_types.h>
#include "os/ump_uku.h"

#include <cutils/log.h>

#include <dlfcn.h>
#include <errno.h>


#include "shim.h"



/* libUMP-shim constructor / destructor */

void libEvtLoading(void) __attribute__((constructor));
void libEvtUnloading(void) __attribute__((destructor));

/* wrapped library handle */

static void *realLibHandle;

int *ump_uk_ctx_ptr = NULL;
int *hwmem_ump_lock_ptr = NULL;
/* wrapped callbacks */

/* arch */

//ump_result (*fReal_ump_arch_open)(void);
//void (*fReal_ump_arch_close)(void);
//ump_secure_id (*fReal_ump_arch_allocate)(unsigned long * size, ump_alloc_constraints constraints);
int (*fReal_ump_arch_lock)(unsigned long offset, size_t size);
int (*fReal_ump_arch_unlock)(unsigned long offset, void *mapped_mem, size_t size);

//ump_cache_enabled (*fReal_ump_arch_msync)(ump_secure_id secure_id, void* mapping, unsigned long cookie,
//	 void * address, unsigned long size,  ump_cpu_msync_op op);

//void (*fReal_ump_arch_release)(ump_secure_id secure_id);

ump_secure_id (*fReal_ump_arch_import)(ump_secure_id secure_id, unsigned long *size);
ump_secure_id (*fReal_ump_arch_export)(ump_secure_id secure_id);


/* frontend */

//UMP_API_EXPORT unsigned long (*fReal_ump_size_get)(ump_handle memh);
//UMP_API_EXPORT ump_result  (*fReal_ump_open)(void);
//UMP_API_EXPORT void (*fReal_ump_close)(void);
//UMP_API_EXPORT ump_secure_id (*fReal_ump_secure_id_get)(ump_handle memh);
//UMP_API_EXPORT ump_handle (*fReal_ump_handle_create_from_secure_id)(ump_secure_id secure_id);
//UMP_API_EXPORT void (*fReal_ump_read)(void *dst, ump_handle srch, unsigned long offset, unsigned long length);
//UMP_API_EXPORT void (*fReal_ump_write)(ump_handle dsth, unsigned long offset, const void *src, unsigned long length);
//UMP_API_EXPORT void* (*fReal_ump_mapped_pointer_get)(ump_handle memh);
//UMP_API_EXPORT void (*fReal_ump_mapped_pointer_release)(ump_handle memh);
//UMP_API_EXPORT void (*fReal_ump_reference_add)(ump_handle memh);
//UMP_API_EXPORT void (*fReal_ump_reference_release)(ump_handle memh);

/******************************************************************************************************************************/


void libEvtLoading(void)
{

        realLibHandle = dlopen(REAL_LIB_NAME, RTLD_LOCAL);
        if (!realLibHandle) {
                RLOGE("Failed to load the real LIB '" REAL_LIB_NAME  "': %s\n", dlerror());
                return;
        }
        // load the real lib
	//LOAD_SYMBOL(fReal_ump_arch_open, "ump_arch_open");
	//LOAD_SYMBOL(fReal_ump_arch_close, "ump_arch_close");
	//LOAD_SYMBOL(fReal_ump_arch_allocate, "ump_arch_allocate");
	LOAD_SYMBOL(fReal_ump_arch_lock, "ump_arch_lock");
	LOAD_SYMBOL(fReal_ump_arch_unlock, "ump_arch_unlock");
	//LOAD_SYMBOL(fReal_ump_arch_msync, "ump_arch_msync");
	//LOAD_SYMBOL(fReal_ump_arch_release, "ump_arch_release");
	LOAD_SYMBOL(fReal_ump_arch_import, "ump_arch_import");
	LOAD_SYMBOL(fReal_ump_arch_export, "ump_arch_export");
	//LOAD_SYMBOL(fReal_ump_size_get, "ump_size_get");
        //LOAD_SYMBOL(fReal_ump_open, "ump_open");
        //LOAD_SYMBOL(fReal_ump_close, "ump_close");
        //LOAD_SYMBOL(fReal_ump_secure_id_get, "ump_secure_id_get");
        //LOAD_SYMBOL(fReal_ump_handle_create_from_secure_id, "ump_handle_create_from_secure_id");
        //LOAD_SYMBOL(fReal_ump_read, "ump_read");
        //LOAD_SYMBOL(fReal_ump_write, "ump_write");
        //LOAD_SYMBOL(fReal_ump_mapped_pointer_get, "ump_mapped_pointer_get");
        //LOAD_SYMBOL(fReal_ump_mapped_pointer_release, "ump_mapped_pointer_release");
	//LOAD_SYMBOL(fReal_ump_reference_add, "ump_reference_add");
	//LOAD_SYMBOL(fReal_ump_reference_release, "ump_reference_release");

	LOAD_SYMBOL(ump_uk_ctx_ptr, "ump_uk_ctx");
	LOAD_SYMBOL(hwmem_ump_lock_ptr, "hwmem_ump_lock");

	return;

out_fail:
	dlclose(realLibHandle);
}

void libEvtUnloading(void)
{
	if (realLibHandle)
		 dlclose(realLibHandle);
}

/* arch */

//WRAP_FUNCTION(ump_result, ump_arch_open, (void), (), fReal_ump_arch_open)

/*ump_result ump_arch_open(void) {
	int res = fReal_ump_arch_open();

	if (ump_uk_ctx_ptr != NULL) {
		ALOGE("UMP: ump_uk_ctx_ptr = %p", ump_uk_ctx_ptr);
		int uk_ctx = *ump_uk_ctx_ptr;
		ALOGE("UMP: ump_uk_ctx = %d", uk_ctx);
	}

	return res;
}*/

//WRAP_VOID_FUNCTION(ump_arch_close, (void), (), fReal_ump_arch_close)
//WRAP_FUNCTION(ump_secure_id, ump_arch_allocate, (unsigned long * size, ump_alloc_constraints constraints),
//		(size, constraints), fReal_ump_arch_allocate)

WRAP_FUNCTION(int, ump_arch_lock, (unsigned long offset, size_t size),
		(offset, size), fReal_ump_arch_lock)

WRAP_FUNCTION(int, ump_arch_unlock, (unsigned long offset, void *mapped_mem, size_t size),
		(offset, mapped_mem, size), fReal_ump_arch_unlock)

//WRAP_FUNCTION(ump_cache_enabled, ump_arch_msync, (ump_secure_id secure_id, void* mapping, unsigned long cookie,
//		void * address, unsigned long size,  ump_cpu_msync_op op),
//		(secure_id, mapping, cookie, address, size, op), fReal_ump_arch_msync)

//WRAP_VOID_FUNCTION(ump_arch_release, (ump_secure_id secure_id), (secure_id), fReal_ump_arch_release)

WRAP_FUNCTION(ump_secure_id, ump_arch_import, (ump_secure_id secure_id, unsigned long *size), (secure_id, size), fReal_ump_arch_import)
WRAP_FUNCTION(ump_secure_id, ump_arch_export, (ump_secure_id secure_id), (secure_id), fReal_ump_arch_export)

/* frontend */

//WRAP_FUNCTION(unsigned long, ump_size_get, (ump_handle memh), (memh), fReal_ump_size_get)

//WRAP_FUNCTION(ump_result, ump_open, (void), (), fReal_ump_open)
//WRAP_VOID_FUNCTION(ump_close, (void), (), fReal_ump_close)

//WRAP_FUNCTION(ump_secure_id, ump_secure_id_get, (ump_handle memh), (memh), fReal_ump_secure_id_get)
//WRAP_FUNCTION(ump_handle, ump_handle_create_from_secure_id, (ump_secure_id secure_id), (secure_id), fReal_ump_handle_create_from_secure_id)

ump_handle ump_handle_create_from_secure_id(ump_secure_id secure_id) {
	unsigned long cookie, size;
	void *mapping;

	ump_mem *mem = _ump_osu_calloc(1u, 0x1Cu);

	cookie = ump_arch_import(secure_id, &size);
	mapping = ump_arch_lock(cookie, size);

          mem->secure_id = secure_id;
          mem->mapped_mem = mapping;
          mem->size = size;
          mem->cookie = cookie;
          _ump_osu_lock_auto_init(&mem->ref_lock, _UMP_OSU_LOCKFLAG_DEFAULT, 0, 0);
          if (mem->ref_lock)
            mem->ref_count = 1;

	ALOGE("%s: UMP: UMP handle created for ID %u of size %lu, mapped into address 0x%08lx, ref_lock=0x%08lx, cookie=%ld, cached=%d", __func__, mem->secure_id, mem->size, (unsigned long)mem->mapped_mem, (unsigned long)mem->ref_lock, mem->cookie, mem->is_cached);
	return (ump_handle)mem;
}

//WRAP_VOID_FUNCTION(ump_read, (void *dst, ump_handle srch, unsigned long offset, unsigned long length),
//		(dst, srch, offset, length), fReal_ump_read)

//WRAP_VOID_FUNCTION(ump_write, (ump_handle dsth, unsigned long offset, const void *src, unsigned long length),
//		(dsth, offset, src, length), fReal_ump_write)

//WRAP_FUNCTION(void*, ump_mapped_pointer_get, (ump_handle memh), (memh), fReal_ump_mapped_pointer_get)
//WRAP_VOID_FUNCTION(ump_mapped_pointer_release, (ump_handle memh), (memh), fReal_ump_mapped_pointer_release)
//WRAP_VOID_FUNCTION(ump_reference_add, (ump_handle memh), (memh), fReal_ump_reference_add)
//WRAP_VOID_FUNCTION(ump_reference_release, (ump_handle memh), (memh), fReal_ump_reference_release)
