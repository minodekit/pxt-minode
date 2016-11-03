// Auto-generated. Do not edit.
declare namespace minode {

    /**
     * Do something when a switch (``A``, ``B``, ``C``, ``D``, ``E``) is opened /closed
     * @param switchId a switch ID .
     * @param connName MiNode Connector Name
     * @param event Event to listen
     */
    //% blockId=device_on_switch_event block="switch %switchId| connected to %connName |on %event"
    //% icon="\uf192" shim=minode::onSwitchEvent
    function onSwitchEvent(switchId: SwitchName, connName: ConnName, event: SwitchEvent, body: () => void): void;

    /**
     * Get the button state (pressed or not) for ``A`` and ``B``.
     */
    //% blockId=device_switch_is_opened block="switch %SwitchId| connected to %connName| is opened" shim=minode::switchIsOened
    function switchIsOened(switchId: SwitchName, connName: ConnName): boolean;
}

// Auto-generated. Do not edit. Really.
