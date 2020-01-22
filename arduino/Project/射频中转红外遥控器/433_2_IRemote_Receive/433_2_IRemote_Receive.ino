/*
  Simple example for receiving
  
  http://code.google.com/p/rc-switch/
*/

#include <RCSwitch.h>
#include <IRremote.h>   

RCSwitch mySwitch = RCSwitch();

IRsend irsend;          

void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(0);  // Receiver on inerrupt 0 => that is pin #2
}

void loop() {
  if (mySwitch.available()) {
    
    int value = mySwitch.getReceivedValue();
    
    if (value == 0) {
      Serial.print("Unknown encoding");
    } else {
      Serial.print("Received ");
      Serial.print( mySwitch.getReceivedValue() );

  irsend.sendSony(mySwitch.getReceivedValue(), 32);  
    }

    mySwitch.resetAvailable();
  }
}
