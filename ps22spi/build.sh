set -e
SRC="main.cpp"

mkdir -p out
avr-gcc \
    -Wall -gstabs+ \
    -ffunction-sections -fdata-sections \
    -Wl,--gc-sections \
    -Os \
    -mmcu=attiny13a \
    $SRC \
    -o ps22spi.elf \
    -std=gnu++1y

avr-objcopy -j .text -j .data -O ihex ps22spi.elf ps22spi.hex
avr-objdump -s -h -m avr -D ps22spi.elf > ps22spi.dump
avr-size -C -d --mcu=atmega328p ps22spi.elf | grep Full
cat ps22spi.dump | grep push | wc -l | sed 's,^,Push count = ,'
