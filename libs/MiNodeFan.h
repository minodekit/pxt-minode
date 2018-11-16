#ifndef MINODE_FAN_H
#define MINODE_FAN_H

#include "mbed.h"

#include "MicroBitConfig.h"
#include "MicroBitComponent.h"
#include "MicroBitEvent.h"
#include "MiNodeComponent.h"
#include "MiNodeConn.h"
#include "MicroBitDisplay.h"
#include "MicroBitSystemTimer.h"


enum FanStatus
{
  //% block="open" enumval=1
  MINODE_FAN_OPEN = 1,
  //% block="close" enumval=2
  MINODE_FAN_CLOSE = 2
};

class MiNodeFan : public MiNodeComponent
{
public:

  MiNodeFan();
  ~MiNodeFan();

  void attach(ConnName connName);

  void fanOpen();
  void fanClose();

private:
  DigitalOut* pin;
};

#endif