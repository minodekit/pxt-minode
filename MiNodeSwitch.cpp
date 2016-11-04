#include "MiNodeSwitch.h"


MiNodeSwitch::MiNodeSwitch() :
pin(NULL)
{
  this->baseId = MINODE_ID_MODULE_SWITCH;
}


MiNodeSwitch::~MiNodeSwitch()
{
  if(pin) {
    delete pin;
  }
}

void MiNodeSwitch::attach(ConnName connName)
{
  if(this->cn != MN_NC) {
    return;
  }

  MiNodeComponent::initConnector(connName);
  eventOn();
}


void MiNodeSwitch::eventOn()
{
  PinName pinName = MiNodeConn::calcP0Name(this->cn);
  if(pin) {
    delete pin;
  }
  pin = new InterruptIn(pinName);

  pin->mode(PullNone);
  pin->rise(this, &MiNodeSwitch::onOpen);
  pin->fall(this, &MiNodeSwitch::onClose);
}

void MiNodeSwitch::onOpen()
{
  MicroBitEvent(this->baseId + this->id, MINODE_SWITCH_EVT_OPEN);
}

void MiNodeSwitch::onClose()
{
  MicroBitEvent(this->baseId + this->id, MINODE_SWITCH_EVT_CLOSE);
}

int MiNodeSwitch::isOpened()
{
  int status = 0;
  if(pin) {
    status = pin->read();
  }
  return status;
}