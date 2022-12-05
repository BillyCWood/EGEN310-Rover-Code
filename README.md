# EGEN 310R Rover Project
## Section 6 Group B8
### Group Members - Jason Key, Alix Huhta, Billy Wood, Crandell Sanders, Logan Dahlin
### Instructor - Stacy Turoski

## Setup and Overview
All coding and integration was done using the [Arduino IDE](https://www.arduino.cc/)

The micro controller used for the rover is the [ESP32-WROOM-32D by Espressif Systems](https://www.espressif.com/en/products/socs/esp32)

In order to properly use the ESP32 microcontroller with the Arduino IDE, it must be added to the board manager. Intructions for this can be found [here.](https://espressif-docs.readthedocs-hosted.com/projects/arduino-esp32/en/latest/installing.html)

The rover is being controlled using a Playstation 4 DualShock controller via Bluetooth connection using and external library.  The external library's .zip folder must be added to the Arduino IDE's libraries in order to use.

The .zip folder can be downloaded from this GitHub: https://github.com/aed3/PS4-esp32

To download the .zip, go to the top and click <code>Code -> Download ZIP</code>

To add the .zip to the library manager inside the Arduino IDE:

Go to <code>Sketch -> Include Library -> Add .ZIP Library</code> and browse for the .zip named <code>PS4-esp32-master.zip</code>

Unfortunately, the built-in <code>Servo.h</code> library is incompatible with the ESP32, and the <code>ESP32Servo.h</code> library ***must*** be used instead.

To install this library, go to <code>Sketch -> Include Library -> Manage Libraries...</code> and search <code>ESP32Servo</code> by Kevin Herrington. Then click <code>Install</code>
