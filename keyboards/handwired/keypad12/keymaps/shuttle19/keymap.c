#include QMK_KEYBOARD_H

enum layer_names {
    _RAISE,   // Left
    _LOWER,   // Right
    _RAISEFN, // Symbol
    _RAISEFS, // Shift Symbol
    _LOWERFN, // Number
    _LOWERFS, // Shift Number
    _NAV,     // Navigation
    _FN,      // Function
    _NUMPAD   // Numpad
};

#define LOWER TO(_LOWER)
#define RAISE TO(_RAISE)
#define LOWERFN OSL(_LOWERFN)
#define RAISEFN OSL(_RAISEFN)
#define LOWERFS OSL(_LOWERFS)
#define RAISEFS OSL(_RAISEFS)
#define NAV TG(_NAV)
#define FN TG(_FN)
#define NUMPAD TO(_NUMPAD)

enum combos {
    LCTL_FN_LSFT_LOWER_CLEAR_MODS,
    LCTL_FN_RAISE_RSFT_CLEAR_MODS,
    LCTL_RSFT_RAISE_LOWER_CLEAR_MODS,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM lctl_fn_lsft_lower_combo[] = {KC_LCTL, RAISEFN, KC_LSFT, LOWER, COMBO_END};
const uint16_t PROGMEM lctl_fn_raise_rsft_combo[] = {KC_LCTL, LOWERFN, RAISE, KC_RSFT, COMBO_END};
const uint16_t PROGMEM lctl_rsft_raise_lower_combo[] = {KC_LCTL, KC_RSFT, RAISE, LOWER, COMBO_END};

combo_t key_combos[] = {
    [LCTL_FN_LSFT_LOWER_CLEAR_MODS] = COMBO_ACTION(lctl_fn_lsft_lower_combo),
    [LCTL_FN_RAISE_RSFT_CLEAR_MODS] = COMBO_ACTION(lctl_fn_lsft_lower_combo),
    [LCTL_RSFT_RAISE_LOWER_CLEAR_MODS] = COMBO_ACTION(lctl_fn_lsft_lower_combo),
};

enum custom_keycodes {
    KC_P000 = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ t │ g │ b │LOW│
     * ├───┼───┼───┼───┤
     * │ r │ f │ v │Sft│
     * ├───┼───┼───┼───┤
     * │ e │ d │ c │Fn │
     * ├───┼───┼───┼───┤
     * │ w │ s │ x │   │
     * ├───┼───┼───┤Ctl│
     * │ q │ a │ z │   │
     * └───┴───┴───┴───┘
     */
    [_RAISE] = LAYOUT(
        KC_T,    KC_G,    KC_B,    LOWER,
        KC_R,    KC_F,    KC_V,    KC_LSFT,
        KC_E,    KC_D,    KC_C,    RAISEFN,
        KC_W,    KC_S,    KC_X,    KC_LCTL,
        KC_Q,    KC_A,    KC_Z
    ),

    /*
     * ┌───┬───┬───┬───┐
     * │ p │Ent│Spc│Sft│
     * ├───┼───┼───┼───┤
     * │ o │ l │ . │RAI│
     * ├───┼───┼───┼───┤
     * │ i │ k │ , │Fn │
     * ├───┼───┼───┼───┤
     * │ u │ j │ m │   │
     * ├───┼───┼───┤Ctl│
     * │ y │ h │ n │   │
     * └───┴───┴───┴───┘
     */
    [_LOWER] = LAYOUT(
        KC_P,    KC_ENT,  KC_SPC,  KC_RSFT,
        KC_O,    KC_L,    KC_DOT,  RAISE,
        KC_I,    KC_K,    KC_COMM, LOWERFN,
        KC_U,    KC_J,    KC_M,    KC_LCTL,
        KC_Y,    KC_H,    KC_N
    ),

