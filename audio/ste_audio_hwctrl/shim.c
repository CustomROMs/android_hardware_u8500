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

#define LOG_TAG "libste_audio_hwctrl-shim"

#include <cutils/log.h>

#include <dlfcn.h>
#include <errno.h>
#include <poll.h>

#include <stdbool.h>
#include <stdint.h>

#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>

#include "shim.h"

#include "alsactrl_tinyalsa_extn.h"
#include <tinyalsa/asoundlib.h>
#include <sound/asound.h>

#include <alsactrl_audiocodec.h>

typedef unsigned short uint16;
typedef signed short int16;
typedef unsigned long uint32;
typedef signed long int32;

enum audio_hal_chip_id_t {
       CHIP_ID_UNKNOWN = 0,
       CHIP_ID_AB8500 = 1,
};

struct sndrv_ctl_card_info {
        int card;                       /* card number */
        int pad;                        /* reserved for future (was type) */
        unsigned char id[16];           /* ID of card (user selectable) */
        unsigned char driver[16];       /* Driver name */
        unsigned char name[32];         /* Short name of soundcard */
        unsigned char longname[80];     /* name + info text about soundcard */
        unsigned char reserved_[16];    /* reserved for future (was ID of mixer) */
        unsigned char mixername[80];    /* visual mixer identification */
        unsigned char components[128];  /* card components / fine identification, delimited with one space (AC97 etc..) */
};

typedef struct sndrv_ctl_card_info snd_ctl_card_info_t;

//typedef struct alsactrl_dev_info_t audio_hwctrl_dev_info_t;

typedef struct sndrv_ctl_elem_list snd_ctl_elem_list_t;

typedef int snd_ctl_ops_t;

typedef enum _snd_ctl_type {
        /** Kernel level CTL */
        SND_CTL_TYPE_HW,
        /** Shared memory client CTL */
        SND_CTL_TYPE_SHM,
        /** INET client CTL (not yet implemented) */
        SND_CTL_TYPE_INET,
        /** External control plugin */
        SND_CTL_TYPE_EXT
} snd_ctl_type_t;

typedef struct _snd_ctl {
        void *dl_handle;
        char *name;
        snd_ctl_type_t type;
        const snd_ctl_ops_t *ops;
        void *private_data;
        int nonblock;
        int poll_fd;
        //struct list_head async_handlers;
} snd_ctl_t;


/** \brief Configuration node type. */
typedef enum _snd_config_type {
        /** Integer number. */
        SND_CONFIG_TYPE_INTEGER,
        /** 64-bit integer number. */
        SND_CONFIG_TYPE_INTEGER64,
        /** Real number. */
        SND_CONFIG_TYPE_REAL,
        /** Character string. */
        SND_CONFIG_TYPE_STRING,
        /** Pointer (runtime only, cannot be saved). */
        SND_CONFIG_TYPE_POINTER,
        /** Compound node. */
        SND_CONFIG_TYPE_COMPOUND = 1024
} snd_config_type_t;

/**
 * \brief Internal structure for a configuration node object.
 *
 * The ALSA library uses a pointer to this structure as a handle to a
 * configuration node. Applications don't access its contents directly.
 */
typedef struct _snd_config snd_config_t;

typedef struct _snd_input snd_input_t;

struct sndrv_ctl_elem_id {
        unsigned int numid;             /* numeric identifier, zero = invalid */
        int iface;                      /* interface identifier */
        unsigned int device;            /* device/client number */
        unsigned int subdevice;         /* subdevice (substream) number */
        unsigned char name[44];         /* ASCII name of item */
        unsigned int index;             /* index of item */
};

struct sndrv_ctl_elem_list {
        unsigned int offset;            /* W: first element ID to get */
        unsigned int space;             /* W: count of element IDs to get */
        unsigned int used;              /* R: count of element IDs set */
        unsigned int count;             /* R: count of all elements */
        struct sndrv_ctl_elem_id *pids; /* R: IDs */
        unsigned char reserved[50];
};

struct sndrv_ctl_elem_info {
        struct sndrv_ctl_elem_id id;    /* W: element ID */
        int type;                       /* R: value type - SNDRV_CTL_ELEM_TYPE_* */
        unsigned int access;            /* R: value access (bitmask) - SNDRV_CTL_ELEM_ACCESS_* */
        unsigned int count;             /* count of values */
        pid_t owner;                    /* owner's PID of this control */
        union {
                struct {
                        long min;               /* R: minimum value */
                        long max;               /* R: maximum value */
                        long step;              /* R: step (0 variable) */
                } integer;
                struct {
                        long long min;          /* R: minimum value */
                        long long max;          /* R: maximum value */
                        long long step;         /* R: step (0 variable) */
                } integer64;
                struct {
                        unsigned int items;     /* R: number of items */
                        unsigned int item;      /* W: item number */
                        char name[64];          /* R: value name */
                } enumerated;
                unsigned char reserved[128];
        } value;
        union {
                unsigned short d[4];            /* dimensions */
                unsigned short *d_ptr;          /* (obsolete) indirect */
        } dimen;
        unsigned char reserved[56];
};


struct sndrv_aes_iec958 {
        unsigned char status[24];       /* AES/IEC958 channel status bits */
        unsigned char subcode[147];     /* AES/IEC958 subcode bits */
        unsigned char pad;              /* nothing */
        unsigned char dig_subframe[4];  /* AES/IEC958 subframe bits */
};

struct sndrv_ctl_elem_value {
        struct sndrv_ctl_elem_id id;    /* W: element ID */
        unsigned int indirect: 1;       /* (obsolete) W: use indirect pointer (xxx_ptr member) */
        union {
                union {
                        long value[128];
                        long *value_ptr;        /* obsolete */
                } integer;
                union {
                        long long value[64];
                        long long *value_ptr;   /* obsolete */
                } integer64;
                union {
                        unsigned int item[128];
                        unsigned int *item_ptr; /* obsolete */
                } enumerated;
                union {
                        unsigned char data[512];
                        unsigned char *data_ptr;        /* obsolete */
                } bytes;
                struct sndrv_aes_iec958 iec958;
        } value;                /* RO */
        struct timespec tstamp;
        unsigned char reserved[128-sizeof(struct timespec)];
};

typedef struct sndrv_ctl_elem_info snd_ctl_elem_info_t;

typedef struct sndrv_ctl_elem_value snd_ctl_elem_value_t;


enum alsactrl_alsa_device {
        ALSACTRL_ALSA_DEVICE_AB850x = 0,
        ALSACTRL_ALSA_DEVICE_CG29XX = 1,
        ALSACTRL_ALSA_DEVICE_AB8540 = 2,
        ALSACTRL_ALSA_DEVICE_AB8540_VC= 3,
};

enum alsactrl_channel_state {
        ALSACTRL_CHANNEL_STATE_CLOSE = 0,
        ALSACTRL_CHANNEL_STATE_OPEN = 1,
};

typedef struct {
        const char* name;
        enum alsactrl_alsa_device alsa_dev;
        const char* dev_name;
        unsigned int stream_dir;
        int channels;
        int bits;
        int rate;
        struct pcm *pcm;
        int active;
        bool opened;
} alsactrl_dev_info_t;

typedef alsactrl_dev_info_t audio_hwctrl_dev_info_t;
/* libUMP-shim constructor / destructor */

void libEvtLoading(void) __attribute__((constructor));
void libEvtUnloading(void) __attribute__((destructor));

int alsactrl_set_channel_state(alsactrl_dev_info_t* dev, enum alsactrl_channel_state channel_state, bool matchPeer);
alsactrl_dev_info_t* Alsactrl_Hwh_GetDevInfo_Peer(alsactrl_dev_info_t* dev);
alsactrl_dev_info_t* Alsactrl_Hwh_GetDevInfo(enum alsactrl_alsa_device alsa_dev, unsigned int stream_dir);
int Alsactrl_Hwh_OpenAlsaDev(alsactrl_dev_info_t* dev_info_p);
void Alsactrl_Hwh_CloseAlsaDev(alsactrl_dev_info_t* dev_info_p);
/* wrapped library handle */

static void *realLibHandle;

bool audio_hal_alsa_get_ignore_defaults();



int (*fReal_audio_hwctrl_alsa_set_control)(snd_ctl_t *ctl, unsigned int numid, unsigned int idx, long value);

int (*fReal_change_active_count)(audio_hwctrl_dev_info_t* dev_info_p, enum alsactrl_channel_state channel_state);



