#ifndef F_CPU
#define F_CPU (16000000)
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/io.h>
#include <avr/pgmspace.h>

#include "aiavr.h"
#include "font_asm.h"
#include "font.h"
#include "scancodes.h"

typedef NanoD3_PD3_INT1_OC2B VsyncPin; // yellow
typedef NanoD9_PB1_OC1A      HSyncPin; // violet

#define console_width 40
#define console_height 29
#define VIDEO_START_CLK (540-486)
#define VIDEO_START_LINE (497-484)

const u8 PROGMEM banner[] =
"              BSW-100                   "
"========================================"
"=                                      ="
"= ABCDEFGHIJKLMNOPQRSTUVWXYZ           ="
"= abcdefghijklmnopqrstuvwxyz  {}|:\"<>? ="
"= `1234567890-= ~!@#$%^&*()_+ []\\;',./ ="
"=                                      ="
"========================================"
"\0"
;


u16 line = 0;
u8 current_screen_row;
u8 current_char_row;
u8 kb_received;
u8 uart_received;
u8 console_cursor_row, console_cursor_col;
u8 console_top_row;

unsigned char screen_scanline[console_width + 1];
u8 console[console_width*console_height];

u8 kb_flags;
u8 kb_last_byte;
u8 kb_bit_no;
u8 kb_updates;
bool kb_prev_clk, kb_prev_data;
bool kb_parity;
bool kb_prev_up, kb_prev_ext;
bool kb_shifted, kb_ctrled;

INLINE void kb_error(u8 code) { }

INLINE void kb_new_byte() {
    if (kb_last_byte==0xf0) {
        kb_prev_up = 1;
    } else if (kb_last_byte==0xe0) {
        kb_prev_ext = 1;
    } else {
        if (kb_last_byte==0x12) {
            kb_shifted = !kb_prev_up;
        } else if (kb_last_byte==0x59) {
            kb_shifted = !kb_prev_up;
        } else if (kb_last_byte==0x14) {
            kb_ctrled = !kb_prev_up;
            /*
        } else if (last_byte==0x11) {
            // alt
        } else if (last_byte==0x1f) {
            // lwin
        } else if (last_byte==0x2f) {
            // menu
        } else if (last_byte==0x27) {
            // rwin (ext)
            */
        } else {
            u8 sc;
            sc = pgm_read_byte(&scancodes[kb_last_byte]);
            if (sc != '?') {
                if (!kb_prev_up) {
                    if (kb_shifted) {
                        sc = pgm_read_byte(&scancodes[kb_last_byte+256]);
                    }
                    if (kb_ctrled) {
                        sc = sc + 1 - 'a';
                    }
                    kb_received = sc;
                }
            } else {/*
                if (prev_up) {
                    addbuf('^');
                }
                if (prev_ext) {
                    addbuf('X');
                }
                u8 xx;
                xx = last_byte / 16;
                addbuf(((xx < 10) ? '0' : 'a' - 10) + xx);
                xx = (last_byte % 16);
                addbuf(((xx < 10) ? '0' : 'a' - 10) + xx);
                addbuf(' ');*/
            }
        }
        kb_prev_ext = 0;
        kb_prev_up = 0;
    }
}

INLINE void kb_new_bit(bool bit) {
    if (kb_bit_no == 0) {
        // nothing
        kb_last_byte = 0;
        if (bit != 0) {
            kb_error('0');
        }
    } else if (1 <= kb_bit_no && kb_bit_no <= 8) {
        // LSB first
        kb_last_byte = (kb_last_byte >> 1) | (bit ? 128 : 0);
        kb_parity = kb_parity ^ bit;
    } else if (kb_bit_no == 9) {
        if (kb_parity == bit) {
            kb_error('p');
        }
    } else if (kb_bit_no >= 10) {
        if (bit != 1) {
            kb_error('s');
        }
        kb_new_byte();
        kb_last_byte = 0;
        kb_parity = 0;
        kb_bit_no = 0;
        return;
    }
    kb_updates=0;
    kb_bit_no++;
}

INLINE void kb_update(bool clk, bool data) {
    if (kb_prev_clk==1 && clk == 0) {
        kb_new_bit(data);
    }
    kb_prev_clk = clk;
    kb_updates++;
    if (kb_updates==0 && kb_bit_no!=0 && kb_prev_clk==1) {
        kb_last_byte=0;
        kb_bit_no=0;
        kb_parity=0;
        kb_error('R');
    }
}

void spi_init(){
    SPCR = 0;
    SPCR = /*_BV(SPIE) | */           //SPI Interrupt enable
           _BV(SPE)  |                // SPI Enable
           /* _BV(DORD) | */          // Data order, 0 - LSB first
           /* _BV(MSTR) | */          // Master/Slave select, 0 - slave
           _BV(CPOL) |                // Clock polatity, 1 - SCK=1 when idle
           _BV(CPHA) |                // Clock phase, 0 - sample on leading edge
           /* _BV(SPR1) | _BV(SPR0)*/ // Oscillator freq
           0;
    SPDR = 0xff;
}

void spi_update() {
    if (SPSR & _BV(SPIF)) {
        u8 ch = SPDR;
        SPDR = 0xff;
        for (u8 a=0;a<8;a++) {
            u8 bit = (ch & 128) ? 1 : 0;
            kb_new_bit(bit);
            ch *= 2;
        }
    }
}

static INLINE void increase_row(u8& row) {
    row++;
    if (row==console_height) {
        row=0;
    }
}

