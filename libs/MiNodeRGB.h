#ifndef MINODE_RGB_H
#define MINODE_RGB_H

#include "mbed.h"

#include "MicroBitConfig.h"
#include "MicroBitComponent.h"
#include "MicroBitEvent.h"
#include "MiNodeComponent.h"
#include "MiNodeConn.h"
#include "MicroBitDisplay.h"
#include "MicroBitSystemTimer.h"

enum MiNodeColor
{
  //% block="Red" enumval=0
  MiNode_RGB_COLOR_RED = 0,
  //% block="Green" enumval=1
  MiNode_RGB_COLOR_GREEN = 1,
  //% block="Blue" enumval=2
  MiNode_RGB_COLOR_BLUE = 2,
  //% block="Yellow" enumval=3
  MiNode_RGB_COLOR_YELLOW = 3,
  //% block="Pink" enumval=4
  MiNode_RGB_COLOR_PINK = 4,
  //% block="Cyan" enumval=5
  MiNode_RGB_COLOR_CYAN = 5,
  //% block="White" enumval=6
  MiNode_RGB_COLOR_WHITE = 6
};

class MiNodeRGB : public MiNodeComponent
{
public:
  MiNodeRGB();

  void setRGB(uint8_t r,uint8_t g,uint8_t b);
  void setRGBInHex(unsigned int);
  void chooseColor(MiNodeColor c);

  void attach(ConnName connName);
  ~MiNodeRGB();

private:
  DigitalOut* CLOCK;
  DigitalOut* DATA;

  unsigned int rgbHEX;

  void rgbDelay();
  void rgbWrite(uint8_t r,uint8_t g,uint8_t b);
  void rgbClockWrite(int value);
  void rgbDataWrite(int value);

};

#endif