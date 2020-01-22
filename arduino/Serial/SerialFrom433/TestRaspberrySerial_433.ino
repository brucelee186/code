#include <RCSwitch.h>

// 测试用led
int led = 13;

// 433接收端
// 这里的0指中断零也是就是2
#define pinRec433 0

// 433接受遥控对象
RCSwitch switch433Rec = RCSwitch();
void setup(){
     Serial.begin(9600);
     switch433Rec.enableReceive(pinRec433);
     pinMode(led, OUTPUT);
}

void loop(){
  if(switch433Rec.available()){
    long rec433 = switch433Rec.getReceivedValue();
      if(rec433 != 0){
         digitalWrite(led, HIGH);
         // Serial.print("Receive Code 433: ");
         Serial.println(rec433);
         switch433Rec.resetAvailable();
         delay(500);
         digitalWrite(led, LOW);
      }
  }
}
