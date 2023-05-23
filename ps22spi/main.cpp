#ifdef QWE
//#define __AVR_ATmega328P__
#define __AVR_ATtiny13A__
#endif

#if defined (__AVR_ATtiny13A__)
#define F_CPU (8000000)
#elif defined (__AVR_ATmega328P__)
#define F_CPU (16000000)
#endif

#include <avr/io.h>

#include <stdint.h>
#include <stdbool.h>

#include "../src/aiavr.h"
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <avr/eeprom.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <stdint.h>

/*
Attiny:
    PB5    -###-  VCC
Out PB3 Tx -###-  PB2-SCK  In
 In PB4 Rx -###-  PB1-MISO Out
    GND    -###-  PB0-MOSI In
*/
#if defined (__AVR_ATtiny13A__)
typedef AttinyPB1_MISO   PinPs2Dat;
typedef AttinyPB4_RX     PinPs2Clk;

typedef AttinyPB2_SCK   PinSpiMosi;
typedef AttinyPB0_MOSI  PinSpiMiso;
typedef AttinyPB3_TX    PinSpiSck;

#elif defined (__AVR_ATmega328P__)
typedef NanoA1_PC1      PinPs2Dat;
typedef NanoA0_PC0      PinPs2Clk;

typedef NanoD8_PB0_CLKO_ICP1  PinSpiMosi;
typedef NanoD9_PB1_OC1A       PinSpiMiso;
typedef NanoD10_PB2_OC1B_SS   PinSpiSck;
#endif


static INLINE void attinyDisablePrescaler8() {
    CLKPR = (1<<CLKPCE);
    CLKPR = 0;
}


template<class MOSI=NullPin,
         class MISO=NullPin,
         class SCK=NullPin,
         bool SCK_ACTIVE_HIGH=false,
         bool MSB_FIRST=false,
         class T=u8,
         int BIT_COUNT=8
         >
struct SwSpiMaster {
    T to_write, to_read;
    u8 counter;

    INLINE T MSB() {
        return COMPILE_TIME_CONST_INT<1 << (BIT_COUNT-1)>();
    }
    INLINE u8 get_bit_and_shift(T& byte) {
        if (MSB_FIRST) {
            T bit = byte & 1;
            byte /= 2;
            return bit;
        } else {
            T bit = (byte & MSB()) / MSB();
            byte *= 2;
            return bit;
        }
    }
    INLINE void set_bit_and_shift(u8& byte, u8 bit) {
        if (MSB_FIRST) {
            byte = 2*byte + bit;
        } else {
            byte /= 2;
            byte += (bit ? MSB() : 0);
        }
    }
    INLINE void init() {
        set_sck_inactive();
        MOSI::setHigh();

        SCK::setOutput();
        MOSI::setOutput();
        MISO::setInputWithPullUp();
    }

    INLINE void set_sck_active() {
        //SCK::write(SCK_ACTIVE_HIGH);
        SCK::setLow();
    }

    INLINE void set_sck_inactive() {
        //SCK::write(!SCK_ACTIVE_HIGH);
        SCK::setHigh();
    }

    INLINE void is_sck_active() {
        return SCK::read() == SCK_ACTIVE_HIGH;
    }

    INLINE void send_char(T toSend = 'Z') {
        to_write = toSend;
        counter = 2*BIT_COUNT;
    }

    INLINE bool can_send() {
        return counter == 0;
    }

    INLINE void update() {
        if (counter == 0) {
            MOSI::setHigh();
            return;
        }
        if (counter % 2 == 0) {
            u8 bit = get_bit_and_shift(to_write);
            MOSI::write(bit);
            set_sck_active();
        } else {
            set_sck_inactive();
            set_bit_and_shift(to_read, MISO::read());
        }
        counter--;
    }
};

template<int size=8>
struct RingBuffer {
    u8 data[size];
    u8 reader, writer;
    INLINE u8 next(u8 x) {
        return (x + 1) % size;
    }
    INLINE bool can_read(){
        return reader != writer;
    }
    INLINE bool can_write() {
        return next(writer) != reader;
    }
    INLINE u8 read() {
        u8 result = data[reader];
        reader = next(reader);
        return result;
    }
    INLINE void write(u8 value) {
        data[writer] = value;
        writer = next(writer);
    }
};


