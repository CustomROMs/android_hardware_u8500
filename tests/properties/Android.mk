LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := main.c
LOCAL_MODULE_PATH := $(TARGET_OUT_EXECUTABLES)
LOCAL_MODULE_TAGS := optional
LOCAL_SHARED_LIBRARIES := libcutils
LOCAL_C_INCLUDES := $(TOP)/system/core/include
LOCAL_MODULE := properties_test

LOCAL_CFLAGS +=  -std=gnu99

LOCAL_REPORT_FLAGS := true
include $(BUILD_EXECUTABLE)
