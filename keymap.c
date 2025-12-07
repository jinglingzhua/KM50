#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _FUSE,
  _FUN,
  _MOUSE,
  _GAME
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_QWERTY] = LAYOUT(
  XXXXXXX,  XXXXXXX,   KC_2,    KC_3,    KC_4,    KC_5,                                  KC_6,    KC_7,    KC_8,    KC_9,    XXXXXXX, TG(_GAME),
  KC_1,        KC_Q,   KC_W,    KC_E, KC_R,  KC_T,                                    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_0,
  KC_EQL, LGUI_T(KC_A),LALT_T(KC_S),LCTL_T(KC_D),LT(_FUN, KC_F),LT(_MOUSE,KC_G),       KC_H,LT(_FUN,KC_J),RCTL_T(KC_K),RALT_T(KC_L),    RGUI_T(KC_SCLN), KC_MINUS,
  KC_GRV,       KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  XXXXXXX,              XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_BSLS,
        XXXXXXX,  LSFT_T(KC_ESC),  LT(_FUSE, KC_SPC),  KC_BSPC,                              KC_TAB,  RSFT_T(KC_ENT),  KC_QUOT,  KC_DEL
), // LALT_T(KC_ESC)
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      =\ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_FUSE] = LAYOUT(
  _______, _______,      _______,   _______,   _______,     _______,                _______,   _______,   _______,   _______,   _______,  _______,
  KC_EXLM,  KC_EXLM, KC_AT, KC_HASH, KC_DLR,  KC_PERC,                              KC_CIRC,  KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_RPRN,
  KC_PLUS, KC_LGUI, KC_LALT, KC_LCTL, KC_LBRC,  KC_RBRC,                            KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT, KC_COLN, KC_UNDS,
  KC_TILD, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_DEL, _______, _______, KC_LCBR, KC_RCBR, KC_LT, KC_GT, KC_QUES, KC_PIPE,
                             _______,  _______, _______, _______,                  LCTL(KC_SPC), _______, KC_DQT,  _______ 
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_FUN] = LAYOUT(
  _______,         _______,    KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   _______, _______,
  KC_F1,MEH(KC_1), MEH(KC_2), KC_F12, MEH(KC_3), MEH(KC_4),                         _______,  _______, LCTL(KC_PGUP), LCTL(KC_PGDN), KC_PSCR,  KC_F10,
  MEH(KC_0), KC_LGUI, KC_LALT, KC_LCTL, _______,  MEH(KC_5),                          KC_APP,_______,KC_LCTL,KC_LALT, KC_LGUI, KC_F11,
  _______, MEH(KC_F12),MEH(KC_F11),MEH(KC_9),MEH(KC_8),MEH(KC_7),MEH(KC_6),         _______, KC_HOME, KC_END, KC_PGDN, KC_PGUP, _______, _______,
                             _______,  _______, _______, _______,                    _______,  _______, _______, _______
),


[_MOUSE] = LAYOUT(
  _______,  _______,  _______, _______, _______, _______,                  _______, _______, _______, _______, _______, _______,
  _______,  _______,  _______, _______, _______, _______,                  _______, _______, MS_WHLU, MS_WHLD, _______, _______,
  _______,  _______, MS_ACL0, MS_ACL1, MS_ACL2, _______,                   MS_LEFT, MS_DOWN, MS_UP, MS_RGHT, _______, _______,
  _______,  _______, _______, _______, _______, _______,   _______, _______,  _______, _______, MS_WHLU, MS_WHLD, _______, _______,
            _______, _______, _______, _______,                            MS_BTN3,  MS_BTN1, MS_BTN2, _______
),


[_GAME] = LAYOUT(
  XXXXXXX,  XXXXXXX,   KC_2,    KC_3,    KC_4,    KC_5,                                  KC_6,    KC_7,    KC_8,    KC_9,    XXXXXXX, _______,
  KC_1,        KC_Q,   KC_W,    KC_E,     KC_R,  KC_T,                                    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_0,
  KC_EQL,      KC_A,   KC_S,    KC_D,     KC_F,    KC_G,                                KC_H,     KC_J,     KC_K,   KC_L,    KC_SCLN, KC_MINUS,
  KC_GRV,      KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  XXXXXXX,              XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_BSLS,
        XXXXXXX,  KC_ESC,  KC_SPC,  KC_BSPC,                              KC_TAB,  KC_ENT,  KC_QUOT,  KC_DEL
), // LALT_T(KC_ESC)
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_FUSE, KC_SPC):
            return true;
        case RSFT_T(KC_ENT):
            return true;
        default:
            return false;
    }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_FUSE, KC_SPC):
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}