LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_CFLAGS :=  -DITERATIONS=0 -O3 -mthumb -fstrict-aliasing -funroll-loops
LOCAL_REPORT_FLAGS := true

LOCAL_SRC_FILES := core_list_join.c core_main.c core_matrix.c core_state.c core_util.c core_portme.c 
LOCAL_MODULE_PATH := $(TARGET_OUT_EXECUTABLES)
LOCAL_MODULE_TAGS := optional
LOCAL_SYSTEM_SHARED_LIBRARIES := libc libm libstdc++
LOCAL_MODULE := coremark_thumb

LOCAL_CFLAGS += -DFLAGS_STR="\"\n\TARGET_GLOBAL_CFLAGS=$(TARGET_GLOBAL_CFLAGS)\n\
TARGET_\$\(mode\)_CFLAGS=$(TARGET_thumb_CFLAGS)\n\
LOCAL_CFLAGS=$(LOCAL_CFLAGS)\""

include $(BUILD_EXECUTABLE)


include $(CLEAR_VARS)

LOCAL_CFLAGS := -O3 -marm -fstrict-aliasing -funroll-loops
LOCAL_REPORT_FLAGS := true

LOCAL_SRC_FILES := core_list_join.c core_main.c core_matrix.c core_state.c core_util.c core_portme.c 
LOCAL_MODULE_PATH := $(TARGET_OUT_EXECUTABLES)
LOCAL_MODULE_TAGS := optional
LOCAL_SYSTEM_SHARED_LIBRARIES := libc libm libstdc++
LOCAL_MODULE := coremark_arm

LOCAL_CFLAGS += -DFLAGS_STR="\"\n\TARGET_GLOBAL_CFLAGS=$(TARGET_GLOBAL_CFLAGS) \n\
TARGET_GLOBAL_CPPFLAGS=$(TARGET_GLOBAL_CPPFLAGS) \n\
TARGET_\$\(mode\)_CFLAGS=$(TARGET_thumb_CFLAGS) \n\
LOCAL_CFLAGS=$(LOCAL_CFLAGS)\"" -DITERATIONS=0

include $(BUILD_EXECUTABLE)


