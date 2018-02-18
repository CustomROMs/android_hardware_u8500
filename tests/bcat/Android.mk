LOCAL_PATH := $(call my-dir)

#COMMON_FLAGS := -DPRINTOUT -g

include $(CLEAR_VARS)

LOCAL_CFLAGS := $(COMMON_FLAGS) -O2 -Wall -Wundef
LOCAL_CFLAGS += -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration
#LOCAL_LDFLAGS := -Wl,--no-gc-sections
LOCAL_SRC_FILES := main.c
LOCAL_MODULE_PATH := $(TARGET_OUT_EXECUTABLES)
LOCAL_MODULE_TAGS := optional
LOCAL_SYSTEM_SHARED_LIBRARIES := libc
LOCAL_MODULE := bcat
include $(BUILD_EXECUTABLE)
