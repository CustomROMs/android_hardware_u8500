/*
 * Copyright (C) 2010-2011, 2013 ARM Limited. All rights reserved.
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
 * @file ump_frontend.c
 *
 * This file implements the user space API of the UMP API.
 * It relies heavily on a arch backend to do the communication with the UMP device driver.
 */



#include "ump.h"
#include "ump_internal.h"
#include "ump_arch.h"
#include <ump/ump_debug.h>
#include <ump/ump_osu.h>

//#include <linux/hwmem.h>

extern void *ump_uk_ctx;
_ump_osu_lock_t *hwmem_ump_lock = NULL;

static volatile int ump_ref_count = 0;

ump_result ump_arch_open(void)
{
  signed int result;
  signed int result_1;

  _ump_osu_lock_auto_init(&hwmem_ump_lock, _UMP_OSU_LOCKFLAG_DEFAULT, 0, 0);
  if ( hwmem_ump_lock )
  {
    if ( _ump_osu_lock_wait(hwmem_ump_lock, _UMP_OSU_LOCKMODE_RW) )
    {
      puts("UMP: ump_arch_open() failed to aquire lock");
      result = 1;
    }
    else
    {
      if ( ump_ref_count < 0 )
      {
        puts("*********************************************************************");
        printf("ASSERT EXIT: ");
        printf(
          "In file: vendor/st-ericsson/variant/multimedia/linux/mali400/driver/./src/ump/arch_hwmem/ump_arch_hwmem.c  fun"
          "ction: %s()   line:%4d\n",
          "ump_arch_open",
          53);
        printf("UMP: Reference count invalid at _mali_base_arch_open()");
        putchar(10);
        abort();
      }
      if ( ++ump_ref_count == 1 )
      {
        result_1 = hwmem_uku_open(&ump_uk_ctx);
        if ( result_1 )
        {
          result_1 = 1;
          puts("UMP: ump_arch_open() failed to open UMP device driver");
        }
      }
      _ump_osu_lock_signal(hwmem_ump_lock, 0);
      result = result_1;
    }
  }
  else
  {
    puts("UMP: ump_arch_open() failed to init lock");
    result = 1;
  }
  return result;
}


void ump_arch_close()
{
  _ump_osu_lock_auto_init(&hwmem_ump_lock, _UMP_OSU_LOCKFLAG_DEFAULT, 0, 0);
  if ( hwmem_ump_lock )
  {
    if ( _ump_osu_lock_wait(hwmem_ump_lock, _UMP_OSU_LOCKMODE_RW) )
    {
      puts("UMP: ump_arch_close() failed to aquire lock");
    }
    else
    {
      if ( ump_ref_count <= 0 )
      {
        puts("*********************************************************************");
        printf("ASSERT EXIT: ");
        printf(
          "In file: vendor/st-ericsson/variant/multimedia/linux/mali400/driver/./src/ump/arch_hwmem/ump_arch_hwmem.c  fun"
          "ction: %s()   line:%4d\n",
          "ump_arch_close",
          93);
        printf("UMP: ump_arch_close() called while no references exist");
        putchar(10);
        abort();
      }
      if ( ump_ref_count <= 0 || (--ump_ref_count, ump_ref_count) )
      {
        _ump_osu_lock_signal(hwmem_ump_lock, _UMP_OSU_LOCKMODE_RW);
      }
      else
      {
        if ( hwmem_uku_close(&ump_uk_ctx) )
        {
          puts("*********************************************************************");
          printf("ASSERT EXIT: ");
          printf(
            "In file: vendor/st-ericsson/variant/multimedia/linux/mali400/driver/./src/ump/arch_hwmem/ump_arch_hwmem.c  f"
            "unction: %s()   line:%4d\n",
            "ump_arch_close",
            100);
          printf("UMP: Failed to close UMP interface");
          putchar(10);
          abort();
        }
        ump_uk_ctx = NULL;
        _ump_osu_lock_signal(hwmem_ump_lock, _UMP_OSU_LOCKMODE_RW);
        _ump_osu_lock_term(hwmem_ump_lock);
        hwmem_ump_lock = NULL;
      }
    }
  }
  else
  {
    puts("UMP: ump_arch_close() failed to init lock");
  }
}

UMP_API_EXPORT void ump_open(void)
{
	ump_arch_open();
}

UMP_API_EXPORT void ump_close(void)
{
	ump_arch_close();
}

UMP_API_EXPORT ump_secure_id ump_secure_id_get(ump_handle memh)
{
	ump_mem * mem = (ump_mem*)memh;
	UMP_DEBUG_ASSERT(UMP_INVALID_MEMORY_HANDLE != memh, ("Handle is invalid"));
	UMP_DEBUG_ASSERT(UMP_INVALID_SECURE_ID != mem->secure_id, ("Secure ID is inavlid"));
	UMP_DEBUG_ASSERT(0 < mem->ref_count, ("Reference count too low"));
	UMP_DEBUG_ASSERT(0 < mem->size, ("Memory size of passed handle too low"));

	return mem->secure_id;
}

