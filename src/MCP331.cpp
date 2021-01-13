#include "MCP331.h"
#include "SPI.h"
#include "Arduino.h"

// Suggested CS = 10

MCP331::MCP331(int CS, int clockDivider, uint8_t numBits){    
    _chipSelector = CS;
    _numBits = numBits;
    double _offsetTimming = 64.0;// time with no activity to the ADC
    double _fAtmega328 = 16000000.0;
    double _division = _fAtmega328/clockDivider;
    _periodArduinoDivision = (1024/division) + _offsetTimming;

    switch(clockDivider){
        case 2:
            SPI.setClockDivider(SPI_CLOCK_DIV2);//8MHZ                     
            break;
        case 4:
            SPI.setClockDivider(SPI_CLOCK_DIV4);//4MHZ  
            break;
        case 8:
            SPI.setClockDivider(SPI_CLOCK_DIV8);//2MHZ
            break;
        case 16:
            SPI.setClockDivider(SPI_CLOCK_DIV16);//1MHZ
            break;
        case 32:
            SPI.setClockDivider(SPI_CLOCK_DIV32);
            break;
        case 64:
            SPI.setClockDivider(SPI_CLOCK_DIV64);
            break;
        case 128:
            SPI.setClockDivider(SPI_CLOCK_DIV128);
            break;        
    }  

    SPI.setBitOrder(MSBFIRST);//conf mas significativo revision de esto 
    SPI.setDataMode(SPI_MODE0);// reloj arriba sample flanco subida
    SPI.begin();     
}

void MCP331::begin(void){
    pinMode(_chipSelector,OUTPUT);    
    digitalWrite(_chipSelector, HIGH);    
}

uint16_t MCP331::readMCP331(){
    digitalWrite(_chipSelector, LOW);
    uint8_t _msb = SPI.transfer(0xFF);
    uint8_t lsb = SPI.transfer(0xFF);
    digitalWrite(_chipSelector, HIGH);
    uint16_t val = (((uint16_t) msb << 8)| lsb);
    if(_numBits == 14) {val = val >> 2;}//for 14 bits
    else if(_numBits == 16) {val = val;}
    else if(_numBits == 12) {val = val>> 4;}
    return val;

}

void MCP331::reCalibrate(){
    Serial.println("Recalibrating do not touch anything...!");
    delay(64);   
    digitalWrite(_chipSelector, LOW);
    delayMicroseconds(_periodArduinoDivision);   
    uint8_t sdo = SPI.transfer(0xFF);
    while(sdo == 0X00) delayMicroSeconds(700);
    digitalWrite(_chipSelector,HIGH);
    Serial.println("Done...!");
}