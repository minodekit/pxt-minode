#ifndef MINODE_PIR_H
#define MINODE_PIR_H

#include "mbed.h"

#include "mbed.h"
#include "MicroBitConfig.h"
#include "MicroBitComponent.h"
#include "MicroBitEvent.h"
#include "MiNodeComponent.h"

#define MINODE_PIR_EVT_TRIG                  1
#define MINODE_PIR_EVT_CLOSE                 2

class MiNodePIR : public MiNodeComponent
{
public:

  MiNodePIR();

  void onTrigger();
  int readPir();
  int isTriged();

  void attach(ConnName connName);

  ~MiNodePIR();

private:
  InterruptIn* pin;
  
};

#endif
