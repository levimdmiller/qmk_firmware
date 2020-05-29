/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"
#include "keymap_steno.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _PLOVER,
  _PLO_QTY,
  _QWERTY,
  _ADJUST
};

#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Plover layer (http://opensteno.org)
     * ,-----------------------------------------------------------------------------------.
     * |  ESC |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   S  |   T  |   P  |   H  |  TAB |  ALT |   *  |   F  |   P  |   L  |   T  |   D  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   S  |   K  |   W  |   R  | STAB |  GUI |   *  |   R  |   B  |   G  |   S  |   Z  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |  SFT |   A  |   O  |ADJUST|   E  |   U  | Left |  Up  | Down |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_PLOVER] = LAYOUT_planck_grid(
      KC_ESC,    STN_N2,     STN_N3,  STN_N4,  STN_N5,       STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  STN_NC,
      STN_S1,    STN_TL,     STN_PL,  STN_HL,  KC_TAB,       KC_RALT, STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
      STN_S2,    STN_KL,     STN_WL,  STN_RL,  LSFT(KC_TAB), KC_LGUI, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
      XXXXXXX,   XXXXXXX,    KC_LSFT, STN_A,   STN_O,        ADJUST,  STN_E,   STN_U,   KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
    ),

    /* Plover layer (http://opensteno.org)
     * ,-----------------------------------------------------------------------------------.
     * |  ESC |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   S  |   T  |   P  |   H  |  TAB |  ALT |   *  |   F  |   P  |   L  |   T  |   D  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   S  |   K  |   W  |   R  | STAB |  GUI |   *  |   R  |   B  |   G  |   S  |   Z  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |  SFT |   A  |   O  |ADJUST|   E  |   U  | Left |  Up  | Down |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_PLO_QTY] = LAYOUT_planck_grid(
        KC_ESC,  KC_1,     KC_1,    KC_1,    KC_1,          KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,
        KC_Q,    KC_W,     KC_E,    KC_R,    KC_TAB,        KC_RALT, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
        KC_A,    KC_S,     KC_D,    KC_F,    LSFT(KC_TAB),  KC_LGUI, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        XXXXXXX, XXXXXXX,  KC_LSFT, KC_C,    KC_V,          ADJUST,  KC_N,    KC_M,    KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
    ),

    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Shift|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |Return| Esc  | Alt  | GUI  |ADJUST|    Space    |ADJUST| Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_planck_grid(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_ENT,  KC_ESC,  KC_LALT, KC_LGUI, ADJUST,  KC_SPC,  KC_SPC,  ADJUST,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

  /* Function/Cursor (FC)
     .--------.--------.--------.--------.--------.--------.--------.--------.--------.--------.--------.--------.
     |        |        |        |        | Plover | PloQty |        | Home   | Up     | End    | PgUp   |        |
     |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     |        |        |        |        | Qwerty |        |        | Left   | Down   | Right  | PgDn   |        |
     |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     |        |        |        |        |        |        |        | PScr   | Break  | ScLk   | Caps   |        |
     |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     |        |        |        |        |  XXXX  |  XXXX  |  XXXX  |        |        |        |        |        |
     '--------'--------'--------'--------'--------'--------'--------'--------'--------'--------'--------'--------'
  */
  [_ADJUST] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(_PLOVER), TO(_PLO_QTY), XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_PGUP, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(_QWERTY), XXXXXXX,      XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,      XXXXXXX, KC_PSCR, KC_BRK,  KC_SLCK, KC_CAPS, XXXXXXX,
    _______, _______, _______, XXXXXXX, _______,     _______,      _______, _______, _______, _______, _______, XXXXXXX
  )
};

void matrix_init_user() {
  steno_set_mode(STENO_MODE_GEMINI);
}
