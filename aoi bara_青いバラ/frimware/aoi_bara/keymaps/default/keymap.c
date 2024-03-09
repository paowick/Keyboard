// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_name {
    DEFAULT,
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
[DEFAULT] = LAYOUT_66_ansi(
        
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL,     KC_BSPC,       KC_NO,

        KC_TAB,   KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC,  KC_BSLS,

        KC_CAPS,   KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,       KC_ENT,

        KC_LSFT,    KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,          KC_RSFT,  KC_UP,

        KC_LCTL, KC_LGUI, KC_LALT,               KC_SPC,              KC_ESC, DF(FUNC), DF(MOUSE), KC_LEFT, KC_DOWN, KC_RGHT

        ),
[FUNC] = LAYOUT_66_ansi(
        
        KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,     KC_TRNS,       KC_TRNS,

        KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,

        KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,

        KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,  KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS,              DF(DEFAULT), DF(FUNC), DF(MOUSE), KC_TRNS, KC_TRNS, KC_TRNS

        ),
[MOUSE] = LAYOUT_66_ansi(
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,       KC_TRNS,

        KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,

        KC_TRNS,   KC_TRNS, KC_BTN2, KC_BTN3, KC_BTN1, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, KC_TRNS,       KC_TRNS,
        
        KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,  KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS,              DF(DEFAULT), DF(FUNC), DF(MOUSE), KC_TRNS, KC_TRNS, KC_TRNS

      
        ),
        

};


#ifdef OLED_ENABLE

    oled_rotation_t oled_init_user(oled_rotation_t rotation) {
        if (is_keyboard_master()) {
            return OLED_ROTATION_90;
        }

        return rotation;
    }

    bool oled_task_user(void) {
        oled_set_cursor(0,1);

        switch (get_highest_layer(layer_state))
        {
        case DEFAULT :
            oled_write("DEF", false);
            break;
        case FUNC :
            oled_write("FUNC", false);
            break;
        case MOUSE :
            oled_write("MOUSE", false);
            break;
        }
        return false;
}
#endif

bool encoder_update_user(uint8_t index, bool clockwise) {
        if (clockwise) {
            tap_code(KC_RIGHT);
        } else {
            tap_code(KC_LEFT);
        }
    return false;
}