int (*fReal_audio_hal_alsa_get_card_and_device_idx)(const char* name, unsigned int stream_dir, int* idx_card_p, int* idx_dev_p);
void (*fReal_audio_hal_alsa_close_controls)(void);
int (*fReal_audio_hal_alsa_open_controls_cardno)(int cardno_open);
int (*fReal_audio_hal_alsa_open_controls)(const char* card_name);
int (*fReal_audio_hal_alsa_get_control_values)(const char* control_name, long** values);
enum audio_hal_chip_id_t (*fReal_audio_hal_alsa_get_chip_id)(void);
int (*fReal_audio_hal_alsa_set_control_values)(const char* name, long* values);
int (*fReal_audio_hal_alsa_set_control)(const char* name, unsigned int idx, long value);
int (*fReal_audio_hal_alsa_set_control_cfg)(struct control_config_t *control_p);
void (*fReal_audio_hal_alsa_set_ignore_defaults)(bool ignore);
bool (*fReal_audio_hal_alsa_get_ignore_defaults)(void);

int (*fReal_audio_hal_set_volume)();
int (*fReal_audio_hal_get_volume)();
int (*fReal_audio_hal_set_mute)();
signed int (*fReal_audio_hal_get_mute)();
AUDIO_HAL_STATUS (*fReal_audio_hal_set_power)(unsigned int channel_index, AUDIO_HAL_STATE power_control, audio_hal_channel channel);
AUDIO_HAL_STATE (*fReal_audio_hal_get_power)(unsigned int channel_index, audio_hal_channel channel);
int (*fReal_audio_hal_digital_mute)(bool mute);
AUDIO_HAL_STATUS (*fReal_audio_hal_configure_channel)(audio_hal_channel channel, void* param);
int (*fReal_audio_hal_start_fsbitclk)(int value);
int (*fReal_audio_hal_stop_fsbitclk)(int value);
AUDIO_HAL_STATUS (*fReal_audio_hal_close_channel)(audio_hal_channel channel);
AUDIO_HAL_STATUS (*fReal_audio_hal_open_channel)(audio_hal_channel a1);
int (*fReal_audio_hal_switch_to_burst)(unsigned int framecount);
int (*fReal_audio_hal_switch_to_normal)();
int (*fReal_audio_hal_set_burst_device)(audio_hal_channel channel);


int (*fReal_audio_hal_alsa_set_controls_cfg)(const char* name);

/******************************************************************************************************************************/


void libEvtLoading(void)
{

        realLibHandle = dlopen(REAL_LIB_NAME, RTLD_LOCAL);
        if (!realLibHandle) {
                RLOGE("Failed to load the real LIB '" REAL_LIB_NAME  "': %s\n", dlerror());
                return;
        }
        // load the real lib

LOAD_SYMBOL(fReal_audio_hwctrl_alsa_set_control, "_Z29audio_hwctrl_alsa_set_controlP8_snd_ctljjl");
//LOAD_SYMBOL(fReal_audio_hwctrl_alsa_get_card_idx, "audio_hwctrl_alsa_get_card_idx");
//LOAD_SYMBOL(fReal_audio_hwctrl_alsa_open_card, "audio_hwctrl_alsa_open_card");
LOAD_SYMBOL(fReal_audio_hal_alsa_get_card_and_device_idx, "audio_hal_alsa_get_card_and_device_idx");
LOAD_SYMBOL(fReal_audio_hal_alsa_close_controls, "audio_hal_alsa_close_controls");
LOAD_SYMBOL(fReal_audio_hal_alsa_open_controls_cardno, "audio_hal_alsa_open_controls_cardno");
LOAD_SYMBOL(fReal_audio_hal_alsa_open_controls, "audio_hal_alsa_open_controls");
LOAD_SYMBOL(fReal_audio_hal_alsa_get_control_values, "audio_hal_alsa_get_control_values");
LOAD_SYMBOL(fReal_audio_hal_alsa_get_chip_id, "audio_hal_alsa_get_chip_id");
LOAD_SYMBOL(fReal_audio_hal_alsa_set_control_values, "audio_hal_alsa_set_control_values");
LOAD_SYMBOL(fReal_audio_hal_alsa_set_control, "audio_hal_alsa_set_control");
LOAD_SYMBOL(fReal_audio_hal_alsa_set_control_cfg, "audio_hal_alsa_set_control_cfg");
LOAD_SYMBOL(fReal_audio_hal_alsa_set_controls_cfg, "audio_hal_alsa_set_controls_cfg");

LOAD_SYMBOL(fReal_audio_hal_alsa_set_ignore_defaults, "audio_hal_alsa_set_ignore_defaults");
LOAD_SYMBOL(fReal_audio_hal_alsa_get_ignore_defaults, "audio_hal_alsa_get_ignore_defaults");
/*LOAD_SYMBOL(fReal_alsactrl_channel_state_earpiece, "alsactrl_channel_state_earpiece");
LOAD_SYMBOL(fReal_alsactrl_channel_state_hsetout, "alsactrl_channel_state_hsetout");
LOAD_SYMBOL(fReal_alsactrl_channel_state_speaker, "alsactrl_channel_state_speaker");
LOAD_SYMBOL(fReal_audio_hal_channel_vibral, "audio_hal_channel_vibral");
LOAD_SYMBOL(fReal_alsactrl_channel_state_vibrar, "alsactrl_channel_state_vibrar");
LOAD_SYMBOL(fReal_alsactrl_channel_state_hsetin, "alsactrl_channel_state_hsetin");
LOAD_SYMBOL(fReal_alsactrl_channel_state_mic, "alsactrl_channel_state_mic");*/
//LOAD_SYMBOL(fReal_audio_hwctrl_get_dev_info, "audio_hwctrl_get_dev_info");
//LOAD_SYMBOL(fReal_audio_hwctrl_channel_state, "audio_hwctrl_channel_state");
//LOAD_SYMBOL(fReal_sub_46F4, "sub_46F4");
//LOAD_SYMBOL(fReal_audio_hwctrl_close_alsa_device, "audio_hwctrl_close_alsa_device");
//LOAD_SYMBOL(fReal_audio_hwctrl_open_alsa_device, "audio_hwctrl_open_alsa_device");
//LOAD_SYMBOL(fReal_audio_hwctrl_open_alsa_device, "audio_hwctrl_open_alsa_device");
//LOAD_SYMBOL(fReal_alsactrl_set_channel_state, "alsactrl_set_channel_state");
//LOAD_SYMBOL(fReal_check_alsa_card_number, "check_alsa_card_number");
LOAD_SYMBOL(fReal_audio_hal_set_volume, "audio_hal_set_volume");
LOAD_SYMBOL(fReal_audio_hal_get_volume, "audio_hal_get_volume");
LOAD_SYMBOL(fReal_audio_hal_set_mute, "audio_hal_set_mute");
LOAD_SYMBOL(fReal_audio_hal_get_mute, "audio_hal_get_mute");
LOAD_SYMBOL(fReal_audio_hal_set_power, "audio_hal_set_power");
LOAD_SYMBOL(fReal_audio_hal_get_power, "audio_hal_get_power");
LOAD_SYMBOL(fReal_audio_hal_digital_mute, "audio_hal_digital_mute");
LOAD_SYMBOL(fReal_audio_hal_configure_channel, "audio_hal_configure_channel");
LOAD_SYMBOL(fReal_audio_hal_start_fsbitclk, "audio_hal_start_fsbitclk");
LOAD_SYMBOL(fReal_audio_hal_stop_fsbitclk, "audio_hal_stop_fsbitclk");
LOAD_SYMBOL(fReal_change_active_count, "_Z19change_active_countP23audio_hwctrl_dev_info_t26audio_hwctrl_channel_state");
//LOAD_SYMBOL(fReal_audio_hal_change_channel, "audio_hal_change_channel");
LOAD_SYMBOL(fReal_audio_hal_close_channel, "audio_hal_close_channel");
LOAD_SYMBOL(fReal_audio_hal_open_channel, "audio_hal_open_channel");
LOAD_SYMBOL(fReal_audio_hal_switch_to_burst, "audio_hal_switch_to_burst");
LOAD_SYMBOL(fReal_audio_hal_switch_to_normal, "audio_hal_switch_to_normal");
LOAD_SYMBOL(fReal_audio_hal_set_burst_device, "audio_hal_set_burst_device");
//LOAD_SYMBOL(fReal_get_fcn_name, "get_fcn_name");


	return;

out_fail:
	dlclose(realLibHandle);
}

void libEvtUnloading(void)
{
	if (realLibHandle)
		 dlclose(realLibHandle);
}


int gCardNo = -1;
snd_ctl_card_info_t * gCardInfo;
snd_ctl_card_info_t card_info;
snd_ctl_t* gControl = NULL;
snd_ctl_elem_list_t *gElemList = NULL;