    /*
     * ┌───┬───┬───┬───┐
     * │ ^ │ : │ \ │LOW│
     * ├───┼───┼───┼───┤
     * │ - │ ; │ / │Sft│
     * ├───┼───┼───┼───┤
     * │ ¥ │ ] │Nav│Fn │
     * ├───┼───┼───┼───┤
     * │ @ │ [ │Cap│   │
     * ├───┼───┼───┤Ctl│
     * │Esc│Tab│Bs │   │
     * └───┴───┴───┴───┘
     */
    [_RAISEFN] = LAYOUT(
        KC_EQL,  KC_QUOT,   KC_RO,   LOWER,
        KC_MINS, KC_SCLN,   KC_SLSH, RAISEFS,
        KC_JYEN, KC_NUHS,   NAV,     _______,
        KC_LBRC, KC_RBRC,   KC_CAPS, KC_LCTL,
        KC_ESC,  KC_TAB,    KC_BSPC
    ),
    /*
     * ┌───┬───┬───┬───┐
     * │ ^ │ : │ \ │LOW│
     * ├───┼───┼───┼───┤
     * │ - │ ; │ / │Sft│
     * ├───┼───┼───┼───┤
     * │ ¥ │ ] │Nav│Fn │
     * ├───┼───┼───┼───┤
     * │ @ │ [ │Cap│   │
     * ├───┼───┼───┤Ctl│
     * │Esc│Tab│Bs │   │
     * └───┴───┴───┴───┘
     */
    [_RAISEFS] = LAYOUT(
        S(KC_EQL),  S(KC_QUOT), S(KC_RO),   LOWER,
        S(KC_MINS), S(KC_SCLN), S(KC_SLSH), _______,
        S(KC_JYEN), S(KC_NUHS), NAV,        RAISEFN,
        S(KC_LBRC), S(KC_RBRC), S(KC_CAPS), KC_LCTL,
        S(KC_ESC),  S(KC_TAB),  S(KC_BSPC)
    ),

    /*
     * ┌───┬───┬───┬───┐
     * │ 5 │ 0 │Xfr│Sft│
     * ├───┼───┼───┼───┤
     * │ 4 │ 9 │Nfr│RAI│
     * ├───┼───┼───┼───┤
     * │ 3 │ 8 │Nav│Fn │
     * ├───┼───┼───┼───┤
     * │ 2 │ 7 │Grv│   │
     * ├───┼───┼───┤Ctl│
     * │ 1 │ 6 │Bs │   │
     * └───┴───┴───┴───┘
     */
    [_LOWERFN] = LAYOUT(
        KC_5,    KC_0,    KC_HENK, LOWERFS,
        KC_4,    KC_9,    KC_MHEN, RAISE,
        KC_3,    KC_8,    NAV,     _______,
        KC_2,    KC_7,    KC_GRV,  KC_LCTL,
        KC_1,    KC_6,    KC_BSPC 
    ),

    /*
     * ┌───┬───┬───┬───┐
     * │ 5 │ 0 │Xfr│Sft│
     * ├───┼───┼───┼───┤
     * │ 4 │ 9 │Nfr│RAI│
     * ├───┼───┼───┼───┤
     * │ 3 │ 8 │Nav│Fn │
     * ├───┼───┼───┼───┤
     * │ 2 │ 7 │Grv│   │
     * ├───┼───┼───┤Ctl│
     * │ 1 │ 6 │Bs │   │
     * └───┴───┴───┴───┘
     */
    [_LOWERFS] = LAYOUT(
        S(KC_5), S(KC_0), S(KC_HENK), _______,
        S(KC_4), S(KC_9), S(KC_MHEN), RAISE,
        S(KC_3), S(KC_8), NAV,        LOWERFN,
        S(KC_2), S(KC_7), S(KC_GRV),  KC_LCTL,
        S(KC_1), S(KC_6), S(KC_BSPC) 
    ),

    /*
     * ┌───┬───┬───┬───┐
     * │NPd│Alt│Sup│LOW│
     * ├───┼───┼───┼───┤
     * │PgU│ ↑ │PgD│RAI│
     * ├───┼───┼───┼───┤
     * │ ← │   │ → │Sft│
     * ├───┼───┼───┼───┤
     * │Hom│ ↓ │End│   │
     * ├───┼───┼───┤Ctl│
     * │Ins│Fnc│Del│   │
     * └───┴───┴───┴───┘
     */
    [_NAV] = LAYOUT(
        NUMPAD,  KC_LALT, KC_LGUI, LOWER,
        KC_PGUP, KC_RGHT, KC_PGDN, RAISE,
        KC_UP,   XXXXXXX, KC_DOWN, KC_RSFT,
        KC_HOME, KC_LEFT, KC_END,  KC_LCTL,
        KC_INS,  FN,      KC_DEL
    ),

