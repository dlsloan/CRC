#pragma once
//
//    FILE: CRC8.h
//  AUTHOR: Rob Tillaart
// PURPOSE: Arduino class for CRC8
//     URL: https://github.com/RobTillaart/CRC


#include "Arduino.h"

#define CRC8_DEFAULT_POLYNOME       0x07


class CRC8
{
public:
  CRC8(bool will_yield=true);

  // set parameters to default
  void     reset();       // set all to constructor defaults
  void     restart();     // reset crc with same parameters.

  // set parameters
  void     setPolynome(uint8_t polynome)  { _polynome = polynome; };
  void     setStartXOR(uint8_t start)     { _startMask = start; };
  void     setEndXOR(uint8_t end)         { _endMask = end; };
  void     setReverseIn(bool reverseIn)   { _reverseIn = reverseIn; };
  void     setReverseOut(bool reverseOut) { _reverseOut = reverseOut; };

  // get parameters
  uint8_t  getPolynome()   { return _polynome; };
  uint8_t  getStartXOR()   { return _startMask; };
  uint8_t  getEndXOR()     { return _endMask; };
  bool     getReverseIn()  { return _reverseIn; };
  bool     getReverseOut() { return _reverseOut; };

  void     add(uint8_t value);
  void     add(const uint8_t * array, int length);

  uint8_t  getCRC();  // returns CRC
  uint32_t count()    { return _count; };

private:
  uint8_t  _reverse(uint8_t value);
  void     _update(uint8_t value);

  uint8_t  _polynome;
  uint8_t  _startMask;
  uint8_t  _endMask;
  uint8_t  _crc;
  bool     _reverseIn;
  bool     _reverseOut;
  bool     _started;
  bool     _will_yield;
  uint32_t _count;
};


// -- END OF FILE --

