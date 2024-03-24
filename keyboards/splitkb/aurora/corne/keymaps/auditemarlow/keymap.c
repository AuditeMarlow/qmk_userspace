#include QMK_KEYBOARD_H

enum layers {
    U_BASE = 0,
    U_EXTRA,
    U_TAP,
    U_GAME,
    U_NAV,
    U_MOUSE,
    U_MEDIA,
    U_NUM,
    U_SYM,
    U_FUN
};

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

enum {
	G_1,
	G_2,
	G_3,
	G_4,
	G_5
};

int base = U_BASE;

#define L_BASE DF(U_BASE)
#define L_EXTRA DF(U_EXTRA)
#define L_TAP DF(U_TAP)
#define L_GAME DF(U_GAME)

// Layer keys
#define L_NAV LT(U_NAV, KC_SPC)
#define L_SPC LT(U_NAV, KC_SPC)
#define L_MOUSE LT(U_MOUSE, KC_TAB)
#define L_TAB LT(U_MOUSE, KC_TAB)
#define L_MEDIA LT(U_MEDIA, KC_ESC)
#define L_ESC LT(U_MEDIA, KC_ESC)
#define L_NUM LT(U_NUM, KC_BSPC)
#define L_BSPC LT(U_NUM, KC_BSPC)
#define L_SYM LT(U_SYM, KC_ENT)
#define L_ENT LT(U_SYM, KC_ENT)
#define L_FUN LT(U_FUN, KC_DEL)
#define L_DEL LT(U_FUN, KC_DEL)

// Base layer home-row mod keys
#define LA_S MT(MOD_LALT, KC_S)
#define LC_D MT(MOD_LCTL, KC_D)
#define LG_A MT(MOD_LGUI, KC_A)
#define LS_F MT(MOD_LSFT, KC_F)
#define RA_L MT(MOD_RALT, KC_L)
#define RC_K MT(MOD_RCTL, KC_K)
#define RG_QUOT MT(MOD_RGUI, KC_QUOT)
#define RS_J MT(MOD_RSFT, KC_J)

// Extra layer home-row mod keys
#define LA_R MT(MOD_LALT, KC_R)
#define LC_S MT(MOD_LCTL, KC_S)
#define LG_A MT(MOD_LGUI, KC_A)
#define LS_T MT(MOD_LSFT, KC_T)
#define RA_I MT(MOD_RALT, KC_I)
#define RC_E MT(MOD_RCTL, KC_E)
#define RG_O MT(MOD_RGUI, KC_O)
#define RS_N MT(MOD_RSFT, KC_N)

