/*
 * Copyright (C) 2012-2013, The CyanogenMod Project
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

/**
* @file CameraWrapper.cpp
*
* This file wraps a vendor camera module.
*
*/


//#include <string.h>
#define DBGT_CONFIG_DEBUG 1
#define DBGT_CONFIG_AUTOVAR 1

//#undef CAM_LOG_TAG
//#define CAM_LOG_TAG DBGT_TAG

#define DBGT_DECLARE_AUTOVAR
#define DBGT_LAYER 0
#define DBGT_PREFIX "DevBas"

#include "STECamTrace.h"
#include <STECameraDeviceBase.h>

#define LOG_NDEBUG 0
#define LOG_PARAMETERS

#define LOG_TAG "CameraWrapper"
#include <cutils/log.h>

#include <utils/threads.h>
#include <utils/String8.h>
#include <hardware/hardware.h>
#include <hardware/camera.h>
//#include <camera/Camera.h>
#include <camera/Camera.h>
//#include <camera/CameraParameters.h>
#include <cutils/properties.h>

// Sony parameter names
static char KEY_SONY_IMAGE_STABILISER_VALUES[] = "sony-is-values";
static char KEY_SONY_IMAGE_STABILISER[] = "sony-is";
static char KEY_SONY_VIDEO_STABILISER[] = "sony-vs";
static char KEY_SONY_VIDEO_HDR[] = "sony-video-hdr";
static char KEY_SONY_ISO_AVAIL_MODES[] = "sony-iso-values";
static char KEY_SONY_ISO_MODE[] = "sony-iso";
static char KEY_SONY_AE_MODE_VALUES[] = "sony-ae-mode-values";
static char KEY_SONY_AE_MODE[] = "sony-ae-mode";

// Sony parameter values
static char VALUE_SONY_ON[] = "on";
static char VALUE_SONY_OFF[] = "off";
static char VALUE_SONY_STILL_HDR[] = "on-still-hdr";


static android::Mutex gCameraWrapperLock;
static android::Mutex gCameraLock;
static camera_module_t *gVendorModule = 0;
static unsigned int gCamerasOpen = 0;
static void * gHandle_addr = NULL;

void * _ZN7android9STECameraC2Ei_real;

static int camera_device_open(const hw_module_t* module, const char* name,
                hw_device_t** device);
static int camera_device_close(hw_device_t* device);
static int camera_get_number_of_cameras(void);
static int camera_get_camera_info(int camera_id, struct camera_info *info);


/* Real functions */
extern int camera_device_open_real(const hw_module_t* module, const char* name,
                              hw_device_t** device);
extern int camera_device_close_real(hw_device_t* device);
extern int camera_module_get_number_of_cameras_real(void);
extern int camera_module_get_camera_info_real(int camera_id, struct camera_info *info);


//#if 0
extern int set_preview_window_real(camera_device_t* aCameraDevice,
                                struct preview_stream_ops* aWindow);
extern void set_callbacks_real(camera_device_t* aCameraDevice,
                            camera_notify_callback notify_cb,
                            camera_data_callback data_cb,
                            camera_data_timestamp_callback data_cb_timestamp,
                            camera_request_memory get_memory,
                            void *user);
extern void enable_msg_type_real(camera_device_t* aCameraDevice, int32_t msg_type);
extern void disable_msg_type_real(camera_device_t* aCameraDevice, int32_t msg_type);
extern int msg_type_enabled_real(camera_device_t* aCameraDevice, int32_t msg_type);
extern int start_preview_real(camera_device_t* aCameraDevice);
extern void stop_preview_real(camera_device_t* aCameraDevice);
extern int preview_enabled_real(camera_device_t* aCameraDevice);
extern int store_meta_data_in_buffers_real(camera_device_t* aCameraDevice, int enable);
extern int start_recording_real(camera_device_t* aCameraDevice);
extern void stop_recording_real(camera_device_t* aCameraDevice);
extern int recording_enabled_real(camera_device_t* aCameraDevice);
extern void release_recording_frame_real(camera_device_t* aCameraDevice,
                                      const void *opaque);
extern int auto_focus_real(camera_device_t* aCameraDevice);
extern int cancel_auto_focus_real(camera_device_t* aCameraDevice);
extern int take_picture_real(camera_device_t* aCameraDevice);
extern int cancel_picture_real(camera_device_t* aCameraDevice);
extern int set_parameters_real(camera_device_t* aCameraDevice, const char *parms);
extern char* get_parameters_real(camera_device_t* aCameraDevice);
extern void put_parameters_real(camera_device_t* aCameraDevice, char* aParam);
extern int send_command_real(camera_device_t* aCameraDevice,
                          int32_t cmd, int32_t arg1, int32_t arg2);
extern void release_real(camera_device_t* aCameraDevice);
extern int dump_real(camera_device_t* aCameraDevice, int fd);
//#endif

#include <string1.h>
/*
 * Copyright (C) ST-Ericsson SA 2010. All rights reserved.
 *
 * Code adapted for usage of OMX components. All functions
 * using OMX functionality are under copyright of ST-Ericsson
 *
 * This code is ST-Ericsson proprietary and confidential.
 * Any use of the code for whatever purpose is subject to
 * specific written permission of ST-Ericsson SA.
 */

//System includes
#include <semaphore.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <linux/time.h>
#include <unistd.h>
#include <utils/Errors.h>

#include "STECamTrace.h"

#include "STECamera.h"
#include "STEExtIspCamera.h"
#include "STECameraDeviceBase.h"

//for property
#include <cutils/properties.h>

int camera_device_open_real(const hw_module_t* module, const char* name,
                              hw_device_t** device);
int camera_device_close_real(hw_device_t* device);
int camera_module_get_number_of_cameras_real(void);
int camera_module_get_camera_info_real(int camera_id, struct camera_info *info);


