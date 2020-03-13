/*
 * Copyright (C) 2010-2013 ARM Limited. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @file ump_arch.c
 *
 * UMP arch layer for UMP-UDD
 */

#include "ump.h"
#include "ump_arch.h"
#include <ump/ump_debug.h>

#include <ump/ump_uk_types.h>
#include "../os/ump_uku.h"

#include <linux/hwmem.h>

#include <cutils/log.h>

/** Pointer to an OS-Specific context that we should pass in _uku_ calls */
void *ump_uk_ctx = NULL;

/** Lock for critical section in open/close */
_ump_osu_lock_t * ump_lock_arch = NULL;

ump_secure_id ump_arch_allocate(unsigned long * size, ump_alloc_constraints constraints)
{
	_ump_uk_allocate_s call_arg;

	if ( NULL == size )
	{
		return UMP_INVALID_SECURE_ID;
	}

	call_arg.ctx = ump_uk_ctx;
	call_arg.secure_id = UMP_INVALID_SECURE_ID;
	call_arg.size = *size;
#ifdef UMP_DEBUG_SKIP_CODE
	/** Run-time ASSERTing that _ump_uk_api_version_s and ump_alloc_constraints are
	 * interchangable */
	switch (constraints)
	{
	case UMP_REF_DRV_CONSTRAINT_NONE:
		UMP_DEBUG_ASSERT( UMP_REF_DRV_UK_CONSTRAINT_NONE == constraints, ("ump_uk_alloc_constraints out of sync with ump_alloc_constraints") );
		break;
	case UMP_REF_DRV_CONSTRAINT_PHYSICALLY_LINEAR:
		UMP_DEBUG_ASSERT( UMP_REF_DRV_UK_CONSTRAINT_PHYSICALLY_LINEAR == constraints, ("ump_uk_alloc_constraints out of sync with ump_alloc_constraints") );
		break;
	default:
		UMP_DEBUG_ASSERT( 1, ("ump_uk_alloc_constraints out of sync with ump_alloc_constraints: %d unrecognized", constraints) );
		break;
	}
#endif
	call_arg.constraints = (ump_uk_alloc_constraints)constraints;

	if ( _UMP_OSU_ERR_OK != _ump_uku_allocate(&call_arg) )
	{
		return UMP_INVALID_SECURE_ID;
	}

	*size = call_arg.size;

	UMP_DEBUG_PRINT(4, ("UMP: Allocated ID %u, size %ul", call_arg.secure_id, call_arg.size));

	return call_arg.secure_id;
}

unsigned long ump_arch_size_get(ump_secure_id secure_id)
{
	_ump_uk_size_get_s dd_size_call_arg;

	dd_size_call_arg.ctx = ump_uk_ctx;
	dd_size_call_arg.secure_id = secure_id;
	dd_size_call_arg.size = 0;

	if (_UMP_OSU_ERR_OK == _ump_uku_size_get( &dd_size_call_arg ) )
	{
		return dd_size_call_arg.size;
	}

	return 0;
}

int ump_arch_release(ump_secure_id secure_id)
{
        int uk_ctx = (int)ump_uk_ctx;
        return hwmem_uku_release(uk_ctx, secure_id);
}

int ump_arch_import(ump_secure_id secure_id, unsigned long *size)
{
  unsigned long cookie; // r0@1
  struct hwmem_get_info_request req; // [sp+0h] [bp-20h]@1

  cookie = hwmem_uku_import((int)ump_uk_ctx, secure_id);
  req.size = 0;
  req.id = cookie;
  hwmem_uku_get_info((int)ump_uk_ctx, &req);

  *size = req.size;
  return cookie;
}

int ump_arch_export(int a1)
{
  return hwmem_uku_export((int)ump_uk_ctx, a1);
}

int ump_arch_lock(unsigned long offset, size_t size)
{
  int result; // r0@1

  result = hwmem_uku_map((int)ump_uk_ctx, offset, size);
  if ( result == -1 )
    result = 0;
  return result;
}
// 5054: using guessed type int ump_uk_ctx;

//----- (00001C80) --------------------------------------------------------
int ump_arch_unlock(unsigned long offset, void *mapped_mem, size_t size)
{
  return munmap(mapped_mem, size);
}

