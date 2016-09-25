# Audio
PRODUCT_PACKAGES += \
   libasound
$(call inherit-product, hardware/u8500/audio/libasound/alsa-lib-products.mk)

# STE Display 
PRODUCT_PACKAGES += \
   lights.montblanc \
   hwcomposer.montblanc \
   gralloc.montblanc \
   copybit.montblanc \
   libblt_hw

# STE Media
PRODUCT_PACKAGES += \
   libbassapp \
   libnmf \
   liblos \
   libomxil-bellagio \
   libste_omxil-interface \
   libstelpcutils \
   libstagefrighthw \
   libstagefright_soft_ste_wmapro_v10 \
   libstagefright_soft_ste_mp3dec \
   libstagefright_soft_ste_aacdec \
   libtrace

# WLAN
PRODUCT_PACKAGES += \
   iw

# CSPSA 
PRODUCT_PACKAGES += \
   cspsa-server \
   cspsa-cmd \
   libcspsa

# RIL
PRODUCT_PACKAGES += \
    msa \
    libtee \
    libmpl \
    libisimessage \
    libshmnetlnk \
    libmalutil \
    libpscc \
    libsterc \
    libstecom \
    libsms_server \
    libsecril-client \

# External
PRODUCT_PACKAGES += \
   memtrack.montblanc

#   whetstone \
#   whetstone_hard

# Sensors
#PRODUCT_PACKAGES += \
#   sensors.montblanc

BOARD_HAL_STATIC_LIBRARIES := libhealthd.montblanc
