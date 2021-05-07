LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES :=  \
	alsactrl_tinyalsa_extn.c \
        shim.c

LOCAL_CFLAGS += -D_POSIX_C_SOURCE
LOCAL_CFLAGS += -O3 -Wall -funwind-tables
LOCAL_CFLAGS += -DALSACTRL_LOG_ERRORS -DADM_LOG_WARNINGS

LOCAL_MODULE           := libste_audio_hwctrl
LOCAL_MODULE_TAGS      := optional
LOCAL_PRELINK_MODULE   := false

LOCAL_SHARED_LIBRARIES := \
        libcutils \
        libutils \
	liblog \
        libdl \
        libc \
        libsqlite \
        libtinyalsa \
	libasound \
	libalsactl

LOCAL_C_INCLUDES := \
    $(LOCAL_PATH)/include \
    $(LOCAL_PATH)/ \
    vendor/st-ericsson/multimedia \
    $(TOP)/external/sqlite/dist/  \
    $(TOP)/external/tinyalsa/include/ \
    $(TOP)/hardware/u8500/audio/libasound/include

include $(BUILD_SHARED_LIBRARY)
