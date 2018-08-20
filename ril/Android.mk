# Copyright 2006 The Android Open Source Project

ifeq ($(TARGET_SOC), u8500)

ril-modules := libcops at_core_common access_services libsecril-client libisimessage libmpl libpscc libstecom libsterc mal_util sms
include $(call all-named-subdir-makefiles,$(ril-modules))

endif
