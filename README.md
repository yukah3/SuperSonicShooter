# SuperSonicShooter
Project for UIST SIC
developed in Keio SFC Nakanish Lab.

INSTRUCTIONS FOR MAKING SUPER SONIC SHOOTER

The instruction below is for making 1 device.
You will need more then 2 to play/enjoy the game.

1. Get the necessary electronic components

Microcomputers
- Arduino Nano
- Chip for Arduino Uno (SSCI-ATMEGA328P+OPTIBOOT)

Sensors
- Piezo sensor (SEN-09198)
- Ultrasonic Sensor (UT1612MPR)

Electric Muscle Stumulation Kit
- MOS-FET (2SK2232)
- Diode (1N4148)

Others
- 9V battery
- spacer

then, assemble the electronic parts and make the hardware.
The whole schematic is on [SSS_schematic.pdf]

after building the hardware, upload the code and you are ready to play!
The codes are [SSS_Main] for the arduino nano,
[SSS_I2C_Slave_Sound] for the arduino uno chip.

[SSS_Simple] is the simplified code without the sound + charging system and can be built easier.

please enjoy playing with SSS!
