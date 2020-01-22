#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {

  Serial.begin(9600);
  
  //输出脚为 Arduino Pin #10  
  mySwitch.enableTransmit(5);
}


void loop() {
  int swVal = Serial.read();
  if(49 == swVal){
    Serial.println(swVal);
    mySwitch.send("000000000001010100010001");
    Serial.println("ON");
    digitalWrite(16,HIGH);
    delay(500);
    }
   else if(48 == swVal){
    Serial.println(swVal);
    mySwitch.send("000000000001010100010100");
    Serial.println("OFF");
    digitalWrite(16,LOW);
    delay(500);
   }
}
