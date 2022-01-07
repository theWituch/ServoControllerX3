#
- rotated encoders gate transoptors for more space

# 1.2.0
- the dimensions of the plate have been corrected to 159x73mm (from 157x72mm)
- PCB dimensions have been corrected to 170x73mm (from 159x72mm), adding one housing module
- IC3-5 and IC6-8 have been relocated
- individual voltage fuses for DC / DC converters have been added with LEDs indicating burnout
- the USB interface has been implemented
- RX / TX signaling diodes for communication have been added
- an RS-485 interface with two RJ-45 sockets was implemented instead of the RS-232
- changed the + -12V converter type from Traco to Aimtec
- a diode has been added to protect the 3V3 power supply against overvoltage


# 1.1.0
- the error of connecting the encoder interface ENCODER1 has been corrected - the connection of the CH1_QE_x leads has been changed:
CH1_QE_A> IC9.30
CH1_QE_B> IC9.33
CH1_QE_I> IC9.31
- fixed error of connecting (no ground) relay output RO1 - change to 5V power supply
- the resistance values ​​of the resistors R27 and R28 have been changed
R27> 1K ohm
228> 470 ohms
- the bug with the description of the R27 and R28 resistors has been corrected
- added external SPI EEPROM memory
- RS232 interface socket has been changed from DB9 plug to RJ9
- the position of the 24 / + - 12V converter and accessories has been corrected
- the position of the 5 / 3.3V converter and accessories has been corrected
- the +/- 12V voltage lead has been added to the OUTPUT connector

# 1.0.0
- the first version of the layout
