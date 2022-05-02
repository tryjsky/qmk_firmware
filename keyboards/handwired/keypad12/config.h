// Copyright 2022 Y., Ryota (@tryjsky)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

#define MANUFACTURER "Y., Ryota"

#define USB_MAX_POWER_CONSUMPTION 50

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

// The state of the indicator pins when the LED is "on" - 1 for high
#define LED_PIN_ON_STATE 1

#define LED_NUM_LOCK_PIN D4

#define MATRIX_HAS_GHOST
