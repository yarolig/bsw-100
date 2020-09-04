#pragma once

#include <avr/pgmspace.h>
#include "aiavr.h"

#define BSW_F1 (128+1)
#define BSW_F2 (128+2)
#define BSW_F3 (128+3)
#define BSW_F4 (128+4)
#define BSW_F5 (128+5)
#define BSW_F6 (128+6)
#define BSW_F7 (128+7)
#define BSW_F8 (128+8)
#define BSW_F9 (128+9)
#define BSW_F10 (128+10)
#define BSW_F11 (128+11)
#define BSW_F12 (128+12)

#define BSW_LEFT (128+13)
#define BSW_RIGHT (128+14)
#define BSW_UP (128+15)
#define BSW_DOWN (128+16)
#define BSW_HOME (128+17)
#define BSW_END (128+18)
#define BSW_PAGEUP (128+19)
#define BSW_PAGEDOWN (128+20)
#define BSW_DELETE (128+21)
#define BSW_INSERT (128+22)

#define BSW_NUMLOCK (128+23)
#define BSW_CAPSLOCK (128+24)
#define BSW_SCROLLLOCK (128+25)

#define BSW_MENU (128+26)
#define BSW_WINKEYL (128+27)
#define BSW_WINKEYR (128+28)
#define BSW_SYSRQ (128+29)




extern const u8 PROGMEM scancodes[];
