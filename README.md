# pxt-minode

Mi:Node Kit(micro:bit accessories by Embest) driver package for [PXT/microbit](https://pxt.microbit.org)

## Usage

1. Open [Microsoft PXT/microbit](https://pxt.microbit.org) and new a project
2. Search and add the `minode` package
3. Use the `Minode` drawer in the editor to drag out and arrange the blocks
4. Click `Download` to move your program to the micro:bit

## About minode Kit

The Mi:Node kit is a modular, safe and easy to use group of items that allow kids to minimize the effort required to get started with IOT learning with [micro:bit](https://www.microbit.org).

![](minode.png)

For this kit, there is no need for soldering, plug then use, the construction of the working circuit can be done within one minute.

- Safe, Ready-to-use like Lego
    + It is modular
    + Safe for kids. No need for soldering
    + Easy. Just plug then use it
    + Expandable and reusable
- Ten modules Focus on IOT Node
    + 10 sensor modules include:environmental monitoring, user interface, physical monitoring
    + Can be built a lot of cool projects include wearable device and smart home, etc.

More please refer to http://www.embest-tech.com.

## Example
Change the RGB LED color by pressing the button A and B.

```blocks
input.onButtonPressed(Button.A, () => {
    minode.rgbChooseColor(ConnName.D13, MiNodeColor.MiNode_RGB_COLOR_RED)
})
input.onButtonPressed(Button.B, () => {
    minode.rgbChooseColor(ConnName.D13, MiNodeColor.MiNode_RGB_COLOR_GREEN)
})
```

![](rgb2.jpg)

## License

MIT

## Supported targets

* for PXT/microbit
(The metadata above is needed for package search.)

```package
minode=github:minodekit/pxt-minode
```