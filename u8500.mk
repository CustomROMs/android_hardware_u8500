# Audio
PRODUCT_PACKAGES += \
   libasound
$(call inherit-product, hardware/u8500/audio/libasound/alsa-lib-products.mk)

# STE Display 
PRODUCT_PACKAGES += \
   libblt_hw
   libgralloc-shim \
   libUMP-shim \
   copybit.montblanc \
   gralloc.montblanc \
   hwcomposer.montblanc \
   lights.montblanc

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

# STE Compat Symbols
PRODUCT_PACKAGES += \
   libste_symbols

# STE Camera
PRODUCT_PACKAGES += \
    camera.montblanc \
    libcamera_symbols 

# RIL
PRODUCT_PACKAGES += \
    libril \
    libsecril-client \
    libsec-ril-wrapper

# STE gps Compat Symbols
PRODUCT_PACKAGES += \
    libshim_gps


# External
PRODUCT_PACKAGES += \
   memtrack.montblanc

#   whetstone \
#   whetstone_hard

BOARD_HAL_STATIC_LIBRARIES := libhealthd.montblanc