static INLINE void term_handle_ch(u8 ch){
    ch = ch & ~128;
    if (ch=='\r') {
        console_cursor_col = 0;
        return;
    }
    if (ch==8 || ch == 127) {
        if (console_cursor_col>0) {
            console_cursor_col--;
            console[console_cursor_row*console_width+console_cursor_col] = ' ';
        }
        return;
    }
    if (ch=='\n') {
        increase_row(console_cursor_row);
        if (console_cursor_row==console_top_row) {
#if 0
            for (u8 a=0;a<console_width;a++){
                console[console_top_row*console_width+a] = 0;
            }
#else
            clear_console_line(&console[console_top_row*console_width], 0);
#endif
            increase_row(console_top_row);
        }
        return;
    }

    if (ch == '\b') {
        return;
    }
    if (ch < 32) {
        // Other non-printable character
        // Ignore it
        return;
    }
    //if (ch >= 128) {
    //    // Non-ANSI characters, ignore it
    //    return;
    //}
    console[console_cursor_row*console_width+console_cursor_col] = ch;
    console_cursor_col++;
    if (console_cursor_col==console_width){
        console_cursor_col=0;
        term_handle_ch('\n');
    }
}

static INLINE void process_uart() {
    if (uart_received) {
        u8 ch = uart_received;
        term_handle_ch(ch);
        if (ch=='\n') {
            term_handle_ch('\r');
        }
        uart_received = 0;
    }
    if (kb_received) {
        USART_Transmit(kb_received);
        kb_received = 0;
    }

    spi_update();
    if (kb_received && USART_CanWrite()) {
        USART_Transmit(kb_received);
        kb_received = 0;
    }
    if (USART_CanRead()) {
        u8 ch = USART_Receive();
        term_handle_ch(ch);
        if (ch=='\n') {
            term_handle_ch('\r');
        }
    }
}

static INLINE void preprocess_uart() {
    if (USART_CanRead()) {
        uart_received = USART_Receive();
    }
    spi_update();
}

static INLINE void prepare_scanline() {
    current_char_row = current_screen_row % 8;
    u8 current_console_row_no = current_screen_row / 8;

    if (current_char_row >= 5 || current_console_row_no>console_height) {
        screen_scanline[0] = 0;
        if (current_char_row == 5 &&
            (console_cursor_row                  == current_console_row_no + console_top_row ||
             console_cursor_row + console_height == current_console_row_no + console_top_row
            )
        ) {
            clear_console_line(screen_scanline, 123);
            screen_scanline[console_cursor_col] = 67;
            screen_scanline[console_cursor_col+1] = 0;
        }
        process_uart();
        process_uart();
        return;
    }
    current_console_row_no += console_top_row;
    if (current_console_row_no >= console_height) {
        current_console_row_no -= console_height;
    }

#if 0
    u8 a;
    for (a=0; a < console_width; a++) {
        u8 ch = console[current_console_row_no*console_width+a];
        screen_scanline[a] = (font_chars[128 * current_char_row + ch]);
    }
    screen_scanline[console_width] = 0;
#else

    prepare_screen_scanline(&console[current_console_row_no*console_width],
                            &font_chars[128 * current_char_row],
                            screen_scanline);
#endif
}

static INLINE void on_timer1(){
    PORTC = 0x00;
    line++;
    if (line==481+VIDEO_START_LINE) {
        // vsync active
        VsyncPin::setLow();
    } else if (line >= 484+VIDEO_START_LINE+0) {
        line = 0;
        VsyncPin::setHigh();
    }

    if (32 <= line && line < 480+VIDEO_START_LINE) {
        //PORTC = line % 0x100 / 32;
        if (line % 2 == 1) {
            draw_screen_scanline();
            if (current_char_row == 2){
                preprocess_uart();
            }
        } else if (line % 2 == 0) {
            current_screen_row = ((line-32) / 2);
            prepare_scanline();
        }
        PORTC = 0x00;
        return;
    } else {
        process_uart();
        process_uart();
    }
}

ISR(TIMER1_OVF_vect) {
    on_timer1();
}

void load_banner() {
    console_cursor_col = 0;
    console_cursor_row = 8;
    for (u16 a=0;;a++) {
        u8 c = pgm_read_byte(&banner[a]);
        if (c==0) {
            break;
        }
        console[a] = c;
    }
}

int main (void) {
    load_banner();
    USART_InitBAUD(57600);

    NanoD5_PD5_T1_OCO0B::setOutput();
    NanoD9_PB1_OC1A::setOutput();
    NanoD3_PD3_INT1_OC2B::setOutput();

    NanoA0_PC0::setOutput();
    NanoA1_PC1::setOutput();
    NanoA2_PC2::setOutput();

    NanoD11_PB3_OC2A_MOSI::setInputWithoutPullUp();
    NanoD12_PB4_MISO::setInputWithoutPullUp();
    NanoD13_PB5_SCK::setInputWithoutPullUp();

    spi_init();

    timer1_Stop();
    ICR1 = 540;
    OCR1A = (443+VIDEO_START_CLK);
    TCNT1 = 1;
    HSyncPin::setHigh();
    timer1_FastPWM_TopICR1();
    timer1_CompareMatchOutputA_ClearOnMatch();
    timer1_EnableOverflowInterrupt();
    timer1_StartWithPrescaler1();

    set_sleep_mode(SLEEP_MODE_IDLE);
    sei();
    sleep_enable();
    for (;;) {
        sleep_cpu();
    }
}
