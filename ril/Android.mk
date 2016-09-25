# Copyright 2006 The Android Open Source Project

ifeq ($(TARGET_SOC), u8500)

ril-modules := libsecril-client libisimessage libmpl libpscc libshmnetlnk libstecom libsterc libtee mal_util sms
include $(call all-named-subdir-makefiles,$(ril-modules))

endif
