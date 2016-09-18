# Copyright 2006 The Android Open Source Project

ifeq ($(TARGET_SOC), u8500)

ril-modules := libsecril-client
include $(call all-named-subdir-makefiles,$(ril-modules))

endif
