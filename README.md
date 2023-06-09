# MPL3115A2-Library
The MPL3115A2 is a low-cost, low power, highly accurate barometric pressure sensor. The aim of this project is to create a weather station that consists of an LCD display and the pressure sensor MPL3115A2.

The MPL3115A2 sensor is controlled via the I2C bus. This bus consists of only two lines: the data line (marked as SDA, serial data) and the line of the transmission clock (marked as SCL, serial clock). These two lines carry all information: data, addresses and control signals. To establish a connection between the MPL3115A2 and the microcontroller, you need to connect the following pins:

VCC->+3.3V

GND->GND

SDA->PC1

SCL->PC0

The LCD display works with the AVR Atmega32 microcontroller using 4-bit mode, where four data lines (D4-D7) are used to send commands and data. These data lines can be connected to any Atmega32 port. To establish a connection between the LCD and the microcontroller, you need to connect the following pins:

D4-D7->PA4-PA7

E->PA3

RS->PA2
