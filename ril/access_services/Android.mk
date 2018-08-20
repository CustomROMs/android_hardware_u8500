subdirs := sim call_network
include $(call all-named-subdir-makefiles,$(subdirs))