static pthread_mutex_t ctl_open_mutex = PTHREAD_MUTEX_INITIALIZER;

int audio_hwctrl_alsa_open_card(int cardno_open)
{
  int res_tmp; // r5@2
  int result; // r0@3
  size_t card_info_size; // r0@6
   // [sp+8h] [bp+0h]@6 snd_ctl_card_info_t card_info;
                 //                   
  char name[64]; // [sp+Ch] [bp+4h]@5

  if ( gCardNo != -1 )
    goto err;
  sprintf(name, "hw:%d", cardno_open + 1);
  res_tmp = snd_ctl_open(&gControl, name, 4);
  if ( res_tmp < 0 )
  {
    ALOGE("%s: ERROR: Can't open card %s!", __func__, name);
    hwctrl_free();
  }
  else
  {
    gCardNo = cardno_open;
    gCardInfo = &card_info;
    card_info_size = snd_ctl_card_info_sizeof();
    memset(&card_info, 0, card_info_size);
    res_tmp = snd_ctl_card_info(gControl, gCardInfo);
    if ( res_tmp >= 0 )
    {
err:
      res_tmp = 0;
      goto out;
    }

    ALOGE("%s: ERROR: snd_ctl_card_info returned %d!", __func__, res_tmp);
    hwctrl_free();
  }
out:
  result = res_tmp;

  return result;
}

int audio_hal_alsa_open_controls_cardno(int cardno_open)
{
  int res_tmp; // r7@1
  int res; // r4@2
  unsigned int elem_list_count; // r0@4


  pthread_mutex_lock(&ctl_open_mutex);
  res_tmp = audio_hwctrl_alsa_open_card(cardno_open);
  if ( res_tmp < 0 )
  {
    res = -1;
  
    ALOGE("%s: ERROR: audio_hwctrl_alsa_open_card returned %d!", __func__, res_tmp);
    pthread_mutex_unlock(&ctl_open_mutex);
    return res;
  }
  res = snd_ctl_elem_list_malloc(&gElemList);
  if ( res < 0 )
  {
    ALOGE("%s: ERROR: snd_ctl_elem_list_malloc returned %d!", __func__, res);
    hwctrl_free();
    pthread_mutex_unlock(&ctl_open_mutex);
    return res;
  }
  res = snd_ctl_elem_list(gControl, gElemList);
  if ( res < 0 )
  {
    ALOGE("%s: ERROR: snd_ctl_elem_list returned %d!", __func__, res);
    return res;
  }
  elem_list_count = snd_ctl_elem_list_get_count(gElemList);
  res = snd_ctl_elem_list_alloc_space(gElemList, elem_list_count);
  if ( res < 0 )
  {
    ALOGE("%s: ERROR: snd_ctl_elem_list_alloc_space returned %d!", __func__, res);
    return res;
  }
  res = snd_ctl_elem_list(gControl, gElemList);
  if ( res < 0 )
  {
    ALOGE("%s: ERROR: snd_ctl_elem_list returned %d!", __func__, res);
    return res;
  }
  res = 0;
  snd_ctl_elem_list_get_used(gElemList);
  return res;
}

int load_state(const char *file, const char *initfile, const char *cardname,
               int do_init);

int audio_hal_alsa_set_controls_cfg(const char *name)
{
	__android_log_print(6, LOG_TAG, "%s: len=%d, name = %s", __func__, strlen(name), name);
	if (!gControl || !gElemList)
		ALOGE("%s: audio_hal_alsa_open_controls_cardno=%d", __func__, audio_hal_alsa_open_controls_cardno(-1));
	else
		ALOGE("%s: gControl = %p, gElemList = %p", __func__, gControl, gElemList);
	
   FILE *fptr;

   fptr = fopen("/data/local/audio_hal_alsa_set_controls_cfg.txt","w");

   if(fptr == NULL)
   {
      ALOGE("Error writing to audio_hal_alsa_set_controls_cfg.txt!");               
   } 	

// loop i
fwrite(name, strlen(name), 1, fptr);

fclose(fptr);
	load_state("/data/local/audio_hal_alsa_set_controls_cfg.txt", "/system/usr/share/alsa/init/00main", NULL, 0);
	return 0;
	//return fReal_audio_hal_alsa_set_controls_cfg(name);
}

enum audio_hal_chip_id_t audio_hal_alsa_get_chip_id(void)
{
	//enum audio_hal_chip_id_t value = fReal_audio_hal_alsa_get_chip_id();
	//ALOGE("%s: value=%d", __func__, value);
	
	//return value;
	return 1;
}

int numid_from_name(const snd_ctl_elem_list_t *obj, const char *control_name, unsigned int *value)
{
  unsigned int elem_used; // r0@1 MAPDST
  unsigned int idx; // r1@1
  const char *elem_list_name; // r0@3
  int result; // r0@3

  elem_used = snd_ctl_elem_list_get_used(obj);
  idx = 0;
  *value = 0;
  while ( 1 )
  {
    elem_list_name = snd_ctl_elem_list_get_name(obj, idx);
    result = strcmp(elem_list_name, control_name);
    if ( !result )
      break;
    idx = *value + 1;
    *value = idx;
    if ( elem_used <= idx )
      goto err;
  }
  if ( elem_used > *value )
  {
    ++*value;
    return result;
  }
err:
  ALOGE("%s: ERROR: Couldn't find control '%s'!\n", __func__, control_name);
  return -1;
}

int set_ctl_elem_value(snd_ctl_t *ctl, unsigned int numid, unsigned int idx, long val, snd_ctl_elem_value_t *value)
{
  size_t elem_info_size; // r0@1
  snd_ctl_elem_type_t elem_type; // r0@2 MAPDST
  int result; // r0@8
  int val1; // r2@18
  snd_ctl_elem_info_t elem_info; // [sp+8h] [bp+0h]@1

  elem_info_size = snd_ctl_elem_info_sizeof();
  memset(&elem_info, 0, elem_info_size);
  snd_ctl_elem_info_set_numid(&elem_info, numid);
  if ( snd_ctl_elem_info(ctl, &elem_info) < 0 )
  {
    ALOGE("%s: ERROR: Unable to get CTL-info!\n", __func__);
    result = -1;
    goto out;
  }
  elem_type = snd_ctl_elem_info_get_type(&elem_info);
  if ( elem_type == 2 )
  {
    snd_ctl_elem_value_get_integer(value, idx);
    goto integer_handler;
  }
  if ( elem_type == 3 )
  {
    snd_ctl_elem_value_get_enumerated(value, idx);
    goto enum_handler;
  }
  if ( elem_type != 1 )
  {
    if ( elem_type != 2 )
    {
      if ( elem_type != 3 )
      {
        if ( elem_type != 1 )
        {
          ALOGE("%s: ERROR: Unknown CTL value-type (%d)!\n", __func__, elem_type);
          result = -1;
          goto out;
        }
        goto boolean_handler;
      }
enum_handler:
      if ( val > snd_ctl_elem_info_get_items(&elem_info) - 1)
      {
        
        ALOGE("%s: ERROR: Enum-index %d outside bounds!\n", __func__, val);
        result = -1;
      }
      else
      {
        snd_ctl_elem_value_set_enumerated(value, idx, val);
        result = 0;
      }
      goto out;
    }
integer_handler:
    snd_ctl_elem_value_set_integer(value, idx, val);
    result = 0;
    goto out;
  }
  snd_ctl_elem_value_get_boolean(value, idx);
boolean_handler:
  if ( val >= 1 )
    val1 = 1;
  else
    val1 = val;
  snd_ctl_elem_value_set_boolean(value, idx, val1);
  result = 0;
out:
  return result;
}

