# EGEN 310R Rover Project
## Section 6 Group B8 10:00am - 10:50am
### Group Members - Jason Key, Alix Huhta, Billy Wood (Repo Owner), Crandell Sanders, Logan Dahlin
### Instructor - Stacy Turoski

## Setup
All coding and integration was done using the [Arduino IDE](https://www.arduino.cc/)

The micro controller used for the rover is the [ESP32-WROOM-32D by Espressif Systems](https://www.espressif.com/en/products/socs/esp32)

In order to properly use the ESP32 microcontroller with the Arduino IDE, it must be added to the board manager. Intructions for this can be found [here.](https://espressif-docs.readthedocs-hosted.com/projects/arduino-esp32/en/latest/installing.html)

The rover is being controlled using a Playstation 4 DualShock controller via Bluetooth connection using an external library.  The external library's .zip folder must be added to the Arduino IDE's libraries in order to use.

The .zip folder can be downloaded from this GitHub: https://github.com/aed3/PS4-esp32

To download the .zip, go to the top and click <code>Code -> Download ZIP</code>

To add the .zip to the library manager inside the Arduino IDE:

Go to <code>Sketch -> Include Library -> Add .ZIP Library</code> and browse for the .zip named <code>PS4-esp32-master.zip</code>

Unfortunately, the built-in <code>Servo.h</code> library is incompatible with the ESP32, and the <code>ESP32Servo.h</code> library ***must*** be used instead.

To install this library, go to <code>Sketch -> Include Library -> Manage Libraries...</code> and search <code>ESP32Servo</code> by Kevin Herrington. Then click <code>Install</code>

**Restart the IDE**

## Uploading Code
To upload the code from the Arduino IDE, connect a USB to Micro-USB cable from your computer to the ESP32. After the code compiles and is waiting to upload, press and hold the <code>BOOT</code> button to the right of the Micro-USB port until it begins uploading.

## Stakeholder
We partnered with a resource company to build a rover that will extract and transport resources from Planet X. The rover must be able to move forwards and backwards, as well as turn left and right.  The rover must also be able to extract and transport materials.

To move, both joysticks must be held forward or backwards to move in that direction.  For turning, the joysticks must be held in opposing directions, still forwards and backwards, so that it may turn in the direction of backwards-held joystick.

A shovel and a bucket is used to extract and transport the materials.  The shovel is controlled using a [MG92B Servo Motor.](https://www.adafruit.com/product/2307) The servo motor moves the shovel up and down and dumps into the holding bucket on the rear of the rover. The servo is controlled using the Directional Pad on the DualShock 4 controller.
