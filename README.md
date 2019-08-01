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
 - 40x29 characters
 - Single color on black background
 - VGA output
 - PS/2 keyboard
 - Serial interface that can be connected to router or PC
 - BackSpace Works!
 - TODO: arrow keys, F1-F12, Home/End, NumLock
 - TODO: terminfo entry or shell script to configure terminal
 - TODO: It is still dumb terminal, vim or mc will not work with it
 - TODO: understand Escape-sequences that should be invisible

## Misfeatures
- Terrible font
- Delayed reaction to key presses

## Installing with platformio
To build firmware install platformio and run

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

## Using as a console for router
Break you router apart, locate UART interface, solder some wires and connect
GND, TX, RX from router to GND, RX, TX pins of atmega328p.
