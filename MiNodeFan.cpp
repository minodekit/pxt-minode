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
  
  PinName pinName = MiNodeConn::calcP0Name(this->cn);
  if(pin) {
    delete pin;
  }
  pin = new DigitalOut(pinName);

  MiNodeComponent::initConnector(connName);
}

void MiNodeFan::fanOpen()
{
	pin->write(1);
}

void MiNodeFan::fanClose()
{
	pin->write(0);
}

