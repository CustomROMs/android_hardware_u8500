# Copyright (C) 2008 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

LOCAL_PATH:= $(call my-dir)

COMMON_CFLAGS := \
-D ANDROID \
-D SK_RELEASE \
-D NDEBUG \
-D __STN_8500=30 \
-D __CUT_30 \
-D __STN_4500=30 \
-D LINUX \
-D __ARM_LINUX \
-D __ARM_ANDROID \
-D ENS_DONT_CHECK_STRUCT_SIZE_AND_VERSION \
-D SW_VARIANT_ANDROID \
-D ENS_VERSION=1 \
-D ENS_VERSION_SHARED=1 \
-D ENS_VERSION_VIDEO=2 \
-D ENS_VERSION_AUDIO=3 \
-D ENS_VERSION_IMAGING=4


include $(CLEAR_VARS)
LOCAL_C_INCLUDES += $(LOCAL_PATH)
LOCAL_PRELINK_MODULE := false
LOCAL_MODULE_PATH := $(PRODUCT_OUT)/lib
LOCAL_SRC_FILES := \
    trace.c

LOCAL_CFLAGS += $(COMMON_CFLAGS)
LOCAL_MODULE := libtrace
LOCAL_MODULE_TAGS := optional
include $(BUILD_STATIC_LIBRARY)


include $(CLEAR_VARS)
LOCAL_C_INCLUDES += $(LOCAL_PATH)
LOCAL_PRELINK_MODULE := false
LOCAL_WHOLE_STATIC_LIBRARIES := libtrace
LOCAL_SHARED_LIBRARIES := liblog libcutils libdl
LOCAL_MODULE_PATH := $(PRODUCT_OUT)/lib

LOCAL_MODULE := libtrace
LOCAL_CFLAGS += $(COMMON_CFLAGS)
LOCAL_MODULE_TAGS := optional
include $(BUILD_SHARED_LIBRARY)
