// Auto-generated. Do not edit.
declare namespace minode {

    /**
     * Add a switch module
     * @param switchId TODO
     * @param connName TODO
     * @param event TODO
     * @param body TODO
     */
    //% help=minode/add-a-switch-module weight=55 blockGap=8
    //% blockId=device_create_switch block="add switch|%SwitchName||%ConnName| |%SwitchEvent|" icon="\uf01e" shim=minode::createSwitch
    function createSwitch(switchId: SwitchName, connName: ConnName, event: SwitchEvent, body: () => void): void;
}

// Auto-generated. Do not edit. Really.
