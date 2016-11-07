#include "MiNodeFan.h"

MiNodeFan::MiNodeFan() :
pin(NULL)
{
  this->baseId = MINODE_ID_MODULE_SWITCH;
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
	pin->write(1);
}

void MiNodeFan::fanClose()
{
	pin->write(0);
}

