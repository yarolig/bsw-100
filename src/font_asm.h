#pragma once

#include "font.h"
extern "C" void draw_screen_scanline();
extern "C" void prepare_screen_scanline(unsigned char* console_line,
                                        const char* fontline,
                                        unsigned char* scanline);
extern "C" void clear_console_line(unsigned char* console_line, unsigned char value);
