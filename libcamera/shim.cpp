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

#include <hardware/hardware.h>
#include <hardware/camera_common.h>
#include <cutils/log.h>

#include <dlfcn.h>
#include <errno.h>

#include <string.h>

//System includes
#include <semaphore.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <linux/time.h>
#include <unistd.h>
#include <utils/Errors.h>

#undef CAM_LOG_TAG
#define CAM_LOG_TAG DBGT_TAG
#define DBGT_LAYER 0
#define DBGT_PREFIX "Module"

#include "STECamTrace.h"

#include "STECamera.h"
#include "STEExtIspCamera.h"
#include "STECameraDeviceBase.h"

//for property
#include <cutils/properties.h>


static unsigned int gCamerasOpen = 0;
static android::Mutex gCameraHalDeviceLock;

static int camera_device_open(const hw_module_t* module, const char* name,
                              hw_device_t** device);
static int camera_device_close(hw_device_t* device);
static int camera_module_get_number_of_cameras(void);
static int camera_module_get_camera_info(int camera_id, struct camera_info *info);

#if 0
static struct hw_module_methods_t camera_module_methods = {
	.open = camera_device_open
};
#endif

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

#if 0
extern "C" {
	struct camera_module HAL_MODULE_INFO_SYM = {
	    .common = {
	        .tag = HARDWARE_MODULE_TAG,
	        .version_major = 1,
	        .version_minor = 0,
	        .id = CAMERA_HARDWARE_MODULE_ID,
	        .name = "STE CameraHal Module",
	        .author = "STE",
	        .methods = &camera_module_methods,
	    },
	    .get_number_of_cameras = camera_module_get_number_of_cameras,
	    .get_camera_info = camera_module_get_camera_info,
	};
}
#endif

int camera_device_close(hw_device_t* aDevice) {
    DBGT_PROLOG("");
    if(NULL == aDevice) {
        DBGT_CRITICAL("Null Device.....");
        DBGT_EPILOG("");
        return 0;
    }
    android::Mutex::Autolock lock(gCameraHalDeviceLock);
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

/*******************************************************************
 * implementation of camera_module functions
 *******************************************************************/

/* open device handle to one of the cameras
 *
 * assume camera service will keep singleton of each camera
 * so this function will always only be called once per camera instance
 */

int camera_device_open(const hw_module_t* module, const char* name,
                       hw_device_t** device) {
    DBGT_PROLOG("");
    int num_cameras = 0;
    int cameraId;
    android::STECameraDeviceBase* cameraDevice = NULL;
    camera_device_t* camera_device_handle = NULL;


    android::Mutex::Autolock lock(gCameraHalDeviceLock);

    DBGT_PINFO("camera_device open");

    if (name != NULL) {
        cameraId = atoi(name);
        num_cameras = camera_module_get_number_of_cameras();

        if(cameraId > num_cameras) {
            DBGT_CRITICAL("camera service provided cameraId out of bounds, "
                 "cameraid = %d, num supported = %d",
                 cameraId, num_cameras);
            return -EINVAL;
        }

        if(gCamerasOpen >= MAX_SIMUL_CAMERAS_SUPPORTED) {
            DBGT_CRITICAL("maximum number of cameras already open");
            return -ENOMEM;
        }

        if (sCameraInfo[cameraId].facing == CAMERA_FACING_BACK) {
#ifdef PRIMARY_RAW_BAYER
            cameraDevice = new android::STECamera(cameraId);
            DBGT_PINFO("PRIMARY_RAW_BAYER");
#endif
#ifdef PRIMARY_YUV
            cameraDevice = new android::STEExtIspCamera(cameraId);
            DBGT_PINFO("PRIMARY_YUV");
#endif
            if(cameraDevice == NULL) {
                DBGT_CRITICAL("Primary camera could not be instatiated!!");
                return -ENOMEM;
            }
        } else if (sCameraInfo[cameraId].facing == CAMERA_FACING_FRONT) {
#ifdef SECONDARY_RAW_BAYER
            cameraDevice = new android::STECamera(cameraId);
            DBGT_PINFO("SECONDARY_RAW_BAYER");
#endif
#ifdef SECONDARY_YUV
            cameraDevice = new android::STEExtIspCamera(cameraId);
            DBGT_PINFO("SECONDARY_YUV");
#endif
            if(cameraDevice == NULL) {
                DBGT_CRITICAL("Secondary camera could not be instatiated!!");
                return -ENOMEM;
            }

        } else {
            DBGT_CRITICAL("camera_device_open: unknown camera");
            return -EINVAL;
        }
        if (OMX_ErrorNone != cameraDevice->init()) {
            DBGT_CRITICAL("camera_device_open: init failed");
            delete cameraDevice;
            return -EINVAL;
        }
        camera_device_handle = android::STECameraDeviceBase::CreateCameraDevice(cameraDevice);
        if(NULL == camera_device_handle) {
            DBGT_CRITICAL("Couldn't create camera device");
            delete cameraDevice;
            return -ENOMEM;
        }
        camera_device_handle->common.module = (hw_module_t *)(module);
        camera_device_handle->common.close = camera_device_close;
        *device = (hw_device_t*)camera_device_handle;
        gCamerasOpen++;
    }
    DBGT_EPILOG("");
    return 0;
}

int camera_module_get_number_of_cameras(void) {
    DBGT_PROLOG("");
    int num_cameras;

    num_cameras = sizeof(sCameraInfo) / sizeof(sCameraInfo[0]);
    DBGT_EPILOG("");
    return num_cameras;
}

int camera_module_get_camera_info(int camera_id, struct camera_info *info) {
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

    DBGT_PINFO("Camera Orientation: ");
    DBGT_PINFO("  Back camera: %d", back_orientation);
    DBGT_PINFO("  Front camera: %d", front_orientation);

    memcpy(info, &sCameraInfo[camera_id], sizeof(camera_info));
    DBGT_EPILOG("");
    return rv;
}

/* libcamera constructor / destructor */

void libEvtLoading(void) __attribute__((constructor));
void libEvtUnloading(void) __attribute__((destructor));

/* wrapped library handle */

static void *realLibHandle;

/* wrapped symbols */

struct camera_module *shim_HMI = NULL;
//struct (*camera_module) shim_HMI;

/******************************************************************************************************************************/

void libEvtLoading(void)
{

        realLibHandle = dlopen("/system/lib/libcamera_aptina.so", RTLD_LAZY);
        if (!realLibHandle) {
                ALOGE("Failed to load the /system/lib/libcamera_aptina.so: %s\n", dlerror());
                return;
        }

	shim_HMI = (struct camera_module *)dlsym(realLibHandle, "HMI");
	if (!shim_HMI) {
                ALOGE("Failed to find HMI symbol!\n");
		goto out_fail;
	}

	return;

out_fail:
	dlclose(realLibHandle);
}

void libEvtUnloading(void)
{
	if (realLibHandle)
		 dlclose(realLibHandle);
}

extern "C" {
	camera_module_t HAL_MODULE_INFO_SYM __attribute__ ((visibility("default"))) = {
		.common = {
			.tag = HARDWARE_MODULE_TAG,
			.version_major = 1,
			.version_minor = 0,
			.id = CAMERA_HARDWARE_MODULE_ID,
			.name = "STE CameraHal Module",
			.author = "STE",
			.methods = shim_HMI->common.methods,
		},

             .get_number_of_cameras = camera_module_get_number_of_cameras,
             .get_camera_info = shim_HMI->get_camera_info,
        };
}
