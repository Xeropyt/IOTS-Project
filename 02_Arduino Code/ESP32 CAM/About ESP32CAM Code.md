# ESP32 CAM

Before Using the code the following libraries need to be installed

![Image not found!](https://github.com/Xeropyt/IOTS-Project/blob/main/Images/32Cam1.png?raw=true)

The Universal Telegram Bot has to be downloaded on the web

The link will be provided in the Readme page

![Image not found!](https://github.com/Xeropyt/IOTS-Project/blob/main/Images/Border.png?raw=true)

![Image not found!](https://github.com/Xeropyt/IOTS-Project/blob/main/Images/32Cam2.png?raw=true)

This portion of the code calls a function for the ESP32 CAM to connect to WiFi while showing it's progress

As the microcontroller connects to WiFi, The setCACert() is called to establish a secure connection encrypted with SSL

This will ensure communication from the microsontroller to telegram is encrypted

![Image not found!](https://github.com/Xeropyt/IOTS-Project/blob/main/Images/Border.png?raw=true)

![Image not found!](https://github.com/Xeropyt/IOTS-Project/blob/main/Images/32Cam3.png?raw=true)

The first function constantly listens for any updates in the group chat where it is located

If the bot sees "/photo" it will capture a photo and send it to the chat
If the bot sees "/flash", the flash on the camera will be activated

Moving on, the next portion of the code constantly reads data from firebase and reacts accordingly:

If failed attempts = 5 aka getInt(/Fail/fail) == 5, it will take it as intruder detected and capture an image
this image will be sent to the Home Owner alerting an intruder detected and the otp will be updated

If login to the website is successful, an otp will be requested aka getInt(/otp/num) == 1
The function continues in our next snippet below

![Image not found!](https://github.com/Xeropyt/IOTS-Project/blob/main/Images/32Cam4.png?raw=true)

The funtion above is called when the otp has been requested and will send the otp via telegram to the chat via bot
Along with sending the otp to a grp chat with the residents inside, the email will also be shown contributing to non-repudiation
