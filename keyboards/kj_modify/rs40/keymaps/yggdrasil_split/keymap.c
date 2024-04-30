// Copyright 2023 Audite Marlow (@auditemarlow)
// SPDX-License-Identifier: GPL-3.0

#include QMK_KEYBOARD_H

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum layers {
	L0,
	L1,
	L2,
	L3
};

enum tap_dance_codes {
	TD_BSLS,
	TD_COMM,
	TD_DOT,
	TD_PIPE,
	TD_QUOT,
	TD_SLSH
};

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state = {
    .is_press_action = true,
    .step = 0
};

#define BWD LGUI(KC_LBRC)
#define CTRL OSM(MOD_RCTL)
#define D MT(MOD_LALT, KC_D)
#define F MT(MOD_LGUI, KC_F)
#define FWD LGUI(KC_RBRC)
#define J MT(MOD_RGUI, KC_J)
#define K MT(MOD_RALT, KC_K)
#define NTAB RCTL(KC_TAB)
#define PTAB LCTL(LSFT(KC_TAB))
#define SHIFT OSM(MOD_LSFT)
#define SPACE MT(MOD_MEH, KC_SPC)

#define BSLS TD(TD_BSLS)
#define COMM TD(TD_COMM)
#define DOT TD(TD_DOT)
#define PIPE TD(TD_PIPE)
#define QUOT TD(TD_QUOT)
#define SLSH TD(TD_SLSH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* L0
 * .-----------------------------------------------------------------------------------------------.
 * | Q     | W     | E     | R     | T     |       | Y     | U     | I     | O     | P     | Bspc  |
 * |-----------------------------------------------------------------------------------------------|
 * | A       | S     | D     | F     | G     |       | H     | J     | K     | L     | Return      |
 * |-----------------------------------------------------------------------------------------------|
 * | Z           | X     | C     | V     | B     |       | N     | M     | ,     | .     | /       |
 * |-----------------------------------------------------------------------------------------------|
 * |         |       | Shift   | Space           | L1                 | Ctrl     |       |         |
 * '-----------------------------------------------------------------------------------------------'
 */
[L0] = LAYOUT(
	KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
	KC_A,    KC_S,    D,       F,       KC_G,    _______, KC_H,    J,       K,       KC_L,             KC_ENT,
	         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, KC_N,    KC_M,    COMM,    DOT,     SLSH,
	_______, _______, SHIFT,            SPACE,                     TO(L1),           CTRL,    _______, _______
),

/* L1
 * .-----------------------------------------------------------------------------------------------.
 * | Tab   | @     | #     | $     | %     |       | ^     | &     | *     | ;     | :     |       |
 * |-----------------------------------------------------------------------------------------------|
 * | Escape  | =     |       |       | '     |       | \     | {     | }     | |     | Return      |
 * |-----------------------------------------------------------------------------------------------|
 * | ~           |       |       |       | "     |       | [     | (     | )     | ]     | L3      |
 * |-----------------------------------------------------------------------------------------------|
 * |         |       | Shift   | L0              | L2                 | Alt      |       |         |
 * '-----------------------------------------------------------------------------------------------'
 */
[L1] = LAYOUT(
	KC_TAB,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_SCLN, KC_COLN, _______,
	KC_ESC,  KC_EQL,  _______, _______, QUOT,    _______, BSLS,    KC_LCBR, KC_RCBR, PIPE,             KC_ENT,
	KC_TILD,          _______, _______, _______, KC_DQUO, _______, KC_LBRC, KC_LPRN, KC_RPRN, KC_RBRC, TO(L3),
	_______, _______, SHIFT,            TO(L0),                    TO(L2),           KC_RALT, _______, QK_BOOT
),

