#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_F7,   KC_F9,   KC_F5,                              KC_F3,   KC_GRV,  /* 10000 =>  1 */
        KC_INT5, KC_1,                                        KC_F2,            /* 10001 =>  2 */
        KC_SCRL, KC_LCTL, KC_CAPS,          KC_MENU, KC_RCTL, KC_LGUI, KC_TAB,  /* 10010 =>  3 */
                 KC_LSFT,                            KC_RSFT, KC_V,             /* 10011 =>  4 */
                 KC_RGUI,          KC_LALT, KC_RALT, KC_INT1, KC_LEFT, KC_B,    /* 10100 =>  5 */
                          KC_2,    KC_Q,    KC_A,    KC_S,    KC_Z,    KC_X,    /* 10101 =>  6 */
                          KC_3,    KC_4,    KC_W,    KC_E,    KC_D,    KC_C,    /* 10110 =>  7 */
                                                     KC_ENT,  KC_RBRC, KC_BSLS, /* 10111 =>  8 */
        KC_F11,  KC_BSPC, KC_EQL,  KC_INT3, KC_P,    KC_LBRC, KC_QUOT, KC_SLSH, /* 01000 =>  9 */
                 KC_SCLN,          KC_MINS, KC_K,    KC_O,             KC_L,    /* 01001 => 10 */
        KC_DOT,  KC_COMM, KC_9,    KC_0,    KC_U,    KC_I,    KC_J,    KC_M,    /* 01010 => 11 */
                 KC_7,    KC_8,    KC_T,    KC_Y,    KC_G,    KC_H,    KC_N,    /* 01011 => 12 */
        KC_F8,   KC_F12,  KC_5,    KC_6,    KC_R,    KC_F,    KC_F1,   KC_ESC,  /* 01100 => 13 */
        KC_PGUP, KC_PGDN, KC_F6,   KC_F10,           KC_HOME, KC_F4,   KC_DOWN, /* 01101 => 14 */
        KC_UP,   KC_SPC,           KC_INT4,                   KC_INT2, KC_END,  /* 01110 => 15 */
        KC_DEL,  KC_PSCR,                            KC_PAUS, KC_INS,  KC_RGHT  /* 01111 => 16 */
    )
};
