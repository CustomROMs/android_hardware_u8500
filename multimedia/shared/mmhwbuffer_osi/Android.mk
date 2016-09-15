# Copyright (C) 2008 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

## Get the OMX headers directly from omxil and not from the ENS ones
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../omxil \
 $(LOCAL_PATH)/../utils/include/ \
 $(LOCAL_PATH)/include/ \
 $(LOCAL_PATH)/../mmhwbuffer_api/include \
 $(LOCAL_PATH)/../omxilosalservices_api \
 $(LOCAL_PATH)/../../ \
 $(LOCAL_PATH)/../../../display/libgralloc

LOCAL_CFLAGS += -DENS_VERSION=1 -DENS_VERSION_SHARED=1 -DENS_VERSION_VIDEO=2 -DENS_VERSION_AUDIO=3 -DENS_VERSION_IMAGING=4
LOCAL_SRC_FILES       = src/MMHwBufferLinux.cpp \
               src/MMHwBufferPool.cpp \
               src/MMHwBufferList.cpp \
               src/MMNativeBuffer.cpp \
               src/mmhwbuffer_c_wrapper.cpp

LOCAL_MODULE  = libst_mmhwbuffer

#ifeq ($(MYMMSYSTEM),android)
#CPPFLAGS += -I$(ANDROID_BUILD_TOP)/frameworks/base/include \
#            -I$(ANDROID_BUILD_TOP)/frameworks/native/include \
#            -I$(ANDROID_BUILD_TOP)/frameworks/native/include/media/hardware \
#            -I$(ANDROID_BUILD_TOP)/hardware/libhardware/include \
#            -I$(GRALLOC_PATH)
#endif # MYMMSYSTEM = android
#INSTALL_HEADER = mmhwbuffer_ext.h MMNativeBuffer.h
LOCAL_MODULE_TAGS := optional
include $(BUILD_STATIC_LIBRARY)
