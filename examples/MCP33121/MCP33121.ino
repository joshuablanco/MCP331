#include <MCP331.h>

/*
This library can be used for MCP33111, MCP33121, MCP33131 single-ended 
for ATMEGA328P
Define first or declare as a variable
- division clock from 16 MHZ of ATMEGA328P could be (2,4,8,16,32,64,128)
- Number of Bits.
- Voltage Reference.
*/
#define Clock_Division 2
#define Num_Bits 14
#define V_Ref 5

MCP331 mcp331(10, Clock_Division, Num_Bits);

void setup(){
    mcp331.begin();    
    Serial.begin(9600);
}

void loop(){
    uint16_t value = mcp331.readMCP331();
    double value_temp = (double) value;
    double voltage = value_temp*(V_Ref/pow(value,2)-1);
    Serial.print("Voltage: ");
    Serial.println(value,4);    
}
