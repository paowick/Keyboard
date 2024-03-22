// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include "animation.h"
#include "animation2.h"
#include "animation3.h"
#include QMK_KEYBOARD_H

enum layer_names {
    BASE,
    FUNC,
    MOUSE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐  ┌───┐
     * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│  │   │ <------ OLED
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤  │   │
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │  │   │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤  └───┘
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │  ┌───┐
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──────┬─┴─┐│   │ <------ encoder
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ Shift  │ ↑ │└───┘
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┼────┬───┼───┼───┐
     * │Ctrl│GUI │Alt │                        │ Alt│GUI│ Ctl│ ← │ ↓ │ → │
     * └────┴────┴────┴────────────────────────┴────┴───┴────┴───┴───┴───┘
     */
[0] = LAYOUT_66_ansi(
        
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL,     KC_BSPC,       KC_NO,

        KC_TAB,   KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC,  KC_BSLS,

        KC_CAPS,   KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,       KC_ENT,

        KC_LSFT,    KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,          KC_RSFT,  KC_UP,

        KC_LCTL, KC_LGUI, KC_LALT,               KC_SPC,              KC_ESC, TO(1), TO(2), KC_LEFT, KC_DOWN, KC_RGHT

        ),
[1] = LAYOUT_66_ansi(
        
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL,     KC_BSPC,       KC_NO,

        KC_TAB,   KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC,  KC_BSLS,

        KC_CAPS,   KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,       KC_ENT,

        KC_LSFT,    KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,          KC_RSFT,  KC_UP,

        KC_LCTL, KC_LGUI, KC_LALT,               KC_SPC,              KC_ESC, TO(1), TO(2), KC_LEFT, KC_DOWN, KC_RGHT

        ),
[2] = LAYOUT_66_ansi(
        
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL,     KC_BSPC,       KC_NO,

        KC_TAB,   KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC,  KC_BSLS,

        KC_CAPS,   KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,       KC_ENT,

        KC_LSFT,    KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,          KC_RSFT,  KC_UP,

        KC_LCTL, KC_LGUI, KC_LALT,               KC_SPC,              KC_ESC, TO(1), TO(2), KC_LEFT, KC_DOWN, KC_RGHT

        ),
};

#ifdef AUDIO_ENABLE
    float change_gif[][2] = SONG(SONIC_RING);
#endif

uint8_t gif = 0;
#ifdef OLED_ENABLE

    oled_rotation_t oled_init_user(oled_rotation_t rotation) {
        if (is_keyboard_master()) {
            return OLED_ROTATION_90;
        }

        return rotation;
    }


    bool oled_task_user(void) {

        oled_set_cursor(0,15);

        led_t led_state = host_keyboard_led_state();
        if (led_state.caps_lock)
        {
            oled_write("CapsLock!!", false);
        }else
        {
            oled_write("          ", false);
        }
        
        
        oled_set_cursor(0,5);
        oled_write("wpm :", false);
        oled_set_cursor(6,5);
        oled_write(get_u8_str(get_current_wpm(), '0'), false);
        
        oled_set_cursor(0,0);
        oled_write("BASE", false);
        oled_set_cursor(0,2);
        oled_write("FUNC", false);
        oled_set_cursor(0,4);
        oled_write("MOUSE", false);

        switch (get_highest_layer(layer_state)) {
        case BASE :
            gif = 0; 
            oled_set_cursor(6,0);
            oled_write("<---", false);
            oled_set_cursor(6,2);
            oled_write("    ", false);
            oled_set_cursor(6,4);
            oled_write("    ", false);
            break;
        case FUNC :
            gif = 1;
            oled_set_cursor(6,0);
            oled_write("    ", false);
            oled_set_cursor(6,2);
            oled_write("<---", false);
            oled_set_cursor(6,4);
            oled_write("    ", false);
            break;
        case MOUSE :
            gif = 2;
            oled_set_cursor(6,0);
            oled_write("    ", false);
            oled_set_cursor(6,2);
            oled_write("    ", false);
            oled_set_cursor(6,4);
            oled_write("<---", false);
            break;
        }
        oled_set_cursor(0,6);
        switch (gif){
            case 0 :
               render_animation();
               break;
            case 1 :
                render_animation2();
                break;
            case 2 :
                render_animation3();
                break;
        }
        return false;
    }
#endif
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)},
    [1] =   { ENCODER_CCW_CW(RGB_HUD, RGB_HUI)},
    [2] =   { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    //                  Encoder 1                                     Encoder 2
};
#endif
