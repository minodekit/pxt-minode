#ifndef MINODE_SWITCH_H
#define MINODE_SWITCH_H

#include "mbed.h"
#include "MicroBitConfig.h"
#include "MicroBitComponent.h"
#include "MicroBitEvent.h"
#include "MiNodeComponent.h"


typedef enum {
  MINODE_SWITCH_EVT_OPEN = 1,
  MINODE_SWITCH_EVT_CLOSE = 2,
}SwitchEvent;


class MiNodeSwitch : public MiNodeComponent
{
public:
  MiNodeSwitch();
  ~MiNodeSwitch();

  void attach(ConnName connName);

  int isOpened();


private:
  void onOpen();
  void onClose();
  void eventOn();

  InterruptIn* pin;
};

#endif