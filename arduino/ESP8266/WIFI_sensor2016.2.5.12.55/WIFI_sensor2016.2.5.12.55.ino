#include <ESP8266WiFi.h>
#include <RCSwitch.h>
#include <OneWire.h>
#include <DallasTemperature.h>
 //最大同时联接数，即你想要接入的设备数量，8266tcpserver只能接入五个
#define MAX_SRV_CLIENTS 3  
// 测试用led
#define led 15
// 315接收端
#define pinRec315 4

//315发射端
#define pinSen315 0

//315发射端
#define pinSen433 14

// ds18b20传输端
#define pinDS18B20 14

// 人体红外传感器SR501
#define pinInfrared501 13


// 人体红外传感器SR505
#define pinInfrared505 5

const char *ssid = "NETGEAR19";
const char *password = "19891114"; 

// 光线传感器
#define pinLight 12


 //端口号，范围0-65535
WiFiServer server(8266);
WiFiClient serverClients[MAX_SRV_CLIENTS];

// 315接受遥控对象
RCSwitch switch315Rec = RCSwitch();

// 315发送遥控对象
RCSwitch switch315Sen = RCSwitch();


// 433发送遥控对象
RCSwitch switch433Sen = RCSwitch();

// 初始连接在单总线上的单总线设备
OneWire oneWire(pinDS18B20);
DallasTemperature sensors(&oneWire);
 
void setup()
{
    Serial.begin(9600);
    delay(10);
    pinMode(16, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(led, OUTPUT);
    pinMode(pinInfrared501, INPUT);
    pinMode(pinInfrared505, INPUT);
      //pinMode(pinLight, OUTPUT);
    digitalWrite(16, 0);
    WiFi.begin(ssid, password);
 
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
    }
    server.begin();
    //加上后才正常些
    server.setNoDelay(true);  
    switch315Rec.enableReceive(pinRec315);
    switch315Sen.enableTransmit(pinSen315);
    switch433Sen.enableTransmit(pinSen433);

     // DS18B20
    sensors.begin();
}
  
void blink()
{
    switch315Sen.send(1531148, 24);
    switch315Sen.send(1531148, 24);
    static long previousMillis = 0;
    static int currstate = 0;

     //200ms
    if (millis() - previousMillis > 200)  
    {
        previousMillis = millis();
        currstate = 1 - currstate;
        digitalWrite(16, currstate);
    }
}
void loop()
{

    int infrared501Val = digitalRead(pinInfrared501);
   // Serial.println(infrared501Val);
    int infrared505Val = digitalRead(pinInfrared505);
  //  Serial.println(infrared505Val);
      if(1 == infrared501Val){
         switch433Sen.send(1004000, 24);
         digitalWrite(led, HIGH);
      } 
    if(1 == infrared505Val){
         switch433Sen.send(1004001, 24);
         digitalWrite(led, LOW);
         
      } 
  
      //else if(0 == infrared505Val){
      //  digitalWrite(led, LOW);
      //  }

      
//    blink();
//     // 发送命令获取温度
//     //sensors.requestTemperatures();
//  
//    uint8_t i;
//    if (server.hasClient())
//    {
//        for (i = 0; i < MAX_SRV_CLIENTS; i++)
//        {
//            if (!serverClients[i] || !serverClients[i].connected())
//            {
//                //未联接,就释放
//                if (serverClients[i]) serverClients[i].stop();
//                //分配新的
//                serverClients[i] = server.available();
//                continue;
//            }
// 
//        }
//        WiFiClient serverClient = server.available();
//        serverClient.stop();
//    }
//    for (i = 0; i < MAX_SRV_CLIENTS; i++)
//    {
//        if (serverClients[i] && serverClients[i].connected())
//        {
//          //有链接存在,就一直长亮
//            digitalWrite(16, 0);
//            
//            if (serverClients[i].available())
//            {
//           size_t len = 20;
//                  uint8_t msg = serverClients[i].read();
//
//                    // 读取温度
//                   //String temp = String("") + sensors.getTempCByIndex(0);
//                  // serverClients[i].println(temp);
//
//                  
//                  //String temp = sensors.getTempCByIndex(0);
//                  //const char * temp1 = "test";
//                 //uint64_t temp = sensors.getTempCByIndex(0);
//                 ///char temp = sensors.getTempCByIndex(0).c_str();
//                
//                  //serverClients[i].write(temp);
//                  //serverClients[i].print(sensors.getTempCByIndex(0));
//                 
//                  //serverClients[i].send(1531148, 24);
//                 // serverClients[i].write("11111",6);
//                 // serverClients[i].write(""+ sensors.getTempCByIndex(0), len);
//                // serverClients[i].write(temp, len);
//                  if('1' == msg){
//                    digitalWrite(led, HIGH);
//                    switch315Sen.send(1531148, 24);
//                    } else if('0' == msg){
//                      digitalWrite(led,LOW);
//                      switch315Sen.send(1531148, 24);
//                   
//                      }
//                  Serial.write(serverClients[i].read());
//                    
//            }
//        }
//    }

    
  if(switch315Rec.available()){
    int rec315 = switch315Rec.getReceivedValue();
    Serial.println(rec315);
    if(rec315 != 0){
      Serial.print("Receive Code 315: ");
       Serial.println(rec315);
     
      // 如果光线暗,并且门禁移动,那么触发开灯事件
      if(5592405 == rec315 ){
         // 取得光线信号
      int senLight = analogRead(pinLight);
      if(1023 == senLight){
                Serial.println("receive315 OK");
        digitalWrite(led, HIGH);
        switch315Sen.send(1531148, 24);
        switch315Sen.send(1531148, 24);
        switch315Sen.send(1531148, 24);
        // 3分钟
        delay(3 * 6 * 1000);
        switch315Sen.send(1531139, 24);
        delay(1000);
        switch315Sen.send(1531139, 24);
        delay(1000);
        switch315Sen.send(1531139, 24);
        digitalWrite(led, LOW);
        //Serial.println("Light = " + senLight);
       // Serial.print("Receive Code: ");
        //Serial.println(rec315);
        switch315Rec.resetAvailable();
        }
        }
     switch315Rec.resetAvailable();
      }
    }
}
 

