avrdude -p m328p -c arduino -b 57600 -U flash:w:out/vgaterm.hex -P /dev/ttyUSB0 
