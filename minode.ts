/**
 * Blocks to simulate MIDI instruments.
 */
//% weight=85 icon="\uf001" color="#5ea9dd"
namespace minode {
   
    /**
     * Maps a frequency to a note key
     */
    //% blockId=minode_rgb_choose_color block="RGB at %connName | with %color"
    //% shim=minode::rgbChooseColor
    export function rgbChooseColor(connName: ConnName, color: MiNodeColor): void {
        return;
    }

    /**
     * Converts red, green, blue channels into a RGB color.
     */
    //% blockId=minode_rgb_setcolor block="rgb led %connName| set red %red| green %green| blue %blue"
    //% advanced=true
    //% shim=minode::RGBSetColor
    export function RGBSetColor(connName: ConnName, red: number, green: number, blue: number): void{
    	return;
    }

    /**
     * Get DHT11 temperature (celsius or fahrenheit).
     */
    //% blockId=minode_dht_get_temperature block="dht11 %connName| tempreature %FanStatus" 
    //% shim=minode::DHTGetTemperature
    export function DHTGetTemperature(connName: ConnName, style: DHTTemStyle): number{
      return 0;
    }

    /**
     * Get DHT11 Humidity.
     */
    //% blockId=minode_dht_get_humidity block="dht11 %connName| humidity"
    //% advanced=true
    //% shim=minode::DHTGetHumidity
    export function DHTGetHumidity(connName: ConnName): number{
      return 0;
    }

    /**
     * Do something when DHT11 temperature change.
     */
    //% blockId=minode_on_dhttemperature_change block="dht11 %connName| on temperature change"
    //% advanced=true
    //% shim=minode::onDHTEvent
    export function onDHTEvent(connName: ConnName, body: () => void): void{
    	return;
    }

    /**
     * Do something when a switch is opened/closed
     * @param switchId a switch ID .
     * @param connName MiNode Connector Name
     * @param event Event to listen
     */
    //% blockId=minode_on_switch_event block="switch %connName| on %event"
    //% shim=minode::onSwitchEvent
    export function onSwitchEvent(connName: ConnName, event: SwitchEvent, body: () => void): void{
    	return;
    }

    /**
     * Get the switch state (open or not).
     */
    //% blockId=minode_switch_is_opened block="switch %connName| is opened"
    //% advanced=true
    //% shim=minode::switchIsOpened
    export function switchIsOpened(connName: ConnName): boolean{
      return true;
    }

    /**
     * Do something when Rotary change.
     */
    //% blockId=minode_on_ROTARY_CHANGE block="rotary %connName| on trigger"
    //% shim=minode::onRotaryEvent
    export function onRotaryEvent(connName: AnalogConnName, body: () => void): void{
    	return;
    }

    /**
     * Get Rotary percentage.
     */
    //% blockId=minode_ROTARY_GET_Percentage block="rotary %connName| get Percentage"
    //% advanced=true
    //% shim=minode::RotaryGetPercentage
    export function RotaryGetPercentage(connName: AnalogConnName): number{
      return 0;
    }

    /**
     * Do something when PIR triggered.
     */
    //% blockId=minode_on_PIR_trig block="pir %connName| on trigger"
    //% shim=minode::onPIREvent
    export function onPIREvent(connName: ConnName, body: () => void): void{
    	return;
    }

    /**
     * Get the PIR state (trigger or not).
     */
    //% blockId=minode_PIR_istrig block="pir %connName| is triggered"
    //% advanced=true
    //% shim=minode::PIRIsTriggered
    export function PIRIsTriggered(connName: ConnName): boolean{
      return true;
    }

    /**
     * Do something when MIC level change.
     */
    //% blockId=device_on_MIC_level_change block="mic %connName| on change"
    //% shim=minode::onMICEvent
    export function onMICEvent(connName: AnalogConnName, body: () => void): void{
    	return;
    }

    /**
     * Get MIC level.from 1(quiet) to 5(noisy).
     */
    //% blockId=device_MIC_GET_mic_level block="mic %connName| get level"
    //% advanced=true
    //% shim=minode::MICGetLevel
    export function MICGetLevel(connName: AnalogConnName): number{
      return 0;
    }

    /**
     * Do something when Light level change.
     */
    //% blockId=device_on_LightSensor_CHANGE block="light %connName| on change"
    //% shim=minode::onLightSensorEvent
    export function onLightSensorEvent(connName: AnalogConnName, body: () => void): void{
    	return;
    }

    /**
     * Get Light level.from 1(brightest) to 5(darkness).
     */
    //% blockId=device_LightSensor_GET_light_level block="light %connName| get level"
    //% advanced=true
    //% shim=minode::LightSensorGetLevel
    export function LightSensorGetLevel(connName: AnalogConnName): number{
      return 0;
    }

}