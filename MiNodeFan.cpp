#include "MiNodeFan.h"

MiNodeFan::MiNodeFan() :
pin(NULL)
{
  this->baseId = MINODE_ID_MODULE_FAN;
}

MiNodeFan::~MiNodeFan()
{
  if(pin) {
    delete pin;
  }
}

void MiNodeFan::attach(ConnName connName)
{
  if(this->cn != MN_NC) {
    return;
  }

  MiNodeComponent::initConnector(connName);
}

void MiNodeFan::fanOpen()
{
  PinName pinName = MiNodeConn::calcP0Name(this->cn);
  if(pin) {
    delete pin;
  }
  pin = new DigitalOut(pinName);
	pin->write(1);
}

void MiNodeFan::fanClose()
{
  PinName pinName = MiNodeConn::calcP0Name(this->cn);
  if(pin) {
    delete pin;
  }
  pin = new DigitalOut(pinName);
	pin->write(0);
}

