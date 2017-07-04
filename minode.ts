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
      return 1;
    }

    /**
     * Get DHT11 Humidity.
     */
    //% blockId=minode_dht_get_humidity block="dht11 %connName| humidity"
    //% advanced=true
    //% shim=minode::DHTGetHumidity
    export function DHTGetHumidity(connName: ConnName): number{
      return 1;
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

}