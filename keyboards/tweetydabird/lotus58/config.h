// Copyright 2022 Markus Knutsson (@TweetyDaBird)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Options not yet fully implemented in info.json
//#define RGBLIGHT_LIMIT_VAL 175
//#define RGBLIGHT_DEFAULT_VAL ( RGBLIGHT_LIMIT_VAL / 2 )
//#define RGBLIGHT_SLEEP

#define SPLIT_HAND_PIN B5
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
//Uncommented to prevent a 1-OLED-on-slave-side setup from trying to sync OLED status to master (with no OLED)
//#define SPLIT_OLED_ENABLE
