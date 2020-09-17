#pragma once
#include <avr/io.h>
#include <avr/pgmspace.h>

extern __attribute__ ((aligned (512))) PROGMEM const char font_char_scanlines[];
extern __attribute__ ((aligned (256))) char font_chars[];
extern __attribute__ ((aligned (256))) PROGMEM const char font_chars_P[];
extern const char font_space_index;
extern const char font_cursor_index;
