
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
int hwmem_uku_import(int cookie, int a2)
{
  if ( cookie != -1 )
    cookie = ioctl(cookie, 0x570Bu, a2);
  return cookie;
}

//----- (00001DCC) --------------------------------------------------------
int hwmem_uku_export(int result, int a2)
{
  if ( result != -1 )
    result = ioctl(result, 0x570Au, a2);
  return result;
}

//----- (00001DE0) --------------------------------------------------------
void *hwmem_uku_map(void **context, unsigned long offset, size_t len)
{
  void *mapped_mem;
  if ((int)*context != -1)
    mapped_mem = mmap(0, len, 3, 1, (int)*context, offset);
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
int hwmem_uku_get_info(int fd, int a2)
{
  if ( fd != -1 )
    fd = ioctl(fd, 0xC0105709, a2);
  return fd;
}
