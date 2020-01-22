#include <ESP8266WiFi.h>
#include <RCSwitch.h>
#include <OneWire.h>
#include <DallasTemperature.h>
 //最大同时联接数，即你想要接入的设备数量，8266tcpserver只能接入五个
#define MAX_SRV_CLIENTS 1


// 433接收端
#define pinRec433 4

// 433发射端
#define pinSen433 5

const char *ssid = "NETGEAR19";
const char *password = "19891114"; 

const char *host = "192.168.1.106";
const int port = 8266;




 //端口号，范围0-65535
WiFiServer server(8266);
WiFiClient serverClients[MAX_SRV_CLIENTS];
WiFiClient client;

// 433接受遥控对象
RCSwitch switch433Rec = RCSwitch();

// 433发送遥控对象
RCSwitch switch433Sen = RCSwitch();
 
void setup()
{
    Serial.begin(9600);
    WiFi.begin(ssid, password);
 
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
    }
    server.begin();
    //加上后才正常些
    server.setNoDelay(true);  
    
    switch433Rec.enableReceive(pinRec433);
    switch433Sen.enableTransmit(pinSen433);


}
  
void blink()
{
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
    blink();
    if(switch433Rec.available()){
      int rec433 = switch433Rec.getReceivedValue();
      if(rec433 != 0){
         Serial.print("Receive Code 433: ");
         Serial.println(rec433);
                  
      uint8_t i;

    if (server.hasClient())
    {
      Serial.println("server.hasClient()");
        for (i = 0; i < MAX_SRV_CLIENTS; i++)
        {
            if (!serverClients[i] || !serverClients[i].connected())
            {
                //未联接,就释放
                if (serverClients[i]) serverClients[i].stop();
                //分配新的
                serverClients[i] = server.available();
                continue;
            }
 
        }
        WiFiClient serverClient = server.available();
        serverClient.stop();
    }
    for (i = 0; i < MAX_SRV_CLIENTS; i++)
    {
        if (serverClients[i] && serverClients[i].connected())
        {
          Serial.println("connected cell phone");
          serverClients[i].println(rec433);

          // 1号键天吸顶灯
          if(283907 == rec433){
             switch433Sen.send(2499600, 24);
          // 2号键关吸顶灯
          } else if(283916 == rec433){
            switch433Sen.send(5529536, 24);
          }
        }
    }
    switch433Rec.resetAvailable();
   }

  }

      blink();

  
    uint8_t i;
  
    if (server.hasClient())
    {
        for (i = 0; i < MAX_SRV_CLIENTS; i++)
        {
            if (!serverClients[i] || !serverClients[i].connected())
            {
                //未联接,就释放
                if (serverClients[i]) serverClients[i].stop();
                //分配新的
                serverClients[i] = server.available();
                continue;
            }
 
        }
        WiFiClient serverClient = server.available();
        serverClient.stop();
    }
       int j = 0;
    for (i = 0; i < MAX_SRV_CLIENTS; i++)
    {
       char codeFR;
       Serial.print("aaaaaa");
       Serial.println(j);
        Serial.print("xxxxxxxxxxxxxxx");
        j = j + 1;
        delay(2000);
        Serial.println(j);
        if (serverClients[i] && serverClients[i].connected())
        {
           //Serial.print("clinet count : ");
           //Serial.println(i);
          //有链接存在,就一直长亮
            //digitalWrite(16, 0);
            int k = 0;
            if (serverClients[i].available())
            {
              Serial.print("--");
              Serial.println(k);
              k = k++;
              Serial.print("++");
              Serial.println(k);
              size_t counti = serverClients[i].available();
              Serial.println(counti);
              size_t len = 20;
              char msg = serverClients[i].read();
              codeFR = msg;
              Serial.println("test");
              Serial.println(msg);
             // Serial.println(codeFR);
               //Serial.write(serverClients[i].read());      
            }
        }
    }

}

