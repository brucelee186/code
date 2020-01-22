#include <IRremote.h>   

#include <RCSwitch.h>

// 433接收端
#define pinRec433 2

// 红外发射端
int pinSenRF = 3;

// 
int led = 1;

// 433接受遥控对象
RCSwitch switch433Rec = RCSwitch();

// 遥控器发射对象
IRsend irsend;  

void setup()
{
    Serial.begin(9600);
    pinMode(pinSenRF, OUTPUT);   
    pinMode(pinRec433, INPUT);
    pinMode(led,OUTPUT);
    switch433Rec.enableReceive(pinRec433);
}
  

void loop()
{
   digitalWrite(led, digitalRead(pinRec433));
    if(switch433Rec.available()){
      //Serial.println("OK");
      int rec433 = switch433Rec.getReceivedValue();
      if(rec433 != 0){
         Serial.print("Receive Code 433: ");
         Serial.println(rec433);
         irsend.sendNEC(rec433, 32);  
         switch433Rec.resetAvailable();
      }
  }


}

