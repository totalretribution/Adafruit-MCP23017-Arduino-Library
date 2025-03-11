/*!
 * @file Adafruit_MCP23X18.cpp
 */

#include "Adafruit_MCP23X18.h"

/**************************************************************************/
/*!
  @brief default ctor.
*/
/**************************************************************************/
Adafruit_MCP23X18::Adafruit_MCP23X18() { pinCount = 16; }

/**************************************************************************/
/*!
  @brief Configures the specified pin to behave either as an input or an
  output.
  @param pin the Arduino pin number to set the mode of
  @param mode INPUT, OUTPUT, or INPUT_PULLUP
*/
/**************************************************************************/
void Adafruit_MCP23X18::pinMode(uint8_t pin, uint8_t mode) {
  Adafruit_BusIO_Register IODIR(i2c_dev, spi_dev, MCP23XXX_SPIREG,
                                getRegister(MCP23XXX_IODIR, MCP_PORT(pin)));
  Adafruit_BusIO_Register GPPU(i2c_dev, spi_dev, MCP23XXX_SPIREG,
                               getRegister(MCP23XXX_GPPU, MCP_PORT(pin)));
  Adafruit_BusIO_RegisterBits dir_bit(&IODIR, 1, pin % 8);
  Adafruit_BusIO_RegisterBits pullup_bit(&GPPU, 1, pin % 8);

  dir_bit.write((mode == OUTPUT) ? 0 : 1);
  pullup_bit.write((mode == INPUT_PULLUP || mode == OUTPUT_PULLUP) ? 1 : 0);
}