# Copyright (C) 2015 The CyanogenMod Project
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

#
# compat symbols for camera HAL
#

LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES := ste_camera.cpp
LOCAL_SHARED_LIBRARIES := libgui libui libutils
LOCAL_MODULE := libcamera_symbols
LOCAL_MODULE_TAGS := optional

include $(BUILD_SHARED_LIBRARY)

#
# compat symbols for cn_server
#

include $(CLEAR_VARS)

LOCAL_SRC_FILES := ucnv_51.c
LOCAL_SHARED_LIBRARIES := libicuuc
LOCAL_MODULE := libicuuc_51
LOCAL_MODULE_TAGS := optional

include $(BUILD_SHARED_LIBRARY)

#
# compat symbols for RIL
#

include $(CLEAR_VARS)

LOCAL_SHARED_LIBRARIES := \
    liblog \
    libutils \
    libbinder \
    libcutils \
    libhardware_legacy \
    librilutils \

LOCAL_STATIC_LIBRARIES := \
    libprotobuf-c-nano-enable_malloc \

ifneq ($(filter xmm6262 xmm6360,$(BOARD_MODEM_TYPE)),)
LOCAL_CFLAGS := -DMODEM_TYPE_XMM6262
endif
ifeq ($(BOARD_MODEM_TYPE),xmm6260)
LOCAL_CFLAGS := -DMODEM_TYPE_XMM6260
endif
ifneq ($(filter m7450 mdm9x35 ss333 xmm7260,$(BOARD_MODEM_TYPE)),)
LOCAL_CFLAGS := -DSAMSUNG_NEXT_GEN_MODEM
endif

ifneq ($(filter m7450 xmm7260,$(BOARD_MODEM_TYPE)),)
LOCAL_CFLAGS += -DNEEDS_VIDEO_CALL_FIELD
endif

LOCAL_C_INCLUDES += $(TARGET_OUT_HEADER)/librilutils
LOCAL_C_INCLUDES += external/nanopb-c


LOCAL_SRC_FILES :=   \
           ste_ril.cpp \
         ril_event.cpp \
       RilSocket.cpp \
       RilSapSocket.cpp 

LOCAL_SHARED_LIBRARIES += libril

LOCAL_MODULE := libste_ril
LOCAL_COPY_HEADERS_TO := libste_ril
LOCAL_COPY_HEADERS := ril_ex.h

LOCAL_MODULE_TAGS := optional

include $(BUILD_SHARED_LIBRARY)

#
# compat symbols for gps
#

include $(CLEAR_VARS)

LOCAL_SRC_FILES := libshim_gps.c
LOCAL_SHARED_LIBRARIES := liblog libcutils libgui libbinder libutils
LOCAL_MODULE := libshim_gps
LOCAL_MODULE_TAGS := optional

include $(BUILD_SHARED_LIBRARY)
