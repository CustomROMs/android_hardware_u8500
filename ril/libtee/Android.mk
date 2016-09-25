# Copyright (c) ST-Ericsson AB 2009-2010
#
# Author: Manish Sharma <manish.sharma@stericsson.com>
#

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LIBTEE_LIBPATH := $(LOCAL_PATH)/pre_built
LOCAL_PATH := $(LIBTEE_LIBPATH)
LOCAL_MODULE_TAGS := optional
LOCAL_PREBUILT_LIBS := libtee.so 
include $(BUILD_MULTI_PREBUILT)
