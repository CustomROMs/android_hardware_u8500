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

LOCAL_CFLAGS += -DENS_VERSION=1 -DENS_VERSION_SHARED=1 -DENS_VERSION_VIDEO=2 -DENS_VERSION_AUDIO=3 -DENS_VERSION_IMAGING=4

# Since the generic Make.config add the NMF and medium includes to CPPFLAGS
# and we don't want those, make sure we include omxil headers first as 
# we want to be able to be able to compile rme while having the ens installed

LOCAL_C_INCLUDES += $(LOCAL_PATH)/../include $(LOCAL_PATH)/../../omxil $(LOCAL_PATH)/../../../ \
 $(LOCAL_PATH)/../../omxilosalservices_api/ \
        $(LOCAL_PATH)/../../ens_interface/include/ \
        $(LOCAL_PATH)/../../nmf/linux/api \
        $(LOCAL_PATH)/../../ens_interface/nmf/mpc/nmf_repository/mmdsp_x \
        $(LOCAL_PATH)/../../host_trace \
        $(LOCAL_PATH)/../../utils/include/ \
        $(LOCAL_PATH)/../../mmhwbuffer_api/include/ \
        $(LOCAL_PATH)/../../osttrace/include/

#VPATH+= ../include


LOCAL_SRC_FILES := \
 RMEimpl.cpp \
 ORPComp.cpp \
 ORPCompHalfline.cpp \
 ORPCompNetwork.cpp \
 ResManager.cpp \
 ResLevels.cpp \
 ResEstimator.cpp \
 ResAlp.cpp \
 PfRoles.cpp \
 PfDomManager.cpp \
 NmfDomains.cpp \
 AGov.cpp

#CPPFLAGS += -DNODEFAULTDOMAIN
LOCAL_CFLAGS += -DNOCREATEDOMAINFORCLIENT

#TEMPORARY definition of SW_VARIANT_ANDROID => shall come from upper layers
#ifeq ($(MMSYSTEM),android)
LOCAL_CFLAGS += -DSW_VARIANT_ANDROID
#endif
#ifeq ($(SW_VARIANT),android)
#CPPFLAGS += -DSW_VARIANT_ANDROID
#endif

LOCAL_MODULE  = libst_rme
LOCAL_MODULE_TAGS := optional
include $(BUILD_STATIC_LIBRARY)