static camera_info sCameraInfo[] = {
    {
        CAMERA_FACING_BACK, // facing
        90,  // orientation
        0,   // device_version
        0    // static_camera_characteristics
    },
    {
        CAMERA_FACING_FRONT, //facing
        90,  // orientation
        0,   // device_version
        0    // static_camera_characteristics
    }
};

int camera_device_close_real(hw_device_t* aDevice) {
    DBGT_PROLOG("");
    if(NULL == aDevice) {
        ALOGE("Null Device.....");
        DBGT_EPILOG("");
        return 0;
    }
    android::Mutex::Autolock lock(gCameraWrapperLock);
    camera_device_t* camDevice = (camera_device_t*)aDevice;
    android::STECameraDeviceBase* camDeviceBase = (android::STECameraDeviceBase *) camDevice->priv;

    if (NULL != camDeviceBase) {
        // may call steCam->release/deinit() if any required
        camDeviceBase->release();
        delete camDeviceBase;
    }
    if(camDevice->ops) free(camDevice->ops);
    free(camDevice);
    gCamerasOpen--;
    DBGT_EPILOG("");
    return 0;
}

static android::STECameraDeviceBase* getSTECamera(camera_device_t* aCamDevice) {
    //DBGT_PROLOG("");
    if(NULL == aCamDevice) {
        ALOGE("aCamDevice = %d", (int)aCamDevice);
        return NULL;
    }
    //ALOGE("");
    return (android::STECameraDeviceBase *) aCamDevice->priv;
}


int set_preview_window_real(camera_device_t* aCameraDevice,
                                struct preview_stream_ops* aWindow) {
    DBGT_PROLOG("");
    android::STECameraDeviceBase *steCam = getSTECamera(aCameraDevice);
    if (NULL != steCam) {
        int retval = steCam->setPreviewWindow(aWindow);
        ALOGE("retval = %d", retval);
        return retval;
    }
    ALOGE("");
    return -EINVAL;
}

void set_callbacks_real(camera_device_t* aCameraDevice,
                            camera_notify_callback notify_cb,
                            camera_data_callback data_cb,
                            camera_data_timestamp_callback data_cb_timestamp,
                            camera_request_memory get_memory,
                            void *user) {
    DBGT_PROLOG("");
    android::STECameraDeviceBase *steCam = getSTECamera(aCameraDevice);
    if (NULL != steCam) {
        steCam->setCallbacks(notify_cb,
                                     data_cb,
                                     data_cb_timestamp,
                                     get_memory,
                                     user);
    }
    ALOGE("");
}

void enable_msg_type_real(camera_device_t* aCameraDevice, int32_t msg_type) {
    DBGT_PROLOG("");
    android::STECameraDeviceBase *steCam = getSTECamera(aCameraDevice);
    if (NULL != steCam) {
        steCam->enableMsgType(msg_type);
    }
    ALOGE("");
}

void disable_msg_type_real(camera_device_t* aCameraDevice, int32_t msg_type) {
    DBGT_PROLOG("");
    android::STECameraDeviceBase *steCam = getSTECamera(aCameraDevice);
    if (NULL != steCam) {
        steCam->disableMsgType(msg_type);
    }
    ALOGE("");
}

int msg_type_enabled_real(camera_device_t* aCameraDevice, int32_t msg_type) {
    DBGT_PROLOG("");
    android::STECameraDeviceBase *steCam = getSTECamera(aCameraDevice);
    if (NULL != steCam) {
        int retval = steCam->msgTypeEnabled(msg_type);
        ALOGE("retval = %d", retval);
        return retval;
    }
    ALOGE("");
    return -EINVAL;
}

int start_preview_real(camera_device_t* aCameraDevice) {
    DBGT_PROLOG("");
    android::STECameraDeviceBase *steCam = getSTECamera(aCameraDevice);
    if (NULL != steCam) {
        int retval =  steCam->startPreview();
        ALOGE("retval = %d", retval);
        return retval;
    }
    ALOGE("");
    return -EINVAL;
}

void stop_preview_real(camera_device_t* aCameraDevice) {
    DBGT_PROLOG("");
    android::STECameraDeviceBase *steCam = getSTECamera(aCameraDevice);
    if (NULL != steCam) {
        steCam->stopPreview();
    }
    ALOGE("");
}

int preview_enabled_real(camera_device_t* aCameraDevice) {
    DBGT_PROLOG("");
    android::STECameraDeviceBase *steCam = getSTECamera(aCameraDevice);
    if (NULL != steCam) {
        int retval = steCam->previewEnabled();
        ALOGE("retval = %d", retval);
        return retval;
    }
    ALOGE("");
    return -EINVAL;
}

int store_meta_data_in_buffers_real(camera_device_t* aCameraDevice, int enable) {
    DBGT_PROLOG("");
    android::STECameraDeviceBase *steCam = getSTECamera(aCameraDevice);
    if (NULL != steCam) {
        int retval = steCam->storeMetaDataInBuffers(enable);
        ALOGE("retval = %d", retval);
        return retval;
    }
    ALOGE("");
    return -EINVAL;
}

int start_recording_real(camera_device_t* aCameraDevice) {
    DBGT_PROLOG("");
    android::STECameraDeviceBase *steCam = getSTECamera(aCameraDevice);
    if (NULL != steCam) {
        int retval = steCam->startRecording();
        ALOGE("retval = %d", retval);
        return retval;
    }
    ALOGE("");
    return -EINVAL;
}

void stop_recording_real(camera_device_t* aCameraDevice) {
    DBGT_PROLOG("");
    android::STECameraDeviceBase *steCam = getSTECamera(aCameraDevice);
    if (NULL != steCam) {
        steCam->stopRecording();
    }
    ALOGE("");
}

