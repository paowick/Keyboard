
#pragma once
#define I2C_DRIVER I2CD1
#define HAL_USE_I2C TRUE
#define I2C1_SDA_PIN GP26
#define I2C1_SCL_PIN GP27

#define OLED_DISPLAY_128x64
#define OLED_DISPLAY_128X64

#define ENCODERS_PAD_A { GP21 }
#define ENCODERS_PAD_B { GP22 }
#define ENCODER_RESOLUTION 1

#define AUDIO_PIN GP28
#define AUDIO_PWM_DRIVER PWMD0
#define AUDIO_PWM_CHANNEL 1
#define AUDIO_ENABLE_TONE_MULTIPLEXING
#define AUDIO_TONE_MULTIPLEXING_RATE_DEFAULT 10


/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
