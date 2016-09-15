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

LOCAL_CFLAGS += -DENS_VERSION=1 -DENS_VERSION_SHARED=1 -DENS_VERSION_VIDEO=2 -DENS_VERSION_AUDIO=3 -DENS_VERSION_IMAGING=4

#include ../make.ost_conf
#KStEnsOstTraceProxy   = KStUidCommonDefine018 = 0x2003064D = 537069133
#OST_COMPONENT_ID = 537069133
#OST_DICO_NAME = $(OST_COMPONENT_NAME)_proxy
#OST_SRC_DIR = ENS_Fsm ENS_Component
#CPPFLAGS+= -I$(OST_COMPONENT_INC)/autogentraces

#INSTALL_DICO+=ENS_proxy.xml
#include $(MM_MAKEFILES_DIR)/SharedConfig.mk

#ifeq ($(MEDIUM),shared)
#LIBSUFFIX =
#else
#LIBSUFFIX = _$(MEDIUM)
#endif


#INSTALL_HEADERDIR= include 
#VPATH+= include


LOCAL_C_INCLUDES +=  $(LOCAL_PATH)/include $(NMF_TOOLS_DIR)/api/cpp \
	$(LOCAL_PATH)/../../omxil \
	$(LOCAL_PATH)/../../ens_interface/include/ \
            $(LOCAL_PATH)/../common \
	$(LOCAL_PATH)/../../rme/include \
	$(LOCAL_PATH)/../../nmf/linux/api \
	$(LOCAL_PATH)/../../ens_interface/nmf/mpc/nmf_repository/mmdsp_x \
	$(LOCAL_PATH)/../../host_trace \
	$(LOCAL_PATH)/../../utils/include/ \
	$(LOCAL_PATH)/../../mmhwbuffer_api/include/ \
	$(LOCAL_PATH)/../../osttrace/include/

ifndef DISABLE_BACKWARD_COMPATIBILTY_MODE
LOCAL_CFLAGS+=-DBACKWARD_COMPATIBILTY_MODE
endif

#VPATH+= ENS_Utils ENS_Component ENS_Fsm

#TODO: compile these
# ENS_Component/ENS_Port.cpp \
# ENS_Component/NmfHostMpc_ProcessingComponent.cpp \
# ENS_Component/ENS_Component.cpp \
# ENS_Component/NmfHost_ProcessingComponent.cpp \
# ENS_Component/NmfMpc_ProcessingComponent.cpp \
# ENS_Fsm/ENS_Port_Fsm.cpp \
# ENS_Fsm/ENS_Component_Fsm.cpp

LOCAL_SRC_FILES   := \
 ENS_Utils/ENS_List.cpp \
 ENS_Utils/ENS_Trace.cpp \
 ENS_Utils/SharedBuffer.cpp \
 ENS_Utils/ENS_Nmf.cpp \
 ENS_Component/ENS_ResourcesDB.cpp \
 ENS_Fsm/ENS_Fsm.cpp \

#ifeq ($(CORE_NUMBER),2)
# mpc relative code is added
#LIBOBJ+= ENS_Nmf SharedBuffer NmfMpc_ProcessingComponent 
#ifeq ($(MEDIUM),shared)
#LIBOBJ+= ens_cpp-user2mpc-stubs ens_cpp-mpc2user-skels NmfHostMpc_ProcessingComponent
#endif
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../nmf/mpc/nmf_repository/mmdsp_x

#VPATH+= $(REPOSITORY_MPC)/host
#TODO: ???

#endif


LOCAL_MODULE  := libst_ens
LOCAL_FLAGS += -DRELEASE -D__RELEASE
LOCAL_MODULE_TAGS := optional
include $(BUILD_STATIC_LIBRARY)

