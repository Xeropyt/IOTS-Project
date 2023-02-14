# ESP32 (without cam)

## Set up of arduino for ESP32

1. In your Arduino IDE, go to File> Preferences.
1. Enter https://dl.espressif.com/dl/package\_esp32\_index.json into the “Additional Board Manager URLs” field as shown in the figure below. Then, click the “OK” button.
1. Open the Boards Manager. Go to Tools > Board > Boards Manager…
1. Search for ESP32 and press install button for the “ESP32 by Espressif Systems”

**Libraries to install**

1. Firebase Arduino Client Library for ESP8266 and ESP32
1. ServoESP32-master

![Image not found!](https://github.com/Xeropyt/IOTS-Project/blob/main/Images/321.jpeg?raw=true)

Firebase Arduino Client Library for ESP8266 and ESP32 can be installed by going to sketch > include library > manage library and search for firebase esp.

ServoESP32-master can be installed by going to sketch > include library > include.zip. ServoESP32-master.zip is included in the github.

**Header files**

![Image not found!](https://github.com/Xeropyt/IOTS-Project/blob/main/Images/322.png?raw=true)

These are the header files used for the system.

**Definitions needed**

![Image not found!](https://github.com/Xeropyt/IOTS-Project/blob/main/Images/323.png?raw=true)

![Image not found!](https://github.com/Xeropyt/IOTS-Project/blob/main/Images/324.png?raw=true)

![Image not found!](https://github.com/Xeropyt/IOTS-Project/blob/main/Images/325.png?raw=true)

![Image not found!](https://github.com/Xeropyt/IOTS-Project/blob/main/Images/326.png?raw=true)

![Image not found!](https://github.com/Xeropyt/IOTS-Project/blob/main/Images/327.png?raw=true)

## void setup()

![Image not found!](https://github.com/Xeropyt/IOTS-Project/blob/main/Images/328.png?raw=true)

## void loop()

Ultrasound code

![Image not found!](https://github.com/Xeropyt/IOTS-Project/blob/main/Images/329.png?raw=true)

Send otp to database

![Image not found!](https://github.com/Xeropyt/IOTS-Project/blob/main/Images/330.png?raw=true)

![Image not found!](https://github.com/Xeropyt/IOTS-Project/blob/main/Images/331.png?raw=true)

Open lock code

Generate OTP code

![Image not found!](https://github.com/Xeropyt/IOTS-Project/blob/main/Images/332.png?raw=true)
