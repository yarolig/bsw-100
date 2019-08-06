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
// u8 kb_received;
u8 uart_received;
u8 console_cursor_row, console_cursor_col;
u8 console_top_row;
u8 term_status, term_csi1, term_csi2;
u8 background;
u8 tx_buf[8];
u8 tx_buf_start, tx_buf_end;

void addbuf(u8 ch) {
    tx_buf[tx_buf_end++] = ch;
    tx_buf_end = tx_buf_end % 8;
}

u8 getbuf() {
    if (tx_buf_start==tx_buf_end) {
        return 0;
    }
    u8 res = tx_buf[tx_buf_start++];
    tx_buf_start = tx_buf_start % 8;
    return res;
}

#define TS_NORMAL 0
#define TS_ESCAPE 1
#define TS_CSI 2
#define TS_CSI2 3
#define TS_VT52_Y1 4
#define TS_VT52_Y2 5
#define TS_DEC_PRIVATE 6


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
                    if (sc & 128) {
                            addbuf('\e');
                            addbuf('[');
                            addbuf('0' + (sc - 128));
                            addbuf('F');
                    } else if ( kb_prev_ext && '.' <= sc && sc <= '9') {
                        if (sc == '8') {
                            addbuf('\e'); addbuf('['); addbuf('A');
                        } else if (sc == '2') {
                            addbuf('\e'); addbuf('['); addbuf('B');
                        } else if (sc == '4') {
                            addbuf('\e'); addbuf('['); addbuf('D');
                        } else if (sc == '6') {
                            addbuf('\e'); addbuf('['); addbuf('C');
                        } else if (sc == '7') { // Home
                            addbuf('\e'); addbuf('['); addbuf('H');
                        } else if (sc == '1') { // End
                            addbuf('\e'); addbuf('['); addbuf('F');
                        } else if (sc == '9') { // PageUp
                            addbuf('\e'); addbuf('['); addbuf('5'); addbuf('~');
                        } else if (sc == '3') { // PageDown
                            addbuf('\e'); addbuf('['); addbuf('6'); addbuf('~');
                        } else if (sc == '.') { // Delete
                            addbuf('\e'); addbuf('['); addbuf('3'); addbuf('~');
                        } else if (sc == '/') { // Insert
                            addbuf('\e'); addbuf('['); addbuf('2'); addbuf('~');
                        }
                    } else {
                        addbuf(sc);
                    }
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


static INLINE void decrease_row(u8& row) {
    if (row==0) {
        row = console_height - 1;
    } else {
        row--;
    }
}


static INLINE void term_handle_ch_normal(u8 ch){
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
            clear_console_line(&console[console_top_row*console_width],  ' ');
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
    if (ch == ' ' && background) {
        ch = 127;
    }
    //if (ch >= 128) {
    //    // Non-ANSI characters, ignore it
    //    return;
    //}
    console[console_cursor_row*console_width+console_cursor_col] = ch;
    console_cursor_col++;
    if (console_cursor_col==console_width){
        console_cursor_col=0;
        term_handle_ch_normal('\n');
    }
}

/*
mach|Mach Console,
        am, km,
        cols#80, it#8, lines#25,
        bel=^G, blink=\E[5m, bold=\E[1m, clear=\Ec, cr=^M,
        cub=\E[%p1%dD, cub1=^H, cud=\E[%p1%dB, cud1=^J,
        cuf=\E[%p1%dC, cuf1=\E[C, cup=\E[%i%p1%d;%p2%dH,
        cuu=\E[%p1%dA, cuu1=\E[A, dl=\E[%p1%dM, dl1=\E[M, ed=\E[J,
        el=\E[K, home=\E[H, ht=^I, il=\E[%p1%dL, il1=\E[L, ind=^J,
        kbs=\177, kcub1=\E[D, kcud1=\E[B, kcuf1=\E[C, kcuu1=\E[A,
        kdch1=\E[9, kend=\E[Y, kf1=\EOP, kf10=\EOY, kf2=\EOQ,
        kf3=\EOR, kf4=\EOS, kf5=\EOT, kf6=\EOU, kf7=\EOV, kf8=\EOW,
        kf9=\EOX, khome=\E[H, kich1=\E[@, kll=\E[F, knp=\E[U,
        kpp=\E[V, rev=\E[7m, rmso=\E[0m, rmul=\E[24m, sgr0=\E[0m,
        smso=\E[7m, smul=\E[4m,

#       Reconstructed via infocmp from file: /lib/terminfo/v/vt52
vt52|dec vt52,
        cols#80, it#8, lines#24,
        acsc=+h.k0affggolpnqprrss, bel=^G, clear=\EH\EJ, cr=^M,
        cub1=\ED, cud1=\EB, cuf1=\EC,
        cup=\EY%p1%' '%+%c%p2%' '%+%c, cuu1=\EA, ed=\EJ, el=\EK,
        home=\EH, ht=^I, ind=^J, kbs=^H, kcub1=\ED, kcud1=\EB,
        kcuf1=\EC, kcuu1=\EA, nel=^M^J, ri=\EI, rmacs=\EG, smacs=\EF,

*/
static INLINE void term_handle_ch_escape(u8 ch) {
    if (ch == 'A') {        // vt52 cuu, cursor_up
        increase_row(console_cursor_row);
    } else if (ch == 'B') { // vt52 cud, cursor_down
        decrease_row(console_cursor_row);
    } else if (ch == 'C') { // vt52 cuf, cursor_right
        if (console_cursor_col!=console_width) {
            console_cursor_col++;
        }
    } else if (ch == 'D') { // vt52 cub, cursor_left
        if (console_cursor_col!=0) {
            console_cursor_col--;
        }
    } else if (ch == 'Y') { // vt52 position cursor
        term_status = TS_VT52_Y1;
    }
}

