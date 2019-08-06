# BSW-100
## What is it?
BSW-100 is a video terminal made of atmega328p and some parts.

## Warranty
No warranty. Be prepared that BSW-100 will destroy your PC, router, monitor,
PS/2 keyboard and power supply, cause fire, explosions, epilepsy and unexpected
radiation (including ionizing radiation).

See LICENSE.txt for details.

## Features
 - Popular 16Mhz atmega328 chip with small number of other parts
 - 40x29 characters, 6x5 font (or 6x10, even lines are black)
 - Single color on black background, whitespace can be highlighted
 - VGA output
 - PS/2 keyboard
 - Serial interface that can be connected to a router or a PC
 - BackSpace Works! Arrow keys, F1-F12, Home/End too.
 - Terminfo entry
 - Working programs: bash, vim, more, links
 - TODO: mc, alsamixer, less, aptitude, nethack, emacs, info, nano
 - TODO: NumLock, CapsLock, Shift+Function keys, Ctrl+[, Alt+X
 - TODO: highlight text to make mc usable

## Misfeatures
 - Meagre font
 - Delayed reaction to key presses

## Installing with platformio
To build firmware install platformio and run

    ./rebuild-font.sh
    platformio run
To flash firmware run:

    platformio run --target upload

## Installing with Debian or Ubuntu
Install dependencies:

    apt-get install gcc-avr binutils-avr avr-libc avrdude

Run:

    ./build.sh

Flash with avrdude:

    avrdude -p m328p -c arduino -b 57600 -U flash:w:out/vgaterm.hex -P /dev/ttyUSB0
or just:

    ./flash.sh

## Using as a PC serial terminal
Launch:

    sudo setsid /sbin/getty -L 57600 ttyUSB0 dumb

## Instlling terminfo
This command writes terminal description to ~/.terminfo/

    tic bsw100.terminfo

## Using as a console for router
Break you router apart, locate UART interface, solder some wires and connect
GND, TX, RX from router to GND, RX, TX pins of atmega328p.

## Hardware

    ROUTER_RX--TX1            VIN
    ROUTER_TX--RX1            GND--KB_GND--VGA_GND
               RST            RST
    ROUTER_GND-GND            5V---KB_POWER
               D2             A7
    VGA_VSYNC--D3             A6
               D4   Arduino   A5
               D5    Nano     A4
               D6             A3
               D7             A2---1k resistor--VGA_B
               D8             A1---1k resistor--VGA_G
    VGA_HSYNC--D9             A0---1k resistor--VGA_R
    GND--------D10            REF
    KB_DATA----D11            3V3
               D12            D13--NOT gate--NOT gate--KB_CLK