int audio_hwctrl_alsa_set_control(snd_ctl_t *ctl, unsigned int numid, unsigned int idx, long value)
{
  size_t elem_info_size; // r0@1
  int res; // r4@1
  unsigned int elem_info_count; // r10@2
  size_t elem_value_size; // r0@3
  int result; // r0@8
  snd_ctl_elem_info_t elem_info; // [sp+10h] [bp+0h]@1
  snd_ctl_elem_value_t elem_value;

  snd_ctl_elem_info_sizeof();
  elem_info_size = snd_ctl_elem_info_sizeof();
  memset(&elem_info, 0, elem_info_size);
  snd_ctl_elem_info_set_numid(&elem_info, numid);
  res = snd_ctl_elem_info(ctl, &elem_info);
  if ( res < 0 )
  {

    ALOGE(
      "%s: ERROR: Unable to get get CTL-info for control %d! (ret = %d)",
      __func__,
      numid,
      res);
  }
  else
  {
    elem_info_count = snd_ctl_elem_info_get_count(&elem_info);
    if ( elem_info_count - 1 < idx )
    {

      ALOGE(
        "%s: ERROR: Unable set CTL-value at index %d for control %d! (count = %d)\n",
        __func__,
        idx,
        numid,
        elem_info_count);
    }
    else
    {
      elem_value_size = snd_ctl_elem_value_sizeof();
      memset(&elem_value, 0, elem_value_size);
      snd_ctl_elem_value_set_numid(&elem_value, numid);
	  res = snd_ctl_elem_read(ctl, &elem_value);
      if (elem_info_count > 1 &&  res < 0)
      {

        ALOGE(
          "%s: ERROR: Unable to read current CTL-value from control %d! (ret = %d)\n",
          __func__,
          numid,
          res);
      }
      else
      {
        res = set_ctl_elem_value(ctl, numid, idx, value, &elem_value);
        if ( res < 0 )
        {

          ALOGE(
            "%s: ERROR: Unable set CTL-value (idx = %d) for control %d! (ret = %d)\n",
            __func__,
            idx,
            numid,
            res);
        }
        else
        {
          res = snd_ctl_elem_write(ctl, &elem_value);
          if ( res < 0 )
          {

            ALOGE(
              "%s: ERROR: Unable write CTL-value to control %d! (ret = %d)\n",
              __func__,
              numid,
              res);
          }
          else
          {
            res = 0;
          }
        }
      }
    }
  }
  result = res;

  return result;
}

int audio_hal_alsa_set_control(const char *name, unsigned int idx, long value)
{
  int result; // r0@4
  unsigned int numid; // [sp+4h] [bp-14h]@3
  
	if (!gControl || !gElemList)
		ALOGE("%s: audio_hal_alsa_open_controls_cardno=%d", __func__, audio_hal_alsa_open_controls_cardno(-1));
	else
		ALOGE("%s: gControl = %p, gElemList = %p", __func__, gControl, gElemList);

  if ( gControl && gElemList )
  {
    if ( numid_from_name(gElemList, name, &numid) >= 0 )
      result = audio_hwctrl_alsa_set_control(gControl, numid, idx, value);
    else
      result = -1;
  }
  else
  {
    ALOGE("%s: ERROR: Controls not opened!\n", __func__);
    audio_hal_alsa_close_controls();
    result = -1;
  }
  return result;
}

int audio_hwctrl_alsa_set_control1(snd_ctl_t *ctl, unsigned int idx, long *values)
{
  size_t elem_info_size; // r0@1
  int res; // r8@1
  unsigned int elem_count; // r11@2
  size_t elem_value_size; // r0@2
  unsigned int count; // r4@3
  long values_local; // t1@5
  int set_elem_value_res; // r9@5
  signed int tmp_res; // r5@6
  int result; // r0@7

  snd_ctl_elem_info_t elem_info; // [sp+10h] [bp+0h]@1
  snd_ctl_elem_value_t elem_value;

  elem_info_size = snd_ctl_elem_info_sizeof();
  memset(&elem_info, 0, elem_info_size);
  snd_ctl_elem_info_set_numid(&elem_info, idx);
  res = snd_ctl_elem_info(ctl, &elem_info);
  if ( res < 0 )
  {
    tmp_res = -1;
    
    ALOGE(
      "%s: ERROR: Unable to get get CTL-info for control %d! (ret = %d)",
      __func__,
      idx,
      elem_info);
  }
  else
  {
    elem_count = snd_ctl_elem_info_get_count(&elem_info);
    elem_value_size = snd_ctl_elem_value_sizeof();
    memset(&elem_value, 0, elem_value_size);
    snd_ctl_elem_value_set_numid(&elem_value, idx);
    if ( elem_count )
    {
      count = 0;
      while ( 1 )
      {
        values_local = *values;
        ++values;
        set_elem_value_res = set_ctl_elem_value(
                               ctl,
                               idx,
                               count,
                               values_local,
                               &elem_value);
        if ( set_elem_value_res < 0 )
          break;
        if ( ++count == elem_count )
          goto out;
      }
      tmp_res = -1;

      ALOGE(
        "%s: ERROR: Unable set CTL-value (idx = %d) for control %d! (ret = %d)\n",
        __func__,
        count,
        idx,
        set_elem_value_res);
    }
    else
    {
out:
      tmp_res = snd_ctl_elem_write(ctl, &elem_value);
      if ( tmp_res < 0 )
      {

        ALOGE(
          "%s: ERROR: Unable write CTL-value to control %d! (ret = %d)\n",
          __func__,
          idx,
          tmp_res);
      }
      else
      {
        tmp_res = 0;
      }
    }
  }
  result = tmp_res;

  return result;
}

int audio_hal_alsa_set_control_values(const char *name, long *values)
{
  int result; // r0@4
  unsigned int numid; // [sp+4h] [bp-14h]@3
	if (!gControl || !gElemList)
		ALOGE("%s: audio_hal_alsa_open_controls_cardno=%d", __func__, audio_hal_alsa_open_controls_cardno(-1));
	else
		ALOGE("%s: gControl = %p, gElemList = %p", __func__, gControl, gElemList);

  if ( gControl && gElemList )
  {
    if ( numid_from_name(gElemList, name, &numid) >= 0 )
      result = audio_hwctrl_alsa_set_control1(gControl, numid, values);
    else
      result = -1;
  }
  else
  {
    ALOGE("%s: ERROR: Controls not opened!\n", __func__);
    audio_hal_alsa_close_controls();
    result = -1;
  }
  return result;
}

static alsactrl_dev_info_t devs[] = {
	{
		"AB8500 (Playback)",
		ALSACTRL_ALSA_DEVICE_AB850x,
		"ab8500_0",
		PCM_OUT,
		8,
		16,
		48000,
		NULL,
		0,
		false
	},
	{
		"AB8500 (Capture)",
		ALSACTRL_ALSA_DEVICE_AB850x,
		"ab8500_1",
		PCM_IN,
		8,
		16,
		48000,
		NULL,
		0,
		false
	},
	{
		"Generic MSP (Playback)",
		ALSACTRL_ALSA_DEVICE_CG29XX,
		"msp_0",
		PCM_OUT,
		1,
		16,
		8000,
		NULL,
		0,
		false
	},
	{
		"Generic MSP (Capture)",
		ALSACTRL_ALSA_DEVICE_CG29XX,
		"msp_0",
		PCM_IN,
		1,
		16,
		8000,
		NULL,
		0,
		false
	},
};

signed int audio_hwctrl_get_dev_info(audio_hal_channel channel, alsactrl_dev_info_t **dev_info)
{
  signed int result; // r0@2
  const char *fcn; // r0@7
  
  switch ( channel )
  {
    case 8:                                     // AUDIO_HAL_CHANNEL_BTIN
      result = 0;
      *dev_info = &devs[3]; //&gDevCG29XXCapture;
      break;
    case 7:                                     // AUDIO_HAL_CHANNEL_BTOUT
      result = 0;
      *dev_info = &devs[2]; // &gDevCG29XXPlayback;
      break;
    case 3:                                     // AUDIO_HAL_CHANNEL_HSETIN
    case 4:                                     // AUDIO_HAL_CHANNEL_MIC
    case 6:                                     // AUDIO_HAL_CHANNEL_FMRX
      result = 0;
      *dev_info = &devs[1]; // &gDevAB8500Capture;
      break;
    case 0:                                     // AUDIO_HAL_CHANNEL_SPEAKER
    case 1:                                     // AUDIO_HAL_CHANNEL_EARPIECE
    case 2:                                     // AUDIO_HAL_CHANNEL_HSETOUT
    case 5:                                     // AUDIO_HAL_CHANNEL_FMTX
    case 10:                                    // AUDIO_HAL_CHANNEL_VIBRAL
    case 11:                                    // AUDIO_HAL_CHANNEL_VIBRAR
      result = 0;
      *dev_info = &devs[0]; // &gDevAB8500Playback;
      break;
    default:
      ALOGE("%s: ERROR: No device defined on channel (%d)!", __func__, channel);
      result = 0x80001005;
      break;
  }
  return result;
}


//----- (00004174) --------------------------------------------------------
int alsactrl_channel_state_earpiece(enum alsactrl_channel_state state)
{
  int result; // r0@2

  if ( state == 1 )
  {
    audio_hal_alsa_set_control("Earpiece", 0, 1);
    audio_hal_alsa_set_control("Earpiece Playback Switch", 0, state);
    audio_hal_alsa_set_control("Earpiece Analog Gain Playback Volume", 0, 6);
    audio_hal_alsa_set_control("Headset Master Gain Playback Volume", 0, 40);
    audio_hal_alsa_set_control("Headset Master Gain Playback Volume", state, 40);
    result = 0;
  }
  else
  {
    audio_hal_alsa_set_control("Earpiece", 0, 0);
    audio_hal_alsa_set_control("Earpiece Playback Switch", 0, 0);
    result = 0;
  }
  return result;
}

