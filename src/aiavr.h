#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef int8_t s8;
typedef uint8_t u8;
typedef int16_t s16;
typedef uint16_t u16;
typedef __uint24 u24;
typedef __int24  s24;
typedef uint32_t u32;
typedef int32_t s32;
typedef int32_t i32;


#define INLINE __attribute__((always_inline)) inline
#define NOINLINE __attribute__ ((noinline))

#define OrVal(reg,val) reg|=(val)
#define AndNVal(reg,val) reg&=~(val)

template<int BITNO>
INLINE int bitoffsetToValue() {
    return 1 << BITNO;
}

template<int C>
INLINE int COMPILE_TIME_CONST_INT() {return C;}
#define CTRL(a) ((a) - 'A' + 1)

//----------------------------------------------------------------------------

struct NullPin {
    static INLINE bool read() { return false; }
    static INLINE bool isHigh() { return false;}
    static INLINE bool isLow() { return true; }
    static INLINE void write(bool value) {}
    static INLINE void toggle() {    }
    static INLINE void setHigh() {    }
    static INLINE void setLow() {    }
    static INLINE void setInput() {    }
    static INLINE void setInputWithPullUp() {    }
    static INLINE void setInputWithoutPullUP() {    }
    static INLINE void setOutput() {    }
    static INLINE void setPinChangeIntMask() {    }
    static INLINE void clearPinChangeIntMask() {    }
};

#define PINDEF(NAME, PORTX, PINX, DDRX,NO) \
    struct NAME {                                            \
        static INLINE bool read() {                                 \
            return PINX & bitoffsetToValue<NO>();            \
        }                                                    \
        static INLINE bool isHigh() {                               \
            return read();                                   \
        }                                                    \
        static INLINE bool isLow() {                                \
            return !read();                                  \
        }                                                    \
        static INLINE void write(bool value) {                      \
            if (value) {                                     \
                setHigh();                                   \
            } else {                                         \
                setLow();                                    \
            }                                                \
        }                                                    \
        static INLINE void toggle() {                               \
            /* Writing logic 1 to PIN  toggles value */      \
            PINX |= bitoffsetToValue<NO>();                  \
        }                                                    \
        static INLINE void setHigh() {                              \
            PORTX |= bitoffsetToValue<NO>();                 \
        }                                                    \
        static INLINE void setLow() {                               \
            PORTX &= ~bitoffsetToValue<NO>();                \
        }                                                    \
        static INLINE void setInput() {                             \
            DDRX &= ~bitoffsetToValue<NO>();                 \
        }                                                    \
        static INLINE void setInputWithPullUp() {                   \
            DDRX &= ~bitoffsetToValue<NO>();                  \
            setHigh();                                       \
        }                                                    \
        static INLINE void setInputWithoutPullUp() {                \
            DDRX &= ~bitoffsetToValue<NO>();                 \
            setLow();                                        \
        }                                                    \
        static INLINE void setOutput() {                     \
            DDRX |= bitoffsetToValue<NO>();                  \
        }                                                    \
        static INLINE bool isOutput() {                      \
            return DDRX & bitoffsetToValue<NO>();            \
        }                                                    \
};
//-----------------------------------------------------------------------------