#define U_RDO KC_AGIN
#define U_PST S(KC_INS)
#define U_CPY C(KC_INS)
#define U_CUT S(KC_DEL)
#define U_UND KC_UNDO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base
     *
     *.-----------------------------------------------------,                          ,-----------------------------------------------------.
     *|        | Q      | W      | E      | R      | T      |                          | Y      | U      | I      | O      | P      | Game   |
     *|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
     *|        | A      | S      | D      | F      | G      |                          | H      | J      | K      | L      | '      |        |
     *|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
     *|        | Z      | X      | C      | V      | B      |                          | N      | M      | ,      | .      | /      |        |
     *'-----------------------------------+--------+--------+--------,        ,--------+--------+--------+-----------------------------------'
     *                                    | Esc    | Space  | Tab    |        | Enter  | Bspc   | Delete |
     *                                    '--------------------------'        '--------------------------'
     */
    [U_BASE] = LAYOUT_split_3x6_3(
        _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    L_GAME,
        _______, LG_A,    LA_S,    LC_D,    LS_F,    KC_G,                               KC_H,    RS_J,    RC_K,    RA_L,    RG_QUOT, _______,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                                            L_ESC,   L_SPC,   L_TAB,            L_ENT,   L_BSPC,  L_DEL
    ),

    /* Extra
     *
     *.-----------------------------------------------------,                          ,-----------------------------------------------------.
     *|        | Q      | W      | F      | P      | B      |                          | J      | L      | U      | Y      | '      | Game   |
     *|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
     *|        | A      | R      | S      | T      | G      |                          | M      | N      | E      | I      | O      |        |
     *|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
     *|        | Z      | X      | C      | D      | V      |                          | K      | H      | ,      | .      | /      |        |
     *'-----------------------------------+--------+--------+--------,        ,--------+--------+--------+-----------------------------------'
     *                                    | Esc    | Space  | Tab    |        | Enter  | Bspc   | Delete |
     *                                    '--------------------------'        '--------------------------'
     */
    [U_EXTRA] = LAYOUT_split_3x6_3(
        _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, L_GAME,
        _______, LG_A,    LA_R,    LC_S,    LS_T,    KC_G,                               KC_M,    RS_N,    RC_E,    RA_I,    RG_O,    _______,
        _______, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                               KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                                            L_ESC,   L_SPC,   L_TAB,            L_ENT,   L_BSPC,  L_DEL
    ),

    /* Tap
     *
     *.-----------------------------------------------------,                          ,-----------------------------------------------------.
     *|        | Q      | W      | E      | R      | T      |                          | Y      | U      | I      | O      | P      |        |
     *|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
     *|        | A      | S      | D      | F      | G      |                          | H      | J      | K      | L      | '      |        |
     *|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
     *|        | Z      | X      | C      | V      | B      |                          | N      | M      | ,      | .      | /      |        |
     *'-----------------------------------+--------+--------+--------,        ,--------+--------+--------+-----------------------------------'
     *                                    | Esc    | Space  | Tab    |        | Enter  | Bspc   | Delete |
     *                                    '--------------------------'        '--------------------------'
     */
    [U_TAP] = LAYOUT_split_3x6_3(
        _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    L_BASE,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, _______,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                                            KC_ESC,  KC_SPC,  KC_TAB,           KC_ENT,  KC_BSPC, KC_DEL
    ),

    /* Game
     *
     *.-----------------------------------------------------,                          ,-----------------------------------------------------.
     *| Tab    | Q      | W      | E      | R      | T      |                          | Y      | U      | I      | O      | P      | Base   |
     *|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
     *| Escape | A      | S      | D      | F      | G      |                          | H      | J      | K      | L      | '      |        |
     *|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
     *| Shift  | 1      | 2      | 3      | 4      | 5      |                          | N      | M      | ,      | .      | /      |        |
     *'-----------------------------------+--------+--------+--------,        ,--------+--------+--------+-----------------------------------'
     *                                    | Ctrl   | Space  | C      |        | Enter  | Bspc   | Delete |
     *                                    '--------------------------'        '--------------------------'
     */
    [U_GAME] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     L_BASE,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT,  _______,
        KC_LSFT, TD(G_1), TD(G_2), TD(G_3), TD(G_4), TD(G_5),                            KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  _______,
                                            KC_LCTL, KC_SPC,  KC_C,             KC_ENT,  KC_BSPC, KC_DEL
    ),

    /* Nav
     *
     *.-----------------------------------------------------,                          ,-----------------------------------------------------.
     *|        | Boot   | Tap    | Extra  | Base   |        |                          | Redo   | Paste  | Copy   | Cut    | Undo   |        |
     *|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
     *|        | GUI    | Alt    | Ctrl   | Shift  |        |                          | Left   | Down   | Up     | Right  | CapsL  |        |
     *|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
     *|        |        |        |        |        |        |                          | Home   | PgDwn  | PgUp   | End    | Insert |        |
     *'-----------------------------------+--------+--------+--------,        ,--------+--------+--------+-----------------------------------'
     *                                    |        |        |        |        | Enter  | Bspc   | Delete |
     *                                    '--------------------------'        '--------------------------'
     */
    [U_NAV] = LAYOUT_split_3x6_3(
        _______, QK_BOOT, L_TAP,   L_EXTRA, L_BASE,  _______,                            U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,   _______,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CAPS, _______,
        _______, _______, _______, _______, _______, _______,                            KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,  _______,
                                            _______, _______, _______,          KC_ENT,  KC_BSPC, KC_DEL
    ),

    /* Mouse
     *
     *.-----------------------------------------------------,                          ,-----------------------------------------------------.
     *|        | Boot   | Tap    | Extra  | Base   |        |                          | Redo   | Paste  | Copy   | Cut    | Undo   |        |
     *|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
     *|        | GUI    | Alt    | Ctrl   | Shift  |        |                          | MLeft  | MDown  | MUp    | MRight |        |        |
     *|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
     *|        |        |        |        |        |        |                          | WLeft  | WDown  | WUp    | WRight |        |        |
     *'-----------------------------------+--------+--------+--------,        ,--------+--------+--------+-----------------------------------'
     *                                    |        |        |        |        | Btn2   | Btn1   | Btn3   |
     *                                    '--------------------------'        '--------------------------'
     */
    [U_MOUSE] = LAYOUT_split_3x6_3(
        _______, QK_BOOT, L_TAP,   L_EXTRA, L_BASE,  _______,                            U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,   _______,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                            KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
        _______, _______, _______, _______, _______, _______,                            KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______,
                                            _______, _______, _______,          KC_BTN2, KC_BTN1, KC_BTN3
    ),

    /* Media
     *
     *.-----------------------------------------------------,                          ,-----------------------------------------------------.
     *|        | Boot   | Tap    | Extra  | Base   |        |                          | Redo   | Paste  | Copy   | Cut    | Undo   |        |
     *|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
     *|        | GUI    | Alt    | Ctrl   | Shift  |        |                          | Left   | Down   | Up     | Right  |        |        |
     *|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
     *|        |        |        |        |        |        |                          |        |        |        |        |        |        |
     *'-----------------------------------+--------+--------+--------,        ,--------+--------+--------+-----------------------------------'
     *                                    |        |        |        |        | MStop  | MPlay  | Mute   |
     *                                    '--------------------------'        '--------------------------'
     */
    [U_MEDIA] = LAYOUT_split_3x6_3(
        _______, QK_BOOT, L_TAP,   L_EXTRA, L_BASE,  _______,                            U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,   _______,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                            KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______, _______,
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______,          KC_MSTP, KC_MPLY, KC_MUTE
    ),

    /* Num
     *
     *.-----------------------------------------------------,                          ,-----------------------------------------------------.
     *|        | [      | 7      | 8      | 9      | ]      |                          |        | Base   | Extra  | Tap    | Boot   |        |
     *|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
     *|        | ;      | 4      | 5      | 6      | =      |                          |        | Shift  | Ctrl   | Alt    | GUI    |        |
     *|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
     *|        | `      | 1      | 2      | 3      | \      |                          |        |        |        |        |        |        |
     *'-----------------------------------+--------+--------+--------,        ,--------+--------+--------+-----------------------------------'
     *                                    | .      | 0      | -      |        |        |        |        |
     *                                    '--------------------------'        '--------------------------'
     */
    [U_NUM] = LAYOUT_split_3x6_3(
        _______, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,                            _______, L_BASE,  L_EXTRA, L_TAP,   QK_BOOT, _______,
        _______, KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,                             _______, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,
        _______, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS,                            _______, _______, _______, _______, _______, _______,
                                            KC_DOT,  KC_0,    KC_MINS,          _______, _______, _______
    ),

    /* Sym
     *
     *.-----------------------------------------------------,                          ,-----------------------------------------------------.
     *|        | {      | &      | *      | (      | }      |                          |        | Base   | Extra  | Tap    | Boot   |        |
     *|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
     *|        | :      | $      | %      | ^      | +      |                          |        | Shift  | Ctrl   | Alt    | GUI    |        |
     *|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
     *|        | ~      | !      | @      | #      | |      |                          |        |        |        |        |        |        |
     *'-----------------------------------+--------+--------+--------,        ,--------+--------+--------+-----------------------------------'
     *                                    | (      | )      | _      |        |        |        |        |
     *                                    '--------------------------'        '--------------------------'
     */
    [U_SYM] = LAYOUT_split_3x6_3(
        _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                            _______, L_BASE,  L_EXTRA, L_TAP,   QK_BOOT, _______,
        _______, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                            _______, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,
        _______, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,                            _______, _______, _______, _______, _______, _______,
                                            KC_LPRN, KC_RPRN, KC_UNDS,          _______, _______, _______
    ),

    /* Fun
     *
     *.-----------------------------------------------------,                          ,-----------------------------------------------------.
     *|        | F12    | F7     | F8     | F9     | PrSrc  |                          |        | Base   | Extra  | Tap    | Boot   |        |
     *|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
     *|        | F11    | F4     | F5     | F6     | Scroll |                          |        | Shift  | Ctrl   | Alt    | GUI    |        |
     *|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
     *|        | F10    | F1     | F2     | F3     | Pause  |                          |        |        |        |        |        |        |
     *'-----------------------------------+--------+--------+--------,        ,--------+--------+--------+-----------------------------------'
     *                                    | App    | Space  | Tab    |        |        |        |        |
     *                                    '--------------------------'        '--------------------------'
     */
    [U_FUN] = LAYOUT_split_3x6_3(
        _______, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,                            _______, L_BASE,  L_EXTRA, L_TAP,   QK_BOOT, _______,
        _______, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL,                            _______, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,
        _______, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS,                            _______, _______, _______, _______, _______, _______,
                                            KC_APP,  KC_SPC,  KC_TAB,           _______, _______, _______
    )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	tap_dance_action_t *action;

	switch (keycode) {
		// Layer keys
		case L_BASE:
			if (record->event.pressed) {
				base = U_BASE;
			}
			return true;
		case L_EXTRA:
			if (record->event.pressed) {
				base = U_EXTRA;
			}
			return true;
		case L_TAP:
			if (record->event.pressed) {
				base = U_TAP;
			}
			return true;
		case L_GAME:
			if (record->event.pressed) {
				base = U_GAME;
			}
			return true;

		// Tap dance keys
		case TD(G_1):
		case TD(G_2):
		case TD(G_3):
		case TD(G_4):
		case TD(G_5):
			action = &tap_dance_actions[TD_INDEX(keycode)];
			if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
	}

	return true;
}

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

