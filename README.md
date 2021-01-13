#** MCP331## **
Contains the library for MCP331##. I required for my final year thesis.
Feel free to give in constructive feedback on my email id joshua.andres.blanco@gmail.com

hope this would be useful for you.

This library can be used for MCP33111, MCP33121, MCP33131 single-ended  for ATMEGA328P. The main difference among those ADC is the number of bits and such parameter can be set in the constructor of the class MCP331#

Summarizing, this library contains two functions:

- constuctor MCP331 nameOfVariable(int CS, int clockDivider, int numBits)
    - CS, chip selector wired to CNVST in the MCP331#
    - clockDivider, number to divide the clock comming from de SPI Serial Clock. use by default 2.
    - numBits, number of bits related to the reference MCP33111, MCP33121, MCP33131; 12, 14 or 16 bits respectively

- readMCP331() {return uint16_t foo}. 
    - This reading is the equivalent number in the ADC range, is not the equivalent in volts. 

- calibrate() this function calibrates the ADC voltage supply.



