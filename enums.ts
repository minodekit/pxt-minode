enum ConnName
{
  //% block="A0" enumval=0
  A0 = 0,
  //% block="A1" enumval=1
  A1 = 1,
  //% block="A2" enumval=2
  A2 = 2,
  //% block="D12" enumval=12
  D12 = 12,
  //% block="D13" enumval=13
  D13 = 13,
  //% block="D14" enumval=14
  D14 = 14,
  //% block="D15" enumval=15
  D15 = 15
}

enum AnalogConnName
{
  //% block="A0" enumval=0
  Analog_A0 = 0,
  //% block="A1" enumval=1
  Analog_A1 = 1,
  //% block="A2" enumval=2
  Analog_A2 = 2
}

enum SwitchEvent
{
  //% block="open" enumval=1
  MINODE_SWITCH_EVT_OPEN = 1,
  //% block="close" enumval=2
  MINODE_SWITCH_EVT_CLOSE = 2,
}

enum FanStatus
{
  //% block="open" enumval=1
  MINODE_FAN_OPEN = 1,
  //% block="close" enumval=2
  MINODE_FAN_CLOSE = 2,
}

enum DHTTemStyle
{
  //% block="Celsius" enumval=1
  MINODE_DHT_CELSIUS = 1,
  //% block="Fahrenheit" enumval=2
  MINODE_FAN_FAHRENHEIT = 2,
}

enum  MiNodeColor
{
  //% block="Red" enumval=0
  MiNode_RGB_COLOR_RED = 0,
  //% block="Green" enumval=1
  MiNode_RGB_COLOR_GREEN = 1,
  //% block="Blue" enumval=2
  MiNode_RGB_COLOR_BLUE = 2,
  //% block="Yellow" enumval=3
  MiNode_RGB_COLOR_YELLOW = 3,
  //% block="Pink" enumval=4
  MiNode_RGB_COLOR_PINK = 4,
  //% block="Cyan" enumval=5
  MiNode_RGB_COLOR_CYAN = 5,
  //% block="White" enumval=6
  MiNode_RGB_COLOR_WHITE = 6,
}