int recording_enabled_real(camera_device_t* aCameraDevice) {
    DBGT_PROLOG("");
    android::STECameraDeviceBase *steCam = getSTECamera(aCameraDevice);
    if (NULL != steCam) {
        int retval = steCam->recordingEnabled();
        ALOGE("retval = %d", retval);
        return retval;
    }
    ALOGE("");
    return -EINVAL;
}

void release_recording_frame_real(camera_device_t* aCameraDevice,
                                      const void *opaque) {
    DBGT_PROLOG("");
    android::STECameraDeviceBase *steCam = getSTECamera(aCameraDevice);
    if (NULL != steCam) {
        steCam->releaseRecordingFrame(opaque);
    }
    ALOGE("");
}

int auto_focus_real(camera_device_t* aCameraDevice) {
    DBGT_PROLOG("");
    android::STECameraDeviceBase *steCam = getSTECamera(aCameraDevice);
    if (NULL != steCam) {
        int retval = steCam->autoFocus();
        ALOGE("retval = %d", retval);
        return retval;
    }
    ALOGE("");
    return -EINVAL;
}

int cancel_auto_focus_real(camera_device_t* aCameraDevice) {
    DBGT_PROLOG("");
    android::STECameraDeviceBase *steCam = getSTECamera(aCameraDevice);
    if (NULL != steCam) {
        int retval = steCam->cancelAutoFocus();
        ALOGE("retval = %d", retval);
        return retval;
    }
    ALOGE("");
    return -EINVAL;
}

int take_picture_real(camera_device_t* aCameraDevice) {
    android::STECameraDeviceBase *steCam = getSTECamera(aCameraDevice);
    if (NULL != steCam) {
        int retval = steCam->takePicture();
        ALOGE("retval = %d", retval);
        return retval;
    }
    ALOGE("");
    return -EINVAL;
}

int cancel_picture_real(camera_device_t* aCameraDevice) {
    DBGT_PROLOG("");
    android::STECameraDeviceBase *steCam = getSTECamera(aCameraDevice);
    if (NULL != steCam) {
        int retval = steCam->cancelPicture();
        ALOGE("retval = %d", retval);
        return retval;
    }
    ALOGE("");
    return -EINVAL;
}

int set_parameters_real(camera_device_t* aCameraDevice, const char *parms) {
    DBGT_PROLOG("");
    android::STECameraDeviceBase *steCam = getSTECamera(aCameraDevice);
    if (NULL != steCam) {
        int retval = steCam->setParameters(parms);
        ALOGE("retval = %d", retval);
        return retval;
    }
    ALOGE("");
    return -EINVAL;
}

char* get_parameters_real(camera_device_t* aCameraDevice) {
    DBGT_PROLOG("");
    android::STECameraDeviceBase *steCam = getSTECamera(aCameraDevice);
    if (NULL != steCam) {
        char *retval = steCam->getParameters();
        ALOGE("");
        return retval;
    }
    ALOGE("");
    return NULL;
}

void put_parameters_real(camera_device_t* aCameraDevice, char* aParam) {
    DBGT_PROLOG("");
    android::STECameraDeviceBase *steCam = getSTECamera(aCameraDevice);
    if (NULL != steCam) {
        steCam->putParameters(aParam);
    }
    ALOGE("");
}

int send_command_real(camera_device_t* aCameraDevice,
                          int32_t cmd, int32_t arg1, int32_t arg2) {
    DBGT_PROLOG("");
    android::STECameraDeviceBase *steCam = getSTECamera(aCameraDevice);
    if (NULL != steCam) {
        int retval = steCam->sendCommand(cmd, arg1, arg2);
        ALOGE("retval = %d", retval);
        return retval;
    }
    ALOGE("");
    return -EINVAL;
}

void release_real(camera_device_t* aCameraDevice) {
    DBGT_PROLOG("");
    android::STECameraDeviceBase *steCam = getSTECamera(aCameraDevice);
    if (NULL != steCam) {
        steCam->release();
    }
    ALOGE("");
}

int dump_real(camera_device_t* aCameraDevice, int fd) {
    DBGT_PROLOG("");
    android::STECameraDeviceBase *steCam = getSTECamera(aCameraDevice);
    if (NULL != steCam) {
        int retval = steCam->dump(fd);
        ALOGE("retval = %d", retval);
        return retval;
    }
    ALOGE("");
    return -EINVAL;
}

static struct hw_module_methods_t camera_module_methods = {
        open: camera_device_open
};

camera_module_t HAL_MODULE_INFO_SYM = {
    common: {
         tag: HARDWARE_MODULE_TAG,
         version_major: 1,
         version_minor: 0,
         id: CAMERA_HARDWARE_MODULE_ID,
         name: "Xperia Camera Wrapper",
         author: "The CyanogenMod Project",
         methods: &camera_module_methods,
         dso: NULL, /* remove compilation warnings */
         reserved: {0}, /* remove compilation warnings */
    },
    get_number_of_cameras: camera_get_number_of_cameras,
    get_camera_info: camera_get_camera_info,
};

typedef struct wrapper_camera_device {
    camera_device_t base;
    int id;
    camera_device_t *vendor;
} wrapper_camera_device_t;

#define VENDOR_CALL(device, func, ...) ({ \
    wrapper_camera_device_t *__wrapper_dev = (wrapper_camera_device_t*) device; \
    ALOGV("%s: vendor function address: 0x%08X", __func__, 0x92000 + (uintptr_t)__wrapper_dev->vendor->ops->func - (uintptr_t)HMI_real); \
    __wrapper_dev->vendor->ops->func(__wrapper_dev->vendor, ##__VA_ARGS__); \
})

#define VENDOR_CALL_REAL(device, func, ...) ({ \
    wrapper_camera_device_t *__wrapper_dev = (wrapper_camera_device_t*) device; \
    ALOGV("%s: vendor function address: 0x%08X", __func__, 0x92000 + (uintptr_t)__wrapper_dev->vendor->ops->func - (uintptr_t)HMI_real); \
    func##_real(__wrapper_dev->vendor, ##__VA_ARGS__); \
})

