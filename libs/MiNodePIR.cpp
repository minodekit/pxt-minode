#include "MiNodePIR.h"

MiNodePIR::MiNodePIR() :
pin(NULL)
{
  this->baseId = MINODE_ID_MODULE_PIR;
}

MiNodePIR::~MiNodePIR()
{
  if(pin) {
    delete pin;
  }
}

void MiNodePIR::attach(ConnName connName)
{
  if(this->cn != MN_NC) {
    return;
  }

  MiNodeComponent::initConnector(connName);

  PinName pinName = MiNodeConn::calcP0Name(this->cn);
  if(pin) {
    delete pin;
  }
  pin = new InterruptIn(pinName);
  pin->mode(PullNone);
  pin->rise(this, &MiNodePIR::onTrigger);
}

int MiNodePIR::isTriged()
{
  int temp=0;
  for (int i = 0; i < 10; ++i)
  {
    if (readPir() != 0)
    {
      temp += 1;
    }
  }
  if(temp > 8)
    return 1;
  else
    return 0;
}

void MiNodePIR::onTrigger()
{
  MicroBitEvent evt(this->baseId + this->id,MINODE_PIR_EVT_TRIG);
}

int MiNodePIR::readPir()
{
	return pin->read();
}