void log_c(char c);

template<class PinDat=NullPin,
         class PinClk=NullPin>
struct Ps2Host {
    u8 kb_last_byte;
    u8 kb_bit_no;
    u8 kb_updates;
    u8 kb_byte;

    bool kb_prev_clk, kb_prev_data;
    bool kb_parity;
    bool can_read_;

    INLINE void init() {
        PinClk::setInputWithoutPullUp();
        PinDat::setInputWithoutPullUp();
    }
    INLINE bool can_read() {
        return can_read_;
    }
    INLINE u8 read() {
        can_read_ = false;
        return kb_byte;
    }

    INLINE void kb_new_byte() {
        can_read_ = true;
        kb_byte = kb_last_byte;
        //log_c('@');
    }
    INLINE void update() {
        kb_update(PinClk::read(), PinDat::read());
    }
    INLINE void kb_error(u8 code) {
        log_c('E');
        log_c(code);
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

};


RingBuffer<16> spi_buffer;
SwSpiMaster<PinSpiMosi, PinSpiMiso, PinSpiSck> spi_master;
Ps2Host<PinPs2Dat, PinPs2Clk> keyboard;

#if defined (__AVR_ATtiny13A__)
void log_init() { }
void log_c(char c) { }
void log_update() {}

#elif defined (__AVR_ATmega328P__)

typedef HwUart<57600> hwuart;
RingBuffer<8> log_buffer;

void log_init() {
    USART_Init2(57600);
    USART_Transmit('P');
    USART_Transmit('S');
    USART_Transmit('2');
    USART_Transmit('\r');
    USART_Transmit('\n');
}
void log_c(char c) {
    log_buffer.write(c);
}

void log_update() {
    if (USART_CanWrite() && log_buffer.can_read()) {
        USART_Transmit(log_buffer.read());
    }
}
#endif

static INLINE void printx(u8 x) {
    u8 xx;
    xx = x / 16;
    log_c(((xx < 10) ? '0' : 'a' - 10) + xx);
    xx = (x % 16);
    log_c(((xx < 10) ? '0' : 'a' - 10) + xx);
}


int main (void) {
    attinyDisablePrescaler8();
    PinSpiSck::setOutput();
    PinSpiSck::setHigh();

    PinSpiMosi::setOutput();
    PinSpiMosi::setLow();
    _delay_ms(1000);

    log_init();
    spi_master.init();
    keyboard.init();

    log_c('o');
    log_c('k');
    u16 t = 0;


    // 4d f0 4d 1b f0 1b 1e f0 1e
    spi_buffer.write(0x4d);

    spi_buffer.write(0xf0);
    spi_buffer.write(0x4d);

    spi_buffer.write(0x1b);

    spi_buffer.write(0xf0);
    spi_buffer.write(0x1b);

    spi_buffer.write(0x1e);

    spi_buffer.write(0xf0);
    spi_buffer.write(0x1e);

    for(;;) {
        t++;
        if (t % 8 == 0) spi_master.update();
        keyboard.update();
        log_update();

        /*
        if (USART_CanRead()) {
            USART_Receive();
            log_c('A' + (PinSpiMiso::read() ? 1 : 0)
                      + (PinSpiMosi::read() ? 2 : 0)
                      + (PinSpiSck::read() ? 4 : 0)
                  );
            log_c('a' + spi_master.counter);
        }
        */
        //if (t==0) {
        //    log_c('a' + (PinPs2Dat::read() ? 1 : 0) + (PinPs2Clk::read() ? 2 : 0));
        //}
        if (keyboard.can_read()) {
            u8 ps2data = keyboard.read();
            spi_buffer.write(ps2data);
        }

        if (spi_buffer.can_read() && spi_master.can_send()) {
            u8 ps2data = spi_buffer.read();
            printx(ps2data);
            log_c(' ');
            spi_master.send_char(ps2data);
        }
        _delay_us(1);
    }
}

