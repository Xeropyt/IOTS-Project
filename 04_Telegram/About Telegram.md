## Telegram bot

# Step 1:

![Image not found!](https://github.com/Xeropyt/IOTS-Project/blob/main/Images/tele3.png?raw=true)

1. Send /start to BOTFather and create a new bot
2. choose the name and tag for the bot
3. Take down the API key

# Step 2:

![Image not found!](https://github.com/Xeropyt/IOTS-Project/blob/main/Images/tele4.png?raw=true)
![Image not found!](https://github.com/Xeropyt/IOTS-Project/blob/main/Images/tele5.png?raw=true)

1. Get the chat ID of home owner through bot
2. Get the chat ID of the family group chat from the web link
3. Insert chat ID into the code

# Step 3

![Image not found!](https://github.com/Xeropyt/IOTS-Project/blob/main/Images/tele7.png?raw=true)

Insert here in Arduino Code -> ESP32 CAM and ESP32

Example:
> String CHAT_ID = "12345678"

# Security Features:

![Image not found!](https://github.com/Xeropyt/IOTS-Project/blob/main/Images/tele6.jpeg?raw=true)

If any user tries to use the bot and their CHAT_ID does not match, bot will deny access to functions
and send "unauthorized user"

![Image not found!](https://github.com/Xeropyt/IOTS-Project/blob/main/Images/tele1.png?raw=true)

Here is an example of the output when otp is requested from the website

![Image not found!](https://github.com/Xeropyt/IOTS-Project/blob/main/Images/tele2.png?raw=true)

Here is an example of the output when the number of failed attempts reaches 5
