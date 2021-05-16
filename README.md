# Anatidae
A rubber ducky for stealing wifi passwords.

Rubber Ducky: Rubber Ducky just something that sends out keystrokes to the system.

Hardware and Arduino config:

1. Purchase Digispark Attiny85 microcontroller

2. Install Arduino

3. Add Board manager json(http://digistump.com/package\_digistump\_index.json) in File\&gt;preferences\&gt;Additional Board Managers
 This allows us to install digistump board manager.(Tools\&gt;Boards\&gt;Board Manager\&gt;Install Digistump AVR Board)

4. Install Digistump Arduino Drivers \&gt; Digistump.Drivers.zip from [https://github.com/digistump/DigistumpArduino/releases](https://github.com/digistump/DigistumpArduino/releases)

Code:

1. Check if your MCU is working with ./wifi stealer/Sample\_LED\_testing/Sample\_LED\_testing.ino following step 3 and 4 with this file.

2. Open ./wifi stealer/Steal/Steal.ino, change your hook and upload

3. After upload is complete, insert your MCU. This will upload the program to it.

4. Remove it and insert it again.

5. Now you can see that your Rubber Ducky is working and your Wifi Password would be sent to your hook in 10-20 seconds.
