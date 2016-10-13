#include "MiNodeSwitch.h"

namespace minode {

    //%
  int extfun_switch(int x, int y) {
      return x + y;
  }


}

MiNodeSwitch::MiNodeSwitch(int id, ConnName connName) :
pin(MiNodeConn::calcP0Name(connName))
{
  this->id = id;
  pin.mode(PullNone);
}

MiNodeSwitch::MiNodeSwitch(int id, PinName pinName) :
pin(pinName)
{
  this->id = id;
  pin.mode(PullNone);
}

void MiNodeSwitch::eventOn(int eventType)
{
  switch(eventType) {
    case MINODE_SWITCH_EVT_OPEN:
      pin.rise(this, &MiNodeSwitch::onOpen);
      break;
    case MINODE_SWITCH_EVT_CLOSE:
      pin.fall(this, &MiNodeSwitch::onClose);
      break;
  }
}

void MiNodeSwitch::onOpen()
{
  MicroBitEvent(id, MINODE_SWITCH_EVT_OPEN);
}

void MiNodeSwitch::onClose()
{
  MicroBitEvent(id, MINODE_SWITCH_EVT_CLOSE);
}

int MiNodeSwitch::isOpened()
{
  return pin.read();
}