#define CAMERA_ID(device) (((wrapper_camera_device_t *)(device))->id)

void *HMI_real;

//void check_vendor_module(void) __attribute__((constructor));
__attribute__((constructor)) void* check_vendor_module()
{
    //android::STECameraDeviceBase* cameraDevice = NULL;
    //int rv = 0;
    ALOGV("%s", __FUNCTION__);

    if(gVendorModule)
        return gHandle_addr;

    gHandle_addr = hw_get_module_by_path("/system/lib/libcamera_codina.so", (const hw_module_t **)&gVendorModule);
    if (gHandle_addr) {
	HMI_real = dlsym(gHandle_addr, "HMI");
	//_ZN7android15STEExtIspCameraC2Ei
       _ZN7android9STECameraC2Ei_real = dlsym(gHandle_addr, "_ZN7android9STECameraC2Ei");
    }

    //void *mem = malloc(sizeof(android::STECameraDeviceBase));
    //android::STECameraDeviceBase* cameraDevice = (android::STECameraDeviceBase*)(new (mem) _ZN7android9STECameraC2Ei_real());

    //if (rv)
    //    ALOGE("failed to open vendor camera module");
    return gHandle_addr;
}

#if 0
void camera_fixup_capability(CameraParameters *params)
{
    ALOGV("%s", __FUNCTION__);
    if (params->get(KEY_SONY_IMAGE_STABILISER_VALUES)) {
        const char* supportedIsModes = params->get(KEY_SONY_IMAGE_STABILISER_VALUES);

        if (strstr(supportedIsModes, VALUE_SONY_STILL_HDR) != NULL) {
            char buffer[255];
            const char* supportedSceneModes = params->get(android::CameraParameters::KEY_SUPPORTED_SCENE_MODES);
            sprintf(buffer, "%s,hdr", supportedSceneModes);
            params->set(android::CameraParameters::KEY_SUPPORTED_SCENE_MODES, buffer);
        }
    }
}
#endif

static char * camera_fixup_getparams(int id, const char * settings)
{
#if 0
    android::CameraParameters params;
    params.unflatten(android::String8(settings));

    camera_fixup_capability(&params);
    // fixup the iso mode list with those that are in the sony list
    const char* isoModeList = params.get(KEY_SONY_ISO_AVAIL_MODES);
    char buffer[255];
    sprintf(buffer, "%s,auto", isoModeList);
    params.set(android::CameraParameters::KEY_SUPPORTED_ISO_MODES, buffer);
    if (params.get(KEY_SONY_IMAGE_STABILISER)) {
        const char* sony_is = params.get(KEY_SONY_IMAGE_STABILISER);
        if (strcmp(sony_is, VALUE_SONY_STILL_HDR) == 0) {
            // Scene mode is HDR then (see fixup_setparams)
            params.set(android::CameraParameters::KEY_SCENE_MODE, "hdr");
        }
    }

    android::String8 strParams = params.flatten();
    char *ret = strdup(strParams.string());

    ALOGD("%s: get parameters fixed up", __FUNCTION__);
    return ret;
#endif
    return NULL;
}

char * camera_fixup_setparams(int id, const char * settings)
{
#if 0
    android::CameraParameters params;
    params.unflatten(android::String8(settings));

    char value[3];
    bool isHdr = false;

    // for now we can force the video HDR state via a property, for testing
    property_get("sony.force.hdr", value, NULL);

    if (strcmp(value, "on") == 0){
        isHdr = true;
    }

    if (params.get(android::CameraParameters::KEY_ISO_MODE)) {
        const char* isoMode = params.get(android::CameraParameters::KEY_ISO_MODE);
        if (strcmp(isoMode, "auto") != 0) {
            params.set(KEY_SONY_ISO_MODE, isoMode);
        }
        if (params.get(KEY_SONY_AE_MODE_VALUES)) {
            const char* aeModes = params.get(KEY_SONY_AE_MODE_VALUES);
            if (strcmp(isoMode, "auto") == 0) {
                if (strstr(aeModes, "auto") != NULL) {
                    params.set(KEY_SONY_AE_MODE, "auto");
                }
            } else {
                if (strstr(aeModes, "iso-prio") != NULL) {
                    params.set(KEY_SONY_AE_MODE, "iso-prio");
                }
            }
        }
    }

    if (params.get(android::CameraParameters::KEY_SCENE_MODE)) {
        const char* sceneMode = params.get(android::CameraParameters::KEY_SCENE_MODE);
        if (strcmp(sceneMode, "hdr") == 0) {
            params.set(KEY_SONY_IMAGE_STABILISER, VALUE_SONY_STILL_HDR);
            params.set(android::CameraParameters::KEY_SCENE_MODE, android::CameraParameters::SCENE_MODE_AUTO);
        } else {
            params.set(KEY_SONY_IMAGE_STABILISER, VALUE_SONY_ON);
        }
    }

    if (params.get(android::CameraParameters::KEY_RECORDING_HINT)) {
        if (strcmp(params.get(android::CameraParameters::KEY_RECORDING_HINT), android::CameraParameters::TRUE) == 0) {
            params.set(KEY_SONY_VIDEO_STABILISER, VALUE_SONY_ON);
            params.set(KEY_SONY_IMAGE_STABILISER, VALUE_SONY_OFF);
            params.set(KEY_SONY_VIDEO_HDR, VALUE_SONY_OFF);

            // TODO: Allow setting this from the camera app
            if (isHdr)
                params.set(KEY_SONY_VIDEO_HDR, VALUE_SONY_ON);
        }
    }

    android::String8 strParams = params.flatten();
    char *ret = strdup(strParams.string());

    ALOGD("%s: set parameters fixed up", __FUNCTION__);
    return ret;
#endif
    return NULL;
}

/*******************************************************************
 * implementation of camera_device_ops functions
 *******************************************************************/

