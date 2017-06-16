// Auto-generated. Do not edit.
declare namespace minode {

    /**
     * Get pinname
     */
    //% blockId=get_pin_name
    //% shim=minode::MinodeShim
    function getPin(connName: ConnName): number;

    /**
     * Get analog pinname
     */
    //% blockId=get_analog_pin_name
    //% shim=minode::MinodeShim
    function getanalogPin(connName: AnalogConnName): number;

    /**
     * Get Pin Property
     */
    //% blockId=get_pin_property
    //% shim=minode::MinodeShim
    function getPinProperty(connName: ConnName): number;

    /**
     * Do something when a switch is opened/closed
     * @param switchId a switch ID .
     * @param connName MiNode Connector Name
     * @param event Event to listen
     */
    //% blockId=device_on_switch_event block="switch %connName| on %event"
    //% shim=minode::MinodeShim
    function onSwitchEvent(connName: ConnName, event: SwitchEvent, body: () => void): void;

    /**
     * Get the switch state (open or not).
     */
    //% blockId=device_switch_is_opened block="switch %connName| is opened"
    //% advanced=true
    //% shim=minode::MinodeShim
    function switchIsOpened(connName: ConnName): boolean;

    /**
     * Get DHT11 temperature (celsius or fahrenheit).
     */
    //% blockId=device_DHT_GET_Temperature block="dht11 %connName| tempreature %FanStatus" 
    //% shim=minode::MinodeShim
    function DHTGetTemperature(connName: ConnName, style: DHTTemStyle): number;

    /**
     * Get DHT11 Humidity.
     */
    //% blockId=device_DHT_GET_Humidity block="dht11 %connName| humidity"
    //% advanced=true
    //% shim=minode::MinodeShim
    function DHTGetHumidity(connName: ConnName): number;

    /**
     * Do something when DHT11 temperature change.
     */
    //% blockId=device_on_DHTtemperature_CHANGE block="dht11 %connName| on temperature change"
    //% advanced=true
    //% shim=minode::MinodeShim
    function onDHTEvent(connName: ConnName, body: () => void): void;

    /**
     * Do something when PIR triggered.
     */
    //% blockId=device_on_PIR_trig block="pir %connName| on trigger"
    //% shim=minode::MinodeShim
    function onPIREvent(connName: ConnName, body: () => void): void;

    /**
     * Get the PIR state (trigger or not).
     */
    //% blockId=device_PIR_istrig block="pir %connName| is triggered"
    //% advanced=true
    //% shim=minode::MinodeShim
    function PIRIsTriggered(connName: ConnName): boolean;

    /**
     * Do something when Rotary change.
     */
    //% blockId=device_on_ROTARY_CHANGE block="rotary %connName| on trigger"
    //% shim=minode::MinodeShim
    function onRotaryEvent(connName: AnalogConnName, body: () => void): void;

    /**
     * Get Rotary percentage.
     */
    //% blockId=device_ROTARY_GET_Percentage block="rotary %connName| get Percentage"
    //% advanced=true
    //% shim=minode::MinodeShim
    function RotaryGetPercentage(connName: AnalogConnName): number;

    /**
     * Do something when Light level change.
     */
    //% blockId=device_on_LightSensor_CHANGE block="light %connName| on change"
    //% shim=minode::MinodeShim
    function onLightSensorEvent(connName: AnalogConnName, body: () => void): void;

    /**
     * Get Light level.from 1(brightest) to 5(darkness).
     */
    //% blockId=device_LightSensor_GET_light_level block="light %connName| get level"
    //% advanced=true
    //% shim=minode::MinodeShim
    function LightSensorGetLevel(connName: AnalogConnName): number;

    /**
     * Do something when MIC level change.
     */
    //% blockId=device_on_MIC_level_change block="mic %connName| on change"
    //% shim=minode::MinodeShim
    function onMICEvent(connName: AnalogConnName, body: () => void): void;

    /**
     * Get MIC level.from 1(quiet) to 5(noisy).
     */
    //% blockId=device_MIC_GET_mic_level block="mic %connName| get level"
    //% advanced=true
    //% shim=minode::MinodeShim
    function MICGetLevel(connName: AnalogConnName): number;

    /**
     * Choose an RGB color from the given table.
     */
    //% blockId=device_RGB_ChooseColor block="rgb led %connName| set %MiNodeColor"
    //% shim=minode::MinodeShim
    function RGBChooseColor(connName: ConnName, color: MiNodeColor): void;

    /**
     * Converts red, green, blue channels into a RGB color.
     */
    //% blockId=device_RGB_SetColor block="rgb led %connName| set red %red| green %green| blue %blue"
    //% advanced=true
    //% shim=minode::MinodeShim
    function RGBSetColor(connName: ConnName, red: number, green: number, blue: number): void;
}

// Auto-generated. Do not edit. Really.