//----- (000041F0) --------------------------------------------------------
int alsactrl_channel_state_hsetout(enum alsactrl_channel_state state)
{
  int result; // r0@2

  if ( state == 1 )
  {
    audio_hal_alsa_set_control("Headset Left", 0, 1);
    audio_hal_alsa_set_control("Headset Right", 0, state);
    audio_hal_alsa_set_control("Headset Digital Gain Playback Volume", 0, 9);
    audio_hal_alsa_set_control("Headset Digital Gain Playback Volume", state, 9);
    audio_hal_alsa_set_control("Headset Master Gain Playback Volume", 0, 40);
    audio_hal_alsa_set_control("Headset Master Gain Playback Volume", state, 40);
    result = 0;
  }
  else
  {
    audio_hal_alsa_set_control("Headset Left", 0, 0);
    audio_hal_alsa_set_control("Headset Right", 0, 0);
    result = 0;
  }
  return result;
}

//----- (00004360) --------------------------------------------------------
int audio_hal_channel_vibral(enum alsactrl_channel_state state)
{
  int result; // r0@2

  if ( state == 1 )
  {
    audio_hal_alsa_set_control("Vibra Master Gain Playback Volume", 0, 63);
    audio_hal_alsa_set_control("Digital Interface DA 5 From Slot Map", 0, 12);
    audio_hal_alsa_set_control("Vibra 1 Playback Route", 0, 0);
    audio_hal_alsa_set_control("Vibra 1", 0, state);
    result = 0;
  }
  else
  {
    audio_hal_alsa_set_control("Vibra 1", 0, 0);
    result = 0;
  }
  return result;
}

//----- (000043C0) --------------------------------------------------------
int alsactrl_channel_state_vibrar(enum alsactrl_channel_state state)
{
  int result; // r0@2

  if ( state == 1 )
  {
    audio_hal_alsa_set_control("Vibra Master Gain Playback Volume", 1u, 63);
    audio_hal_alsa_set_control("Digital Interface DA 6 From Slot Map", 0, 13);
    audio_hal_alsa_set_control("Vibra 2 Playback Route", 0, 0);
    audio_hal_alsa_set_control("Vibra 2", 0, state);
    result = 0;
  }
  else
  {
    audio_hal_alsa_set_control("Vibra 2", 0, 0);
    result = 0;
  }
  return result;
}

//----- (00004420) --------------------------------------------------------
int alsactrl_channel_state_hsetin(enum alsactrl_channel_state state)
{
  int result; // r0@2

  if ( state == 1 )
  {
    audio_hal_alsa_set_control("Mic Master Gain Capture Volume", 0, 50);
    audio_hal_alsa_set_control("Mic Master Gain Capture Volum", state, 50);
    audio_hal_alsa_set_control("Mic 1 Capture Volume", 0, 28);
    audio_hal_alsa_set_control("Mic 1", 0, state);
    audio_hal_alsa_set_control("AD 3 Select Capture Route", 0, 0);
    audio_hal_alsa_set_control("Digital Interface AD To Slot 0 Map", 0, 2);
    audio_hal_alsa_set_control("Mic 1A or 1B Select Capture Route", 0, state);
    result = 0;
  }
  else
  {
    audio_hal_alsa_set_control("Mic 1", 0, 0);
    result = 0;
  }
  return result;
}

//----- (000044B0) --------------------------------------------------------
int alsactrl_channel_state_mic(enum alsactrl_channel_state state)
{
  int result; // r0@2

  if ( state == 1 )
  {
    audio_hal_alsa_set_control("Mic Master Gain Capture Volume", 0, 50);
    audio_hal_alsa_set_control("Mic Master Gain Capture Volume", state, 50);
    audio_hal_alsa_set_control("LineIn Master Gain Capture Volume", state, 50);
    audio_hal_alsa_set_control("Mic 1 Capture Volume", 0, 28);
    audio_hal_alsa_set_control("Mic 2 Capture Volume", 0, 28);
    audio_hal_alsa_set_control("Mic 1", 0, state);
    audio_hal_alsa_set_control("Mic 2", 0, state);
    audio_hal_alsa_set_control("AD 3 Select Capture Route", 0, 0);
    audio_hal_alsa_set_control("AD 2 Select Capture Route", 0, 0);
    audio_hal_alsa_set_control("Mic 2 or LINR Select Capture Route", 0, 0);
    audio_hal_alsa_set_control("Digital Interface AD To Slot 0 Map", 0, 2);
    audio_hal_alsa_set_control("Digital Interface AD To Slot 1 Map", 0, state);
    audio_hal_alsa_set_control("Mic 1A or 1B Select Capture Route", 0, 0);
    result = 0;
  }
  else
  {
    audio_hal_alsa_set_control("Mic 1", 0, 0);
    audio_hal_alsa_set_control("Mic 2", 0, 0);
    result = 0;
  }
  return result;
}

int alsactrl_channel_state_speaker(enum alsactrl_channel_state state)
{
  int result; // r0@2

  if ( state == 1 )
  {
    audio_hal_alsa_set_control("IHF Mode Playback Switch", 0, 0);
    audio_hal_alsa_set_control("IHF Left", 0, state);
    audio_hal_alsa_set_control("IHF Right", 0, state);
    audio_hal_alsa_set_control("IHF High Volume Playback Switch", 0, state);
    audio_hal_alsa_set_control("IHF High Volume Playback Switch", state, state);
    audio_hal_alsa_set_control("IHF Left Source Playback Route", 0, 0);
    audio_hal_alsa_set_control("IHF Right Source Playback Route", 0, 0);
    audio_hal_alsa_set_control("IHF Master Gain Playback Volume", 0, 40);
    audio_hal_alsa_set_control("IHF Digital Gain Playback Volume", 0, 20);
    audio_hal_alsa_set_control("Digital Interface DA 3 From Slot Map", 0, 10);
    audio_hal_alsa_set_control("Digital Interface DA 4 From Slot Map", 0, 11);
    audio_hal_alsa_set_control("IHF Master Gain Playback Volume", state, 40);
    result = 0;
  }
  else
  {
    audio_hal_alsa_set_control("IHF Left", 0, 0);
    audio_hal_alsa_set_control("IHF Right", 0, 0);
    result = 0;
  }
  return result;
}

int audio_hwctrl_channel_state(audio_hal_channel channel, enum alsactrl_channel_state state)
{
  int val; // r4@2
  int result; // r0@3
  const char *fcn_res; // r0@5

  audio_hal_alsa_open_controls("U8500card");
  switch ( channel )
  {
    case 10:                                    // AUDIO_HAL_CHANNEL_VIBRAL
      val = audio_hal_channel_vibral(state);
      goto out;
    default:
      ALOGE("%s: ERROR: Unknown channel type (%d)!", __func__, channel);
      return 0x80001005;
    case 0:                                     // AUDIO_HAL_CHANNEL_SPEAKER
      val = alsactrl_channel_state_speaker(state);
      goto out;
    case 1:                                     // AUDIO_HAL_CHANNEL_EARPIECE
      val = alsactrl_channel_state_earpiece(state);
      goto out;
    case 2:                                     // AUDIO_HAL_CHANNEL_HSETOUT
      val = alsactrl_channel_state_hsetout(state);
      goto out;
    case 3:                                     // AUDIO_HAL_CHANNEL_HSETIN
      val = alsactrl_channel_state_hsetin(state);
      goto out;
    case 4:                                     // AUDIO_HAL_CHANNEL_MIC
      val = alsactrl_channel_state_mic(state);
      goto out;
    case 5:                                     // AUDIO_HAL_CHANNEL_FMTX
                                                // AUDIO_HAL_CHANNEL_FMRX
    case 6:
      audio_hal_alsa_close_controls();
      result = 0;
      break;
    case 11:                                    // AUDIO_HAL_CHANNEL_VIBRAR
      val = alsactrl_channel_state_vibrar(state);
out:
      audio_hal_alsa_close_controls();
      result = (val >> 31) & 0x80001001;
      break;
  }
  return result;
}

