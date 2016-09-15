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

include $(CLEAR_VARS)

LOCAL_C_INCLUDES := $(LOCAL_PATH)/inc $(LOCAL_PATH)/../utils/include $(LOCAL_PATH)/../ens_interface/include/omxil/ \
   $(LOCAL_PATH)/../ens_interface/nmf/mpc/nmf_repository/mmdsp_x \
   $(LOCAL_PATH)/../nmf/linux/api/ \
   $(LOCAL_PATH)/../ens_interface/include \
   $(LOCAL_PATH)/../rme/include \
   $(LOCAL_PATH)/../osttrace/include \
   $(LOCAL_PATH)/../mmhwbuffer_osi/include

# We are still using the RME Get_DefaultDDRDomain deprecated api
LOCAL_CFLAGS += -DDEPRECATED_API
LOCAL_SRC_FILES := \
        src/ENS_Wrapper.cpp \
        src/ENS_Wrapper_Init.cpp \
        src/ENS_Wrapper_NMF.cpp \
        src/ENS_Wrapper_OMX_UserCB.cpp \
        src/ENS_Queue.cpp \
        src/ENS_Wrapper_Services.cpp \
        src/ENS_HwRm.cpp \
        src/ENS_RME_Wrapper.cpp \
        src/ENS_Wrapper_OSTtrace.cpp \
        src/ENS_Wrapper_Construct.cpp \
        src/ENS_Wrapper_CtxTrace.cpp \
        src/ENS_Wrapper_DataDump.cpp \
        src/ENS_Wrapper_Dump.cpp

LOCAL_C_INCLUDES += frameworks/base/include \
            hardware/libhardware/include \
            frameworks/native/include \
            frameworks/native/include/media/hardware

#ifeq ($(MMCOMPILER),android)
  LOCAL_SRC_FILES += src/ENS_WrapperDumpMemInfo.cpp src/mapinfo.c
#endif

LOCAL_MODULE  := libst_enswrapper

#INSTALL_LIB = libst_enswrapper.a
#todo: lib
#
#test:
#	@echo "No Test Available for enswrapper component"
#
#include $(MM_MAKEFILES_DIR)/SharedRules.mk
LOCAL_MODULE_TAGS := optional
include $(BUILD_STATIC_LIBRARY)