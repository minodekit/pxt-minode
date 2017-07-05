#include "MiNodeMIC.h"

MiNodeMIC::MiNodeMIC() :
pin(NULL),count(0),currentAD(-1)
{
  this->baseId = MINODE_ID_MODULE_LIGHT;
  system_timer_add_component(this);
}

MiNodeMIC::~MiNodeMIC()
{
  if(pin) {
    delete pin;
  }
  system_timer_remove_component(this);
}

void MiNodeMIC::attach(AnalogConnName connName)
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

void MiNodeMIC::systemTick()
{
  count++;
  int temp_ad=0;

  if (count == 20)
  {
    temp_ad = getADvalue();
    if (currentAD == -1)
    {
      currentAD = temp_ad;
    }
    else
    {
      if ((temp_ad - currentAD > MINODE_MIC_NOISE_THRESHOLD) || (temp_ad - currentAD < (0-MINODE_MIC_NOISE_THRESHOLD)))
      {
        MicroBitEvent evt(this->baseId + this->id,MINODE_MIC_EVT_NOISE);
        currentAD = temp_ad;
      }
    }
    count = 0;
  }
}

unsigned int MiNodeMIC::getADvalue()
{
  unsigned int temp=0;

  for (int i = 0; i < 32; ++i)
  {
    temp+=pin->read_u16();
  }
  temp >>= 5;

  return temp;
}

int MiNodeMIC::getMicLevel()
{
  unsigned int temp=0;
  temp = getADvalue();

  if ((temp > MICROBIT_MIC_MIN) && (temp < MICROBIT_MIC_LEVEL_A+1))
  {
    return MICROBIT_MIC_LEVEL_1;
  }
  else if ((temp > MICROBIT_MIC_LEVEL_A) && (temp < MICROBIT_MIC_LEVEL_B+1))
  {
    return MICROBIT_MIC_LEVEL_2;
  }
  else if ((temp > MICROBIT_MIC_LEVEL_B) && (temp < MICROBIT_MIC_LEVEL_C+1))
  {
    return MICROBIT_MIC_LEVEL_3;
  }
  else if ((temp > MICROBIT_MIC_LEVEL_C) && (temp < MICROBIT_MIC_LEVEL_D+1))
  {
    return MICROBIT_MIC_LEVEL_4;
  }
  else if ((temp > MICROBIT_MIC_LEVEL_D) && (temp < MICROBIT_MIC_MAX+1))
  {
    return MICROBIT_MIC_LEVEL_5;
  }
  else
  {
    return MICROBIT_MIC_LEVEL_ERROR;
  }
}


