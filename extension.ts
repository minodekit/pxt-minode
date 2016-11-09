namespace minode {
    /**
     * Help goes here.
     */
    //% shim=minode::extfun
    export function extfun(x: number, y: number) {
        // Dummy implementation for the simulator.
        return x - y
    }



    //% blockId=device_on_switch_event2 block="switch2 %connName| on %event"
    export function onSwitchEvent2(connName: ConnName, event: SwitchEvent, body: Action): void {
    	onSwitchEvent(connName, event, body);
    } 
}