AUDIO_HAL_STATUS audio_hal_change_channel(audio_hal_channel channel, enum alsactrl_channel_state state)
{
  //return 0;
  signed int tmp; // r6@2
  AUDIO_HAL_STATUS result; // r0@5
  alsactrl_dev_info_t *dev_info; // [sp+Ch] [bp-14h]@2

  /*if ( check_alsa_card_number() < 0 )
  {
    _android_log_print(6, "audio_hwctrl", "%s: ERROR: ALSA-card not found!\n", __func__);
    result = 1;
  }
  else*/
  if (1) {
    tmp = audio_hwctrl_get_dev_info(channel, &dev_info);
    if ( tmp < 0 )
    {
      ALOGE(
        "%s: ERROR: Unable to get device info for device on channel %d (ret_omx = %d)!",
        __func__,
        channel,
        tmp);
      result = 1;
    }
    else
    {
      if (!audio_hal_alsa_get_ignore_defaults())
        audio_hwctrl_channel_state(channel, state);
      change_active_count(dev_info, state);
      result = 0;
    }
  }
  return result;
}

AUDIO_HAL_STATUS audio_hal_open_channel(audio_hal_channel channel)
{
  //return 0;
  return audio_hal_change_channel(channel, 1);
}

AUDIO_HAL_STATUS audio_hal_close_channel(audio_hal_channel channel)
{
  //return 0;
  return audio_hal_change_channel(channel, 0);
}


int fsbitclkActive = 0;
int gIgnoreDefaults = 0;
int gVal2 = 0;

int sub_46F4(int result)
{
  int v1; // r4@1
  unsigned int v2; // r5@4

  v1 = result;
  if ( result )
  {
    v2 = gVal2;
    if ( !gVal2 )
    {
      audio_hal_alsa_set_control(
        "Digital Interface Master Generator Switch",
        gVal2,
        gVal2);
      result = audio_hal_alsa_set_control("Digital Interface Master Generator Switch", v2, 1);
      gVal2 = 1;
    }
  }
  else
  {
    audio_hal_alsa_set_control("Digital Interface Master Generator Switch", 0, 0);
    result = gVal2;
    gVal2 = v1;
  }
  return result;
}

int audio_hal_start_fsbitclk(int value)
{
  int count1; // r6@2
  int count2; // r4@5


  if ( !value )
  {
    count1 = ++fsbitclkActive;
    if ( fsbitclkActive != 1 )
      return value;
    audio_hal_alsa_open_controls("U8500card");
    audio_hal_alsa_set_control("Burst FIFO Interface Mode", value, count1);
    audio_hal_alsa_set_control("Burst FIFO Interface Switch", value, count1);
    audio_hal_alsa_set_control("Burst FIFO Threshold", value, 27);
    audio_hal_alsa_set_control("Burst FIFO Length", value, 192);
    audio_hal_alsa_set_control("Burst FIFO FS Extra Bit-clocks", value, 28);
    audio_hal_alsa_set_control("Burst FIFO Wake Up Delay", value, 112);
    audio_hal_alsa_set_control("Burst FIFO Switch Frame Number", value, value);
    audio_hal_alsa_set_control("Digital Interface 0 FIFO Enable Switch", value, value);
    audio_hal_alsa_set_control("Digital Interface 0 Bit-clock Switch", value, count1);
    if ( !gVal2 )
    {
      audio_hal_alsa_set_control("Digital Interface Master Generator Switch", 0, 0);
      audio_hal_alsa_set_control("Digital Interface Master Generator Switch", 0, count1);
      gVal2 = count1;
    }

    audio_hal_alsa_set_control("IHF and Headset Swap Playback Switch", 0, 0);
    audio_hal_alsa_close_controls();
	return value;
  }
  if ( value == 1 )
  {
    count2 = ++gIgnoreDefaults;
    if ( gIgnoreDefaults == 1 )
    {
      audio_hal_alsa_open_controls("U8500card");
      audio_hal_alsa_set_control("Digital Interface 1 Bit-clock Switch", 0, count2);
      sub_46F4(count2);
      audio_hal_alsa_set_control("IHF and Headset Swap Playback Switch", 0, 0);
      audio_hal_alsa_close_controls();
	  return value;
    }
  }
  return value;
}

int audio_hal_stop_fsbitclk(int value)
{
  int count; // r4@3

  if ( value )
  {
    if ( value == 1 )
    {
      if ( !gIgnoreDefaults )
        return value;
      count = fsbitclkActive;
      --gIgnoreDefaults;
    }
    else
    {
      count = fsbitclkActive;
    }
  }
  else
  {
    if ( !fsbitclkActive )
      return value;
    count = (fsbitclkActive)-- - 1;
  }
  if ( !count )
  {
    value = gIgnoreDefaults;
    if ( !gIgnoreDefaults )
    {
      audio_hal_alsa_open_controls("U8500card");
      audio_hal_alsa_set_control("Digital Interface Master Generator Switch", 0, 0);
      gVal2 = 0;
      audio_hal_alsa_close_controls();
    }
  }
  return value;
}


int change_active_count(audio_hwctrl_dev_info_t *dev_info_p, enum alsactrl_channel_state channel_state)
{
        int ret, valueOld;
        alsactrl_dev_info_t* dev_info_peer_p = Alsactrl_Hwh_GetDevInfo_Peer(dev_info_p);

        valueOld = dev_info_p->active;
        if (channel_state == ALSACTRL_CHANNEL_STATE_OPEN)
                dev_info_p->active++;
        else
                dev_info_p->active--;

        ALOGE("Active count for '%s' changed from %d to %d\n", dev_info_p->name, valueOld, dev_info_p->active);

        if (dev_info_p->alsa_dev == ALSACTRL_ALSA_DEVICE_AB850x || dev_info_p->alsa_dev == ALSACTRL_ALSA_DEVICE_AB8540) {
                ret = alsactrl_set_channel_state(dev_info_p, channel_state, true); // Match peer-device
                if (dev_info_p->active == 0 && dev_info_peer_p->active == 0 && channel_state == ALSACTRL_CHANNEL_STATE_CLOSE && fsbitclkActive) {
                        ALOGE("Calling audio_hal_stop_fsbitclk().\n");
                        audio_hal_stop_fsbitclk(dev_info_p->active);
                }
        } else if (dev_info_p->alsa_dev == ALSACTRL_ALSA_DEVICE_CG29XX)
                ret = alsactrl_set_channel_state(dev_info_p, channel_state, true); // Match peer-device
        else
                ret = alsactrl_set_channel_state(dev_info_p, channel_state, false);

        if (ret < 0)
                dev_info_p->active = valueOld;

        return ret;
}

#if 0
int change_active_count(audio_hwctrl_dev_info_t *dev_info_p, enum alsactrl_channel_state channel_state)
{
  int active; // r3@1
  int active_plus_minus1; // r3@2
  enum alsactrl_alsa_device alsa_dev; // r1@3
  char v6; // r3@9
  int v7; // r4@12
  int res;

  active = dev_info_p->active;
  if ( channel_state == 1 )
  {
    active_plus_minus1 = active + 1;
    dev_info_p->active = active_plus_minus1;
  }
  else
  {
    active_plus_minus1 = active - 1;
    dev_info_p->active = active_plus_minus1;
  }
  alsa_dev = dev_info_p->alsa_dev;
  if ( alsa_dev )
  {
    if ( alsa_dev == 1 )                        // if (dev_info_p->alsa_dev == ALSACTRL_ALSA_DEVICE_AB850x)
    {
      res = alsactrl_set_channel_state( dev_info_p,
                                                (enum alsactrl_channel_state)2,
                                                3);
    }
    else if ( channel_state == 1 )
    {
      if ( !dev_info_p->opened )
        dev_info_p = (audio_hwctrl_dev_info_t *)audio_hwctrl_open_alsa_device(dev_info_p);
    }
    else if ( !active_plus_minus1 )
    {
      dev_info_p = (audio_hwctrl_dev_info_t *)audio_hwctrl_close_alsa_device(dev_info_p);
    }
  }
  else
  {
    alsactrl_set_channel_state(dev_info_p, channel_state, 0);
    res = gDevAB8500Playback.active;
    if ( !gDevAB8500Playback.active )
    {
      v6 = 1 - !!gDevAB8500Capture.active;
      if ( gDevAB8500Capture.active > 1)
        v6 = 0;
      if ( channel_state )
        v7 = 0;
      else
        v7 = v6 & 1;
      if ( v7 && fsbitclkActive )
        res = audio_hal_stop_fsbitclk(gDevAB8500Playback.active);
    }
  }
  return res;
}
#endif

