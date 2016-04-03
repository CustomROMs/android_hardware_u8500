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

             .get_number_of_cameras = shim_HMI->get_number_of_cameras,
             .get_camera_info = shim_HMI->get_camera_info,
        };
}