/* L2
 * .-----------------------------------------------------------------------------------------------.
 * | Tab   | MPlay | MNext | MPrev | _     |       | -     | 7     | 8     | 9     |       |       |
 * |-----------------------------------------------------------------------------------------------|
 * | Escape  |       | VolD  | VolU  | +     |       | =     | 4     | 5     | 6     | Return      |
 * |-----------------------------------------------------------------------------------------------|
 * |             | *     |       |       | .     |       | 0     | 1     | 2     | 3     |         |
 * |-----------------------------------------------------------------------------------------------|
 * |         |       |         | L0              | L3                 | Alt      |       |         |
 * '-----------------------------------------------------------------------------------------------'
 */
[L2] = LAYOUT(
	KC_TAB,  KC_MPLY, KC_MPRV, KC_MNXT, KC_UNDS, _______, KC_MINS, KC_7,    KC_8,    KC_9,    _______, _______,
	KC_ESC,  _______, KC_VOLD, KC_VOLU, KC_PLUS, _______, KC_EQL,  KC_4,    KC_5,    KC_6,             KC_ENT,
	_______,          KC_PAST, _______, _______, KC_PDOT, _______, KC_0,    KC_1,    KC_2,    KC_3,    _______,
	_______, _______, KC_LGUI,          TO(L0),                    TO(L3),           KC_RALT, _______, _______
),

/* L3
 * .-----------------------------------------------------------------------------------------------.
 * | Tab   | ScLft | MUp   | ScRgt |       |       | Bwd   | PTab  | NTab  | Fwd   | Bspc  |       |
 * |-----------------------------------------------------------------------------------------------|
 * | Escape  | MLeft | MDown | MRght | Del   |       | Left  | Down  | Up    | Right | Return      |
 * |-----------------------------------------------------------------------------------------------|
 * | `           |       | ScUp  | ScDwn | LClck |       | RClck | Acl0  | Acl1  | Acl2  |         |
 * |-----------------------------------------------------------------------------------------------|
 * |         |       |         | L0              | L1                 | Alt      |       |         |
 * '-----------------------------------------------------------------------------------------------'
 */
[L3] = LAYOUT(
	KC_TAB,  KC_WH_L, KC_MS_U, KC_WH_R, _______, _______, BWD,     PTAB,    NTAB,    FWD,     KC_BSPC, _______,
	KC_ESC,  KC_MS_L, KC_MS_D, KC_MS_R, KC_DEL,  _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,          KC_ENT,
	KC_GRV,           _______, KC_WH_U, KC_WH_D, KC_BTN2, _______, KC_BTN1, KC_ACL0, KC_ACL1, KC_ACL2, _______,
	_______, _______, _______,          TO(L0),                    TO(L1),           KC_RALT, _______, _______
)

};

void dance_default_each(tap_dance_state_t *state, void *user_data, uint16_t kc_tap) {
	if(state->count == 3) {
        tap_code16(kc_tap);
        tap_code16(kc_tap);
        tap_code16(kc_tap);
    }
    if(state->count > 3) {
        tap_code16(kc_tap);
    }
}

uint8_t dance_default_step(tap_dance_state_t *state) {
	if (state->count == 1) {
		if (state->interrupted || !state->pressed) return SINGLE_TAP;
		else return SINGLE_HOLD;
	} else if (state->count == 2) {
		if (state->interrupted) return DOUBLE_SINGLE_TAP;
		else if (state->pressed) return DOUBLE_HOLD;
		else return DOUBLE_TAP;
	}
	return MORE_TAPS;
}

void dance_default_finished(tap_dance_state_t *state, void *user_data, uint16_t kc_tap, uint16_t kc_hold) {
	dance_state.step = dance_default_step(state);
	switch (dance_state.step) {
		case SINGLE_TAP: register_code16(kc_tap); break;
		case SINGLE_HOLD: register_code16(kc_hold); break;
		case DOUBLE_TAP: register_code16(kc_tap); register_code16(kc_tap); break;
		case DOUBLE_SINGLE_TAP: tap_code16(kc_tap); register_code16(kc_tap);
	}
}

