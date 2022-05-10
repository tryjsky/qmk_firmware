// Copyright 2022 Y., Ryota (@tryjsky)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "util.h"
#include "matrix.h"
#include "quantum.h"

void matrix_init_custom(void) {
    // Init row pins
    setPinOutput(B5);
    setPinOutput(B1);
    setPinOutput(B3);
    setPinOutput(B2);
    setPinOutput(B6);

    // Init col pins
    setPinInput(D1);
    setPinInput(D0);
    setPinInput(D4);
    setPinInput(C6);
    setPinInput(D7);
    setPinInput(B4);
    setPinInput(D2);
    setPinInput(D3);
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool matrix_has_changed = false;
    matrix_row_t curr_matrix[MATRIX_ROWS] = {0};

    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        matrix_row_t row_value = 0;

        /* drive row decoder */
        uint8_t rowbit = (((row > 0b0111) ? 0 : 1) << 6) |
            (((row > 0b0111) ? 1 : 0) << 2) |
            ((row & 0b0100) << 1) |
            (row & 0b0010) |
            ((row & 0b0001) << 5);
        PORTB = (PORTB & 0b10010001) | rowbit;
        matrix_output_select_delay();
        matrix_output_select_delay();
        matrix_output_select_delay();

        row_value |= readPin(D1) ? 0 : MATRIX_ROW_SHIFTER << 0;
        row_value |= readPin(D0) ? 0 : MATRIX_ROW_SHIFTER << 1;
        row_value |= readPin(D4) ? 0 : MATRIX_ROW_SHIFTER << 2;
        row_value |= readPin(C6) ? 0 : MATRIX_ROW_SHIFTER << 3;
        row_value |= readPin(D7) ? 0 : MATRIX_ROW_SHIFTER << 4;
        row_value |= readPin(B4) ? 0 : MATRIX_ROW_SHIFTER << 5;
        row_value |= readPin(D2) ? 0 : MATRIX_ROW_SHIFTER << 6;
        row_value |= readPin(D3) ? 0 : MATRIX_ROW_SHIFTER << 7;

        curr_matrix[row] = row_value;
    }

    matrix_has_changed = memcmp(current_matrix, curr_matrix, sizeof(curr_matrix)) != 0;
    if (matrix_has_changed) {
        memcpy(current_matrix, curr_matrix, sizeof(curr_matrix));
    }

    return matrix_has_changed;
}
