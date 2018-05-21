#include "MiNodeDHT11.h"


MiNodeDHT::MiNodeDHT() :
pin(NULL),currentTem(-99)
{
  this->baseId = MINODE_ID_MODULE_DHT11;
  system_timer_add_component(this);
}

MiNodeDHT::~MiNodeDHT()
{
  if(pin) {
    delete pin;
  }
  system_timer_remove_component(this);
}

void MiNodeDHT::attach(ConnName connName)
{
  if(this->cn != MN_NC) {
    return;
  }

  MiNodeComponent::initConnector(connName);
  PinName pinName = MiNodeConn::calcP0Name(this->cn);
  if(pin) {
    delete pin;
  }
  pin = new DigitalInOut(pinName);
}

void MiNodeDHT::dhtSet(int level)
{
  pin->output();
  pin->mode(PullNone);
  pin->write(level);
}

int MiNodeDHT::dhtGet()
{
  pin->input();
  return pin->read();
}

int MiNodeDHT::whileGet(int v)
{
  time_out = 0;
  while((v==dhtGet()) && (time_out < TIME_TH))
  {
    time_out ++;
  }
  if(time_out == TIME_TH)
    return 1;
  else
    return 0;
}

void MiNodeDHT::dhtStart()
{
    dhtSet(1);
    delay60US();
    dhtSet(0);
    wait_ms(25);
    dhtSet(1);
}

int MiNodeDHT::dhtReadAck()
{
    if(whileGet(1) == 1)
      return 1;
    if(whileGet(0) == 1)
      return 1;
    if(whileGet(1) == 1)
      return 1;

    return 0;
}

void MiNodeDHT::dhtReadOneBit()
{
  whileGet(0);
  delay60US();
  bt <<= 1;
  if(1==dhtGet())
  {
    bt |= 1;
    whileGet(1);
  }
  else
    bt |= 0;
}

void MiNodeDHT::dhtReadOneByte()
{
  bt=0;
  dhtReadOneBit();
  dhtReadOneBit();
  dhtReadOneBit();
  dhtReadOneBit();
  dhtReadOneBit();
  dhtReadOneBit();
  dhtReadOneBit();
  dhtReadOneBit();
}

void MiNodeDHT::systemTick()
{
  int temp=0;
  count++;

 if (count == 200)
  {
    dhtGetHt();
    if (currentTem == -99)
    {
      currentTem = Temperature;
    }

    if((Temperature - currentTem == 1) || (currentTem - Temperature == 1))
    {
      currentTem = temp;
      MicroBitEvent(this->baseId + this->id, MINODE_DHT_EVT_CHANGE);
    }
    count = 0;
  }

}

int MiNodeDHT::dhtGetHt()
{
    int CHECKSUM=0;
    int R_H=0;
    int R_L=0;
    int T_H=0;
    int T_L=0;

    dhtStart();
    if(dhtReadAck() == 1)
      return 0;

    dhtReadOneByte();
    R_H = bt;
    dhtReadOneByte();
    R_L = bt;
    dhtReadOneByte();
    T_H = bt;
    dhtReadOneByte();
    T_L = bt;
    dhtReadOneByte();
    CHECKSUM = bt;

    if(CHECKSUM == R_H+R_L+T_H+T_L)
    {
        Humidity = R_H;
        Temperature = T_H;
        return 0;
    }
    else
        return 1;
}

int MiNodeDHT::getTemperature()
{
  if (currentTem == -99)
  {
    dhtGetHt();
    currentTem = Temperature;
  }
  return Temperature;
}

int MiNodeDHT::getFahrenheitTemperature()
{
  if (currentTem == -99)
  {
    dhtGetHt();
    currentTem = Temperature;
  }
  return Temperature*9/5+32;
}

int MiNodeDHT::getHumidity()
{
  if (currentTem == -99)
  {
    dhtGetHt();
    currentTem = Temperature;
  }
  return Humidity;
}



