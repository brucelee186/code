#include <RCSwitch.h>

// 433接收端
// 这个针角对应的是终断0,1,arduion uno只有两个中断0,1对应pin,2,3
#define pinRec433 0
int led = 1;



// 433接受遥控对象
RCSwitch switch433Rec = RCSwitch();

void setup()
{
    Serial.begin(9600);
    pinMode(pinRec433,INPUT); 
    pinMode(led,OUTPUT);
    // 这个针角对应的是终断0,1,arduion uno只有两个中断0,1对应pin,2,3
    switch433Rec.enableReceive(pinRec433);
}
  

void loop()
{
  //Serial.println(digitalRead(pinRec433));
  //delay(500);
  digitalWrite(led, digitalRead(pinRec433));
    if(switch433Rec.available()){
      long rec433 = switch433Rec.getReceivedValue();
      if(rec433 != 0){
        
         Serial.print("Receive Code 433: ");
         Serial.println(rec433);
         switch433Rec.resetAvailable();
      }
  }


}

