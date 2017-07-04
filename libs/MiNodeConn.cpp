#include "MiNodeConn.h"

MiNodeConn::MiNodeConn(int id, PinName p0, PinName p1) :
  P0 (id, p0, PIN_CAPABILITY_ALL),
  P1 (id + 1, p1, PIN_CAPABILITY_ALL)
{

}

void MiNodeConn::calcPinName(ConnName name, PinName* p0, PinName* p1)
{
  PinName pin0 = NC;
  PinName pin1 = NC;

  switch(name) {
    case A0:
      pin0 = MICROBIT_PIN_P0;
      pin1 = MICROBIT_PIN_P1;
      break;
    case A1:
      pin0 = MICROBIT_PIN_P1;
      pin1 = MICROBIT_PIN_P2;
      break;
    case A2:
      pin0 = MICROBIT_PIN_P2;
      pin1 = MICROBIT_PIN_P3;
      break;
    case D12:
      pin0 = MICROBIT_PIN_P12;
      pin1 = MICROBIT_PIN_P13;
      break;
    case D13:
      pin0 = MICROBIT_PIN_P13;
      pin1 = MICROBIT_PIN_P14;
      break;
    case D14:
      pin0 = MICROBIT_PIN_P14;
      pin1 = MICROBIT_PIN_P15;
      break;
    case D15:
      pin0 = MICROBIT_PIN_P15;
      pin1 = MICROBIT_PIN_P16;
      break;
    default:
      pin0 = MICROBIT_PIN_P0;
      pin1 = MICROBIT_PIN_P1;
      break;
  }

  *p0 = pin0;
  *p1 = pin1;

  return;
}

void MiNodeConn::calcPinName(AnalogConnName name, PinName* p0, PinName* p1)
{
  PinName pin0 = NC;
  PinName pin1 = NC;

  switch(name) {
    case A0:
      pin0 = MICROBIT_PIN_P0;
      pin1 = MICROBIT_PIN_P1;
      break;
    case A1:
      pin0 = MICROBIT_PIN_P1;
      pin1 = MICROBIT_PIN_P2;
      break;
    case A2:
      pin0 = MICROBIT_PIN_P2;
      pin1 = MICROBIT_PIN_P3;
      break;
    default:
      pin0 = MICROBIT_PIN_P0;
      pin1 = MICROBIT_PIN_P1;
      break;
  }

  *p0 = pin0;
  *p1 = pin1;

  return;
}

ConnName MiNodeConn::calcConnName(PinName p0)
{
  ConnName conn = MN_NC;

  switch(p0) {
    case MICROBIT_PIN_P0:
      conn = A0;
      break;
    case MICROBIT_PIN_P1:
      conn = A1;
      break;
    case MICROBIT_PIN_P2:
      conn = A2;
      break;
    case MICROBIT_PIN_P12:
      conn = D12;
      break;
    case MICROBIT_PIN_P13:
      conn = D13;
      break;
    case MICROBIT_PIN_P14:
      conn = D14;
      break;
    case MICROBIT_PIN_P15:
      conn = D15;
      break;
    default:
      conn = A0;
      break;
  }
  return conn;
}

int MiNodeConn::calcId(ConnName name)
{
  return (int)name;
}

int MiNodeConn::calcId(AnalogConnName name)
{
  return (int)name;
}


PinName MiNodeConn::calcP0Name(ConnName name)
{
  PinName pin0;
  PinName pin1;
  MiNodeConn::calcPinName(name, &pin0, &pin1);

  return pin0;
}

PinName MiNodeConn::calcP0Name(AnalogConnName name)
{
  PinName pin0;
  PinName pin1;
  MiNodeConn::calcPinName(name, &pin0, &pin1);

  return pin0;
}

PinName MiNodeConn::calcP1Name(ConnName name)
{
  PinName pin0;
  PinName pin1;
  MiNodeConn::calcPinName(name, &pin0, &pin1);

  return pin1;
}

PinName MiNodeConn::calcP1Name(AnalogConnName name)
{
  PinName pin0;
  PinName pin1;
  MiNodeConn::calcPinName(name, &pin0, &pin1);

  return pin1;
}
