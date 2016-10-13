#ifndef MINODE_SWITCH_H
#define MINODE_SWITCH_H

#include "MiNodeCore.h"


#define MINODE_ID_SWITCH_A  MINODE_ID_SWITCH_START + 1
#define MINODE_ID_SWITCH_B  MINODE_ID_SWITCH_START + 2
#define MINODE_ID_SWITCH_C  MINODE_ID_SWITCH_START + 3
#define MINODE_ID_SWITCH_D  MINODE_ID_SWITCH_START + 4
#define MINODE_ID_SWITCH_E  MINODE_ID_SWITCH_START + 5


typedef enum {
  SWITCH_A = MINODE_ID_SWITCH_START + 1,
  SWITCH_B,
  SWITCH_C,
  SWITCH_D,
  SWITCH_E
}SwitchName;


typedef enum {
  MINODE_SWITCH_EVT_OPEN = 1,
  MINODE_SWITCH_EVT_CLOSE = 2,
}SwitchEvent;

class MiNodeSwitch : public MicroBitComponent
{
public:
  MiNodeSwitch(int id, ConnName connName);
  MiNodeSwitch(int id, PinName pinName);

  void eventOn(int eventType);

  int isOpened();




private:
  InterruptIn pin;

  void onOpen();
  void onClose();
};

#endif