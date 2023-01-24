#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE,  // default layer
    SYMB,  // symbols
    MDIA,  // media keys
};

#define HYPER (MOD_RGUI | MOD_RALT | MOD_RCTL)

enum custom_keycodes {
  EPRM = SAFE_RANGE,
  VRSN,
  RGB_SLD,
  PLUS_ONE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  | CS[  |           | CS]  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  `   |           | Ctrl |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | C/ Esc |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |  '/L2  |
 * |--------+------+------+------+------+------| Tab  |           |  =   |------+------+------+------+------+--------|
 * | LShift | Z/L1 |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  | //L1 | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  | Ctrl | Opt  | Cmd  |                                       |  Up  | Down |   [  |   ]  | ^A   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | TT(2)| ^A   |       | Left | Right  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Del  |       |      |        |      |
 *                                 | Bksp | LT 1 |------|       |------| Enter  | Spc  |
 *                                 |      |      | Cmd  |       | Cmd  |        |      |
 *                                 `--------------------'       `----------------------'
 */

[BASE] = LAYOUT_ergodox(
  // lh
  KC_TRNS           , KC_1        , KC_2          , KC_3          , KC_4          , KC_5 , LCMD(S(KC_LBRC)) ,
  KC_TAB            , KC_Q        , KC_W          , KC_E          , KC_R          , KC_T , KC_GRAVE ,
  LCTL_T(KC_ESCAPE) , KC_A        , KC_S          , KC_D          , KC_F          , KC_G ,
  KC_LSFT           , LT(1, KC_Z) , KC_X          , KC_C          , KC_V          , KC_B , KC_TAB   ,
  KC_GRAVE          , KC_QUOTE    , OSM(MOD_LCTL) , OSM(MOD_LALT) , OSM(MOD_LGUI) ,

                                                               TT(2),    LCTL(KC_A),
                                                                          KC_DELETE,
                                                    KC_BSPC,  OSL(1), OSM(MOD_LGUI),

  // rh
  RCMD(S(KC_RBRC))     , KC_6  , KC_7        , KC_8        , KC_9        , KC_0            , KC_MINUS   ,
  KC_RCTL              , KC_Y  , KC_U        , KC_I        , KC_O        , KC_P            , KC_BSLS    ,
                         KC_H  , KC_J        , KC_K        , KC_L        , KC_SCLN         , LT(2,KC_QUOTE) ,
  KC_EQUAL             , KC_N  , KC_M        , KC_COMMA    , KC_DOT      , LT(1,KC_SLASH)  , KC_RSFT  ,
                                 KC_DOWN     , KC_UP       , KC_LBRC     , KC_RBRC          , LCTL(KC_A) ,
  KC_LEFT       , KC_RIGHT ,
  KC_TRNS       ,
  OSM(HYPER)    , KC_ENTER , KC_SPACE
),

/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * | Esc     |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   ^  |   &  |   *  |   |  |   ~  |      |           |      |   (  |   =  |   )  |   *  |   +  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   !  |   @  |   #  |   $  |   %  |------|           |------|   {  |   -  |   }  |   >  |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   :  |   ^  |   [  |   ]  |   ~  |      |           |      |   [  |   _  |   ]  |   .  |   ?  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox(
  // lh
  KC_ESCAPE , KC_F1   , KC_F2   , KC_F3       , KC_F4   , KC_F5   , KC_TRNS ,
  KC_TRNS   , KC_CIRC , KC_AMPR , KC_ASTERISK , KC_PIPE , KC_TILD , KC_TRNS ,
  KC_TRNS   , KC_EXLM , KC_AT   , KC_HASH     , KC_DLR  , KC_PERC ,
  KC_TRNS   , KC_COLN , KC_CIRC , KC_LBRC     , KC_RBRC , KC_TILD , KC_NO   ,
  KC_TRNS   , KC_TRNS , KC_TRNS , KC_TRNS     , KC_TRNS ,
                                                          KC_TRNS ,  KC_TRNS,
                                                                     KC_TRNS,
                                                KC_TRNS , KC_TRNS , KC_TRNS,

  KC_TRNS , KC_F6       , KC_F7    , KC_F8       , KC_F9   , KC_F10  , KC_F11  ,
  KC_TRNS , KC_LPRN     , KC_EQUAL , KC_RPRN     , KC_ASTR , KC_PLUS , KC_F12  ,
            KC_LCBR     , KC_MINUS , KC_RCBR     , KC_RABK , KC_TRNS , KC_TRNS ,
  KC_TRNS , KC_LBRC     , KC_UNDS  , KC_RBRC     , KC_TRNS , KC_QUES , KC_TRNS ,
  KC_TRNS , KC_DOT      , KC_0     , KC_EQUAL    , KC_TRNS ,
  KC_TRNS , KC_TRNS,
  KC_TRNS ,
  KC_TRNS , KC_TRNS, KC_TRNS
),

/* Keymap 2: Vim-like + media
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  +1  |      |      |      |      |      |           |      |      |      |      |      |      |  RESET |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |vim w |vim e |      |      |      |           |      |vim  y|      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |cmd x |      |      |      |------|           |------| left | down |  up  |right |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |vim b |      |           | play | mute |voldn |volup |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       | prev | next |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = LAYOUT_ergodox(
  // lh
  KC_TRNS , PLUS_ONE, KC_TRNS        , KC_TRNS        , KC_TRNS    , KC_TRNS       , KC_TRNS ,
  KC_TRNS , KC_TRNS , LALT(KC_RIGHT) , LALT(KC_RIGHT) , KC_TRNS    , KC_TRNS       , KC_TRNS ,
  KC_TRNS , KC_TRNS , KC_TRNS        , LGUI(KC_X)     , KC_TRNS    , KC_TRNS       ,
  KC_TRNS , KC_TRNS , KC_TRNS        , KC_TRNS        , KC_TRNS    , LALT(KC_LEFT) , KC_TRNS ,
  KC_TRNS , KC_TRNS , KC_TRNS        , KC_MS_BTN1     , KC_MS_BTN2 ,
                                                                           KC_TRNS , KC_TRNS ,
                                                                                     KC_TRNS ,
                                                                 KC_TRNS , KC_TRNS , KC_TRNS ,

  //rh
  KC_TRNS , KC_TRNS    , KC_TRNS , KC_TRNS , KC_TRNS  , KC_TRNS    , QK_BOOT ,
  KC_TRNS , LGUI(KC_C) , KC_TRNS , KC_TRNS , KC_TRNS  , LGUI(KC_V) , KC_TRNS ,
            KC_LEFT    , KC_DOWN , KC_UP   , KC_RIGHT , KC_TRNS    , KC_MPLY ,
  KC_MPLY , KC_MUTE    , KC_VOLD , KC_VOLU , KC_TRNS  , KC_TRNS    , KC_TRNS ,
                         KC_TRNS , KC_TRNS , KC_TRNS  , KC_TRNS    , KC_AUDIO_MUTE ,
  KC_MPRV , KC_MNXT    ,
  KC_VOLU ,
  KC_VOLD , KC_TRNS    , KC_TRNS
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      case PLUS_ONE:
        SEND_STRING(":+1:");
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