int camera_set_preview_window(struct camera_device * device,
        struct preview_stream_ops *window)
{
    ALOGV("%s->%08X->%08X", __FUNCTION__, (uintptr_t)device, (uintptr_t)(((wrapper_camera_device_t*)device)->vendor));

    if(!device)
        return -EINVAL;


    return VENDOR_CALL_REAL(device, set_preview_window, window);
}

void camera_set_callbacks(struct camera_device * device,
        camera_notify_callback notify_cb,
        camera_data_callback data_cb,
        camera_data_timestamp_callback data_cb_timestamp,
        camera_request_memory get_memory,
        void *user)
{
    ALOGV("%s->%08X->%08X", __FUNCTION__, (uintptr_t)device, (uintptr_t)(((wrapper_camera_device_t*)device)->vendor));
    ALOGV("%s", __FUNCTION__);

    if(!device)
        return;

    VENDOR_CALL(device, set_callbacks, notify_cb, data_cb, data_cb_timestamp, get_memory, user);
}

void camera_enable_msg_type(struct camera_device * device, int32_t msg_type)
{
    ALOGV("%s->%08X->%08X", __FUNCTION__, (uintptr_t)device, (uintptr_t)(((wrapper_camera_device_t*)device)->vendor));
    ALOGV("%s", __FUNCTION__);

    if(!device)
        return;

    VENDOR_CALL(device, enable_msg_type, msg_type);
}

void camera_disable_msg_type(struct camera_device * device, int32_t msg_type)
{
    ALOGV("%s->%08X->%08X", __FUNCTION__, (uintptr_t)device, (uintptr_t)(((wrapper_camera_device_t*)device)->vendor));
    ALOGV("%s", __FUNCTION__);

    if(!device)
        return;

    VENDOR_CALL(device, disable_msg_type, msg_type);
}

int camera_msg_type_enabled(struct camera_device * device, int32_t msg_type)
{
    ALOGV("%s", __FUNCTION__);
    ALOGV("%s->%08X->%08X", __FUNCTION__, (uintptr_t)device, (uintptr_t)(((wrapper_camera_device_t*)device)->vendor));

    if(!device)
        return 0;

    return VENDOR_CALL_REAL(device, msg_type_enabled, msg_type);
}

int camera_start_preview(struct camera_device * device)
{
    ALOGV("%s", __FUNCTION__);
    ALOGV("%s->%08X->%08X", __FUNCTION__, (uintptr_t)device, (uintptr_t)(((wrapper_camera_device_t*)device)->vendor));

    if(!device)
        return -EINVAL;

    return VENDOR_CALL_REAL(device, start_preview);
}

void camera_stop_preview(struct camera_device * device)
{
    ALOGV("%s", __FUNCTION__);
    ALOGV("%s->%08X->%08X", __FUNCTION__, (uintptr_t)device, (uintptr_t)(((wrapper_camera_device_t*)device)->vendor));

    if(!device)
        return;

    VENDOR_CALL(device, stop_preview);
}

int camera_preview_enabled(struct camera_device * device)
{
    ALOGV("%s", __FUNCTION__);
    ALOGV("%s->%08X->%08X", __FUNCTION__, (uintptr_t)device, (uintptr_t)(((wrapper_camera_device_t*)device)->vendor));

    if(!device)
        return -EINVAL;

    return VENDOR_CALL_REAL(device, preview_enabled);
}

int camera_store_meta_data_in_buffers(struct camera_device * device, int enable)
{
    ALOGV("%s", __FUNCTION__);
    ALOGV("%s->%08X->%08X", __FUNCTION__, (uintptr_t)device, (uintptr_t)(((wrapper_camera_device_t*)device)->vendor));

    if(!device)
        return -EINVAL;

    return VENDOR_CALL_REAL(device, store_meta_data_in_buffers, enable);
}

int camera_start_recording(struct camera_device * device)
{
    ALOGV("%s", __FUNCTION__);
    ALOGV("%s->%08X->%08X", __FUNCTION__, (uintptr_t)device, (uintptr_t)(((wrapper_camera_device_t*)device)->vendor));

    if(!device)
        return EINVAL;

    return VENDOR_CALL_REAL(device, start_recording);
}

void camera_stop_recording(struct camera_device * device)
{
    ALOGV("%s", __FUNCTION__);
    ALOGV("%s->%08X->%08X", __FUNCTION__, (uintptr_t)device, (uintptr_t)(((wrapper_camera_device_t*)device)->vendor));

    if(!device)
        return;


    VENDOR_CALL_REAL(device, stop_recording);
}

int camera_recording_enabled(struct camera_device * device)
{
    ALOGV("%s", __FUNCTION__);
    ALOGV("%s->%08X->%08X", __FUNCTION__, (uintptr_t)device, (uintptr_t)(((wrapper_camera_device_t*)device)->vendor));

    if(!device)
        return -EINVAL;

    return VENDOR_CALL_REAL(device, recording_enabled);
}

void camera_release_recording_frame(struct camera_device * device,
                const void *opaque)
{
    ALOGV("%s", __FUNCTION__);
    ALOGV("%s->%08X->%08X", __FUNCTION__, (uintptr_t)device, (uintptr_t)(((wrapper_camera_device_t*)device)->vendor));

    if(!device)
        return;

    VENDOR_CALL(device, release_recording_frame, opaque);
}

int camera_auto_focus(struct camera_device * device)
{
    ALOGV("%s", __FUNCTION__);
    ALOGV("%s->%08X->%08X", __FUNCTION__, (uintptr_t)device, (uintptr_t)(((wrapper_camera_device_t*)device)->vendor));

    if(!device)
        return -EINVAL;


    return VENDOR_CALL_REAL(device, auto_focus);
}

