#####################################################
#
#
#  Board Uses New Audio HAL=true
#  Use New Audio HAL implementated in C
#
####################################################

LOCAL_PATH := $(call my-dir)

## Definitions used by several targets. ##
##										##

###################################
# AHI files
#
###################################

MULTIMEDIA_PATH := $(LOCAL_PATH)/../../multimedia

#Location for sourcefiles needed for the ANM, AHI implementation
SRC_FOLDER_AHI := src/ahi
#Location of dbg specific files
SRC_FOLDER_DBG := src

# Source files needed to build Audio Network Manager.
SRC_FILES_ANM := \
	$(SRC_FOLDER_AHI)/ste_anm_ahi.c \
	$(SRC_FOLDER_AHI)/ste_anm_ahi_output.c \
	$(SRC_FOLDER_AHI)/ste_anm_ahi_input.c \
	$(SRC_FOLDER_AHI)/ste_anm_ahi_admbase.c \
	$(SRC_FOLDER_DBG)/ste_anm_dbg.c \
	$(SRC_FOLDER_DBG)/ste_anm_util.c


###################################
# Audio Policy files
#
###################################
#Source folder for Audio Policy Manager
SRC_FOLDER_AP := src/policy

#ste_anm_ap.c
#	$(SRC_FOLDER_AP)/ste_hal_a2dp.c \
#	$(SRC_FOLDER_AP)/ste_hal_usb.c \
#ste_anm_ext_hal.c

#Source filed for Audio Policy Manager
SRC_FILES_AP := \
	$(SRC_FOLDER_DBG)/ste_anm_dbg.c \
	$(SRC_FOLDER_DBG)/ste_anm_util.c \
	legacy/src/policy/ste_anm_ap.cpp

###################################
# Flags
#
###################################

# Common flags
CFLAGS_COMMON_ANM := -DLOG_WARNINGS \
	-DLOG_ERRORS \
        -DSTE_VIDEO_CALL \
	-D_POSIX_SOURCE \
	-DUSE_CACHE_MECHANISM \
	-DALLOW_DUPLICATION

ifeq ($(A2DP_USES_STANDARD_ANDROID_PATH),true)
CFLAGS_COMMON_ANM += -DSTD_A2DP_MNGT
endif


# Headers from external packages.
EXTERNAL_INCLUDES_ANM := \
	$(MULTIMEDIA_PATH)/audio/adm/include \
	$(MULTIMEDIA_PATH)/shared/utils/include \
	hardware/libhardware/include \
	$(call include-path-for, audio-effects)

#######################################################################################################
#
# TARGET SHARED LIBRARY #
#
########################################################################################################


# Generate the audio_policy.PLATFORM shared library used by Audio HAL
include $(CLEAR_VARS)
LOCAL_MODULE := libaudiopolicy_sec
#LOCAL_MODULE_PATH := $(TARGET_OUT_SHARED_LIBRARIES)/hw
LOCAL_MODULE_TAGS := optional

LOCAL_SHARED_LIBRARIES := \
	libcutils \
	libstelpcutils \
	libutils \
	libmedia \
	libdl \
	libc

LOCAL_SRC_FILES := $(SRC_FILES_AP) libaudiopolicy_sec_shim.S

LOCAL_CFLAGS += $(CFLAGS_COMMON_ANM)
ifeq ($(BOARD_HAVE_BLUETOOTH),true)
  LOCAL_CFLAGS += -DWITH_BLUETOOTH -DWITH_A2DP
endif

LOCAL_C_INCLUDES += \
	$(LOCAL_PATH)/include \
	$(EXTERNAL_INCLUDES_ANM)

LOCAL_STATIC_LIBRARIES := \
	libmedia_helper

include $(BUILD_SHARED_LIBRARY)

#
# Build audio.primary.PLATFORM for Audio Hardware
#

include $(CLEAR_VARS)
LOCAL_MODULE := audio.primary.$(TARGET_BOARD_PLATFORM)
LOCAL_MODULE_PATH := $(TARGET_OUT_SHARED_LIBRARIES)/hw
LOCAL_MODULE_TAGS := optional

#Android libraries to link against.
LOCAL_SHARED_LIBRARIES := \
	libste_adm \
	libcutils \
	libstelpcutils \
	libutils \
	libmedia \
	libhardware \
	liblog \
	libasound \
	libdl

LOCAL_SRC_FILES += \
	$(SRC_FILES_ANM)

LOCAL_CFLAGS += \
	$(CFLAGS_COMMON_ANM) \

LOCAL_C_INCLUDES += \
	$(EXTERNAL_INCLUDES_ANM) \
	$(LOCAL_PATH)/include

# Static libraries to link against. We also need
# the ADM client library.
LOCAL_STATIC_LIBRARIES += \
	libmedia_helper

#Build shared lib for host using the above variables
#include $(BUILD_SHARED_LIBRARY)