int audio_hwctrl_alsa_get_control(snd_ctl_t *ctl, unsigned int numid, long **values)
{
  size_t elem_info_size1; // r0@1
  int res_tmp; // r8@1
  unsigned int elem_info_count; // r8@2
  snd_ctl_elem_type_t elem_info_type; // r11@2
  size_t elem_info_size; // r0@2
  signed int res; // r5@2
  unsigned int count; // r5@4
  long *v13; // t1@7
  int result; // r0@9
  long **v15; // r10@11
  long *value_ptr; // t1@11
  long elem_value_integer; // r0@11
  unsigned int count1; // r5@11
  long *v19; // t1@12
  long elem_value_integer1; // r0@12
  long **v21; // r10@14
  long *v22; // t1@14
  unsigned int v23; // r0@14
  unsigned int v24; // r5@14
  long *v25; // t1@15
  unsigned int v26; // r0@15
  long **v27; // r10@17
  long *v28; // t1@17
  int v29; // r0@17
  unsigned int v30; // r5@17
  long *v31; // t1@18
  int v32; // r0@18
  const char *fcn2; // r0@20
  const char *fcn; // r0@21
  snd_ctl_elem_info_t elem_info; // [sp+8h] [bp+0h]@1
  snd_ctl_elem_value_t elem_value;

  elem_info_size1 = snd_ctl_elem_info_sizeof();
  memset(&elem_info, 0, elem_info_size1);
  snd_ctl_elem_info_set_numid(&elem_info, numid);
  res_tmp = snd_ctl_elem_info(ctl, &elem_info);
  if ( res_tmp < 0 )
  {
    res = -1;

    ALOGE(
      "%s: ERROR: Unable to get CTL-info for control %d! (ret = %d)",
      __func__,
      numid,
      res_tmp);
  }
  else
  {
    elem_info_count = snd_ctl_elem_info_get_count(&elem_info);
    *values = (long *)malloc(4 * elem_info_count);
    elem_info_type = snd_ctl_elem_info_get_type(&elem_info);

    elem_info_size = snd_ctl_elem_value_sizeof();
    memset(&elem_info, 0, elem_info_size);
    snd_ctl_elem_value_set_numid(&elem_value, numid);
    res = snd_ctl_elem_read(ctl, &elem_value);
    if ( res < 0 )
    {

      ALOGE(
        "%s: ERROR: Unable read CTL-value to control %d! (ret = %d)\n",
        __func__,
        numid,
        res);
    }
    else
    {
      res = elem_info_count;
      if ( elem_info_count )
      {
        count = 0;
        switch ( elem_info_type )
        {
          case 2:
            do
            {
              value_ptr = *values;
              v15 = values + 1;
              elem_value_integer = snd_ctl_elem_value_get_integer(&elem_value, count);
              count1 = count + 1;
              *value_ptr = elem_value_integer;
              if ( count1 == elem_info_count )
                break;
              v19 = *v15;
              values = v15 + 1;
              elem_value_integer1 = snd_ctl_elem_value_get_integer(&elem_value, count1);
              count = count1 + 1;
              *v19 = elem_value_integer1;
            }
            while ( count != elem_info_count );
            break;
          case 3:
            do
            {
              v22 = *values;
              v21 = values + 1;
              v23 = snd_ctl_elem_value_get_enumerated(&elem_value, count);
              v24 = count + 1;
              *v22 = v23;
              if ( v24 == elem_info_count )
                break;
              v25 = *v21;
              values = v21 + 1;
              v26 = snd_ctl_elem_value_get_enumerated(&elem_value, v24);
              count = v24 + 1;
              *v25 = v26;
            }
            while ( count != elem_info_count );
            break;
          case 1:
            do
            {
              v28 = *values;
              v27 = values + 1;
              v29 = snd_ctl_elem_value_get_boolean(&elem_value, count);
              v30 = count + 1;
              *v28 = v29;
              if ( v30 == elem_info_count )
                break;
              v31 = *v27;
              values = v27 + 1;
              v32 = snd_ctl_elem_value_get_boolean(&elem_value, v30);
              count = v30 + 1;
              *v31 = v32;
            }
            while ( count != elem_info_count );
            break;
          default:
            do
            {
              v13 = *values;
              ++values;
              ++count;
              *v13 = -1;
            }
            while ( count != elem_info_count );
            break;
        }
        res = 0;
      }
    }
  }
  result = res;

  return result;
}

int audio_hal_alsa_get_control_values(const char *control_name, long **values)
{
  int result; // r0@4
  const char *fcn1; // r0@7
  unsigned int value; // [sp+4h] [bp-14h]@3
  
  
	if (!gControl || !gElemList)
		ALOGE("%s: audio_hal_alsa_open_controls_cardno=%d", __func__, audio_hal_alsa_open_controls_cardno(-1));
	else
		ALOGE("%s: gControl = %p, gElemList = %p", __func__, gControl, gElemList);

  if ( gControl && gElemList )
  {
    if ( numid_from_name(gElemList, control_name, &value) >= 0 )
      result = audio_hwctrl_alsa_get_control(gControl, value, values);
    else
      result = -1;
  }
  else
  {
    ALOGE("%s: ERROR: Controls not opened!\n", __func__);
    audio_hal_alsa_close_controls();
    result = -1;
  }
  return result;
}

int audio_hal_alsa_open_controls(const char *card_name)
{
  //int card_no; // r0@1

  //card_no = audio_hwctrl_alsa_get_card_idx(card_name);
  return audio_hal_alsa_open_controls_cardno(-1);
}

int hwctrl_free()
{
  int result = 0; // r0@7 MAPDST
  char s[10]; // [sp+4h] [bp-54h]@2

  if ( gCardNo != -1 )
    sprintf(s, "hw:%d");
  gCardInfo = 0;
  if ( gControl )
    snd_ctl_close(gControl);
  gControl = 0;
  if ( gElemList )
  {
    snd_ctl_elem_list_free_space(gElemList);
    snd_ctl_elem_list_free(gElemList);
  }
  gElemList = 0;
  gCardNo = -1;

  return result;
}

void audio_hal_alsa_close_controls()
{
  hwctrl_free();
  pthread_mutex_unlock(&ctl_open_mutex);
}

bool audio_hal_alsa_get_ignore_defaults()
{
  return gIgnoreDefaults;
}

void audio_hal_alsa_set_ignore_defaults(bool ignore)
{
  gIgnoreDefaults = ignore;
}

alsactrl_dev_info_t* Alsactrl_Hwh_GetDevInfo(enum alsactrl_alsa_device alsa_dev, unsigned int stream_dir)
{
	unsigned int i;

	for (i = 0; i < 4; i++)
		if (devs[i].alsa_dev == alsa_dev && devs[i].stream_dir == stream_dir)
			return &devs[i];

	return NULL;
}

alsactrl_dev_info_t* Alsactrl_Hwh_GetDevInfo_Peer(alsactrl_dev_info_t* dev)
{
	unsigned int stream_dir = (dev->stream_dir == PCM_OUT) ? PCM_IN : PCM_OUT;

	return Alsactrl_Hwh_GetDevInfo(dev->alsa_dev, stream_dir);
}

int alsactrl_set_channel_state(alsactrl_dev_info_t* dev, enum alsactrl_channel_state channel_state, bool matchPeer)
{
	int ret;

	alsactrl_dev_info_t* dev_peer = Alsactrl_Hwh_GetDevInfo_Peer(dev);

	if (channel_state == ALSACTRL_CHANNEL_STATE_OPEN) {
		if (!dev->opened) {
			ret = Alsactrl_Hwh_OpenAlsaDev(dev);
			if (ret < 0) {
				ALOGE("ERROR: Failed to open alsa device '%s' (%d)!", dev->name, ret);
				return ret;
			}
		}
		if (matchPeer)
			if (!dev_peer->opened) {
				ret = Alsactrl_Hwh_OpenAlsaDev(dev_peer);
				if (ret < 0) {
					ALOGE("ERROR: Failed to open alsa device '%s' (%d)!", dev_peer->name, ret);
					return ret;
				}
			}
	} else {
		if (matchPeer) {
			if (dev->active == 0 && dev_peer->active == 0) {
				Alsactrl_Hwh_CloseAlsaDev(dev);
				Alsactrl_Hwh_CloseAlsaDev(dev_peer);
			}
		} else {
			if (dev->active == 0)
				Alsactrl_Hwh_CloseAlsaDev(dev);
		}
	}

	return 0;
}

// Private interface

static const char *stream_str(unsigned int stream_dir)
{
	return (stream_dir == PCM_OUT) ? "Playback" : "Capture";
}


// Protected interface

