/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#pragma once

/* buncha shenanigans for dual-use keys */
#undef TAPPING_TERM
#define TAPPING_TERM 165

#undef IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD

/* online configurator sets this to 15, and cli default is 5. I like the old
 * better.
 */
#define DEBOUNCE 20

