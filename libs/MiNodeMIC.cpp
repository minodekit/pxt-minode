#include "MiNodeMIC.h"

MiNodeMIC::MiNodeMIC() :
pin(NULL)
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

void MiNodeMIC::checking(void)
{
  static int adHolder[8] = {0,0,0,0,0,0,0,0};
  static int ad_count = 0;
  int temp = 0;
  int i=0;
  int current_ad = 0;
  static int tri_flag = 0;
  static int time_count = 0;

  current_ad = pin->read_u16();
  if (current_ad > 528)
  {
    adHolder[ad_count%8] = current_ad - 528;
    ad_count++;
  }
  else
  {
    adHolder[ad_count%8] = 528 - current_ad;
    ad_count++;
  }

  if (tri_flag == 1)
  {
    time_count++;
    if (time_count > 1000)
    {
      tri_flag = 0;
      time_count = 0;
    }
  }

  if(tri_flag == 0)
  {
    for(i=0; i<8; i++)
    {
      temp += adHolder[i];
    }
    temp /= 8;

    if(temp > 150)
    {
      MicroBitEvent evt(this->baseId + this->id,MINODE_MIC_EVT_NOISE);
      tri_flag = 1;
      temp = 0;
    }
  }
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

  timer.attach_us(this, &MiNodeMIC::checking, 500);
}

void MiNodeMIC::detachTimer()
{
  timer.detach();
}


