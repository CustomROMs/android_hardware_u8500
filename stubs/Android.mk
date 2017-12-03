LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_CFLAGS := -Wall -Wundef
LOCAL_SRC_FILES := cops_stub.S
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE := libcops
include $(BUILD_SHARED_LIBRARY)



include $(CLEAR_VARS)

LOCAL_CFLAGS := -Wall -Wundef
LOCAL_SRC_FILES := ste_adm_stub.S
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE := libste_adm
include $(BUILD_SHARED_LIBRARY)


include $(CLEAR_VARS)

LOCAL_CFLAGS := -Wall -Wundef
LOCAL_SRC_FILES := cn_stub.S
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE := libcn
include $(BUILD_SHARED_LIBRARY)
