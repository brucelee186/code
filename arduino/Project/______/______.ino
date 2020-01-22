#include <RCSwitch.h>
// 测试用led
#define led 0

// 433接收端
#define pinRec433 0

// 433发射端
#define pinSen433 4


// 433接受遥控对象
RCSwitch switch433Rec = RCSwitch();

// 433发送遥控对象
RCSwitch switch433Sen = RCSwitch();

 
void setup()
{
    Serial.begin(9600);
    switch433Rec.enableReceive(pinRec433);
    switch433Sen.enableTransmit(pinSen433);
}
  

void loop()
{
  // switch433Sen.send(100, 24);
  switch433Sen.send(13391739, 24);
   delay(500);
     switch433Sen.send(13391739, 24);
   delay(500);
     switch433Sen.send(13391739, 24);
   delay(500);
     switch433Sen.send(13391739, 24);
   delay(5000);
    switch433Sen.send(11354927, 24);
   delay(500);
    switch433Sen.send(11354927, 24);
   delay(500);
    switch433Sen.send(11354927, 24);
    delay(500);
    if(switch433Rec.available()){
      long rec433 = switch433Rec.getReceivedValue();
      if(rec433 != 0){
         Serial.print("Receive Code 433: ");
         Serial.println(rec433);
   
              
         switch433Rec.resetAvailable();
      }
  }


}

