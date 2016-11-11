#include "pxt.h"
#include "MiNode.h"

using namespace pxt;

MiNode node;

namespace minode {

  /**
   * Get pinname
   */
  //% blockId=get_pin_name
  int getPin(ConnName connName)
  {
    int temp=0;

    PinName pinName1 = MiNodeConn::calcP0Name(connName);

    switch(pinName1)
    {
      case MICROBIT_PIN_P0:
        temp = MICROBIT_ID_IO_P0;
        break;
      case MICROBIT_PIN_P1:
        temp = MICROBIT_ID_IO_P1;
        break;
      case MICROBIT_PIN_P2:
        temp = MICROBIT_ID_IO_P2;
        break;
      case MICROBIT_PIN_P12:
        temp = MICROBIT_ID_IO_P12;
        break;
      case MICROBIT_PIN_P13:
        temp = MICROBIT_ID_IO_P13;
        break;
      case MICROBIT_PIN_P14:
        temp = MICROBIT_ID_IO_P14;
        break;
      case MICROBIT_PIN_P15:
        temp = MICROBIT_ID_IO_P15;
        break;
      default:
        temp = 0;
        break;
    }

    return temp;
  }

    /**
   * Get analog pinname
   */
  //% blockId=get_analog_pin_name
  int getanalogPin(AnalogConnName connName)
  {
    int temp=0;

    PinName pinName1 = MiNodeConn::calcP0Name(connName);

    switch(pinName1)
    {
      case MICROBIT_PIN_P0:
        temp = MICROBIT_ID_IO_P0;
        break;
      case MICROBIT_PIN_P1:
        temp = MICROBIT_ID_IO_P1;
        break;
      case MICROBIT_PIN_P2:
        temp = MICROBIT_ID_IO_P2;
        break;
      default:
        temp = 0;
        break;
    }

    return temp;
  }

  /**
   * Get Pin Property
   */
  //% blockId=get_pin_property
  int getPinProperty(ConnName connName)
  {
    if (connName == A0 || connName == A1 || connName == A2)
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }


  /**
   * Do something when a switch is opened/closed
   * @param switchId a switch ID .
   * @param connName MiNode Connector Name
   * @param event Event to listen
   */

