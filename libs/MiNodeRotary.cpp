#include "MiNodeRotary.h"

MiNodeRotary::MiNodeRotary() :
pin(NULL),currentAD(-1),count(0)
{
  this->baseId = MINODE_ID_MODULE_SWITCH;
  system_timer_add_component(this);
}

MiNodeRotary::~MiNodeRotary()
{
  if(pin) {
    delete pin;
  }
  system_timer_remove_component(this);
}

void MiNodeRotary::attach(AnalogConnName connName)
{
  if(this->cn != MN_NC) {
    return;
  }

  MiNodeComponent::initAConnector(connName);

  PinName pinName = MiNodeConn::calcP0Name(this->cna);
  if(pin) {
    delete pin;
  }
  pin = new AnalogIn(pinName);
}

void MiNodeRotary::systemTick()
{
  count++;

  if (count == 40)
  {
    if (currentAD == -1)
    {
      currentAD = getADValue();
    }
    else
    {
      if ((getADValue() - currentAD > 31) || (getADValue() - currentAD < -31))
      {
        MicroBitEvent evt(this->baseId + this->id,MINODE_ROTARY_EVT_CHANGE);
        currentAD = getADValue();
      }
    }
    count = 0;
  }
}

int MiNodeRotary::getPercentage()
{
  int temp;
  temp = getADValue();

  return temp*100/1023;
}

float MiNodeRotary::getVolt()
{
  float result;
  result = 3.3*(getADValue()/1023.0);

  return result;
}

int MiNodeRotary::getADValue()
{
  int temp=0;
  for (int i = 0; i < 3; ++i)
  {
    temp += pin->read_u16();
  }
  temp /= 3;
  return temp;
}




