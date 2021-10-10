/*
This library can be used for MCP33111, MCP33121, MCP33131 single-ended 
for ATMEGA328P
Define first or declare as a variable
- division clock from 16 MHZ of ATMEGA328P could be (2,4,8,16,32,64,128)
- Number of Bits.
- Voltage Reference.
*/

#include <MCP331.h>

#define Clock_Division 2
#define Num_Bits 14
#define V_Ref 5.0

MCP331 mcp331(10, Clock_Division, Num_Bits);

void setup(){
    mcp331.begin();    
    Serial.begin(9600);
}

void loop(){
    uint16_t values = mcp331.readMCP331();
    double voltage = values*(V_Ref/pow(2,Num_Bits)-1);
    Serial.print("Voltage: ");
    Serial.println(voltage,4);    
}