int camera_cancel_auto_focus(struct camera_device * device)
{
    ALOGV("%s", __FUNCTION__);
    ALOGV("%s->%08X->%08X", __FUNCTION__, (uintptr_t)device, (uintptr_t)(((wrapper_camera_device_t*)device)->vendor));

    if(!device)
        return -EINVAL;

    return VENDOR_CALL_REAL(device, cancel_auto_focus);
}

int camera_take_picture(struct camera_device * device)
{
    ALOGV("%s", __FUNCTION__);
    ALOGV("%s->%08X->%08X", __FUNCTION__, (uintptr_t)device, (uintptr_t)(((wrapper_camera_device_t*)device)->vendor));

    if(!device)
        return -EINVAL;

    // We safely avoid returning the exact result of VENDOR_CALL_REAL here. If ZSL
    // really bumps fast, take_picture will be called while a picture is already being
    // taken, leading to "picture already running" error, crashing Gallery app. Afaik,
    // there is no issue doing 0 (error appears in logcat anyway if needed).
    VENDOR_CALL_REAL(device, take_picture);

    return 0;
}

int camera_cancel_picture(struct camera_device * device)
{
    ALOGV("%s", __FUNCTION__);
    ALOGV("%s->%08X->%08X", __FUNCTION__, (uintptr_t)device, (uintptr_t)(((wrapper_camera_device_t*)device)->vendor));

    if(!device)
        return -EINVAL;

    return VENDOR_CALL_REAL(device, cancel_picture);
}

int camera_set_parameters(struct camera_device * device, const char *params)
{
    ALOGV("%s", __FUNCTION__);
    ALOGV("%s->%08X->%08X", __FUNCTION__, (uintptr_t)device, (uintptr_t)(((wrapper_camera_device_t*)device)->vendor));

    if(!device)
        return -EINVAL;

#if 0
    char *tmp = NULL;
    tmp = camera_fixup_setparams(CAMERA_ID(device), params);
#ifdef LOG_PARAMETERS
    __android_log_write(ANDROID_LOG_VERBOSE, LOG_TAG, tmp+350);
#endif
#endif

    int ret = VENDOR_CALL_REAL(device, set_parameters, params);
    return ret;
}

char* camera_get_parameters(struct camera_device * device)
{
    ALOGV("%s", __FUNCTION__);
    ALOGV("%s->%08X->%08X", __FUNCTION__, (uintptr_t)device, (uintptr_t)(((wrapper_camera_device_t*)device)->vendor));

    if(!device)
        return NULL;

    char* params = VENDOR_CALL(device, get_parameters);

#ifdef LOG_PARAMETERS
    __android_log_write(ANDROID_LOG_VERBOSE, LOG_TAG, params);
#endif
#if 0
    char * tmp = camera_fixup_getparams(CAMERA_ID(device), params);
#endif
#if 0
    VENDOR_CALL_REAL(device, put_parameters, params);
#endif
#if 0
    params = tmp;

#ifdef LOG_PARAMETERS
    __android_log_write(ANDROID_LOG_VERBOSE, LOG_TAG, params);
#endif
#endif

    return params;
}

static void camera_put_parameters(struct camera_device *device, char *params)
{
    ALOGV("%s", __FUNCTION__);
    ALOGV("%s->%08X->%08X", __FUNCTION__, (uintptr_t)device, (uintptr_t)(((wrapper_camera_device_t*)device)->vendor));

    if(params)
        free(params);
}

int camera_send_command(struct camera_device * device,
            int32_t cmd, int32_t arg1, int32_t arg2)
{
    ALOGV("%s", __FUNCTION__);
    ALOGV("%s->%08X->%08X", __FUNCTION__, (uintptr_t)device, (uintptr_t)(((wrapper_camera_device_t*)device)->vendor));

    if(!device)
        return -EINVAL;

    return VENDOR_CALL_REAL(device, send_command, cmd, arg1, arg2);
}

void camera_release(struct camera_device * device)
{
    ALOGV("%s", __FUNCTION__);
    ALOGV("%s->%08X->%08X", __FUNCTION__, (uintptr_t)device, (uintptr_t)(((wrapper_camera_device_t*)device)->vendor));

    if(!device)
        return;

    VENDOR_CALL(device, release);
}

int camera_dump(struct camera_device * device, int fd)
{
    if(!device)
        return -EINVAL;

    return VENDOR_CALL_REAL(device, dump, fd);
}

extern "C" void heaptracker_free_leaked_memory(void);

int camera_device_close(hw_device_t* device)
{
    int ret = 0;
    wrapper_camera_device_t *wrapper_dev = NULL;

    ALOGV("%s", __FUNCTION__);

    android::Mutex::Autolock lock(gCameraWrapperLock);

    if (!device) {
        ret = -EINVAL;
        goto done;
    }

    wrapper_dev = (wrapper_camera_device_t*) device;

    wrapper_dev->vendor->common.close((hw_device_t*)wrapper_dev->vendor);
    if (wrapper_dev->base.ops)
        free(wrapper_dev->base.ops);
    free(wrapper_dev);
done:
#ifdef HEAPTRACKER
    heaptracker_free_leaked_memory();
#endif
    return ret;
}


