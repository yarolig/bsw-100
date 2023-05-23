avrdude -p t13 -c stk500v1 -b 19200 -P /dev/ttyUSB0 -U flash:w:ps22spi.hex