    /*
     * ┌───┬───┬───┬───┐
     * │PSc│SLk│Pse│LOW│
     * ├───┼───┼───┼───┤
     * │F4 │F8 │F12│RAI│
     * ├───┼───┼───┼───┤
     * │F3 │F7 │F11│Sft│
     * ├───┼───┼───┼───┤
     * │F2 │F6 │F10│   │
     * ├───┼───┼───┤Ctl│
     * │F1 │F5 │F9 │   │
     * └───┴───┴───┴───┘
     */
    [_FN] = LAYOUT(
        KC_PSCR, KC_SCRL, KC_PAUS, LOWER,
        KC_F4,   KC_F8,   KC_F12,  RAISE,
        KC_F3,   KC_F7,   KC_F11,  KC_RSFT,
        KC_F2,   KC_F6,   KC_F10,  KC_LCTL,
        KC_F1,   KC_F5,   KC_F9
    ),

    /*
     * ┌───┬───┬───┬───┐
     * │LOW│ / │ * │ - │
     * ├───┼───┼───┼───┤
     * │ 7 │ 8 │ 9 │ + │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │BS │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │   │
     * ├───┼───┼───┤Ent│
     * │ 0 │000│ . │   │
     * └───┴───┴───┴───┘
     */
    [_NUMPAD] = LAYOUT(
        RAISE,   KC_PSLS, KC_PAST, KC_PMNS,
        KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_P4,   KC_P5,   KC_P6,   KC_BSPC,
        KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_P0,   KC_P000, KC_PDOT
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static int fn_pressed = 0;

    if (record->event.pressed) {
        switch(keycode) {
            case LOWERFN:
            case RAISEFN:
                fn_pressed = 1;
                return true;

            case KC_RSFT:
                if (IS_LAYER_ON(_NAV)) {
                    fn_pressed = 1;
                    return true;
                }
                break;

            case KC_LCTL:
                if (fn_pressed) {
                    add_oneshot_mods(MOD_BIT(KC_RCTL));
                    return false;
                }
                break;

            case RAISE:
            case RAISEFS:
                if (fn_pressed) {
                    add_oneshot_mods(MOD_BIT(KC_RGUI));
                    return false;
                }
                break;

            case LOWER:
            case LOWERFS:
                if (fn_pressed) {
                    add_oneshot_mods(MOD_BIT(KC_RALT));
                    return false;
                }
                break;

            case KC_P0:
            case KC_P1:
            case KC_P2:
            case KC_P3:
            case KC_P4:
            case KC_P5:
            case KC_P6:
            case KC_P7:
            case KC_P8:
            case KC_P9:
            case KC_PDOT:
                if (!host_keyboard_led_state().num_lock) {
                    tap_code(KC_NUM);
                    tap_code(keycode);
                    tap_code(KC_NUM);
                    return false;
                }
                break;

            case KC_P000:
                if (!host_keyboard_led_state().num_lock) {
                    tap_code(KC_NUM);
                    tap_code(KC_P0);
                    tap_code(KC_P0);
                    tap_code(KC_P0);
                    tap_code(KC_NUM);
                } else {
                    tap_code(KC_P0);
                    tap_code(KC_P0);
                    tap_code(KC_P0);
                }
                return false;
        }
    } else {
        switch(keycode) {
            case LOWERFN:
            case RAISEFN:
              fn_pressed = 0;
              return true;

            case KC_RSFT:
                if (IS_LAYER_ON(_NAV)) {
                    fn_pressed = 0;
                    return true;
                }
                break;

            case KC_F1:
            case KC_F2:
            case KC_F3:
            case KC_F4:
            case KC_F5:
            case KC_F6:
            case KC_F7:
            case KC_F8:
            case KC_F9:
            case KC_F10:
            case KC_F11:
            case KC_F12:
            case KC_PSCR:
            case KC_SCRL:
            case KC_PAUS:
                layer_off(_NAV);
                layer_off(_FN);
                return true;
        }
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _NUMPAD:
            numlock_led_on();
            break;

        default:
            numlock_led_off();
    }
    return state;
}

bool led_update_user(led_t led_state) {
    // Control Numlock LED manually
    return false;
}

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        case LCTL_FN_LSFT_LOWER_CLEAR_MODS:
        case LCTL_FN_RAISE_RSFT_CLEAR_MODS:
        case LCTL_RSFT_RAISE_LOWER_CLEAR_MODS:
            if (pressed) {
                clear_oneshot_mods();
            }
            break;
    }
}