void dance_default_reset(tap_dance_state_t *state, void *user_data, uint16_t kc_tap, uint16_t kc_hold) {
	wait_ms(10);
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(kc_tap); break;
		case SINGLE_HOLD: unregister_code16(kc_hold); break;
		case DOUBLE_TAP: unregister_code16(kc_tap); break;
		case DOUBLE_SINGLE_TAP: unregister_code16(kc_tap); break;
	}
	dance_state.step = 0;
}

void dance_bsls_each(tap_dance_state_t *state, void *user_data) {
	dance_default_each(state, NULL, KC_BSLS);
}
void dance_bsls_finished(tap_dance_state_t *state, void *user_data) {
	dance_default_finished(state, NULL, KC_BSLS, KC_HOME);
}
void dance_bsls_reset(tap_dance_state_t *state, void *user_data) {
	dance_default_reset(state, NULL, KC_BSLS, KC_HOME);
}

void dance_comm_each(tap_dance_state_t *state, void *user_data) {
	dance_default_each(state, NULL, KC_COMM);
}
void dance_comm_finished(tap_dance_state_t *state, void *user_data) {
	dance_default_finished(state, NULL, KC_COMM, KC_MINS);
}
void dance_comm_reset(tap_dance_state_t *state, void *user_data) {
	dance_default_reset(state, NULL, KC_COMM, KC_MINS);
}

void dance_dot_each(tap_dance_state_t *state, void *user_data) {
	dance_default_each(state, NULL, KC_DOT);
}
void dance_dot_finished(tap_dance_state_t *state, void *user_data) {
	dance_default_finished(state, NULL, KC_DOT, KC_EXLM);
}
void dance_dot_reset(tap_dance_state_t *state, void *user_data) {
	dance_default_reset(state, NULL, KC_DOT, KC_EXLM);
}

void dance_pipe_each(tap_dance_state_t *state, void *user_data) {
	dance_default_each(state, NULL, KC_PIPE);
}
void dance_pipe_finished(tap_dance_state_t *state, void *user_data) {
	dance_default_finished(state, NULL, KC_PIPE, KC_END);
}
void dance_pipe_reset(tap_dance_state_t *state, void *user_data) {
	dance_default_reset(state, NULL, KC_PIPE, KC_END);
}

void dance_quot_each(tap_dance_state_t *state, void *user_data) {
	dance_default_each(state, NULL, KC_QUOT);
}
void dance_quot_finished(tap_dance_state_t *state, void *user_data) {
	dance_default_finished(state, NULL, KC_QUOT, KC_GRV);
}
void dance_quot_reset(tap_dance_state_t *state, void *user_data) {
	dance_default_reset(state, NULL, KC_QUOT, KC_GRV);
}

void dance_slsh_each(tap_dance_state_t *state, void *user_data) {
	dance_default_each(state, NULL, KC_SLSH);
}
void dance_slsh_finished(tap_dance_state_t *state, void *user_data) {
	dance_default_finished(state, NULL, KC_SLSH, KC_UNDS);
}
void dance_slsh_reset(tap_dance_state_t *state, void *user_data) {
	dance_default_reset(state, NULL, KC_SLSH, KC_UNDS);
}

tap_dance_action_t tap_dance_actions[] = {
	[TD_BSLS] = ACTION_TAP_DANCE_FN_ADVANCED(dance_bsls_each, dance_bsls_finished, dance_bsls_reset),
	[TD_COMM] = ACTION_TAP_DANCE_FN_ADVANCED(dance_comm_each, dance_comm_finished, dance_comm_reset),
	[TD_DOT] = ACTION_TAP_DANCE_FN_ADVANCED(dance_dot_each, dance_dot_finished, dance_dot_reset),
	[TD_PIPE] = ACTION_TAP_DANCE_FN_ADVANCED(dance_pipe_each, dance_pipe_finished, dance_pipe_reset),
	[TD_QUOT] = ACTION_TAP_DANCE_FN_ADVANCED(dance_quot_each, dance_quot_finished, dance_quot_reset),
	[TD_SLSH] = ACTION_TAP_DANCE_FN_ADVANCED(dance_slsh_each, dance_slsh_finished, dance_slsh_reset)
};
