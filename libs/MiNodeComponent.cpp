#include "MiNodeComponent.h"

MiNodeComponent::MiNodeComponent() :
cn(MN_NC),cna(Analog_MN_NC),baseId(0)
{
  this->id = MINODE_ID_NC;
}

MiNodeComponent::~MiNodeComponent()
{

}

void MiNodeComponent::initConnector(ConnName connName)
{
  if(cn != MN_NC) {
    return;
  }

  cn = connName;
  this->id = MiNodeConn::calcId(connName);
}

void MiNodeComponent::initAConnector(AnalogConnName connName)
{
  if(cna != Analog_MN_NC) {
    return;
  }

  cna = connName;
  this->id = MiNodeConn::calcId(connName);
}

ConnName MiNodeComponent::getConnector()
{
  return cn;
}

AnalogConnName MiNodeComponent::AgetConnector()
{
  return cna;
}

int MiNodeComponent::getId()
{
  return baseId + this->id;
}