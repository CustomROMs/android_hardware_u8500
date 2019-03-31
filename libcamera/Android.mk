##
# Copyright (C) ST-Ericsson SA 2010. All rights reserved.
# This code is ST-Ericsson proprietary and confidential.
# Any use of the code for whatever purpose is subject to
# specific written permission of ST-Ericsson SA.
##
_MULTIMEDIA_PATH := hardware/u8500/multimedia

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_CPPFLAGS += -DLINUX -D__ARM_LINUX -D__ARM_ANDROID -DANDROID
LOCAL_CPPFLAGS += -DENS_DONT_CHECK_STRUCT_SIZE_AND_VERSION

# LOCAL_CFLAGS += -Wno-unused-parameter

# CAMERA_SET_PRIMARY_SENSOR := IMX072

# Camera settings
# Platform 
MY_PLATFORM := u8500
# Enable/Disable ST-Ericsson Camera
USE_CAMERA_STUB := false
# Camera product configuration
STE_CAMERA_ENABLE_FEATURE_PLATFORM := u8500
# Select Camera Sensor
CAMERA_SET_PRIMARY_SENSOR ?= MT9P111
CAMERA_SET_SECONDARY_SENSOR ?= MT9V113
# CAMERA_SET_PRIMARY_SENSOR := MT9P111
# CAMERA_SET_SECONDARY_SENSOR := MT9V113
# Select Camera Sensor Type
CAMERA_PRIMARY_TYPE = YUV
CAMERA_SECONDARY_TYPE = YUV

# Detect platform
include $(LOCAL_PATH)/Android.det

# Compile-time options
include $(LOCAL_PATH)/Android.opt

# Debug options
include $(LOCAL_PATH)/Android.dbg

# Work-arounds
include $(LOCAL_PATH)/Android.wa

# Multimedia includes
MY_MULTIMEDIA_PATH := $(_MULTIMEDIA_PATH)

LOCAL_C_INCLUDES += $(LOCAL_PATH)/include/multimedia/imaging/ifm/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include/multimedia/imaging/aiq_common/inc
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include/multimedia/shared/ens/proxy/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include/multimedia/shared/host_trace

LOCAL_C_INCLUDES += $(MY_MULTIMEDIA_PATH)/shared/ens_interface/include
LOCAL_C_INCLUDES += $(MY_MULTIMEDIA_PATH)/shared/mmhwbuffer_api/include
LOCAL_C_INCLUDES += $(MY_MULTIMEDIA_PATH)/shared/mmhwbuffer_osi/include
LOCAL_C_INCLUDES += $(MY_MULTIMEDIA_PATH)/shared/omxil
LOCAL_C_INCLUDES += $(MY_MULTIMEDIA_PATH)/shared/omxilosalservices_api
LOCAL_C_INCLUDES += $(MY_MULTIMEDIA_PATH)/shared/ste_shai/include
LOCAL_C_INCLUDES += $(MY_MULTIMEDIA_PATH)/linux/bellagio_omxcore/omxcore_interface
LOCAL_C_INCLUDES += $(MY_MULTIMEDIA_PATH)/linux/b2r2lib/include
LOCAL_C_INCLUDES += $(MY_MULTIMEDIA_PATH)/shared/utils/include
LOCAL_C_INCLUDES += $(MY_MULTIMEDIA_PATH)

#Android includes
LOCAL_C_INCLUDES += hardware/u8500/libhead
LOCAL_C_INCLUDES += external/neven/FaceRecEm/common/src/b_FDSDK
LOCAL_C_INCLUDES += frameworks/native/include/media/hardware
LOCAL_C_INCLUDES += system/media/camera/include

#LOCAL_ADDITIONAL_DEPENDENCIES += $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr/
#LOCAL_C_INCLUDES += $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr/include

#internal includes
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include/debug
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include/omx
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include/framerate
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include/perf
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include/queue
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include/memorybase
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include/swroutines
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include/threads
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include/framedumpreplay
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include/focus
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include/semaphore
LOCAL_C_INCLUDES += $(LOCAL_PATH)/ZXImg

LOCAL_SRC_FILES := STECamCompiletimeCheck.cpp
LOCAL_SRC_FILES += STEJpegEnc.cpp
LOCAL_SRC_FILES += STEArmIvProc.cpp
LOCAL_SRC_FILES += STECameraHAL_Module.cpp
LOCAL_SRC_FILES += STECamera.cpp
LOCAL_SRC_FILES += STES5K4ECGX.cpp
LOCAL_SRC_FILES += STEExtIspCamera.cpp
LOCAL_SRC_FILES += STECamDynSetting.cpp
LOCAL_SRC_FILES += STECamFlickerUpdate.cpp
LOCAL_SRC_FILES += STEExifMng.cpp
LOCAL_SRC_FILES += omx/STECamOmxUtils.cpp
LOCAL_SRC_FILES += omx/STECamOmxILExtIndex.cpp
LOCAL_SRC_FILES += omx/STECamOmxReqCbHandler.cpp
LOCAL_SRC_FILES += framerate/STECamFrameRateDumper.cpp
LOCAL_SRC_FILES += framedumpreplay/STECamFrameDumpReplay.cpp
LOCAL_SRC_FILES += framedumpreplay/STECamFrameDumper.cpp
LOCAL_SRC_FILES += framedumpreplay/STECamFrameReplay.cpp
LOCAL_SRC_FILES += perf/DurationTimer.cpp
LOCAL_SRC_FILES += perf/STECamPerfManager.cpp
LOCAL_SRC_FILES += perf/STECamPerfTimer.cpp
LOCAL_SRC_FILES += memorybase/STECamBuffer.cpp
LOCAL_SRC_FILES += memorybase/STECamSwBuffer.cpp
LOCAL_SRC_FILES += memorybase/STECamHwBuffer.cpp
LOCAL_SRC_FILES += memorybase/STECamServiceBuffer.cpp
LOCAL_SRC_FILES += swroutines/STECamSwRoutines.cpp
LOCAL_SRC_FILES += hwconversion/STECamHwConversion.cpp
LOCAL_SRC_FILES += mmhwbuffers/STECamMMHwBuffer.cpp
LOCAL_SRC_FILES += b2r2/STECamB2R2Utils.cpp
LOCAL_SRC_FILES += STECamThumbnailHandler.cpp
LOCAL_SRC_FILES += STECamImageRotHandler.cpp
LOCAL_SRC_FILES += STECamFocusHandler.cpp
LOCAL_SRC_FILES += STECameraDeviceBase.cpp
LOCAL_SRC_FILES += STENativeWindow.cpp
LOCAL_SRC_FILES += STEExtIspMyNative.cpp
LOCAL_SRC_FILES += STEExtIspInternal.cpp
LOCAL_SRC_FILES += NevenFaceDetector.cpp

LOCAL_MODULE_PATH := $(TARGET_OUT_SHARED_LIBRARIES)/hw
# LOCAL_MODULE := camera.$(TARGET_BOARD_PLATFORM)
LOCAL_MODULE := camera.montblanc
LOCAL_MODULE_TAGS := optional
LOCAL_PRELINK_MODULE := false

LOCAL_SHARED_LIBRARIES := \
                         liblog \
                         libdl \
                         libcamera_client \
                         libutils \
                         libcutils \
                         libbinder \
                         libblt_hw \
                         libhead \
                         libui \
                         libFFTEm \
                         libZXImg \
                         libstelpcutils

include $(BUILD_SHARED_LIBRARY)

include $(LOCAL_PATH)/ZXImg/Android.mk
