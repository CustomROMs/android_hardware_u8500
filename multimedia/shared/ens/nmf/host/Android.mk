
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

LOCAL_CFLAGS += -DENS_VERSION=1 -DENS_VERSION_SHARED=1 -DENS_VERSION_VIDEO=2 -DENS_VERSION_AUDIO=3 -DENS_VERSION_IMAGING=4 \
 -U OST_TRACE_COMPILER_IN_USE

LOCAL_C_INCLUDES := \
  $(LOCAL_PATH)/fsm/generic \
  $(LOCAL_PATH)/fsm/component \
  $(LOCAL_PATH)/common \
  $(LOCAL_PATH)/../../proxy/include \
  $(LOCAL_PATH)/../../../../imaging/ext_sia_hw_components_8500/nmf/host/nmf_repository/cortexA9-x-android-x/

LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../utils/include $(LOCAL_PATH)/../../../ens_interface/include/omxil/ \
   $(LOCAL_PATH)/../../../ens_interface/nmf/mpc/nmf_repository/mmdsp_x \
   $(LOCAL_PATH)/../../../nmf/linux/api/ \
   $(LOCAL_PATH)/../../../ens_interface/include \
   $(LOCAL_PATH)/../../../rme/include \
   $(LOCAL_PATH)/../../../osttrace/include \
   $(LOCAL_PATH)/../../../mmhwbuffer_osi/include \
   $(LOCAL_PATH)/../../../ostgrp/include \
   $(LOCAL_PATH)/../../../ens/common/ \
   $(LOCAL_PATH)/../../../osttools/osttc/test/ref/test5/

#  fsm/component/Port.cpp \
$(warning $(LOCAL_C_INCLUDES))

LOCAL_SRC_FILES := \
  fsm/generic/FSM.cpp \
  fsm/component/PortQueue.cpp \
  fsm/component/Component.cpp \
  fsm/controller/Controller.cpp

#VPATH+= common fsm/generic fsm/component fsm/controller
#LIBOBJ= FSM PortQueue Port Component Controller

LOCAL_MODULE := libst_ensfsm_host
#LIBNAME           = st_ensfsm_host$(LIBSUFFIX)
#INSTALL_LIB       = lib$(LIBNAME).a
#INSTALL_HEADERDIR = fsm/component fsm/generic fsm/controller common

#WARNING todo target is MANDATORY (exe and/or lib)clear
#todo: lib
LOCAL_MODULE_TAGS := optional
include $(BUILD_STATIC_LIBRARY)

