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

MULTIMEDIA_PATH := hardware/u8500/multimedia

LOCAL_PATH := $(call my-dir)

# HAL module implemenation, not prelinked and stored in
# hw/<OVERLAY_HARDWARE_MODULE_ID>.<ro.product.board>.so
include $(CLEAR_VARS)
LOCAL_PRELINK_MODULE := false
# LOCAL_PROPRIETARY_MODULE := true
LOCAL_MODULE_PATH := $(TARGET_OUT_SHARED_LIBRARIES)/hw
LOCAL_SHARED_LIBRARIES := liblog libcutils libGLESv1_CM libnativewindow

LOCAL_SRC_FILES := hwmem_gralloc.cpp hwmem_gralloc_pmem.cpp hwmem_gralloc_framebuffer.cpp

# LOCAL_HEADER_LIBRARIES := libhardware_headers

LOCAL_C_INCLUDES += $(MULTIMEDIA_PATH)/linux/b2r2lib/include $(MULTIMEDIA_PATH)

LOCAL_STATIC_LIBRARIES        := libgralloc1-adapter
LOCAL_SHARED_LIBRARIES        += libsync

LOCAL_MODULE := gralloc.$(TARGET_BOARD_PLATFORM)
LOCAL_MODULE_TAGS := optional
LOCAL_CFLAGS := -DLOG_TAG=\"gralloc\"

ifeq ($(TARGET_USES_GRALLOC1), true)
LOCAL_CFLAGS += -DADVERTISE_GRALLOC1
endif

include $(BUILD_SHARED_LIBRARY)
