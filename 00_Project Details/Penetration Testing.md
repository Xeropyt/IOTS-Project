# Penetration Testing

## Physical

1. A threat actor may forcefully break down the door in order to gain access to the components of the system. 
2. Code can be extracted using mplabx IDE. However, for this to occur there must be physical access to the microcontroller. Once the code has been extracted from mplabx, it must be fed into a decompiler in order to obtain the raw code. Once the raw code is obtained it can be rewritten and uploaded back into the esp 32.
3. They may be able to guess the password of a user using phishing attacks. The threat actor may be able to lock into the system and unlock the door.

## Mitigation

1. ESP32 cam (1 and 2)
2. OTP (3)

## Kali Linux

A DDOS attack could be carried out on the ESP32 to deny access to the house. For this to happen the threat actor must have wifi access. The threat actor will sit on the wifi network (access gained by password attacks ie. brute force) and scan the network for any transmissions. Since the esp32 is constantly reading and writing from and to the real time database, the threat actor will be able to see the ip address of the device and scan for ports that are opened. With that a DDOS attack can be carried out.

## Mitigation

1. Strong wifi password 
2. Close unused ports
3. Mac Address filtering
