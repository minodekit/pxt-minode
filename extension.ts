
/**
 * Provides access to basic minode functionality.
 */
//% color=#2699BF weight=5
namespace minode {


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
