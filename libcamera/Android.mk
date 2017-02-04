##
# Copyright (C) ST-Ericsson SA 2010. All rights reserved.
# This code is ST-Ericsson proprietary and confidential.
# Any use of the code for whatever purpose is subject to
# specific written permission of ST-Ericsson SA.
##

LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

#Detect platform
include $(LOCAL_PATH)/internal.det

#Compile-time options
include $(LOCAL_PATH)/internal.opt

#Debug options
include $(LOCAL_PATH)/internal.dbg

#Work-arounds
include $(LOCAL_PATH)/internal.wa

#Multimedia includes
MULTIMEDIA_PATH := $(LOCAL_PATH)/../multimedia
MY_MULTIMEDIA_PATH := $(MULTIMEDIA_PATH)
LOCAL_C_INCLUDES += $(MY_MULTIMEDIA_PATH)/imaging/ifm/include
LOCAL_C_INCLUDES += $(MY_MULTIMEDIA_PATH)/imaging/aiq_common/inc
LOCAL_C_INCLUDES += $(MY_MULTIMEDIA_PATH)/shared/ens/proxy/include
LOCAL_C_INCLUDES += $(MY_MULTIMEDIA_PATH)/shared/ens_interface/include
LOCAL_C_INCLUDES += $(MY_MULTIMEDIA_PATH)/shared/mmhwbuffer_api/include
LOCAL_C_INCLUDES += $(MY_MULTIMEDIA_PATH)/shared/mmhwbuffer_osi/include
LOCAL_C_INCLUDES += $(MY_MULTIMEDIA_PATH)/shared/omxil
LOCAL_C_INCLUDES += $(MY_MULTIMEDIA_PATH)/shared/omxilosalservices_api
LOCAL_C_INCLUDES += $(MY_MULTIMEDIA_PATH)/shared/ste_shai/include
LOCAL_C_INCLUDES += $(MY_MULTIMEDIA_PATH)/linux/bellagio_omxcore/omxcore_interface
LOCAL_C_INCLUDES += $(MY_MULTIMEDIA_PATH)/linux/b2r2lib/include
LOCAL_C_INCLUDES += $(MY_MULTIMEDIA_PATH)/shared/host_trace
LOCAL_C_INCLUDES += $(MY_MULTIMEDIA_PATH)/shared/utils/include

LOCAL_C_INCLUDES += bionic/libc/include/

#Android includes
LOCAL_C_INCLUDES += external/jhead
LOCAL_C_INCLUDES += external/neven/FaceRecEm/common/src/b_FDSDK
LOCAL_C_INCLUDES += frameworks/native/include/media/hardware

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

LOCAL_CAMERA_SRC_FILES := STECamCompiletimeCheck.cpp
LOCAL_CAMERA_SRC_FILES += STEJpegEnc.cpp
LOCAL_CAMERA_SRC_FILES += STEArmIvProc.cpp
#LOCAL_CAMERA_SRC_FILES += STECameraHAL_Module.cpp
LOCAL_CAMERA_SRC_FILES += STECamera.cpp
LOCAL_CAMERA_SRC_FILES += STES5K4ECGX.cpp
LOCAL_CAMERA_SRC_FILES += STEExtIspCamera.cpp
LOCAL_CAMERA_SRC_FILES += STECamDynSetting.cpp
LOCAL_CAMERA_SRC_FILES += STECamFlickerUpdate.cpp
LOCAL_CAMERA_SRC_FILES += STEExifMng.cpp
LOCAL_CAMERA_SRC_FILES += omx/STECamOmxUtils.cpp
LOCAL_CAMERA_SRC_FILES += omx/STECamOmxILExtIndex.cpp
LOCAL_CAMERA_SRC_FILES += omx/STECamOmxReqCbHandler.cpp
LOCAL_CAMERA_SRC_FILES += framerate/STECamFrameRateDumper.cpp
LOCAL_CAMERA_SRC_FILES += framedumpreplay/STECamFrameDumpReplay.cpp
LOCAL_CAMERA_SRC_FILES += framedumpreplay/STECamFrameDumper.cpp
LOCAL_CAMERA_SRC_FILES += framedumpreplay/STECamFrameReplay.cpp
LOCAL_CAMERA_SRC_FILES += perf/STECamPerfManager.cpp
LOCAL_CAMERA_SRC_FILES += perf/STECamPerfTimer.cpp
LOCAL_CAMERA_SRC_FILES += memorybase/STECamBuffer.cpp
LOCAL_CAMERA_SRC_FILES += memorybase/STECamSwBuffer.cpp
LOCAL_CAMERA_SRC_FILES += memorybase/STECamHwBuffer.cpp
LOCAL_CAMERA_SRC_FILES += memorybase/STECamServiceBuffer.cpp
LOCAL_CAMERA_SRC_FILES += swroutines/STECamSwRoutines.cpp
LOCAL_CAMERA_SRC_FILES += hwconversion/STECamHwConversion.cpp
LOCAL_CAMERA_SRC_FILES += mmhwbuffers/STECamMMHwBuffer.cpp
LOCAL_CAMERA_SRC_FILES += b2r2/STECamB2R2Utils.cpp
LOCAL_CAMERA_SRC_FILES += STECamThumbnailHandler.cpp
LOCAL_CAMERA_SRC_FILES += STECamImageRotHandler.cpp
LOCAL_CAMERA_SRC_FILES += STECamFocusHandler.cpp
LOCAL_CAMERA_SRC_FILES += STECameraDeviceBase.cpp
LOCAL_CAMERA_SRC_FILES += STENativeWindow.cpp
LOCAL_CAMERA_SRC_FILES += STEExtIspMyNative.cpp
LOCAL_CAMERA_SRC_FILES += STEExtIspInternal.cpp
LOCAL_CAMERA_SRC_FILES += NevenFaceDetector.cpp

LOCAL_SRC_FILES := $(LOCAL_CAMERA_SRC_FILES)

LOCAL_SRC_FILES += \
    CameraWrapper.cpp

#LOCAL_CFLAGS += -Wno-error=tautological-pointer-compare
LOCAL_MODULE_PATH := $(TARGET_OUT_SHARED_LIBRARIES)/hw
LOCAL_MODULE := camera.$(TARGET_BOARD_PLATFORM)
LOCAL_MODULE_TAGS := optional
LOCAL_PRELINK_MODULE := false
LOCAL_CLANG := false

LOCAL_SHARED_LIBRARIES := \
			 libhardware \
			 liblog \
                         libdl \
                         libbinder \
                         libcamera_client \
                         libutils \
                         libcutils \
                         libblt_hw \
                         libhead \
                         libui \
                         libFFTEm \
                         libstelpcutils

include $(BUILD_SHARED_LIBRARY)
