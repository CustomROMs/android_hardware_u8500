# Copyright 2006 The Android Open Source Project

ifeq ($(TARGET_SOC), u8500)

opensource-libs := CMUserProxy omxcore_interface
include $(call all-named-subdir-makefiles,$(opensource-libs))

endif