namespace android {



STECameraDeviceBase::STECameraDeviceBase () {
}

STECameraDeviceBase::~STECameraDeviceBase () {
}

static STECameraDeviceBase* getSTECameraDevice(camera_device_t* aCamDevice) {
    //DBGT_PROLOG("");
    if(NULL == aCamDevice) {
        ALOGE("aCamDevice = %d", (int)aCamDevice);
        return NULL;
    }
    //ALOGE("");
    return (STECameraDeviceBase *) aCamDevice->priv;
}

camera_device_t* STECameraDeviceBase::CreateCameraDevice(STECameraDeviceBase* aCameraDevice) {

    camera_device_t* camera_device = NULL;
    camera_device_ops_t* camera_ops = NULL;

    DBGT_TRACE_INIT(libcamera);
    DBGT_PROLOG("");
     camera_device = (camera_device_t*)malloc(sizeof(*camera_device));
    if(!camera_device) {
        //LOGE("camera_device allocation fail");
        ALOGE("");
        return NULL;
    }

    camera_ops = (camera_device_ops_t*)malloc(sizeof(*camera_ops));
    if(!camera_ops) {
        //LOGE("camera_ops allocation fail");
        free(camera_device);
        camera_device = NULL;
        ALOGE("");
        return NULL;
    }

    memset(camera_device, 0, sizeof(*camera_device));
    memset(camera_ops, 0, sizeof(*camera_ops));

    camera_device->common.tag = HARDWARE_DEVICE_TAG;
    camera_device->common.version = 0;
    camera_device->ops = camera_ops;
    camera_ops->set_preview_window = camera_set_preview_window;
    camera_ops->set_callbacks = camera_set_callbacks;
    camera_ops->enable_msg_type = camera_enable_msg_type;
    camera_ops->disable_msg_type = camera_disable_msg_type;
    camera_ops->msg_type_enabled = camera_msg_type_enabled;
    camera_ops->start_preview = camera_start_preview;
    camera_ops->stop_preview = camera_stop_preview;
    camera_ops->preview_enabled = camera_preview_enabled;
    camera_ops->store_meta_data_in_buffers = camera_store_meta_data_in_buffers;
    camera_ops->start_recording = camera_start_recording;
    camera_ops->stop_recording = camera_stop_recording;
    camera_ops->recording_enabled = camera_recording_enabled;
    camera_ops->release_recording_frame = camera_release_recording_frame;
    camera_ops->auto_focus = camera_auto_focus;
    camera_ops->cancel_auto_focus = camera_cancel_auto_focus;
    camera_ops->take_picture = camera_take_picture;
    camera_ops->cancel_picture = camera_cancel_picture;
    camera_ops->set_parameters = camera_set_parameters;
    camera_ops->get_parameters = camera_get_parameters;
    camera_ops->put_parameters = camera_put_parameters;
    camera_ops->send_command = camera_send_command;
    camera_ops->release = camera_release;
    camera_ops->dump = camera_dump;

    camera_device->priv = (void*)aCameraDevice;
    DBGT_EPILOG("");
    return camera_device;
}

} // namespace android


/*******************************************************************
 * implementation of camera_module functions
 *******************************************************************/

/* open device handle to one of the cameras
 *
 * assume camera service will keep singleton of each camera
 * so this function will always only be called once per camera instance
 */

int camera_device_open_real(const hw_module_t* module, const char* name,
                       hw_device_t** device) {
    DBGT_PROLOG("");
    int num_cameras = 0;
    int cameraId;
    android::STECameraDeviceBase* cameraDevice = NULL;
    camera_device_t* camera_device_handle = NULL;
    void *mem = NULL;

    android::Mutex::Autolock lock(gCameraLock);

    ALOGE("camera_device open");

    if (name != NULL) {
        cameraId = atoi(name);
        num_cameras = camera_module_get_number_of_cameras_real();

        if(cameraId > num_cameras) {
            ALOGE("camera service provided cameraId out of bounds, "
                 "cameraid = %d, num supported = %d",
                 cameraId, num_cameras);
            return -EINVAL;
        }

        if(gCamerasOpen >= MAX_SIMUL_CAMERAS_SUPPORTED) {
            ALOGE("maximum number of cameras already open");
            return -ENOMEM;
        }

        if (sCameraInfo[cameraId].facing == CAMERA_FACING_BACK) {
	            cameraDevice = new android::STEExtIspCamera(cameraId);
	            ALOGE("PRIMARY_YUV");
            if(cameraDevice == NULL) {
                ALOGE("Primary camera could not be instatiated!!");
                return -ENOMEM;
            }
        } else if (sCameraInfo[cameraId].facing == CAMERA_FACING_FRONT) {
	            cameraDevice = new android::STEExtIspCamera(cameraId);
	            ALOGE("SECONDARY_YUV");
            if(cameraDevice == NULL) {
                ALOGE("Secondary camera could not be instatiated!!");
                return -ENOMEM;
            }

        } else {
            ALOGE("camera_device_open: unknown camera");
            return -EINVAL;
        }
        if (OMX_ErrorNone != cameraDevice->init()) {
            ALOGE("camera_device_open: init failed");
            delete cameraDevice;
            return -EINVAL;
        }
        camera_device_handle = android::STECameraDeviceBase::CreateCameraDevice(cameraDevice);
        if(NULL == camera_device_handle) {
            ALOGE("Couldn't create camera device");
            delete cameraDevice;
            return -ENOMEM;
        }
        camera_device_handle->common.module = (hw_module_t *)(module);
        camera_device_handle->common.close = camera_device_close_real;
        *device = (hw_device_t*)camera_device_handle;
        gCamerasOpen++;
    }
    //DBGT_EPILOG("");
    return 0;
}

int camera_module_get_number_of_cameras_real(void) {
    DBGT_PROLOG("");
    int num_cameras;

    num_cameras = sizeof(sCameraInfo) / sizeof(sCameraInfo[0]);
    DBGT_EPILOG("");
    return num_cameras;
}

int camera_module_get_camera_info_real(int camera_id, struct camera_info *info) {
    DBGT_PROLOG("");
    int rv = 0;

    int front_orientation;  //default value is 90
    int back_orientation;  //default value is 90
    char value[PROPERTY_VALUE_MAX];

    property_get("ste.cam.front.orientation", value, "90");
    front_orientation = atoi(value);
    property_get("ste.cam.back.orientation", value, "90");
    back_orientation = atoi(value);

    sCameraInfo[0].orientation = back_orientation;
    sCameraInfo[1].orientation = front_orientation;

    ALOGE("Camera Orientation: ");
    ALOGE("  Back camera: %d", back_orientation);
    ALOGE("  Front camera: %d", front_orientation);

    memcpy(info, &sCameraInfo[camera_id], sizeof(camera_info));
    DBGT_EPILOG("");
    return rv;
}


