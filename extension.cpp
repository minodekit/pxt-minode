#include "pxt.h"
#include "MiNodeSwitch.h"
#include "MiNodeCore.h"




using namespace pxt;


namespace minode {


  /**
   * Do something when a switch (``A``, ``B``, ``C``, ``D``, ``E``) is opened /closed
   * @param switchId a switch ID .
   * @param connName MiNode Connector Name
   * @param event Event to listen
   */

  //% blockId=device_on_switch_event block="switch %SwitchId| connected to %connName |on %event"
  //% icon="\uf192"
  void onSwitchEvent(SwitchName switchId, ConnName connName, SwitchEvent event, Action body) {

    MiNodeSwitch switchModule((int)switchId, connName);

    switchModule.eventOn(event);

    registerWithDal((int)switchId, event, body);

  }


  /**
   * Get the button state (pressed or not) for ``A`` and ``B``.
   */

  //% blockId=device_switch_is_opened block="switch %SwitchId| connected to %connName| is opened"

  bool switchIsOened(SwitchName switchId, ConnName connName) {

    int isOpened;

    MiNodeSwitch a((int)switchId, connName);
    isOpened = a.isOpened();

    return isOpened ? true : false;
  }

}