tap_dance_action_t tap_dance_actions[] = {
	[G_1] = ACTION_TAP_DANCE_TAP_HOLD(KC_1, KC_Z),
	[G_2] = ACTION_TAP_DANCE_TAP_HOLD(KC_2, KC_X),
	[G_3] = ACTION_TAP_DANCE_TAP_HOLD(KC_3, KC_C),
	[G_4] = ACTION_TAP_DANCE_TAP_HOLD(KC_4, KC_V),
	[G_5] = ACTION_TAP_DANCE_TAP_HOLD(KC_5, KC_B),
};

#ifdef OLED_ENABLE
static void render_layer_state(void) {
    static const char PROGMEM base_layer[] = {
        0x20, 0x9d, 0x9e, 0x9f, 0x20,
        0x20, 0xbd, 0x9c, 0xbf, 0x20,
        0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
    static const char PROGMEM extra_layer[] = {
        0x20, 0x9d, 0x9e, 0x9f, 0x20,
        0x20, 0xbd, 0xdb, 0xbf, 0x20,
        0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
    static const char PROGMEM tap_layer[] = {
        0x20, 0x9d, 0x9e, 0x9f, 0x20,
        0x20, 0xbd, 0xda, 0xbf, 0x20,
        0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
    static const char PROGMEM game_layer[] = {
        0x20, 0x9d, 0x9e, 0x9f, 0x20,
        0x20, 0xbd, 0xdc, 0xbf, 0x20,
        0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
    static const char PROGMEM num_layer[] = {
        0x20, 0x9d, 0x9e, 0x9f, 0x20,
        0x20, 0xbd, 0xbc, 0xbf, 0x20,
        0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
    static const char PROGMEM sym_layer[] = {
        0x20, 0x9d, 0x9e, 0x9f, 0x20,
        0x20, 0xbd, 0xbb, 0xbf, 0x20,
        0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
    static const char PROGMEM nav_layer[] = {
        0x20, 0x9d, 0x9e, 0x9f, 0x20,
        0x20, 0xbd, 0xbe, 0xbf, 0x20,
        0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
	static const char PROGMEM mouse_layer[] = {
		0x20, 0x9d, 0x9e, 0x9f, 0x20,
		0x20, 0xbd, 0x9b, 0xbf, 0x20,
		0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
	static const char PROGMEM fun_layer[] = {
		0x20, 0x9d, 0x9e, 0x9f, 0x20,
		0x20, 0xbd, 0x9a, 0xbf, 0x20,
		0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
	static const char PROGMEM media_layer[] = {
		0x20, 0x9d, 0x9e, 0x9f, 0x20,
		0x20, 0xbd, 0xba, 0xbf, 0x20,
		0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
    if (layer_state_is(U_BASE)) {
		if (base == U_BASE) {
			oled_write_P(base_layer, false);
		} else if (base == U_EXTRA) {
			oled_write_P(extra_layer, false);
		} else if (base == U_TAP) {
			oled_write_P(tap_layer, false);
		} else if (base == U_GAME) {
			oled_write_P(game_layer, false);
		}
    } else if (layer_state_is(U_NUM)) {
        oled_write_P(num_layer, false);
    } else if (layer_state_is(U_SYM)) {
        oled_write_P(sym_layer, false);
    } else if (layer_state_is(U_NAV)) {
        oled_write_P(nav_layer, false);
    } else if (layer_state_is(U_MOUSE)) {
        oled_write_P(mouse_layer, false);
    } else if (layer_state_is(U_FUN)) {
        oled_write_P(fun_layer, false);
    } else if (layer_state_is(U_MEDIA)) {
        oled_write_P(media_layer, false);
    }
}

static void render_mod_status_gui_alt(uint8_t modifiers) {
    static const char PROGMEM gui_off_1[] = {0x85, 0x86, 0};
    static const char PROGMEM gui_off_2[] = {0xa5, 0xa6, 0};
    static const char PROGMEM gui_on_1[] = {0x8d, 0x8e, 0};
    static const char PROGMEM gui_on_2[] = {0xad, 0xae, 0};

    static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
    static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
    static const char PROGMEM alt_on_1[] = {0x8f, 0x90, 0};
    static const char PROGMEM alt_on_2[] = {0xaf, 0xb0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_1, false);
    } else {
        oled_write_P(gui_off_1, false);
    }

    if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_1, false);
    } else {
        oled_write_P(alt_off_1, false);
    }

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_2, false);
    } else {
        oled_write_P(gui_off_2, false);
    }

    if (modifiers & MOD_MASK_GUI & MOD_MASK_ALT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_2, false);
    } else {
        oled_write_P(alt_off_2, false);
    }
}

static void render_mod_status_ctrl_shift(uint8_t modifiers) {
    static const char PROGMEM ctrl_off_1[] = {0x89, 0x8a, 0};
    static const char PROGMEM ctrl_off_2[] = {0xa9, 0xaa, 0};
    static const char PROGMEM ctrl_on_1[] = {0x91, 0x92, 0};
    static const char PROGMEM ctrl_on_2[] = {0xb1, 0xb2, 0};

    static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
    static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
    static const char PROGMEM shift_on_1[] = {0xcd, 0xce, 0};
    static const char PROGMEM shift_on_2[] = {0xcf, 0xd0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_1, false);
    } else {
        oled_write_P(ctrl_off_1, false);
    }

    if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_1, false);
    } else {
        oled_write_P(shift_off_1, false);
    }

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_2, false);
    } else {
        oled_write_P(ctrl_off_2, false);
    }

    if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_2, false);
    } else {
        oled_write_P(shift_off_2, false);
    }
}
static void render_aurora_art(void) {
	// clang-format off
	static const char PROGMEM aurora_art[] = {
		0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x1c, 0x08, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x40,
		0xe0, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x80,
		0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x80, 0x00, 0xf0, 0x00, 0x00, 0xc0,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00,
		0x81, 0x00, 0xc0, 0x00, 0xfe, 0x00, 0xfc, 0x00, 0xff, 0x20, 0xff, 0xf0, 0x0f, 0xf0, 0x00, 0xff,
		0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0x00, 0xf8, 0x00, 0x00, 0xf8,
		0xff, 0x10, 0xff, 0x84, 0xff, 0x60, 0xff, 0x36, 0xff, 0x0f, 0xff, 0x3f, 0x00, 0x5f, 0x00, 0x05,
		0x80, 0x00, 0x80, 0x00, 0xc0, 0x38, 0x00, 0xec, 0xf0, 0x00, 0xfb, 0x80, 0xff, 0xf0, 0xff, 0xef,
		0xff, 0xe8, 0xff, 0x03, 0xff, 0x0c, 0xff, 0x00, 0xff, 0x00, 0x03, 0x00, 0x00, 0xf8, 0x00, 0x80,
		0xff, 0x20, 0xff, 0xd0, 0xff, 0xe0, 0xfe, 0xf8, 0xff, 0xfc, 0xff, 0xff, 0x0f, 0xff, 0x01, 0x3f,
		0xff, 0x00, 0x0f, 0x00, 0x01, 0x00, 0x03, 0x00, 0xfe, 0x80, 0xfe, 0x00, 0xc0, 0xff, 0xc4, 0xfb,
		0xff, 0xfe, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0x07, 0xff, 0x03, 0x3f, 0x00, 0x0f, 0xc0, 0x00,
		0x00, 0x00, 0xb8, 0x00, 0xff, 0x40, 0xbe, 0xf0, 0xff, 0xf1, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff,
		0x1f, 0xff, 0x67, 0x00, 0xef, 0x00, 0x1f, 0x00, 0x00, 0x07, 0x00, 0x00, 0xe0, 0x00, 0xff, 0xf0,
		0xff, 0x88, 0xff, 0xc4, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0x7f, 0x0f, 0xff,
		0x00, 0x07, 0xfe, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x00, 0xc0, 0x3f, 0xf8, 0xe7, 0xff,
		0xff, 0xff, 0xff, 0x1f, 0xff, 0xff, 0x1f, 0x3f, 0x01, 0xff, 0x0b, 0x00, 0xff, 0x00, 0x00, 0x05,
		0x00, 0x00, 0x00, 0xe0, 0x00, 0xf8, 0x60, 0x80, 0xfe, 0xe3, 0xfc, 0xff, 0x1e, 0xff, 0xff, 0x23,
		0xff, 0x09, 0xff, 0x20, 0x00, 0x3f, 0x02, 0x00, 0x00, 0x0f, 0x00, 0x40, 0x00, 0xc0, 0x00, 0xfc,
		0xe0, 0xfc, 0xf0, 0xff, 0xff, 0x7f, 0xfc, 0xff, 0x0f, 0xff, 0x07, 0x1f, 0x00, 0x01, 0x0f, 0x00,
		0x0f, 0x00, 0x81, 0x70, 0x0c, 0xf0, 0x80, 0x00, 0x00, 0xe4, 0xf8, 0xe6, 0x70, 0x3f, 0xcf, 0xff,
		0x1f, 0xff, 0x48, 0xff, 0x0f, 0x00, 0x07, 0x00, 0x00, 0x43, 0x60, 0xf8, 0xf0, 0xfe, 0x38, 0xfe,
		0x00, 0xfc, 0x03, 0x00, 0xc8, 0x72, 0xcf, 0xfc, 0x00, 0x03, 0x0f, 0x01, 0xe0, 0x1c, 0xe0, 0x03,
		0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x06, 0xf9, 0x00, 0x03, 0x00, 0x07,
		0xff, 0x00, 0x10, 0x12, 0xc9, 0xf0, 0xcf, 0xb4, 0x7f, 0x80, 0xe0, 0x1e, 0x01, 0x40, 0x65, 0x5e,
		0xe0, 0x00, 0x00, 0xf0, 0x0c, 0xf0, 0x00, 0x80, 0x7e, 0x01, 0x80, 0x93, 0xfc, 0xc0, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x89, 0x18, 0x2c, 0x46, 0x00, 0x07, 0x21, 0x10, 0x10, 0x80, 0x09, 0x13,
		0x31, 0xbf, 0xff, 0x00, 0x08, 0x1a, 0xf7, 0x0f, 0x00, 0x00, 0x44, 0x45, 0x34, 0xbf, 0xb8, 0x00,
		0x10, 0xf0, 0x08, 0xf4, 0x18, 0x11, 0xfc, 0x18, 0xfb, 0x0e, 0x10, 0xf8, 0x04, 0xf8, 0x10, 0x20,
		0x18, 0x09, 0xff, 0x0c, 0xea, 0x1f, 0x28, 0x60, 0x30, 0xf8, 0x20, 0xc0, 0x42, 0x33, 0x21, 0x00
	};
	// clang-format on

	oled_write_raw_P(aurora_art, sizeof(aurora_art));
}

bool oled_task_user(void) {
	if (is_keyboard_master()) {
		render_layer_state();
        render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
        render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
	} else {
		render_aurora_art();
	}
	return false;
}
#endif