int Alsactrl_Hwh_OpenAlsaDev(alsactrl_dev_info_t* dev_info_p)
{
	int ret, idx_card, idx_dev;
	struct pcm_config config;
	unsigned int flags = 0;
	ALOGE("Enter.\n");

	if (dev_info_p->dev_name == NULL) {
		ALOGE("ERROR: No device-name set for stream (%s)!\n", stream_str(dev_info_p->stream_dir));
		return -1;
	}

	if (dev_info_p->opened) {
		ALOGE("ALSA-device %s already opened!\n", dev_info_p->dev_name);
		return 0;
	}

	ret = audio_hal_alsa_get_card_and_device_idx(dev_info_p->dev_name, dev_info_p->stream_dir, &idx_card, &idx_dev);
	if (ret < 0) {
		ALOGE("ERROR: ALSA-device %s not found among %s-devices!\n",
			dev_info_p->dev_name,
			stream_str(dev_info_p->stream_dir));
		return -1;
	}
	ALOGE("Opening ALSA-device (%s).\n", stream_str(dev_info_p->stream_dir));
	flags = dev_info_p->stream_dir;
	memset(&config, 0, sizeof(struct pcm_config));
	config.channels = dev_info_p->channels;
	config.rate = dev_info_p->rate;
	config.period_size = 1024;
	config.period_count = 4;
	config.format = PCM_FORMAT_S16_LE;

	/* Values to use for the ALSA start, stop and silence thresholds.  Setting
	* any one of these values to 0 will cause the default tinyalsa values to be
	* used instead.  Tinyalsa defaults are as follows.
	*
	* start_threshold   : period_count * period_size
	* stop_threshold    : period_count * period_size
	* silence_threshold : 0
	*/
	config.start_threshold = 0;
	config.stop_threshold = 0;
	config.silence_threshold = 0;
	config.avail_min = 0;
	dev_info_p->pcm = pcm_open(idx_card, idx_dev, flags, &config);
	if (!dev_info_p->pcm || !pcm_is_ready(dev_info_p->pcm)) {
		ALOGE("ERROR: Open ALSA-device (%s) failed (ret = %s)!\n",
			stream_str(dev_info_p->stream_dir), pcm_get_error(dev_info_p->pcm));
		return -1;
	}
	ALOGE("hw_params set.\n");
	dev_info_p->opened = true;
	ret = pcm_prepare(dev_info_p->pcm);
	if (ret < 0) {
		ALOGE("ERROR: PCM Start Failed (ret = %s)!", pcm_get_error(dev_info_p->pcm));
	}
	return 0;
}

void Alsactrl_Hwh_CloseAlsaDev(alsactrl_dev_info_t* dev_info_p)
{
	int ret;

	ALOGE("Enter.\n");

	if (dev_info_p->dev_name == NULL) {
		ALOGE("ERROR: No device-name set for stream (%s)!\n", stream_str(dev_info_p->stream_dir));
		return;
	}

	if (!dev_info_p->opened) {
		ALOGE("ALSA-device %s already closed!\n", dev_info_p->dev_name);
		return;
	}
	ALOGE("Closing ALSA-device %s (%s).\n", dev_info_p->dev_name, stream_str(dev_info_p->stream_dir));
	if (dev_info_p->pcm == NULL) {
		ALOGE("Warning: ALSA-device %s is NULL!\n", dev_info_p->dev_name);
	} else {
		ret = pcm_close(dev_info_p->pcm);
		if (ret < 0) {
			ALOGE("Error: PCM close failed, ret = %s", pcm_get_error(dev_info_p->pcm));
		}
		dev_info_p->pcm = NULL;
	}

	dev_info_p->opened = false;
}

int audio_hal_alsa_get_card_and_device_idx(const char* dev_name, unsigned int stream_dir,
											int* idx_card_p, int* idx_dev_p)
{
	if (stream_dir == PCM_IN) {
		stream_dir = 1;
	}
	int ret, idx_dev, len, idx_card, fd;
	struct snd_pcm_info *pcminfo;
	const char* dev_name_read;
	for (idx_card = 0; idx_card < MAX_SND_CARD_NBR; idx_card++) {
		fd = scan_for_next_card(idx_card, NULL, NULL);
		ALOGE("the value of fd = %d", fd);
		if (fd < 0) {
			continue;
		}
		idx_dev = -1;
		for (;;) {
			ret = scan_for_next_device(fd, &idx_dev);
			ALOGE("Device name detected = %d for card no = %d and fd = %d", idx_dev, idx_card, fd);
			if (ret < 0) {
				ALOGE("Device not found");
				break;
			}
			if (idx_dev == -1)
				break;
			ALOGE("idx_card = %d, Device  = %d found", idx_card, idx_dev);
			pcminfo = (struct snd_pcm_info *)malloc(sizeof(struct snd_pcm_info));
			pcminfo->device = idx_dev;
			pcminfo->subdevice = 0;
			pcminfo->stream = stream_dir;
			ALOGE("fd for the pcm info function : %d", fd);
			ret = get_pcm_info(fd, pcminfo);
			ALOGE("Device = %d, subdevice = %d, Stream = %d, card = %d, id = %s,name = %s,subname = %s,subdevices_count= %d,subdevices_avail = %d", pcminfo->device, pcminfo->subdevice, pcminfo->stream, pcminfo->card, pcminfo->id, pcminfo->name, pcminfo->subname, pcminfo->subdevices_count, pcminfo->subdevices_avail);
			if (ret < 0)
				continue;
			dev_name_read = get_device_id(pcminfo);
			ALOGE("The Device name read = %s dev_name = %s", dev_name_read, dev_name);
			len = strchr(dev_name_read, ' ') - dev_name_read;
			if (strncmp(dev_name, dev_name_read, len) == 0)
				break;
		}
		close(fd);
		if (idx_dev >= 0) {
			*idx_card_p = idx_card;
			*idx_dev_p = idx_dev;
			free(pcminfo);
			return 0;
		}
	}
	ALOGE("device name %s not found", dev_name);
	return -1;
}


AUDIO_HAL_STATUS audio_hal_set_power(uint32 channel_index, AUDIO_HAL_STATE power_control, audio_hal_channel channel)
{
	return AUDIO_HAL_STATUS_OK;
}

AUDIO_HAL_STATE audio_hal_get_power(uint32 channel_index, audio_hal_channel channel)
{
	return AUDIO_HAL_STATE_ON;
}

AUDIO_HAL_STATE audio_hal_get_mute()
{
	return AUDIO_HAL_STATE_ON;
}

AUDIO_HAL_STATUS audio_hal_set_mute()
{
	return AUDIO_HAL_STATUS_OK;
}

AUDIO_HAL_STATUS audio_hal_set_volume()
{
	return AUDIO_HAL_STATUS_OK;
}

AUDIO_HAL_STATE audio_hal_get_volume()
{
        return AUDIO_HAL_STATE_ON;
}

int audio_hal_digital_mute(bool mute)
{
	int ret;

	ALOGI("Enter (mute = %d).\n", (int)mute);

	audio_hal_alsa_open_controls("U8500card");
	ret = audio_hal_alsa_set_control("Digital Interface Mute", 0, (int)!mute);
	audio_hal_alsa_close_controls();

	return ret;
}


int audio_hal_switch_to_burst(unsigned int framecount)
{
	int ret;
	ALOGI("Enter (framecount = %d).\n", framecount);

	audio_hal_alsa_open_controls("U8500card");
	ret = (audio_hal_alsa_set_control("Burst FIFO Switch Frame Number", 0, framecount) != 0) ||
		(audio_hal_alsa_set_control("Digital Interface 0 FIFO Enable Switch", 0, 1) != 0);
	audio_hal_alsa_close_controls();

	return ret;
}

int audio_hal_switch_to_normal(void)
{
	int ret;
	ALOGI("Enter.\n");

	audio_hal_alsa_open_controls("U8500card");
	ret = audio_hal_alsa_set_control("Digital Interface 0 FIFO Enable Switch", 0, 0);
	audio_hal_alsa_close_controls();

	return ret;
}

int audio_hal_set_burst_device(audio_hal_channel channel)
{
	int ret;
	ALOGI("Enter (channel = %d).\n", channel);
	audio_hal_alsa_open_controls("U8500card");
	switch (channel) {
		case AUDIO_HAL_CHANNEL_PDMOUT:
		case AUDIO_HAL_CHANNEL_SPEAKER:
			ret = audio_hal_alsa_set_control("IHF and Headset Swap Playback Switch", 0, 1);
			break;
		case AUDIO_HAL_CHANNEL_HSETOUT:
			ret = audio_hal_alsa_set_control("IHF and Headset Swap Playback Switch", 0, 0);
			break;
		default:
			ret = -1;
			break;
	}
	audio_hal_alsa_close_controls();
	return ret;
}
