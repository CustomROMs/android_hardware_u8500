#######################################################################################
#  (c) ST-Ericsson, 2010 - All rights reserved
#  Reproduction and Communication of this document is strictly prohibited
#  unless specifically authorized in writing by ST-Ericsson
#
#  \brief   Android makefile for STE Video Renderer to be used by Stagefright framework
#  \author  ST-Ericsson
#######################################################################################

LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

ifeq ($(BUILD_WITHOUT_PV),true)
LOCAL_SRC_FILES = \
    STECodecsPlugin.cpp
endif


LOCAL_SHARED_LIBRARIES:= \
	libutils \
	libbinder \
	libui \
	libcutils \
	libstagefright \
	libstagefright_foundation \
	libsurfaceflinger \
	libdl

LOCAL_SHARED_LIBRARIES += libui
LOCAL_SHARED_LIBRARIES += liblog libcutils libstelpcutils
LOCAL_CFLAGS += -DBOARD_USES_OVERLAY=1
LOCAL_CFLAGS += -DDBGT_CONFIG_DEBUG -DDBGT_CONFIG_AUTOVAR -DLOG_TAG=\"libstagefrighthw\"

_MULTIMEDIA_PATH := $(LOCAL_PATH)/../../multimedia

LOCAL_C_INCLUDES += \
	$(TOP)/frameworks/native/include/media/hardware \
	$(TOP)/frameworks/av/include/media/stagefright/foundation \
	$(_MULTIMEDIA_PATH)/shared/mmhwbuffer_api/include \
	$(_MULTIMEDIA_PATH)/shared/mmhwbuffer_osi/include \
	$(_MULTIMEDIA_PATH)/shared/omxil \
	$(_MULTIMEDIA_PATH)/linux/bellagio_omxcore/omxcore_interface \
	$(_MULTIMEDIA_PATH)/shared/mmhwbuffer_osi \
	$(_MULTIMEDIA_PATH)/audio/audiolibs

LOCAL_C_INCLUDES += $(_MULTIMEDIA_PATH)/shared/utils/include
LOCAL_C_INCLUDES += $(_MULTIMEDIA_PATH)/shared/host_trace

LOCAL_MODULE:= libstagefrighthw
LOCAL_MODULE_TAGS := optional

LOCAL_PRELINK_MODULE := false

include $(BUILD_SHARED_LIBRARY)

include $(call all-makefiles-under,$(LOCAL_PATH))
