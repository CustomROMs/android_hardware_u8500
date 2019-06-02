# Copyright (C) 2011 The Android Open Source Project
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

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := asoundplay
LOCAL_MODULE_TAGS := optional

LOCAL_SRC_FILES := sound_playback.c

LOCAL_C_INCLUDES += hardware/u8500/audio/libasound/include
LOCAL_C_INCLUDES += hardware/u8500/audio/libasound/src
LOCAL_CFLAGS := -D_POSIX_SOURCE

LOCAL_SHARED_LIBRARIES := libasound

include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS)

LOCAL_MODULE := libtinyasound
LOCAL_MODULE_TAGS := optional

LOCAL_SRC_FILES := tinyasound.c

LOCAL_C_INCLUDES += hardware/u8500/audio/libasound/include
LOCAL_CFLAGS := -D_POSIX_SOURCE

LOCAL_SHARED_LIBRARIES := libasound

include $(BUILD_SHARED_LIBRARY)

#int setup_params(void)
