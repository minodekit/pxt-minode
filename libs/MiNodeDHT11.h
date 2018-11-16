#ifndef MINODE_DHT11_H
#define MINODE_DHT11_H

#include "mbed.h"

#include "MicroBitConfig.h"
#include "MicroBitComponent.h"
#include "MicroBitEvent.h"
#include "MiNodeComponent.h"
#include "MiNodeConn.h"
#include "MicroBitDisplay.h"
#include "MicroBitSystemTimer.h"

#define MINODE_DHT_EVT_CHANGE                  1
#define TIME_TH 		                       10000

enum DHTTemStyle {
  //% block="Celsius" enumval=1
  MINODE_DHT_CELSIUS = 1,
  //% block="Fahrenheit" enumval=2
  MINODE_FAN_FAHRENHEIT = 2,
};

#define delay60US()\
t++;t++;t++;t++;t++;t++;t++;t++;t++;t++;\
t++;t++;t++;t++;t++;t++;t++;t++;t++;t++;\
t++;t++;t++;t++;t++;t++;t++;t++;t++;t++;\
t++;t++;t++;t++;t++;t++;t++;t++;t++;t++;\
t++;t++;t++;t++;t++;t++;t++;t++;t++;t++;\
t++;t++;t++;t++;t++;t++;t++;t++;t++;t++;\
t++;t++;t++;t++;t++;t++;t++;t++;t++;t++;\
t++;t++;t++;t++;t++;t++;t++;t++;t++;t++;\
t++;t++;t++;t++;t++;t++;t++;t++;t++;t++;\
t++;t++;t++;t++;t++;t++;t++;t++;t++;t++;\
t++;t++;t++;t++;t++;t++;t++;t++;t++;t++;\
t++;t++;t++;t++;t++;t++;t++;t++;t++;t++;\
t++;t++;t++;t++;t++;t++;t++;t++;t++;t++;\
t++;t++;t++;t++;t++;t++;t++;t++;t++;t++;\

class MiNodeDHT : public MiNodeComponent
{
  public:
    MiNodeDHT();

    int getTemperature();
    int getHumidity();
    int getFahrenheitTemperature();

    void attach(ConnName connName);
    virtual void systemTick();
    ~MiNodeDHT();

  private:
    DigitalInOut*  pin;

    int Humidity;
    int Temperature;
    int currentTem;
    int count;
    int bt;

    volatile int t;
    volatile int time_out;

    void dhtSet(int  level);
    int dhtGet();
    int whileGet(int v);
    void dhtStart();
    int dhtReadAck();
    void dhtReadOneBit();
    void dhtReadOneByte();
    int dhtGetHt();
};

#endif

