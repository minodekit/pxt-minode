/**
 * Blocks to simulate MIDI instruments.
 */
//% weight=85 icon="\uf001" color="#5ea9dd"
namespace minode {
   
    /**
     * Maps a frequency to a note key
     */
    //% blockId=midi_rgb_choose_color block="RGB at %connName | with %color"
    //% shim=minode::rgbChooseColor
    export function rgbChooseColor(connName: ConnName, color: MiNodeColor): void {
        return;
    }
}