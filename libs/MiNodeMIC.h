#ifndef MINODE_MIC_H
#define MINODE_MIC_H

#include "mbed.h"

#include "MicroBitConfig.h"
#include "MicroBitComponent.h"
#include "MicroBitEvent.h"
#include "MiNodeComponent.h"
#include "MiNodeConn.h"
#include "MicroBitDisplay.h"
#include "MicroBitSystemTimer.h"

#define MINODE_MIC_EVT_NOISE                  1

#define MINODE_MIC_NOISE_THRESHOLD            50

#define MICROBIT_MIC_MIN                     0
#define MICROBIT_MIC_LEVEL_A                 256
#define MICROBIT_MIC_LEVEL_B                 512
#define MICROBIT_MIC_LEVEL_C                 768
#define MICROBIT_MIC_LEVEL_D                 900
#define MICROBIT_MIC_MAX                     1023

#define MICROBIT_MIC_LEVEL_NULL              0
#define MICROBIT_MIC_LEVEL_1                 1
#define MICROBIT_MIC_LEVEL_2                 2
#define MICROBIT_MIC_LEVEL_3                 3
#define MICROBIT_MIC_LEVEL_4                 4
#define MICROBIT_MIC_LEVEL_5                 5
#define MICROBIT_MIC_LEVEL_ERROR             9

class MiNodeMIC : public MiNodeComponent
{
  public:
    MiNodeMIC();

    unsigned int getADvalue();
    int getMicLevel();

    void attach(AnalogConnName connName);

    virtual void systemTick();
    ~MiNodeMIC();

  private:
    AnalogIn* pin;
    int count;
    int currentAD;

};

#endif