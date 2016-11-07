#include "pxt.h"
#include "MiNode.h"


using namespace pxt;

MiNode node;

namespace minode {

  /**
   * Do something when a switch is opened /closed
   * @param switchId a switch ID .
   * @param connName MiNode Connector Name
   * @param event Event to listen
   */

  //% blockId=device_on_switch_event block="switch %connName| on %event"
  //% icon="\uf192"
  void onSwitchEvent(ConnName connName, SwitchEvent event, Action body) {
    int id;
    MiNodeSwitch* pSwitch;

    pSwitch = node.switches.attach(connName);
    id = pSwitch->getId();

    registerWithDal(id, event, body);
  }


  /**
   * Get the switch state (open or not).
   */

  //% blockId=device_switch_is_opened block="switch %connName| is opened"

  bool switchIsOened(ConnName connName) {

    MiNodeSwitch* pSwitch;
    int isOpened;

    pSwitch = node.switches.attach(connName);
    isOpened = pSwitch->isOpened();

    return isOpened ? true : false;
  }

  /**
   * Control the mini Fan (open or close).
   */

  //% blockId=device_fan_control block="fan %connName| is %FanStatus"

  void FanControl(ConnName connName , FanStatus status)
  {
    MiNodeFan* pFan;

    pFan = node.fan.attach(connName);

    switch(status) {
      case MINODE_FAN_OPEN:
          pFan->fanOpen();
        break;
      case MINODE_FAN_CLOSE:
          pFan->fanClose();
        break;
    }
  }

}
