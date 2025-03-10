/*!
 * @file Adafruit_MCP23X18.h
 */

#ifndef __ADAFRUIT_MCP23X18_H__
#define __ADAFRUIT_MCP23X18_H__

#include "Adafruit_MCP23X17.h"

#define OUTPUT_PULLUP 4 //!< Additional define for Output with Pullup

/**************************************************************************/
/*!
    @brief  Class for MCP23018 I2C and MCP23S18 SPI variants.
*/
/**************************************************************************/
class Adafruit_MCP23X18 : public Adafruit_MCP23X17 {
public:
  Adafruit_MCP23X18();
  
  void pinMode(uint8_t pin, uint8_t mode);

};

#endif