#if defined (__AVR_ATmega328P__)
PINDEF(NanoTX1_PD1, PORTD,    PIND, DDRD, PORTD1)
PINDEF(NanoRX1_PD0, PORTD,    PIND, DDRD, PORTD0)
PINDEF(NanoRESET_PC6, PORTC,  PINC, DDRC, PORTC6)
// GND
PINDEF(NanoD2_PD2_INT0,       PORTD, PIND, DDRD, PORTD2)
PINDEF(NanoD3_PD3_INT1_OC2B,  PORTD, PIND, DDRD, PORTD3)
PINDEF(NanoD4_PD4_T0_XCK,     PORTD, PIND, DDRD, PORTD4)
PINDEF(NanoD5_PD5_T1_OCO0B,   PORTD, PIND, DDRD, PORTD5)
PINDEF(NanoD6_PD6_AIN0_OC0A,  PORTD, PIND, DDRD, PORTD6)
PINDEF(NanoD7_PD7_AIN1,       PORTD, PIND, DDRD, PORTD7)
PINDEF(NanoD8_PB0_CLKO_ICP1,  PORTB, PINB, DDRB, PORTB0)
PINDEF(NanoD9_PB1_OC1A,       PORTB, PINB, DDRB, PORTB1)
PINDEF(NanoD10_PB2_OC1B_SS,   PORTB, PINB, DDRB, PORTB2)
PINDEF(NanoD11_PB3_OC2A_MOSI, PORTB, PINB, DDRB, PORTB3)
PINDEF(NanoD12_PB4_MISO,      PORTB, PINB, DDRB, PORTB4)
PINDEF(NanoD13_PB5_SCK,       PORTB, PINB, DDRB, PORTB5)
// 3.3V
// AREF
PINDEF(NanoA0_PC0, PORTC, PINC, DDRC, PORTC0)
PINDEF(NanoA1_PC1, PORTC, PINC, DDRC, PORTC1)
PINDEF(NanoA2_PC2, PORTC, PINC, DDRC, PORTC2)
PINDEF(NanoA3_PC3, PORTC, PINC, DDRC, PORTC3)
PINDEF(NanoA4_PC4_SDA, PORTC, PINC, DDRC, PORTC4)
PINDEF(NanoA5_PC5_SCL, PORTC, PINC, DDRC, PORTC5)
//PINDEF(NanoA6_ADC6, PORTC, PINC, DDRC, PORTC6)
//PINDEF(NanoA7_ADC7, PORTC, PINC, DDRC, PORTC7)
// 5V
// Reset
// GND
// VIN
#elif defined (__AVR_ATtiny13A__)
PINDEF(AttinyPB0_MOSI, PORTB, PINB, DDRB, PORTB0)
PINDEF(AttinyPB1_MISO, PORTB, PINB, DDRB, PORTB1)
PINDEF(AttinyPB2_SCK, PORTB, PINB, DDRB, PORTB2)
PINDEF(AttinyPB3_TX, PORTB, PINB, DDRB, PORTB3)
PINDEF(AttinyPB4_RX, PORTB, PINB, DDRB, PORTB4)
PINDEF(AttinyPB5_RESET, PORTB, PINB, DDRB, PORTB5)
#else
#error "Unknown MCU"
#endif

//-----------------------------------------------------------------------------
#if !defined (__AVR_ATtiny13A__)
static INLINE void USART_Transmit( unsigned char data ) {
    while ( !( UCSR0A & _BV(UDRE0)) )
        ;
    UDR0 = data;
}

static INLINE void USART_InitUBRR(uint32_t ubrr) {
    UCSR0C = _BV(USBS0)|(3<<UCSZ00);
    UBRR0H = (unsigned char)(ubrr>>8);
    UBRR0L = (unsigned char)ubrr;
}

static INLINE void USART_InitBAUD(uint32_t baud) {
    USART_InitUBRR(F_CPU/(baud*16)-1);
}

static INLINE unsigned char USART_Receive( void ) {
    while ( !(UCSR0A & _BV(RXC0)) )
        ;
    return UDR0;
}

static INLINE uint8_t USART_CanRead() {
    return (UCSR0A & _BV(RXC0)) ? 1 : 0;
}

static INLINE uint8_t USART_CanWrite() {
    return (UCSR0A & _BV(UDRE0)) ? 1 : 0;
}

//-----------------------------------------------------------------------------
static INLINE void timer1_Stop() {
    AndNVal(TCCR1B, (1 << CS12) | (1 << CS11) | (1 << CS10));
}

static INLINE void timer1_CompareMatchOutputA_ClearOnMatch() {
    AndNVal(TCCR1A, _BV(COM1A1)|_BV(COM1A0));
    OrVal(TCCR1A, _BV(COM1A1));
}

static INLINE void timer1_EnableOverflowInterrupt() {
    OrVal(TIMSK1, (1 << TOIE1));
}

static INLINE void timer1_StartWithPrescaler1() {
    AndNVal(TCCR1B, (1 << CS12) | (1 << CS11) | (1 << CS10));
    OrVal(TCCR1B,   (1 << CS10));
}

static INLINE void timer1_FastPWM_TopICR1() {
    AndNVal(TCCR1A, _BV(WGM10));
    OrVal(TCCR1A, _BV(WGM11));

    OrVal(TCCR1B, _BV(WGM12));
    OrVal(TCCR1B, _BV(WGM13));
}

#endif
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

