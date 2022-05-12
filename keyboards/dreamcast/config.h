// Copyright 2022 Y., Ryota (@tryjsky)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define USB_MAX_POWER_CONSUMPTION 100
#define MATRIX_HAS_GHOST

#define BOOTMAGIC_LITE_ROW 12
#define BOOTMAGIC_LITE_COLUMN 7

#define LED_CAPS_LOCK_PIN D5
#define LED_SCROLL_LOCK_PIN B0
#define LED_PIN_ON_STATE 0

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
