#include QMK_KEYBOARD_H

enum layers {
	L_RIGHT = 0,
	L_LEFT
};

const uint16_t PROGMEM swap_handedness[] = {KC_BTN5, DRAG_SCROLL, COMBO_END};
combo_t key_combos[] = {COMBO(swap_handedness, TG(L_LEFT))};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_RIGHT] = LAYOUT(KC_BTN4, KC_BTN5, DRAG_SCROLL, KC_BTN2, KC_BTN1, KC_BTN3),
    [L_LEFT] = LAYOUT(KC_BTN2, DRAG_SCROLL, KC_BTN5, KC_BTN4, KC_BTN3, KC_BTN1)
};