void* ump_arch_map(ump_secure_id secure_id, unsigned long size, ump_cache_enabled cache, unsigned long *cookie_out)
{
	_ump_uk_map_mem_s dd_map_call_arg;

	UMP_DEBUG_ASSERT_POINTER( cookie_out );

	dd_map_call_arg.ctx = ump_uk_ctx;
	dd_map_call_arg.secure_id = secure_id;
	dd_map_call_arg.size = size;
	dd_map_call_arg.is_cached = (u32) (UMP_CACHE_ENABLE==cache);

	if ( -1 == _ump_uku_map_mem( &dd_map_call_arg ) )
	{
		UMP_DEBUG_PRINT(4, ("UMP: Mapping failed for ID %u", secure_id));
		return NULL;
	}

	UMP_DEBUG_PRINT(4, ("Mapped %u at 0x%08lx", secure_id, (unsigned long)dd_map_call_arg.mapping));

	*cookie_out = dd_map_call_arg.cookie;
	return dd_map_call_arg.mapping;
}



void ump_arch_unmap(void* mapping, unsigned long size, unsigned long cookie)
{
	_ump_uk_unmap_mem_s dd_unmap_call_arg;

	dd_unmap_call_arg.ctx = ump_uk_ctx;
	dd_unmap_call_arg.mapping = mapping;
	dd_unmap_call_arg.size = size;
	dd_unmap_call_arg.cookie = cookie;

	UMP_DEBUG_PRINT(4, ("Unmapping 0x%08lx", (unsigned long)mapping));
	_ump_uku_unmap_mem( &dd_unmap_call_arg );
}

/** Memory synchronization - cache flushing of mapped memory */
ump_cache_enabled ump_arch_msync(ump_secure_id secure_id, void* mapping, unsigned long cookie, void * address, unsigned long size,  ump_cpu_msync_op op)
{
	_ump_uk_msync_s dd_msync_call_arg;

	dd_msync_call_arg.ctx = ump_uk_ctx;
	dd_msync_call_arg.mapping = mapping;
	dd_msync_call_arg.address = address;
	dd_msync_call_arg.size = size;
	dd_msync_call_arg.op = (ump_uk_msync_op)op;
	dd_msync_call_arg.cookie = cookie;
	dd_msync_call_arg.secure_id = secure_id;
	dd_msync_call_arg.is_cached = 0;

	UMP_DEBUG_PRINT(4, ("Msync 0x%08lx", (unsigned long)mapping));
	_ump_uku_msynch( &dd_msync_call_arg );
	if ( 0==dd_msync_call_arg.is_cached )
	{
		UMP_DEBUG_PRINT(4, ("Trying to flush uncached UMP mem ID: %d", secure_id));
	}
	return (ump_cache_enabled)(dd_msync_call_arg.is_cached);
}

/** Cache operation control. Tell when cache maintenance operations start and end.
This will allow the kernel to merge cache operations togheter, thus making them faster */
int ump_arch_cache_operations_control(ump_cache_op_control op)
{
	_ump_uk_cache_operations_control_s dd_cache_control_arg;

	dd_cache_control_arg.op = (ump_uk_cache_op_control)op;
	dd_cache_control_arg.ctx = ump_uk_ctx;

	UMP_DEBUG_PRINT(4, ("Cache control op:%d",(u32)op ));
	_ump_uku_cache_operations_control( &dd_cache_control_arg );
	return 1; /* Always success */
}

int ump_arch_switch_hw_usage( ump_secure_id secure_id, ump_hw_usage new_user )
{
	_ump_uk_switch_hw_usage_s dd_sitch_user_arg;

	dd_sitch_user_arg.secure_id = secure_id;
	dd_sitch_user_arg.new_user = (ump_uk_user)new_user;
	dd_sitch_user_arg.ctx = ump_uk_ctx;

	UMP_DEBUG_PRINT(4, ("Switch user UMP:%d User:%d",secure_id, (u32)new_user ));
	_ump_uku_switch_hw_usage( &dd_sitch_user_arg );
	return 1; /* Always success */
}
