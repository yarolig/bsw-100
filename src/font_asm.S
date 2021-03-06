#ifndef F_CPU
#define F_CPU (16000000)
#endif


#include <avr/io.h>

.extern screen_scanline
.extern font_char_scanlines
.global draw_screen_scanline
.global debug_scanlines
.global prepare_screen_scanline
.global clear_console_line
#define console_width 40

debug_scanlines:
    ;LDI r24, 0x15
    ;LDI r24, 0xcc
    ;LDI r25, 0xdd
    RET


draw_screen_scanline:
    LDI r24, 0x00 ; r24 = background
    LDI r25, 0xff ; r25 = foreground
    LDI r23, 0x1 ; r23 = highlight

    ;LDI r24, 0x12
    LDI XL, lo8(screen_scanline)
    LDI XH, hi8(screen_scanline)

    ;LDI r24, 0x13
    ; LD   ZL, X+
    LDI  ZL, lo8(font_char_scanlines)
    LDI  ZH, hi8(font_char_scanlines)

    ;LDI  ZH, hi8(debug_scanlines)
    ;LDI  ZL, lo8(debug_scanlines)
    LSR  ZH ; Z = Z / 2
    ROR  ZL ;

    LD ZL, X+
    ;LDI r24, 0x14
    ;LD r30, X+
    ;RET
    IJMP
    RET


#define rChar r19
#define rCharLine r0

; r27:r26 - X
; r31:r30 - Z
#define rX r26
#define rY r28
#define rZ r30

prepare_screen_scanline:
    ; r24, r25 console_line  X
    ; r23, r22 font_line     Y
    ; r21, r20 scanline      Z
    push YL
    push YH
    movw rX, r24
    movw rY, r22
    movw rZ, r20
    ; LDI r20, console_width
.macro loop_body
    LD rChar, X+       ; 2
    movw rY, r22        ; 1
    add  YL, rChar     ; 1
                       ; 0
    LD rChar, Y        ; 2
    ST Z+, rChar       ; 2
    ; SUBI r20, 1      ; 0
                       ; 8 Total
.endm

loop:
    loop_body ;0
    loop_body ;1
    loop_body ;2
    loop_body ;3
    loop_body ;4
    loop_body ;5
    loop_body ;6
    loop_body ;7
    loop_body ;8
    loop_body ;9
    loop_body ;10
    loop_body ;11
    loop_body ;12
    loop_body ;13
    loop_body ;14
    loop_body ;15
    loop_body ;16
    loop_body ;17
    loop_body ;18
    loop_body ;19
    loop_body ;20
    loop_body ;21
    loop_body ;22
    loop_body ;23
    loop_body ;24
    loop_body ;25
    loop_body ;26
    loop_body ;27
    loop_body ;28
    loop_body ;29
    loop_body ;30
    loop_body ;31
    loop_body ;32
    loop_body ;33
    loop_body ;34
    loop_body ;35
    loop_body ;36
    loop_body ;37
    loop_body ;38
    loop_body ;39
    ;BRNE loop          ; 2

    LDI rChar, 0
    ST Z+, rChar
    pop YH
    pop YL
    ret

clear_console_line:
    ; r24, r25 console_line  X
    ; r22? VALUE
    movw rX, r24
    ST X+, r22 ;0
    ST X+, r22 ;1
    ST X+, r22 ;2
    ST X+, r22 ;3
    ST X+, r22 ;4
    ST X+, r22 ;5
    ST X+, r22 ;6
    ST X+, r22 ;7
    ST X+, r22 ;8
    ST X+, r22 ;9
    ST X+, r22 ;10
    ST X+, r22 ;11
    ST X+, r22 ;12
    ST X+, r22 ;13
    ST X+, r22 ;14
    ST X+, r22 ;15
    ST X+, r22 ;16
    ST X+, r22 ;17
    ST X+, r22 ;18
    ST X+, r22 ;19
    ST X+, r22 ;20
    ST X+, r22 ;21
    ST X+, r22 ;22
    ST X+, r22 ;23
    ST X+, r22 ;24
    ST X+, r22 ;25
    ST X+, r22 ;26
    ST X+, r22 ;27
    ST X+, r22 ;28
    ST X+, r22 ;29
    ST X+, r22 ;30
    ST X+, r22 ;31
    ST X+, r22 ;32
    ST X+, r22 ;33
    ST X+, r22 ;34
    ST X+, r22 ;35
    ST X+, r22 ;36
    ST X+, r22 ;37
    ST X+, r22 ;38
    ST X+, r22 ;39
    ret
