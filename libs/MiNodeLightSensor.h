#ifndef MINODE_LIGHT_H
#define MINODE_LIGHT_H

#include "mbed.h"
#include "MicroBitConfig.h"
#include "MicroBitComponent.h"
#include "MicroBitEvent.h"
#include "MiNodeComponent.h"
#include "MiNodeConn.h"
#include "MicroBitSystemTimer.h"


#define MINODE_LIGHT_EVT_LEVEL_CHANGE          1

#define MICROBIT_LIGHT_STATE                   1
#define MICROBIT_LIGHT_STATE_CHANGE            2

#define MINODE_LIGHT_SAMPLE_NUM                3

#define MICROBIT_LIGHT_MIN                     0
#define MICROBIT_LIGHT_LEVEL_A                 256
#define MICROBIT_LIGHT_LEVEL_B                 512
#define MICROBIT_LIGHT_LEVEL_C                 768
#define MICROBIT_LIGHT_LEVEL_D                 900
#define MICROBIT_LIGHT_MAX                     1023

#define MICROBIT_LIGHT_LEVEL_NULL              0
#define MICROBIT_LIGHT_LEVEL_1                 1
#define MICROBIT_LIGHT_LEVEL_2                 2
#define MICROBIT_LIGHT_LEVEL_3                 3
#define MICROBIT_LIGHT_LEVEL_4                 4
#define MICROBIT_LIGHT_LEVEL_5                 5
#define MICROBIT_LIGHT_LEVEL_ERROR             9


class MiNodeLight : public MiNodeComponent
{
	public:
	  MiNodeLight();

	  unsigned short getLightLevel(void);
	  unsigned short getLight(void);

  	void attach(AnalogConnName connName);

	  virtual void systemTick();
	   ~MiNodeLight();

	private:
	  AnalogIn* pin;
	  int sigma;
		int pre_status;
};

#endif