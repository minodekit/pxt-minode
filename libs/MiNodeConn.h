#ifndef MINODE_CONN_H
#define MINODE_CONN_H

#include "mbed.h"
#include "MicroBitConfig.h"
#include "MicroBitPin.h"

enum ConnName
{
  //% block="A0" enumval=0
  A0 = 0,
  //% block="A1" enumval=1
  A1 = 1,
  //% block="A2" enumval=2
  A2 = 2,
  //% block="D12" enumval=12
  D12 = 12,
  //% block="D13" enumval=13
  D13 = 13,
  //% block="D14" enumval=14
  D14 = 14,
  //% block="D15" enumval=15
  D15 = 15,
  //% block="NC" enumval=-1
  MN_NC = -1
};

enum AnalogConnName
{
  //% block="A0" enumval=0
  Analog_A0 = 0,
  //% block="A1" enumval=1
  Analog_A1 = 1,
  //% block="A2" enumval=2
  Analog_A2 = 2,
  //% block="NC" enumval=-1
  Analog_MN_NC = -1
};

class MiNodeConn
{

public:

  MicroBitPin      pin[0];
  MicroBitPin          P0;
  MicroBitPin          P1;

  MiNodeConn(int id, PinName p0, PinName p1);

  static void calcPinName(ConnName name, PinName* p0, PinName* p1);
  static void calcPinName(AnalogConnName name, PinName* p0, PinName* p1);
  static int calcId(ConnName name);
  static int calcId(AnalogConnName name);
  static ConnName calcConnName(PinName p0);
  static PinName calcP0Name(ConnName name);
  static PinName calcP0Name(AnalogConnName name);
  static PinName calcP1Name(ConnName name);
  static PinName calcP1Name(AnalogConnName name);

};

#endif