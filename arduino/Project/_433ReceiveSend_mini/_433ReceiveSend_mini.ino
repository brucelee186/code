#include <RCSwitch.h>
// 测试用led
#define led 0


// 433接收端
// 这里的0指中断零也是就是2
#define pinRec433 0



// 433接受遥控对象
RCSwitch switch433Rec = RCSwitch();



 
void setup()
{
    Serial.begin(9600);
    switch433Rec.enableReceive(pinRec433);

}
  

void loop()
{
   // switch433Sen.send(100, 24);
   // delay(500);
       if(switch433Rec.available()){
      long rec433 = switch433Rec.getReceivedValue();
      if(rec433 != 0){
         Serial.print("Receive Code 433: ");
         Serial.println(rec433);
              
         switch433Rec.resetAvailable();
      }
  }
   


}

