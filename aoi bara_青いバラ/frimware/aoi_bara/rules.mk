# This file intentionally left blank

MCU = RP2040
BOOTLOADER = rp2040

OLED_ENABLE = yes
OLED_DRIVER_ENABLE = yes
OLED_DRIVER = ssd1306
LTO_ENABLE = yes

ENCODER_ENABLE = yes

OPT_DEFS += -DHAL_USE_I2C=TRUE