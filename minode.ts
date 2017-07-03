
/**
 * Provides access to basic minode functionality.
 */
//% color=#2699BF weight=5
namespace minode {

    /**
     * Get pinname
     */
    //% blockId=get_pin_name
    //% shim=minode::getPin
    export function getPin(connName: ConnName): number{
      return 1;
    }

    /**
     * Get analog pinname
     */
    //% blockId=get_analog_pin_name
    //% shim=minode::getanalogPin
    export function getanalogPin(connName: AnalogConnName): number{
      return 1;
    }

    /**
     * Get Pin Property
     */
    //% blockId=get_pin_property
    //% shim=minode::getPinProperty
    export function getPinProperty(connName: ConnName): number{
      return 1;
    }


    /**
     * Do something when a switch is opened/closed
     * @param switchId a switch ID .
     * @param connName MiNode Connector Name
     * @param event Event to listen
     */
    //% blockId=device_on_switch_event block="switch %connName| on %event"
    //% shim=minode::onSwitchEvent
    export function onSwitchEvent(connName: ConnName, event: SwitchEvent, body: () => void): void{

    }

    /**
     * Get the switch state (open or not).
     */
    //% blockId=device_switch_is_opened block="switch %connName| is opened"
    //% advanced=true
    //% shim=minode::switchIsOpened
    export function switchIsOpened(connName: ConnName): boolean{
      return true;
    }

    /**
     * Get DHT11 temperature (celsius or fahrenheit).
     */
    //% blockId=device_DHT_GET_Temperature block="dht11 %connName| tempreature %FanStatus" 
    //% shim=minode::DHTGetTemperature
    export function DHTGetTemperature(connName: ConnName, style: DHTTemStyle): number{
      return 1;
    }

    /**
     * Get DHT11 Humidity.
     */
    //% blockId=device_DHT_GET_Humidity block="dht11 %connName| humidity"
    //% advanced=true
    //% shim=minode::DHTGetHumidity
    export function DHTGetHumidity(connName: ConnName): number{
      return 1;
    }

    /**
     * Do something when DHT11 temperature change.
     */
    //% blockId=device_on_DHTtemperature_CHANGE block="dht11 %connName| on temperature change"
    //% advanced=true
    //% shim=minode::onDHTEvent
    export function onDHTEvent(connName: ConnName, body: () => void): void{
    
    }

    /**
     * Do something when PIR triggered.
     */
    //% blockId=device_on_PIR_trig block="pir %connName| on trigger"
    //% shim=minode::onPIREvent
    export function onPIREvent(connName: ConnName, body: () => void): void{

    }

    /**
     * Get the PIR state (trigger or not).
     */
    //% blockId=device_PIR_istrig block="pir %connName| is triggered"
    //% advanced=true
    //% shim=minode::PIRIsTriggered
    export function PIRIsTriggered(connName: ConnName): boolean{
      return true;
    }

    /**
     * Do something when Rotary change.
     */
    //% blockId=device_on_ROTARY_CHANGE block="rotary %connName| on trigger"
    //% shim=minode::onRotaryEvent
    export function onRotaryEvent(connName: AnalogConnName, body: () => void): void{

    }

    /**
     * Get Rotary percentage.
     */
    //% blockId=device_ROTARY_GET_Percentage block="rotary %connName| get Percentage"
    //% advanced=true
    //% shim=minode::RotaryGetPercentage
    export function RotaryGetPercentage(connName: AnalogConnName): number{
      return 1;
    }

    /**
     * Do something when Light level change.
     */
    //% blockId=device_on_LightSensor_CHANGE block="light %connName| on change"
    //% shim=minode::onLightSensorEvent
    export function onLightSensorEvent(connName: AnalogConnName, body: () => void): void{

    }

    /**
     * Get Light level.from 1(brightest) to 5(darkness).
     */
    //% blockId=device_LightSensor_GET_light_level block="light %connName| get level"
    //% advanced=true
    //% shim=minode::LightSensorGetLevel
    export function LightSensorGetLevel(connName: AnalogConnName): number{
      return 1;
    }

    /**
     * Do something when MIC level change.
     */
    //% blockId=device_on_MIC_level_change block="mic %connName| on change"
    //% shim=minode::onMICEvent
    export function onMICEvent(connName: AnalogConnName, body: () => void): void{

    }

    /**
     * Get MIC level.from 1(quiet) to 5(noisy).
     */
    //% blockId=device_MIC_GET_mic_level block="mic %connName| get level"
    //% advanced=true
    //% shim=minode::MICGetLevel
    export function MICGetLevel(connName: AnalogConnName): number{
      return 1;
    }

    /**
     * Choose an RGB color from the given table.
     */
    //% blockId=device_RGB_ChooseColor block="rgb led %connName| set %MiNodeColor"
    //% shim=minode::RGBChooseColor
    export function RGBChooseColor(connName: ConnName, color: MiNodeColor): void{

    }

    /**
     * Converts red, green, blue channels into a RGB color.
     */
    //% blockId=device_RGB_SetColor block="rgb led %connName| set red %red| green %green| blue %blue"
    //% advanced=true
    //% shim=minode::RGBSetColor
    export function RGBSetColor(connName: ConnName, red: number, green: number, blue: number): void{

    }

    /**
     * control the motor speed (0 to 100)
     */
    //% blockId=device_motor_control1 block="fan %connName| speed %speed"
    export function FanControl_1(connName:AnalogConnName , speed:number): void
    {
      speed *= 200;
      pins.servoSetPulse(getanalogPin(connName),speed);
    }

    /**
     * relay control(open / close)
     */
    //% blockId=device_relay_control block="relay %connName| set %status"
    //% advanced=true
    export function RelayControl(connName:ConnName , status:FanStatus): void
    {
      if(getPinProperty(connName) == 1)
      {
        switch(status) {
            case 1:
                pins.analogWritePin(getPin(connName),1023);
              break;
            case 2:
                pins.analogWritePin(getPin(connName),0);
              break;
        }
      }
      else
      {
        switch(status) {
            case 1:
                pins.digitalWritePin(getPin(connName),1);
              break;
            case 2:
                pins.digitalWritePin(getPin(connName),0);
              break;
        }
      }

    }
}

// Auto-generated. Do not edit. Really.
