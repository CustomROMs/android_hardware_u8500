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

COMMON_CFLAGS := \
-D ANDROID \
-D SK_RELEASE \
-D NDEBUG \
-U DEBUG \
-D __STN_8500=30 \
-D __CUT_30 \
-D __STN_4500=30 \
-D LINUX \
-D __ARM_LINUX \
-D __ARM_ANDROID \
-D ENS_DONT_CHECK_STRUCT_SIZE_AND_VERSION \
-D SW_VARIANT_ANDROID \
-D ENS_VERSION=1 \
-D ENS_VERSION_SHARED=1 \
-D ENS_VERSION_VIDEO=2 \
-D ENS_VERSION_AUDIO=3 \
-D ENS_VERSION_IMAGING=4 \
-D CONFIG_SEC \
-D CONFIG_CODINA \
-D TARGET_PRODUCT="GT-I8160" \
-D PRIMARY_S5K4ECGX \
-D SECONDARY_S5KAAFX13 \
-D OSI_DEBUG \
-D __DEBUG \
-D CONFIG_DEBUG \
-D CONFIG_DEBUG_AUTOVAR

#disable for YUV camera
#CPPFLAGS += -DSTAB #disable for YUV camera

ifeq ($(MMIO_ENABLE_NEW_IF),true)
  CPPFLAGS += -DMMIO_ENABLE_NEW_IF
endif

#enable dynamic debug trace
DEBUG=1

#ifdef DEBUG
# dynamic debug: can be enable/disable by setprop command
#CPPFLAGS += -D__DEBUG
#LIBNAME   = st_ext_hsmcamera
#INSTALL_LIB = libst_ext_hsmcamera.a
#else
#CPPFLAGS += -DRELEASE -D__RELEASE
#LIBNAME   = st_ext_hsmcamera
#INSTALL_LIB = libst_ext_hsmcamera.a
#endif

#CAMERA_SET_PRIMARY_SENSOR=MT9P111
# check for aptina sensor
#ifeq (MT9P111,$(filter MT9P111%,$(CAMERA_SET_PRIMARY_SENSOR)))
CPPFLAGS += -DSTE_SENSOR_MT9P111=1
#endif #module configuration aptina sensor

# check for aptina sensor
#ifeq (MT9V113,$(filter  MT9V113%,$(CAMERA_SET_SECONDARY_SENSOR)))
CPPFLAGS += -DSTE_SENSOR_MT9V113=1
#endif #module configuration aptina sensor


MULTIMEDIA_PATH := $(LOCAL_PATH)/../..

LOCAL_C_INCLUDES  += \
	$(MULTIMEDIA_PATH)/shared/utils/include \
	$(MULTIMEDIA_PATH)/shared/host_trace

CPPFLAGS  += -DDBGT_CONFIG_DEBUG -DDBGT_CONFIG_AUTOVAR 
CPPFLAGS  += -DDBGT_TAG=\"ExtCamera\"
LOCAL_SHARED_LIBRARIES := liblog libcutils libstelpcutils


#src/hostnmf_cb.cpp \
ALOCAL_SRC_FILES := \
src/capture_context.cpp \
src/boot_statemachine.cpp \
src/sia_platform_manager/sia_platform_manager.cpp \
src/omxcamera.cpp \
src/grab.cpp \
src/camera_ctrllib.cpp \
src/camera.cpp \
src/grabctl.cpp \
src/hsmcam.cpp \
src/camport.cpp \
src/opmode_transition/preview_statemachine.cpp \
src/opmode_transition/opmodemgr.cpp \
src/opmode_transition/capture_statemachine.cpp \
src/port_statemachine.cpp

LOCAL_C_INCLUDES += \
		$(LOCAL_PATH)/include \
		$(MULTIMEDIA_PATH)/imaging/include \
		$(LOCAL_PATH)/../sia_hw_components_8500/nmf/mpc/nmf_repository/mmdsp_x/ \
		$(LOCAL_PATH)/../ext_sia_hw_components_8500/nmf/mpc/nmf_repository/mmdsp_x/ \
		$(LOCAL_PATH)/../ext_sia_hw_components_8500/nmf/host/nmf_repository/cortexA9-x-android-x/ \
		$(LOCAL_PATH)/../ext_sia_hw_components_8500/nmf/host/nmf_repository/cortexA9-x-android-x/host/ \
		$(LOCAL_PATH)/../../shared/ens_interface/nmf/mpc/nmf_repository/mmdsp_x/ \
		$(LOCAL_PATH)/include/sia_component_manager 

LOCAL_C_INCLUDES += \
		$(MULTIMEDIA_PATH)/shared/omxil \
		$(LOCAL_PATH)/../../imaging/ifm/include/ \
		$(LOCAL_PATH)/../../shared/ens_interface/include/ \
		$(LOCAL_PATH)/../../shared/omxilosalservices_api/ \
		$(LOCAL_PATH)/../../shared/ste_shai/include/ \
		$(LOCAL_PATH)/../../shared/ens/proxy/include \
		$(LOCAL_PATH)/../../shared/ens/common \
		$(LOCAL_PATH)/../../shared/rme/include \
		$(LOCAL_PATH)/../../shared/nmf/linux/api/ \
		$(LOCAL_PATH)/../../shared/mmhwbuffer_api/include \
		$(LOCAL_PATH)/../ext_imgcommon/include/ \
		$(LOCAL_PATH)/../mmio_api/include \
		$(LOCAL_PATH)/../../linux/i2c_lib/include/ \
		$(LOCAL_PATH)/../../linux/mmio/lib/include/ \
		$(LOCAL_PATH)/../flash_api/include/ \
		$(LOCAL_PATH)/../../linux/bellagio_ste_omxloader

# Generation of solibs
IS_OMX_COMPONENT_LIB=true
#include $(MM_MAKEFILES_DIR)/STEOMXLoaderConfig.mk

#LOCAL_SRC_FILES += src/ste_omx_ens_component.cpp
LOCAL_CFLAGS := $(CPPFLAGS) $(COMMON_CFLAGS)
#IMAGE_LIBS = libst_ext_sia_itfs libst_stab
#libst_i2c libst_ifm libst_mmio libhost_trace libcamera_flash

#IMAGING_NMF_HOST_COMPONENTS = libext_img_network

#SOLIBS_ste_ext_camera += $(IMAGING_NMF_HOST_COMPONENTS_LIBS)
LOCAL_STATIC_LIBRARIES := $(IMAGE_LIBS) 
#LOCAL_WHOLE_STATIC_LIBRARIES := libste_ext_camera

LOCAL_SHARED_LIBRARIES += libste_ext_ens_image_common 
LOCAL_SHARED_LIBRARIES += libste_ensloader libtrace libnmfee libdl liblos libnmftimer libsec_ext_camera

LOCAL_PRELINK_MODULE := false
LOCAL_MODULE := libste_ext_camera
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(PRODUCT_OUT)/lib/ste_omxcomponents
include $(BUILD_SHARED_LIBRARY)
