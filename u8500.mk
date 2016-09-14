# Audio
PRODUCT_PACKAGES += \
   libasound
$(call inherit-product, hardware/u8500/audio/libasound/alsa-lib-products.mk)

# STE Display 
PRODUCT_PACKAGES += \
   lights.montblanc \
   hwcomposer.montblanc \
   copybit.montblanc \
   libblt_hw

# STE Media
PRODUCT_PACKAGES += \
   libomxil-bellagio \
   libstelpcutils \
   libstagefrighthw \
   libstagefright_soft_ste_wmapro_v10 \
   libstagefright_soft_ste_mp3dec \
   libstagefright_soft_ste_aacdec

# WLAN
PRODUCT_PACKAGES += \
   iw

# RIL
PRODUCT_PACKAGES += \
    libril \
    libsecril-client \
    libsec-ril-wrapper

# External
PRODUCT_PACKAGES += \
   memtrack.montblanc

#   whetstone \
#   whetstone_hard

# Sensors
PRODUCT_PACKAGES += \
   sensors.montblanc

BOARD_HAL_STATIC_LIBRARIES := libhealthd.montblanc