  //% blockId=device_on_switch_event block="switch %connName| on %event"
  void onSwitchEvent(ConnName connName, SwitchEvent event, Action body)
  {
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
  //% advanced=true
  bool switchIsOpened(ConnName connName)
  {

    MiNodeSwitch* pSwitch;
    int isOpened;

    pSwitch = node.switches.attach(connName);
    isOpened = pSwitch->isOpened();

    return isOpened ? true : false;
  }

  /**
  * Get DHT11 temperature (celsius or fahrenheit).
  */
  //% blockId=device_DHT_GET_Temperature block="dht11 %connName| tempreature %FanStatus"
  int DHTGetTemperature(ConnName connName , DHTTemStyle style)
  {
    MiNodeDHT* pDHT11;
    int dht_tempreature=0;

    pDHT11 = node.dht11.attach(connName);
    switch(style) {
      case MINODE_DHT_CELSIUS:
          dht_tempreature = pDHT11->getTemperature();
        break;
      case MINODE_FAN_FAHRENHEIT:
          dht_tempreature = pDHT11->getFahrenheitTemperature();
        break;
    }

    return dht_tempreature;
  }

  /**
  * Get DHT11 Humidity.
  */
  //% blockId=device_DHT_GET_Humidity block="dht11 %connName| humidity"
  //% advanced=true
  int DHTGetHumidity(ConnName connName)
  {
    MiNodeDHT* pDHT11;
    int dht_humidity=0;

    pDHT11 = node.dht11.attach(connName);
    dht_humidity = pDHT11->getHumidity();

    return dht_humidity;
  }

  /**
  * Do something when DHT11 temperature change.
  */
  //% blockId=device_on_DHTtemperature_CHANGE block="dht11 %connName| on temperature change"
  //% advanced=true
  void onDHTEvent(ConnName connName, Action body)
  {
    int id;
    MiNodeDHT* pDHT11;

    pDHT11 = node.dht11.attach(connName);
    id = pDHT11->getId();

    registerWithDal(id, MINODE_DHT_EVT_CHANGE, body);
  }

  /**
  * Do something when PIR triggered.
  */
  //% blockId=device_on_PIR_trig block="pir %connName| on trigger"
  void onPIREvent(ConnName connName, Action body)
  {
    int id;
    MiNodePIR* pPir;

    pPir = node.pir.attach(connName);
    id = pPir->getId();

    registerWithDal(id, MINODE_PIR_EVT_TRIG, body);
  }

  /**
  * Get the PIR state (trigger or not).
  */
  //% blockId=device_PIR_istrig block="pir %connName| is triggered"
  //% advanced=true
  bool PIRIsTriggered(ConnName connName)
  {

    MiNodePIR* pPir;
    int triggered;

    pPir = node.pir.attach(connName);
    triggered = pPir->isTriged();

    return triggered ? true : false;
  }

  /**
   * Do something when Rotary change.
   */
  //% blockId=device_on_ROTARY_CHANGE block="rotary %connName| on trigger"
  void onRotaryEvent(AnalogConnName connName, Action body)
  {
    int id;
    MiNodeRotary* pRotary;

    pRotary = node.rotary.attach(connName);
    id = pRotary->getId();

    registerWithDal(id, MINODE_ROTARY_EVT_CHANGE, body);
  }

  /**
   * Get Rotary percentage.
  */
  //% blockId=device_ROTARY_GET_Percentage block="rotary %connName| get Percentage"
  //% advanced=true
  int RotaryGetPercentage(AnalogConnName connName)
  {
    MiNodeRotary* pRotary;
    int rotaryPercentage=0;

    pRotary = node.rotary.attach(connName);
    rotaryPercentage = pRotary->getPercentage();

    return rotaryPercentage;
  }

  /**
  * Do something when Light level change.
  */
  //% blockId=device_on_LightSensor_CHANGE block="light %connName| on change"
  void onLightSensorEvent(AnalogConnName connName, Action body)
  {
    int id;
    MiNodeLight* pLight;

    pLight = node.light.attach(connName);
    id = pLight->getId();

    registerWithDal(id, MINODE_LIGHT_EVT_LEVEL_CHANGE, body);
  }

  /**
   * Get Light level.from 1(brightest) to 5(darkness).
  */
  //% blockId=device_LightSensor_GET_light_level block="light %connName| get level"
  //% advanced=true
  int LightSensorGetLevel(AnalogConnName connName)
  {
    MiNodeLight* pLight;
    int lightLevel=0;

    pLight = node.light.attach(connName);
    lightLevel = pLight->getLightLevel();

    return lightLevel;
  }

  /**
  * Do something when MIC level change.
  */
  //% blockId=device_on_MIC_level_change block="mic %connName| on change"
  void onMICEvent(AnalogConnName connName, Action body)
  {
    int id;
    MiNodeMIC* pMic;

    pMic = node.mic.attach(connName);
    id = pMic->getId();

    registerWithDal(id, MINODE_MIC_EVT_NOISE, body);
  }

  /**
   * Get MIC level.from 1(quiet) to 5(noisy).
  */
  //% blockId=device_MIC_GET_mic_level block="mic %connName| get level"
  //% advanced=true
  int MICGetLevel(AnalogConnName connName)
  {
    MiNodeMIC* pMic;
    int micLevel=0;

    pMic = node.mic.attach(connName);
    micLevel = pMic->getMicLevel();

    return micLevel;
  }

  /**
 * Choose an RGB color from the given table.
 */
  //% blockId=device_RGB_ChooseColor block="rgb led %connName| set %MiNodeColor"
  void RGBChooseColor(ConnName connName , MiNodeColor color)
  {
    MiNodeRGB* pRGB;

    pRGB = node.rgb.attach(connName);

    pRGB->chooseColor(color);
  }

  /**
  * Converts red, green, blue channels into a RGB color.
  */
  //% blockId=device_RGB_SetColor block="rgb led %connName| set red %red| green %green| blue %blue"
  //% advanced=true
  void RGBSetColor(ConnName connName , int red, int green, int blue)
  {
    MiNodeRGB* pRGB;

    pRGB = node.rgb.attach(connName);

    pRGB->setRGB(red,green,blue);
  }

}