static INLINE void term_handle_ch_csi(u8 ch) {
    if (ch == 'H') {
        if (term_csi1 == 0) term_csi1 = 1;
        if (term_csi2 == 0) term_csi2 = 1;

        console_cursor_row = term_csi1 - 1;
        console_cursor_col = term_csi2 - 1;

        console_cursor_row = (console_cursor_row + console_top_row) % console_height;

        if (console_cursor_col>console_width) {
            console_cursor_col = console_width - 1;
        }
    } else if (ch == 'J') {
        clear_console_line(&console[0], ' ');
        for (u8 a=1;a<console_height;a++) {
            console[a*console_width] = 0;
        }
    } else if (ch == 'A') { // vt100 cuu, cursor_up
        increase_row(console_cursor_row);
    } else if (ch == 'B') { // vt100 cud, cursor_down
        decrease_row(console_cursor_row);
    } else if (ch == 'C') { // vt100 cuf, cursor_right
        if (console_cursor_col!=console_width) {
            console_cursor_col++;
        }
    } else if (ch == 'D') { // vt100 cub, cursor_left
        if (console_cursor_col!=0) {
            console_cursor_col--;
        }
    } else if (ch == 'm') {
        if (40 <= term_csi1 && term_csi1 < 49 ) {
            background = 1;
        } else if (term_csi1 == 0) {
            background = 0;
        }

    } else if (ch == '?') {
        term_status = TS_DEC_PRIVATE;
    }
    term_csi1 = 0;
    term_csi2 = 0;
}

static INLINE void term_handle_ch(u8 ch){
    if (term_status == TS_NORMAL) {
        if (ch=='\e') {
            term_status = TS_ESCAPE;
        } else {
            term_handle_ch_normal(ch);
        }
    } else if (term_status == TS_ESCAPE) {
        if (ch=='[') {
            term_status = TS_CSI;
        } else {
            term_handle_ch_escape(ch);
            term_status = TS_NORMAL;
        }
    } else if (term_status == TS_CSI) {
        if (ch==';') {
            term_status = TS_CSI2;
        } else if ('0' <= ch && ch <= '9') {
            term_csi1 = term_csi1*10 + ch - '0';
        } else {
            term_handle_ch_csi(ch);
            term_status = TS_NORMAL;
        }
    } else if (term_status == TS_CSI2) {
        if ('0' <= ch && ch <= '9') {
            term_csi2 = term_csi2*10 + ch - '0';
        } else {
            term_handle_ch_csi(ch);
            term_status = TS_NORMAL;
        }
    } else if (term_status == TS_VT52_Y1) {
        term_csi1 = ch - ' ';
        term_status = TS_VT52_Y2;
    } else if (term_status == TS_VT52_Y2) {
        term_csi2 = ch - ' ';
        term_handle_ch_csi('H');
        term_status = TS_NORMAL;
    } else if (term_status == TS_DEC_PRIVATE) {
        if (ch==';') {
        } else if ('0' <= ch && ch <= '9') {
        } else {
            term_status = TS_NORMAL;
        }
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
    if (USART_CanWrite()){
        u8 gb = getbuf();
        if (gb) {
            USART_Transmit(gb);
        }
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
            clear_console_line(screen_scanline, font_space_index);
            screen_scanline[console_cursor_col] = font_cursor_index;
            screen_scanline[console_cursor_col+1] = 0;
        } else if (current_char_row == 6) {
            // Apply delayed screen clearing
            current_console_row_no += console_top_row;
            if (current_console_row_no >= console_height) {
                current_console_row_no -= console_height;
            }
            if (0 == console[current_console_row_no*console_width]) {
                clear_console_line(&console[current_console_row_no*console_width], ' ');
            }
        }
        spi_update();
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
        spi_update();
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