/*******************************************************************
 * implementation of camera_module functions
 *******************************************************************/

/* open device handle to one of the cameras
 *
 * assume camera service will keep singleton of each camera
 * so this function will always only be called once per camera instance
 */

int camera_device_open(const hw_module_t* module, const char* name,
                hw_device_t** device)
{
    int rv = 0;
    int num_cameras = 0;
    int cameraid;
    wrapper_camera_device_t* camera_device = NULL;
    camera_device_ops_t* camera_ops = NULL;

    android::Mutex::Autolock lock(gCameraWrapperLock);

    ALOGV("camera_device open");

    if (name != NULL) {
        //gHandle_addr = check_vendor_module();

        cameraid = atoi(name);
        num_cameras = gVendorModule->get_number_of_cameras();

        if(cameraid > num_cameras)
        {
            ALOGE("camera service provided cameraid out of bounds, "
                    "cameraid = %d, num supported = %d",
                    cameraid, num_cameras);
            rv = -EINVAL;
            goto fail;
        }

        camera_device = (wrapper_camera_device_t*)malloc(sizeof(*camera_device));
        if(!camera_device)
        {
            ALOGE("camera_device allocation fail");
            rv = -ENOMEM;
            goto fail;
        }
        memset(camera_device, 0, sizeof(*camera_device));
        camera_device->id = cameraid;

#if 0
        if(rv = camera_device_open_real((const hw_module_t*)gVendorModule, name, (hw_device_t**)&(camera_device->vendor)))
#else
        if(rv = gVendorModule->common.methods->open((const hw_module_t*)gVendorModule, name, (hw_device_t**)&(camera_device->vendor)))
#endif
        {
            ALOGE("vendor camera open fail");
            goto fail;
        }
        ALOGV("%s: got vendor camera device 0x%08X", __FUNCTION__, (uintptr_t)(camera_device->vendor));
        ALOGV("%s: got vendor camera open func: 0x%08X", __FUNCTION__, (uintptr_t)(gVendorModule->common.methods->open));
	ALOGV("%s: got vendor _ZN7android9STECameraC2Ei func: 0x%08X", __FUNCTION__, (uintptr_t)(_ZN7android9STECameraC2Ei_real));

        ALOGV("%s: camera open address =0x%08X",
			 __FUNCTION__, 0x92000 + (uintptr_t)(gVendorModule->common.methods->open) - (uintptr_t)HMI_real );

        //ALOGV("%s: camera open HMI-relative address = hmi address + %d",
	//		 __FUNCTION__, (uintptr_t)(gVendorModule->common.methods->open) - (uintptr_t)HMI_real );
        //ALOGV("%s: camera open _ZN7android9STECameraC2Ei-relative address = _ZN7android9STECameraC2Ei address + %d",
	//		 __FUNCTION__, (uintptr_t)(gVendorModule->common.methods->open) - (uintptr_t)_ZN7android9STECameraC2Ei_real );

        camera_ops = (camera_device_ops_t*)malloc(sizeof(*camera_ops));
        if(!camera_ops)
        {
            ALOGE("camera_ops allocation fail");
            rv = -ENOMEM;
            goto fail;
        }

        memset(camera_ops, 0, sizeof(*camera_ops));

        camera_device->base.common.tag = HARDWARE_DEVICE_TAG;
        camera_device->base.common.version = 0;
        camera_device->base.common.module = (hw_module_t *)(module);
        camera_device->base.common.close = camera_device_close;
        camera_device->base.ops = camera_ops;

        camera_ops->set_preview_window = camera_set_preview_window;
        camera_ops->set_callbacks = camera_set_callbacks;
        camera_ops->enable_msg_type = camera_enable_msg_type;
        camera_ops->disable_msg_type = camera_disable_msg_type;
        camera_ops->msg_type_enabled = camera_msg_type_enabled;
        camera_ops->start_preview = camera_start_preview;
        camera_ops->stop_preview = camera_stop_preview;
        camera_ops->preview_enabled = camera_preview_enabled;
        camera_ops->store_meta_data_in_buffers = camera_store_meta_data_in_buffers;
        camera_ops->start_recording = camera_start_recording;
        camera_ops->stop_recording = camera_stop_recording;
        camera_ops->recording_enabled = camera_recording_enabled;
        camera_ops->release_recording_frame = camera_release_recording_frame;
        camera_ops->auto_focus = camera_auto_focus;
        camera_ops->cancel_auto_focus = camera_cancel_auto_focus;
        camera_ops->take_picture = camera_take_picture;
        camera_ops->cancel_picture = camera_cancel_picture;
        camera_ops->set_parameters = camera_set_parameters;
        camera_ops->get_parameters = camera_get_parameters;
        camera_ops->put_parameters = camera_put_parameters;
        camera_ops->send_command = camera_send_command;
        camera_ops->release = camera_release;
        camera_ops->dump = camera_dump;

        *device = &camera_device->base.common;
    }

    return rv;

fail:
    if(camera_device) {
        free(camera_device);
        camera_device = NULL;
    }
    if(camera_ops) {
        free(camera_ops);
        camera_ops = NULL;
    }
    *device = NULL;
    return rv;
}

int camera_get_number_of_cameras(void)
{
    ALOGV("%s", __FUNCTION__);
    //check_vendor_module();
    //if (check_vendor_module())
    //    return 0;
    return camera_module_get_number_of_cameras_real();
}

int camera_get_camera_info(int camera_id, struct camera_info *info)
{
    ALOGV("%s", __FUNCTION__);
    //check_vendor_module();
    //if (check_vendor_module())
    //    return 0;
    return camera_module_get_camera_info_real(camera_id, info);
}
