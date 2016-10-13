#include "pxt.h"
#include "MiNodeSwitch.h"
#include "MiNodeCore.h"




using namespace pxt;


namespace minode {



  //%
  int extfun(int x, int y) {
      return x + y;
  }

  PinName testfun2() {
    return MiNodeConn::calcP0Name(A0);
  }


  /**
   * Add a switch module
   * @param switchId TODO
   * @param connName TODO
   * @param event TODO
   * @param body TODO
   */
  //% help=minode/add-a-switch-module weight=55 blockGap=8
  //% blockId=device_create_switch block="add switch|%SwitchName||%ConnName| |%SwitchEvent|" icon="\uf01e"
  void createSwitch(SwitchName switchId, ConnName connName, SwitchEvent event, Action body) {

    MiNodeSwitch switchModule((int)switchId, connName);

    switchModule.eventOn(event);

    registerWithDal((int)switchId, event, body);

  }

}
