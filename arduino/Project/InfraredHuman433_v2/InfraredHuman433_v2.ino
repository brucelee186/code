#include <RCSwitch.h>
// 测试用led
#define led 13

// 人体红外感应器引角
#define pinInfrared 5

// 433接收端
#define pinRec433 0

// 433发射端
#define pinSen433 4

// 光线传感器
#define pinLight 0


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
    int senLight = analogRead(pinLight);
    if(600 < senLight){ 
     if(digitalRead(pinInfrared)==HIGH){
     digitalWrite(led,HIGH);
     switch433Sen.send(2499600, 24);
     delay(500);
     switch433Sen.send(2499600, 24);
     delay(500);
     switch433Sen.send(2499600, 24);

     // 延迟一分钟
     delay(4 * 60000);
     digitalWrite(led,LOW);
     switch433Sen.send(5529536, 24);
     delay(500);
     switch433Sen.send(5529536, 24);
     delay(500);
     switch433Sen.send(5529536, 24);
     delay(500);  
      }
  
    }


}