void *ump_mapped_pointer_get(ump_handle memh1)
{
  ump_mem *memh = (ump_mem *)memh1;
  ump_mem *mem = (ump_mem *)memh1;

  if ( memh )
  {
    if ( memh->secure_id == UMP_INVALID_SECURE_ID )
    {
      memh = 0;
    }
    else
    {
      memh = (ump_mem *)memh->mapped_mem;
      if ( !memh )
      {
        memh = (ump_mem *)ump_arch_lock(mem->cookie, mem->size);
        mem->mapped_mem = memh;
        if ( !memh )
        {
          puts("*********************************************************************");
          printf("ASSERT EXIT: ");
          printf(
            "In file: vendor/st-ericsson/variant/multimedia/linux/mali400/driver/./src/ump/arch_hwmem/ump_frontend_hwmem."
            "c  function: %s()   line:%4d\n",
            "ump_mapped_pointer_get",
            146);
          printf("Error in mapping pointer (not mapped)");
          putchar(10);
          abort();
        }
      }
    }
  }
  return memh;
}

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

UMP_API_EXPORT void ump_size_get(ump_handle memh)
{
	__asm__("cmp     r0, #0");
	__asm__("bxeq    lr");
	__asm__("ldr     r3, [r0]");
	__asm__("cmn     r3, #1");
	__asm__("ldrne   r0, [r0, #8]");
	__asm__("moveq   r0, #0");

	__asm__("bx      lr");
	//return;
}

UMP_API_EXPORT void ump_read(void *dst, ump_handle srch, unsigned long offset, unsigned long length)
{
	ump_mem * src = (ump_mem*)srch;

	UMP_DEBUG_ASSERT(UMP_INVALID_MEMORY_HANDLE != srch, ("Handle is invalid"));
	UMP_DEBUG_ASSERT(UMP_INVALID_SECURE_ID != src->secure_id, ("Secure ID is inavlid"));
	UMP_DEBUG_ASSERT(0 < src->ref_count, ("Reference count too low"));
	UMP_DEBUG_ASSERT(0 < src->size, ("Memory size of passed handle too low"));
	UMP_DEBUG_ASSERT(NULL != src->mapped_mem, ("UMP Memory is not mapped"));
	UMP_DEBUG_ASSERT((src->size) >= (offset + length), ("Requested read beyond end of UMP memory"));

	_ump_osu_memcpy(dst,(char*)(src->mapped_mem) + offset, length);
}

UMP_API_EXPORT void ump_write(ump_handle dsth, unsigned long offset, const void *src, unsigned long length)
{
	ump_mem * dst = (ump_mem*)dsth;

	UMP_DEBUG_ASSERT(UMP_INVALID_MEMORY_HANDLE != dsth, ("Handle is invalid"));
	UMP_DEBUG_ASSERT(UMP_INVALID_SECURE_ID != dst->secure_id, ("Secure ID is inavlid"));
	UMP_DEBUG_ASSERT(0 < dst->ref_count, ("Reference count too low"));
	UMP_DEBUG_ASSERT(0 < dst->size, ("Memory size of passed handle too low"));
	UMP_DEBUG_ASSERT(NULL != dst->mapped_mem, ("UMP Memory is not mapped"));
	UMP_DEBUG_ASSERT((dst->size) >= (offset + length), ("Requested write beyond end of UMP memory"));

	_ump_osu_memcpy((char*)(dst->mapped_mem) + offset, src, length);
}

UMP_API_EXPORT void ump_reference_add(ump_handle memh)
{
	ump_mem * mem = (ump_mem*)memh;

	UMP_DEBUG_ASSERT(UMP_INVALID_MEMORY_HANDLE != memh, ("Handle is invalid"));
	UMP_DEBUG_ASSERT(UMP_INVALID_SECURE_ID != mem->secure_id, ("Secure ID is inavlid"));
	UMP_DEBUG_ASSERT(0 < mem->ref_count, ("Reference count too low"));
	UMP_DEBUG_ASSERT(0 < mem->size, ("Memory size of passed handle too low"));

	_ump_osu_lock_wait(mem->ref_lock, _UMP_OSU_LOCKMODE_RW);
	mem->ref_count += 1;
	_ump_osu_lock_signal(mem->ref_lock, _UMP_OSU_LOCKMODE_RW);
}

void ump_mapped_pointer_release(ump_handle memh)
{
  ump_mem *mem, *mem1;

  mem = (ump_mem*)memh;

  mem1 = (ump_mem*)mem->mapped_mem;

  if (mem1)
    ump_arch_unlock(mem->cookie, mem1, mem->size);
  mem->mapped_mem = 0;
}

void ump_reference_release(ump_handle memh)
{
  ump_mem *mem = (ump_mem*)memh;

  if ( mem && mem->secure_id != UMP_INVALID_SECURE_ID)
  {
    _ump_osu_lock_wait(mem->ref_lock, 0);
    mem->ref_count -=1 ;

    if (0 == mem->ref_count)
    {
      ump_arch_release(mem->cookie);
      _ump_osu_lock_signal(mem->ref_lock, 0);
      _ump_osu_lock_term(mem->ref_lock);
      _ump_osu_free(mem);
    }
    else
    {
      _ump_osu_lock_signal(mem->ref_lock, 0);
    }
  }
}
