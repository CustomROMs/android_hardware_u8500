LOCAL_PATH := $(call my-dir)

#COMMON_FLAGS := -DPRINTOUT -g

include $(CLEAR_VARS)

LOCAL_CFLAGS := $(COMMON_FLAGS) -O2 -Wall -Wundef
LOCAL_CFLAGS += -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration
#LOCAL_LDFLAGS := -Wl,--no-gc-sections
LOCAL_SRC_FILES := whetstone.c
LOCAL_MODULE_PATH := $(TARGET_OUT_EXECUTABLES)
LOCAL_MODULE_TAGS := optional
LOCAL_SYSTEM_SHARED_LIBRARIES := libc libm
LOCAL_MODULE := whetstone
include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS)

LOCAL_CFLAGS := $(COMMON_FLAGS) -O2 -Wall -Wundef
LOCAL_CFLAGS += -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration
#LOCAL_LDFLAGS := -Wl,--no-gc-sections
LOCAL_SRC_FILES := whetstone.c
LOCAL_MODULE_PATH := $(TARGET_OUT_EXECUTABLES)
LOCAL_MODULE_TAGS := optional
LOCAL_SYSTEM_SHARED_LIBRARIES := libc libm
LOCAL_MODULE := whetstone_thumb
include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS)

LOCAL_CFLAGS := $(COMMON_FLAGS) -O2 -Wall -Wundef
LOCAL_CFLAGS += -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration
#LOCAL_LDFLAGS := -Wl,--no-gc-sections
LOCAL_SRC_FILES := whetstone.c
LOCAL_MODULE_PATH := $(TARGET_OUT_EXECUTABLES)
LOCAL_MODULE_TAGS := optional
LOCAL_STATIC_LIBRARIES := libw
LOCAL_SYSTEM_SHARED_LIBRARIES := libc
#LOCAL_FORCE_STATIC_EXECUTABLE := true
LOCAL_MODULE := whetstone_hard
include $(BUILD_EXECUTABLE)


include $(CLEAR_VARS)

LOCAL_CFLAGS := $(COMMON_FLAGS) -O2 -Wall -Wundef 

LOCAL_CFLAGS += -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration
#LOCAL_LDFLAGS := -Wl,-O2
LOCAL_SRC_FILES := whetstone.c
LOCAL_MODULE_PATH := $(TARGET_OUT_EXECUTABLES)
LOCAL_MODULE_TAGS := optional
LOCAL_STATIC_LIBRARIES := libw libc
#LOCAL_SYSTEM_SHARED_LIBRARIES := libc libw
LOCAL_FORCE_STATIC_EXECUTABLE := true
LOCAL_MODULE := whetstone_hard_test
include $(BUILD_EXECUTABLE)


include $(CLEAR_VARS)

LOCAL_CFLAGS := $(COMMON_FLAGS) -O2 -Wall -Wundef

LOCAL_CFLAGS += -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration
LOCAL_LDFLAGS := -Wl,-O2
LOCAL_SRC_FILES := test.c
LOCAL_MODULE_PATH := $(TARGET_OUT_EXECUTABLES)
LOCAL_MODULE_TAGS := optional
#LOCAL_STATIC_LIBRARIES := libw
LOCAL_SYSTEM_SHARED_LIBRARIES := libc libm
#LOCAL_FORCE_STATIC_EXECUTABLE := true
LOCAL_MODULE := test
include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS)

LOCAL_CFLAGS := $(COMMON_FLAGS) -O2 -Wall -Wundef

LOCAL_CFLAGS += -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration
LOCAL_LDFLAGS := -Wl,-O2
LOCAL_SRC_FILES := test.c
LOCAL_MODULE_PATH := $(TARGET_OUT_EXECUTABLES)
LOCAL_MODULE_TAGS := optional
#LOCAL_STATIC_LIBRARIES := libw
LOCAL_SYSTEM_SHARED_LIBRARIES := libc libw
#LOCAL_FORCE_STATIC_EXECUTABLE := true
LOCAL_MODULE := test_hard
include $(BUILD_EXECUTABLE)


include $(CLEAR_VARS)

LOCAL_CFLAGS := $(COMMON_FLAGS) -O2 -Wall -Wundef

LOCAL_CFLAGS += -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -ffast-math -fno-finite-math-only -ftrapping-math -fno-associative-math
LOCAL_LDFLAGS := -Wl,-O2
LOCAL_SRC_FILES := ffast_math_test.c
LOCAL_MODULE_PATH := $(TARGET_OUT_EXECUTABLES)
LOCAL_MODULE_TAGS := optional
#LOCAL_STATIC_LIBRARIES := libm
LOCAL_SYSTEM_SHARED_LIBRARIES := libc libm
#LOCAL_FORCE_STATIC_EXECUTABLE := true
LOCAL_MODULE := ffast_math_test
include $(BUILD_EXECUTABLE)
