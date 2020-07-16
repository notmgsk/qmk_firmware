/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#pragma once

#define TAPPING_TOGGLE  1

#define TAPPING_TERM    150
// this makes it possible to do rolling combos (zx) with keys that convert to
// other keys on hold (z becomes ctrl when you hold it, and when this option
// isn't enabled, z rapidly followed by x actually sends Ctrl-x. That's bad.)
#define IGNORE_MOD_TAP_INTERRUPT

#undef DEBOUNCE
#define DEBOUNCE 40

// The following is lifted from the thomasbaart config

#undef ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 200

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
#endif

#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_ANIMATIONS
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
  #define RGBLIGHT_SLEEP
#endif

// EC11K encoders have a different resolution than other EC11 encoders.
// When using the default resolution of 4, if you notice your encoder skipping
// every other tick, lower the resolution to 2.
// #define ENCODER_RESOLUTION 2

// The Leader key allows to flexibly assign macros to key sequences.
// #define LEADER_PER_KEY_TIMING
// #define LEADER_TIMEOUT 350

// #define TAPPING_TERM 200

// Allows to use either side as the master. Look at the documentation for info:
// https://docs.qmk.fm/#/config_options?id=setting-handedness
// #define EE_HANDS

// Allows media codes to properly register in macros and rotary encoder code
// #define TAP_CODE_DELAY 10
