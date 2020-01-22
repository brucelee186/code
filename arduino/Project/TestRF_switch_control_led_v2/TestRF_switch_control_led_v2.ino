
#include <RCSwitch.h>
// 测试用led
#define led 13
// 315接收端
#define pinRec315 0

//315发射端
#define pinSen315 4

//// 433接收端
//#define pinRec433 16
//
//// 433发射端
#define pinSen433 5

//// ds18b20传输端
//#define pinDS18B20 14
//
//// 人体红外传感器SR501
//#define pinInfrared501 13
//
//
//// 人体红外传感器SR505
//#define pinInfrared505 8

//const char *ssid = "NETGEAR19";
//const char *password = "19891114";
//
// 光线传感器
#define pinLight 0


// 315接受遥控对象
RCSwitch switch315Rec = RCSwitch();

// 315发送遥控对象
RCSwitch switch315Sen = RCSwitch();

//// 433接受遥控对象
//RCSwitch switch433Rec = RCSwitch();
//
//// 433发送遥控对象
RCSwitch switch433Sen = RCSwitch();


void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  // pinMode(pinRec315, INPUT);
  //pinMode(pinLight, INPUT);

  switch315Rec.enableReceive(pinRec315);
  switch315Sen.enableTransmit(pinSen315);
  //    switch433Rec.enableReceive(pinRec433);
  switch433Sen.enableTransmit(pinSen433);

  // DS18B20
  // sensors.begin();
}


void loop()
{
  if (switch315Rec.available()) {
    long rec315 = switch315Rec.getReceivedValue();
    if (rec315 != 0) {
      //Serial.print("Receive Code 315: ");
      //Serial.println(rec315);
      switch433Sen.send(rec315, 24);

      // 如果光线暗,并且门禁移动0,那么触发开灯事件(门磁固定编码为5592405,测试用:18368)
      // 现在的编码为21845
      // 原固定编码5592405
      if (5592405 == rec315 ) {
        // 取得光线信号
        int senLight = analogRead(pinLight);
        // Serial.print("Sense Ligth: ");
        // Serial.println(senLight);
        if (600 < senLight) {
          //          Serial.println("receive315 OK");
          //          while(600 < senLight){
          //             switch315Sen.send(23820, 24);
          //             senLight = analogRead(pinLight);
          //             Serial.print("Sense Ligth: ");
          //             Serial.println(senLight);
          //             delay(1000);
          //         }

          switch315Sen.send(1531148, 24);
          switch433Sen.send(1531148, 24);
          delay(1000);
          switch315Sen.send(1531148, 24);
          switch433Sen.send(1531148, 24);
          delay(1000);
          switch315Sen.send(1531148, 24);
          switch433Sen.send(1531148, 24);
          delay(1000);
          senLight = analogRead(pinLight);
          Serial.print("Sense Ligth: ");
          Serial.println(senLight);

          digitalWrite(led, HIGH);
          // 3分钟
          delay(3 * 60000);


          switch315Sen.send(1531139, 24);
          switch433Sen.send(1531139, 24);
          delay(1000);
          switch315Sen.send(1531139, 24);
          switch433Sen.send(1531139, 24);
          delay(1000);
          switch315Sen.send(1531139, 24);
          switch433Sen.send(1531139, 24);
          digitalWrite(led, LOW);
          //          if(600 < senLight){
          //
        }
      }
      switch315Rec.resetAvailable();
    }
  }

}

