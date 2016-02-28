LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_CFLAGS := -O2 -Wall -Wundef
LOCAL_CFLAGS += -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration
#LOCAL_LDFLAGS := -Wl,--no-gc-sections
LOCAL_SRC_FILES := whetstone.c
LOCAL_MODULE_PATH := $(TARGET_OUT_EXECUTABLES)
LOCAL_MODULE_TAGS := optional
LOCAL_STATIC_LIBRARIES := libc libm
LOCAL_FORCE_STATIC_EXECUTABLE := true
LOCAL_MODULE := whetstone
include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS)

LOCAL_CFLAGS := -O2 -Wall -Wundef
LOCAL_CFLAGS += -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration
#LOCAL_LDFLAGS := -Wl,--no-gc-sections
LOCAL_SRC_FILES := whetstone.c
LOCAL_MODULE_PATH := $(TARGET_OUT_EXECUTABLES)
LOCAL_MODULE_TAGS := optional
LOCAL_STATIC_LIBRARIES := libc_hard libm_hard
LOCAL_FORCE_STATIC_EXECUTABLE := true
LOCAL_MODULE := whetstone_hard
include $(BUILD_EXECUTABLE)

