//Release Date: 12-1-2021
//joshua.andres.blanco@gmail.com

/*===========================================================================
MCP33121 device library code is placed under the MIT license
Copyright (c) 2021 Joshua Blanco

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
===========================================================================*/
#ifndef MCP331_H
#define MCP331_H

#include "Arduino.h"

class MCP331{
    public:
    MCP331(int CS = 10, uint8_t clockDivider, uint8_t numBits);
    void begin();
    uint16_t readMCP331();
    void reCalibrate();

    private:
    int _chipSelector = 0;
    double _periodArduinoDivision = 0;   
    uint8_t _numBits = 14;
};
#endif