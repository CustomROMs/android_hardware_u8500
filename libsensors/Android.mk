ifeq ($(BOARD_USES_STE_HARDWARE),true)
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := sensors.default
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_RELATIVE_PATH := hw
LOCAL_SHARED_LIBRARIES := liblog libcutils
LOCAL_CLANG := false
LOCAL_CFLAGS := -DTAG="Sensors" -DSKIP_CXXRTOMB
LOCAL_SRC_FILES := sensors.c

include $(BUILD_SHARED_LIBRARY)
endif
