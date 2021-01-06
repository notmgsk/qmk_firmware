#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_PIPE,
        KC_BSPC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, OSL(2), KC_QUOT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, LCTL_T(KC_SPACE), LT(3,KC_ESC), KC_SPC, LT(1,KC_ENT), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        KC_ESC, KC_LALT, KC_LGUI, LCTL_T(KC_SPACE), LT(3,KC_ESC), KC_SPC, LT(1,KC_ENT), KC_RGUI, KC_BSPC, KC_RALT),


    [1] = LAYOUT(
        KC_TRNS, KC_0, KC_1, KC_2, KC_3, KC_PIPE, KC_TRNS, KC_PGUP, KC_UP, KC_PGDOWN, KC_TRNS, KC_BSLS,
        KC_TRNS, KC_HASH, KC_4, KC_5, KC_6, KC_GRV, KC_PLUS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PERC, KC_QUOT,
        KC_TRNS, KC_PERC, KC_7, KC_8, KC_9, KC_TILD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_AMPR, KC_EQL,
        KC_COMM, KC_DOT, KC_SLSH, KC_MINS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SCLN, KC_EQL, KC_EQL, KC_SCLN, KC_TRNS, KC_TRNS, KC_TRNS),


    [2] = LAYOUT(
        KC_EXLM, KC_CIRC, KC_PAST, KC_PPLS, KC_PEQL, KC_AMPR, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_TRNS, KC_TRNS,
        KC_EQL, KC_TILD, KC_LCBR, KC_LBRC, KC_LPRN, KC_LT, KC_GT, KC_RPRN, KC_RBRC, KC_RCBR, KC_TRNS, KC_TRNS,
        KC_BSLASH, KC_PERC, KC_GRV, KC_QUOT, KC_SCLN, KC_QUES, KC_TRNS, KC_TRNS, KC_UNDS, KC_DQUO, KC_MINS, KC_COLN,
        KC_PIPE, KC_TRNS, KC_TRNS, KC_EXLM, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

// Lifted from Thomas' config.
/*
 * 3 Layer: Numpad, Media
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      | VolUp|      |      |                              | / ?  | 7 &  | 8 *  | 9 (  | - _  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      | Prev | Play | Next |      |                              | *    | 4 $  | 5 %  | 6 ^  | , <  | +      |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      | VolDn| Mute |      |      |      |  |      |      | 0 )  | 1 !  | 2 @  | 3 #  | = +  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      | Lower|      |      |  |      | Nav  | Raise|      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [3] = LAYOUT(
        _______, _______, KC_BRMU, KC_VOLU, _______, _______,                                     KC_SLSH, KC_7,    KC_8,    KC_9, KC_MINS, _______,
        _______, _______, KC_BRMD, KC_VOLD, KC_MUTE, _______,                                     KC_ASTR, KC_4,    KC_5,    KC_6, KC_COMM, KC_PLUS,
        _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, _______, KC_0,    KC_1,    KC_2,    KC_3, KC_EQL,  _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
        ),
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

static void render_mccarthy(void) {
    static const char PROGMEM mccarthy[] = {
#include "mccarthy.txt"
    };
    oled_write_raw_P(mccarthy, sizeof(mccarthy));
}

static void render_sicp(void) {
    static const char PROGMEM sicp[] = {
#include "sicp.txt"
    };
    oled_write_raw_P(sicp, sizeof(sicp));
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_mccarthy(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_sicp();
    }
}

#endif

void matrix_init_user(void) { // Runs boot tasks for keyboard
    rgblight_enable();
    rgblight_sethsv(HSV_MAGENTA);
    rgblight_mode(RGBLIGHT_MODE_RAINBOW_MOOD);
};
