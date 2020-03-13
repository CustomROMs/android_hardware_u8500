/*
 * Copyright (C) 2020 Shilin Victor <chrono.monochrome@gmail.com>
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



#include <linux/hwmem.h>
#include "../ump_uku.h"

#include <sys/mman.h>

/* Needed for file operations on the device file*/
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>

//----- (00001D20) --------------------------------------------------------
int hwmem_uku_open(void **uk_ctx)
{
  int fd; // r0@2

  if ( uk_ctx )
  {
    fd = open("/dev/hwmem", O_RDWR);
    if ( fd != -1 )
    {
      *uk_ctx = (void *) fd;
      fd = 0;
    }
  }
  else
  {
    fd = -1;
  }
  return fd;
}

_ump_osu_errcode_t hwmem_uku_close( void **context )
{
        if(NULL == context)
        {
                return _UMP_OSU_ERR_FAULT;
        }

        if(-1 == (int)*context)
        {
                return _UMP_OSU_ERR_FAULT;
        }

        close((int)*context);
        *context = (void *)-1;

        return _UMP_OSU_ERR_OK;
}

//----- (00001D8C) --------------------------------------------------------
int hwmem_uku_allocate(int fd, _ump_uk_allocate_s *call_arg)
{
  if ( fd != -1 )
    fd = ioctl(fd, 0x40105701u, call_arg);
  return fd;
}

//----- (00001DA4) --------------------------------------------------------
int hwmem_uku_release(int result, int a2)
{
  if ( result != -1 )
    result = ioctl(result, 0x5703u, a2);
  return result;
}

//----- (00001DB8) --------------------------------------------------------
int hwmem_uku_import(int fd, int a2)
{
  if ( fd != -1 )
    fd = ioctl(fd, 0x570Bu, a2);
  return fd;
}

//----- (00001DCC) --------------------------------------------------------
int hwmem_uku_export(int result, int a2)
{
  if ( result != -1 )
    result = ioctl(result, 0x570Au, a2);
  return result;
}

//----- (00001DE0) --------------------------------------------------------
void *hwmem_uku_map(int fd, unsigned long offset, size_t len)
{
  void *mapped_mem;
  if (fd != -1)
    mapped_mem = mmap(0, len, 3, 1, fd, offset);
  return mapped_mem;
}

//----- (00001E24) --------------------------------------------------------
int hwmem_uku_set_sync_domain(int fd, struct hwmem_set_domain_request *req)
{
  if ( fd != -1 )
    fd = ioctl(fd, 0x401C5705u, req);
  return fd;
}

//----- (00001E3C) --------------------------------------------------------
int hwmem_uku_set_cpu_domain(int fd, struct hwmem_set_domain_request *req)
{
  if ( fd != -1 )
    fd = ioctl(fd, 0x401C5704u, req);
  return fd;
}

//----- (00001E54) --------------------------------------------------------
int hwmem_uku_pin(int fd, int a2)
{
  if ( fd != -1 )
    fd = ioctl(fd, 0xC0085706, a2);
  return fd;
}

//----- (00001E6C) --------------------------------------------------------
int hwmem_uku_unpin(int fd, int a2)
{
  if ( fd != -1 )
    fd = ioctl(fd, 0x5707u, a2);
  return fd;
}

//----- (00001E80) --------------------------------------------------------
int hwmem_uku_set_access(int fd, int a2)
{
  if ( fd != -1 )
    fd = ioctl(fd, 0x400C5708u, a2);
  return fd;
}

//----- (00001E98) --------------------------------------------------------
int hwmem_uku_get_info(int fd, struct hwmem_get_info_request *req)
{
  if ( fd != -1 )
    fd = ioctl(fd, 0xC0105709, req);
  return fd;
}
