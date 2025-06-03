/*
Copyright 2024 SanderMar

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H

enum layers { _HOME, _NUMS, _SYMS, _NAV, _G0, _G1 };

#define KC_LALA LALT_T(KC_A)
#define KC_LGUR LGUI_T(KC_R)
#define KC_LCTS LCTL_T(KC_S)
#define KC_SFLT LSFT_T(KC_T)
#define KC_RSFN RSFT_T(KC_N)
#define KC_RCTE RCTL_T(KC_E)
#define KC_RGUI RGUI_T(KC_I)
#define KC_RALO RALT_T(KC_O)

#define KC_SFEQ LSFT_T(KC_EQL)

#define KC_TBLN LT(_NUMS, KC_TAB)
#define KC_ESLS LT(_SYMS, KC_ESC)

#define KC_GUPL LGUI_T(KC_MPLY)
#define KC_CTPR LCTL_T(KC_MPRV)
#define KC_SFNX LSFT_T(KC_MNXT)

#define KC_BACK LCTL(LSFT(KC_TAB))
#define KC_FWD LCTL(KC_TAB)

#define OSM_CTL OSM(MOD_LCTL)
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_ALT OSM(MOD_LALT)

#define OSL_NAV OSL(_NAV)

const uint16_t PROGMEM cb_lprn[] = {KC_SFLT, KC_D, COMBO_END};
const uint16_t PROGMEM cb_rprn[] = {KC_RSFN, KC_H, COMBO_END};
const uint16_t PROGMEM cb_lbrc[] = {KC_LCTS, KC_C, COMBO_END};
const uint16_t PROGMEM cb_rbrc[] = {KC_RCTE, KC_COMM, COMBO_END};
const uint16_t PROGMEM cb_lcbr[] = {KC_LGUR, KC_X, COMBO_END};
const uint16_t PROGMEM cb_rcbr[] = {KC_RGUI, KC_DOT, COMBO_END};
const uint16_t PROGMEM cb_quot[] = {KC_SFLT, KC_P, COMBO_END};
const uint16_t PROGMEM cb_dqt[]  = {KC_RSFN, KC_L, COMBO_END};
const uint16_t PROGMEM cb_eql[]  = {KC_RSFN, KC_M, COMBO_END};
const uint16_t PROGMEM cb_copy[] = {KC_D, KC_C, COMBO_END};
const uint16_t PROGMEM cb_past[] = {KC_D, KC_V, COMBO_END};
const uint16_t PROGMEM cb_esc[]  = {KC_SFLT, KC_RSFN, COMBO_END};
const uint16_t PROGMEM cb_ent[]  = {KC_TBLN, KC_BSPC, COMBO_END};

// clang-format off
combo_t key_combos[] = {
    COMBO(cb_lprn, KC_LPRN),
    COMBO(cb_rprn, KC_RPRN),
    COMBO(cb_lbrc, KC_LBRC),
    COMBO(cb_rbrc, KC_RBRC),
    COMBO(cb_lcbr, KC_LCBR),
    COMBO(cb_rcbr, KC_RCBR),
    COMBO(cb_quot, KC_QUOT),
    COMBO(cb_dqt,  KC_DQT),
    COMBO(cb_eql,  KC_EQL),
    COMBO(cb_copy, C(KC_C)),
    COMBO(cb_past, C(KC_V)),
    COMBO(cb_esc,  KC_ESC),
    COMBO(cb_ent,  KC_ENT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_HOME] = LAYOUT(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,            KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
    KC_LALA, KC_LGUR, KC_LCTS, KC_SFLT, KC_G,            KC_M,    KC_RSFN, KC_RCTE, KC_RGUI, KC_RALO,
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,            KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                                    KC_TBLN, KC_BSPC, KC_SPC, KC_ESLS
  ),

  [_NUMS] = LAYOUT(
    KC_PAST, KC_7,    KC_8,    KC_9,    KC_PMNS,         KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_0,    KC_1,    KC_2,    KC_3,    KC_PPLS,         KC_F6,   KC_SFEQ, OSM_CTL, OSM_GUI, OSM_ALT,
    KC_PSLS, KC_4,    KC_5,    KC_6,    KC_PDOT,         KC_F5,   KC_F4,   KC_F3,   KC_F2,   KC_F1,
                                    _______, _______, _______, OSL_NAV
  ),

  [_SYMS] = LAYOUT(
    _______, _______, KC_COLN, KC_LT,   KC_GT,           KC_PLUS, KC_DQT,  KC_QUOT, KC_BSLS, _______,
    KC_CIRC, KC_LCBR, KC_LBRC, KC_LPRN, KC_AMPR,         KC_HASH, KC_MINS, KC_UNDS, KC_SLSH, KC_DLR,
    KC_EXLM, KC_RCBR, KC_RBRC, KC_RPRN, KC_AT,           KC_PERC, KC_TILD, KC_GRV,  KC_PIPE, KC_ASTR,
                                    OSL_NAV, _______, _______, _______
  ),

  [_NAV] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU, XXXXXXX,         KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, KC_PSCR,
    KC_LALT, KC_GUPL, KC_CTPR, KC_SFNX, KC_MUTE,         KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DEL,
    TO(_G0), KC_CAPS, CW_TOGG, KC_VOLD, XXXXXXX,         KC_UP,   KC_LEFT, KC_APP,  XXXXXXX,  TO(_HOME),
                                    _______, KC_BACK, KC_FWD,  _______
  ),

  [_G0] = LAYOUT(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,            KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,
    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,            KC_G,    KC_H,    KC_J,    KC_K,    KC_L,
    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,            KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,
                                    OSL(_G1), KC_SPC, KC_ESC, KC_LGUI
  ),
  [_G1] = LAYOUT(
    _______, _______, _______, _______, KC_9,            _______, _______, _______, _______, _______,
    _______, KC_1,    KC_2,    KC_3,    KC_4,            _______, _______, _______, _______, _______,
    _______, KC_5,    KC_6,    KC_7,    KC_8,            _______, _______, _______, _______, TO(_HOME),
                                    _______, _______, _______,  _______
  )
};
