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

LOCAL_CFLAGS += -DENS_VERSION=1 -DENS_VERSION_SHARED=1 -DENS_VERSION_VIDEO=2 -DENS_VERSION_AUDIO=3 -DENS_VERSION_IMAGING=4#

## Use the STD OMX headers
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../omxil $(LOCAL_PATH)/../omxilosalservices_api \
 $(LOCAL_PATH)/../nmf/linux/api/ \
 $(LOCAL_PATH)/../utils/include

#ifeq ($(MMCOMPILER),android)
  LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../bass_app/include
  LOCAL_CFLAGS+= -DDBGT_PREFIX=\"OSAL\" -DDBGT_CONFIG_DEBUG -DDBGT_CONFIG_AUTOVAR -DDBGT_TAG=\"omxilosal\"
#endif

#ifeq ($(MMENV_SYSTEM),linux)
  LOCAL_CFLAGS+= -DDBGT_PREFIX=\"OSAL\" -DDBGT_CONFIG_DEBUG -DDBGT_CONFIG_AUTOVAR -DDBGT_TAG=\"omxilosal\"
  #LOCAL_C_INCLUDES += -I$(ANDROID_BSP_ROOT)/system/core/include
#endif

LOCAL_SRC_FILES = omxilosalmutex.cpp \
	omxilosaltimerimpl.cpp \
	omxilosaldatetime.cpp \
	omxilosalprm.cpp \
	omxilosalproductid.cpp \
	omxilosalproperty.cpp

LOCAL_MODULE        = libst_omxilosalservices
LOCAL_MODULE_TAGS := optional
include $(BUILD_STATIC_LIBRARY)

