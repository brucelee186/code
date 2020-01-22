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
      if(rec433 != 0)
      {
         Serial.print("Receive Code 433: ");
         Serial.println(rec433);
         // 1号键天吸顶灯
         if(283907 == rec433){
             switch433Sen.send(2499600, 24);
             Serial.println("open");
          // 2号键关吸顶灯
          } else if(283916 == rec433){
            switch433Sen.send(5529536, 24);
             Serial.println("close");
          }
          
          if(283919 == rec433){
             switch433Sen.send(13391739, 24);
             Serial.println("open");
          // 2号键关吸顶灯
          } else if(283952 == rec433){
            switch433Sen.send(11354927, 24);
             Serial.println("close");
          }
                  
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
//          if(rec433 == 283907){
//             switch433Sen.send(2499600, 24);
//             Serial.println("open");
//          // 2号键关吸顶灯
//          } else if(283916 == rec433){
//            switch433Sen.send(5529536, 24);
//             Serial.println("close");
//          }
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
    for (i = 0; i < MAX_SRV_CLIENTS; i++)
    {
        if (serverClients[i] && serverClients[i].connected())
        {
            
            if (serverClients[i].available())
            {
              char msg = serverClients[i].read();
               switch433Sen.send(2499600, 24);
              if('1' == msg)
              {
               
              }
            }
        }
    }

}

