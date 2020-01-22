#include "DigiKeyboard.h"
#include <Manchester.h>

#define RX_PIN 1 //= pin 6

void setup()

{
  man.setupReceive(RX_PIN, MAN_1200);
  man.beginReceive();
}

void loop() {

  if (man.receiveComplete()) {
    DigiKeyboard.sendKeyStroke(0);
    int m = man.getMessage();
    DigiKeyboard.println("Receive Code: " + m);
    man.beginReceive(); //start listening for next message right<br>                        //after you retrieve the message
  }
}
