set -e
SRC="src/main.cpp src/font.c src/font_asm.S src/scancodes.cpp"

mkdir -p out
avr-gcc -I /home/ai0/AVR/include \
    -Wall -gstabs+ \
    -Os \
    -mmcu=atmega328p \
    $SRC \
    -o out/vgaterm.elf \
    -std=gnu++1y

avr-objcopy -j .text -j .data -O ihex out/vgaterm.elf out/vgaterm.hex
avr-objdump -s -h -m avr -D out/vgaterm.elf > out/vgaterm.dump
avr-size -C -d --mcu=atmega328p out/vgaterm.elf | grep Full
cat out/vgaterm.dump | grep push | wc -l | sed 's,^,Push count = ,'
