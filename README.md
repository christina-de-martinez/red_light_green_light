# Red light, green light game for an Adafruit Flora

I have been wanting to try making something with circuits for a while, but have been a bit intimidated. Then I discovered conductive thread and [Adafruit FLORA](https://www.adafruit.com/product/659) parts at a local library's makerspace.

This is the code for a red light, green light game that I made for my nieces, who are 6 and 4 years old. It randomly cycles through red, yellow, and green light mode at random intervals between 1-2.5 seconds long. There's a special "purple light" mode that flashes all of the LEDs purple—that's when the players are supposed to do a silly dance.

This tutorial was helpful to learn how to use conductive thread: https://learn.adafruit.com/flora-accelerometer/wiring-with-conductive-thread

# Materials:

* 3 AAA batteries
* Battery holder with on/off switch: https://www.adafruit.com/product/727
* Adafruit FLORA board: https://www.adafruit.com/product/659
* 6 Neopixel LEDs: https://www.adafruit.com/product/1260
* Conductive thread; I used 2-ply: https://www.adafruit.com/product/640
* Embroidery needle
* Embroidery hoop (not technically necessary, I guess, but helps a ton)
* Scissors
* Background fabric; I used a fat quarter of white quilting cotton
* Optional: small amounts of red, green, and yellow fabric
* Thread and a sewing machine (you could hand sew if you don't have access to a sewing machine)
* For sharper seams, use an iron. I'm not sure if you should iron over the conductive thread, but I avoided doing so.

# Schematic

![A schematic for the circuit. Connect a battery pack containing 3 AAA batteries to an Adafruit FLORA board using the associated plug. Then connect VBATT to the first NeoPixel LED's +, GND to the first NeoPixel's -, and D6 to the in arrow. Then chain each additional NeoPixel by connecting the plus to the next NeoPixel's plus, the out to the next NeoPixel's in, and the minus to the next NeoPixel's minus. Chain 6 NeoPixels together this way.](schematic.png "Schematic")
