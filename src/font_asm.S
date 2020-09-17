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
    LDI r24, 0x00  ; r24 = background
    IN r25, 0x2a   ; r23 = GPIOR1
    ;LDI r25, 0xff ; r25 = foreground
    IN  r23, 0x1e  ; r23 = GPIOR0
    ; LDI r23, 0x1 ; r23 = highlight
    NOP
    NOP
    NOP

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
#define rCharLine r19

; r27:r26 - X
; r31:r30 - Z

#define rXL r26
#define rXH r27
#define rYL r28
#define rYH r29
#define rZL r30
#define rZH r31

#define rconsole_lineL r24
#define rconsole_lineH r25
#define rfont_lineL r22
#define rfont_lineH r23
#define rscanlineL r20
#define rscanlineH r21

prepare_screen_scanline:
    ; r24, r25 console_line  X
    ; r22, r23 font_line     Y
    ; r20, r21 scanline      Z
    push YL
    push YH
    movw rXL, rconsole_lineL
    movw rZL, rfont_lineL
    movw rYL, rscanlineL

.macro loop_body
    LD rChar, X+          ; 2
    movw rZL, rfont_lineL ; 1
    add  ZL, rChar        ; 1
                          ; 0
    LPM rCharLine, Z      ; 3   ; LD rCharLine, Z       ; 2
    ST Y+, rCharLine      ; 2
                          ; 9 Total
.endm

.rept console_width
    loop_body
.endr
    LDI rChar, 0
    ST Y+, rChar
    pop YH
    pop YL
    ret

clear_console_line:
    ; r24, r25 console_line  X
    ; r22      value
    movw rXL, r24
.rept console_width
    ST X+, r22
.endr
    ret
