#include <RCSwitch.h>
#define led 15
RCSwitch mySwitch = RCSwitch();
 
void setup(){
  Serial.begin(9600);
  mySwitch.enableReceive(3);
  pinMode(led,OUTPUT);
}
void loop(){
  if (mySwitch.available()) {
    int value = mySwitch.getReceivedValue();
    if (value != 0) {
      Serial.print("Receive Code: ");
      Serial.println(value);
      mySwitch.resetAvailable();
    }
  
    
  }
}
