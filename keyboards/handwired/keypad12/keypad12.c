// Copyright 2022 Y., Ryota (@tryjsky)
// SPDX-License-Identifier: GPL-2.0-or-later
//
#include "keypad12.h"

#define KEYPAD12_NUMLOCK_LED 4 // D4

void numlock_led_on() {
    PORTD |= (1 << KEYPAD12_NUMLOCK_LED);
}

void numlock_led_off() {
    PORTD &= ~(1 << KEYPAD12_NUMLOCK_LED);
}
