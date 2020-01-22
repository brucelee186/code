#include <RCSwitch.h>
#include <DigiKeyboard.h>

// 433接收端
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
    if(switch433Rec.available()){
      DigiKeyboard.println("OK");
      int rec433 = switch433Rec.getReceivedValue();
      if(rec433 != 0){
        
         DigiKeyboard.print("Receive Code 433: ");
         DigiKeyboard.println(rec433);
         switch433Rec.resetAvailable();
      }
  }


}

