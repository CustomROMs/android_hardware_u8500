
# Audio
PRODUCT_PACKAGES += \
   libasound
$(call inherit-product, hardware/u8500/audio/libasound/alsa-lib-products.mk)

# STE Display
PRODUCT_PACKAGES += \
   lights.montblanc \
   gralloc.montblanc \
   libUMP \
   hwcomposer.montblanc \
   copybit.montblanc \
   libblt_hw

# STE Media
PRODUCT_PACKAGES += \
   libomxil-bellagio \
   libstelpcutils

# WLAN
PRODUCT_PACKAGES += \
   iw

# camera libhead
PRODUCT_PACKAGES += \
    libhead

# libsecril-client
PRODUCT_PACKAGES += \
    libsecril-client

# Legacy RIL
PRODUCT_PACKAGES += \
    libsecril-shim

# power
PRODUCT_PACKAGES += \
    power.montblanc

# External
PRODUCT_PACKAGES += \
   memtrack.montblanc

BOARD_HAL_STATIC_LIBRARIES := libhealthd.montblanc
