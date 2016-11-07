// Auto-generated. Do not edit.
declare namespace minode {

    /**
     * Do something when a switch is opened /closed
     * @param switchId a switch ID .
     * @param connName MiNode Connector Name
     * @param event Event to listen
     */
    //% blockId=device_on_switch_event block="switch %connName| on %event"
    //% icon="\uf192" shim=minode::onSwitchEvent
    function onSwitchEvent(connName: ConnName, event: SwitchEvent, body: () => void): void;

    /**
     * Get the switch state (open or not).
     */
    //% blockId=device_switch_is_opened block="switch %connName| is opened" shim=minode::switchIsOened
    function switchIsOened(connName: ConnName): boolean;

    /**
     * Control the mini Fan (open or close).
     */
    //% blockId=device_fan_control block="fan %connName| is %FanStatus" shim=minode::FanControl
    function FanControl(connName: ConnName, status: FanStatus): void;
}

// Auto-generated. Do not edit. Really.
