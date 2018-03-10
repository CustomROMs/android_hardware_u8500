ifeq ($(strip $(STE_CG29XX_CTRL_ENABLE_FEATURE_STE_CG29XX_CTRL)),true)
LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES := ste-cg29xx_ctrl.c

LOCAL_CFLAGS:= -DANDROID

LOCAL_C_INCLUDES := $(STORAGE_PATH)/parameter_storage/cspsa

LOCAL_SHARED_LIBRARIES := libcspsa

LOCAL_MODULE := ste-cg29xx_ctrl

LOCAL_MODULE_PATH := $(TARGET_OUT_OPTIONAL_EXECUTABLES)

LOCAL_MODULE_TAGS := optional

include $(BUILD_EXECUTABLE)
endif