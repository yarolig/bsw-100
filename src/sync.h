// The MIT License (MIT)
// Copyright (c) 2015 Leon Sodhi
//
// this code is taken from https://github.com/leonsodhi/avr-vga-demo/blob/master/vga_asm.s
// and modified to fit the bsw-100

#include "aiavr.h"
#include <avr/io.h>

static INLINE void sync_to_timer1() {
    __asm__(
    "lds     r24, 0x84\n" // TCNT1
    "andi    r24, 0x07\n"
                                                //     0   1   2   3
    "cpi r24, 7 ; 1\n"                          //     1   1   1   1
    "breq waste7   ; false = 1, true = 2    \n" //     3   2   2   2
                                                //
    "cpi r24, 6 ; 1\n"                          //         3   3   3
    "breq waste6   ; false = 1, true = 2    \n" //         5   4   4
                                                //
    "cpi r24, 5 ; 1\n"                          //             5   5
    "breq waste5   ; false = 1, true = 2    \n" //             7   6
                                                //
    "cpi r24, 4 ; 1\n"                          //                 7
    "breq waste4   ; false = 1, true = 2\n"     //                 9

    "cpi r24, 3 ; 1\n"                          //     1   1   1   1
    "breq waste3   ; false = 1, true = 2    \n" //     3   2   2   2
                                                //
    "cpi r24, 2 ; 1\n"                          //         3   3   3
    "breq waste2   ; false = 1, true = 2    \n" //         5   4   4
                                                //
    "cpi r24, 1 ; 1\n"                          //             5   5
    "breq waste1   ; false = 1, true = 2    \n" //             7   6
                                                //
    "cpi r24, 0 ; 1\n"                          //                 7
    "breq waste0   ; false = 1, true = 2\n"     //                 9

    "waste7: nop\n"                             //     4
    "waste6: nop\n"                             //     5   6
    "waste5: nop\n"                             //     6   7   8
    "waste4: nop\n"                             //     7   8   9   10
    "waste3: nop\n"                             //     4
    "waste2: nop\n"                             //     5   6
    "waste1: nop\n"                             //     6   7   8
    "waste0: nop\n"                             //     7   8   9   10
    :       // OutputOperands
    :       // InputOperands
    : "r24" // Clobbers
    );
}
