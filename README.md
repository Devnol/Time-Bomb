# Time-Bomb

This is a bomb (that detonates only acoustically and is kinda nervewracking) that I originally made on November 2019, when I was twelve years old. 

It doesn't have any functional use but I think it's pretty cool if you wanna pull a prank on your friends or something.

Original code can be viewed in [the v1.0 tag archive](https://github.com/Devnol/Time-Bomb/releases/tag/v1.0). I had also made a fork of this (before I knew how GitHub forks worked) that you can find [here](https://github.com/Devnol/Time-Bomb-With-Selector). The only difference of that one is that it used a potentiometer to choose the time before it "detonates" instead of it being hardcoded. Changes after the v1.0 tag in this repository will include that feature, albeit with push buttons. 
### Parts Required:

- Arduino board (tested on UNO/Atmel 328p, any with pwm and i2c support should work)
- 16x2 Character LCD display
- I2c Character LCD driver (that matches the LCD's power requirements)
- 3x momentary push buttons
- 3x 1kΩ resistors
- Piezo buzzer
- 100Ω resistor
- Some form of power supply for the Arduino and circuit

An example wiring diagram is attached as a [png image](blob/master/Time_Bomb_Schematic.png) and [Fritzing sketch file](blob/master/Time_Bomb_Schematic.fzz).

