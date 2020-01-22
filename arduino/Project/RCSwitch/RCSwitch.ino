#include <ESP8266WiFi.h>
#include <RCSwitch.h>
 //最大同时联接数，即你想要接入的设备数量，8266tcpserver只能接入五个
#define MAX_SRV_CLIENTS 3  
// 测试用led
#define led 15
// 315接收端
#define pinRec315 4

//315发射端
#define pinSen315 0
 
const char *ssid = "NETGEAR19";
const char *password = "19891114"; 

 //端口号，范围0-65535
WiFiServer server(8266);
WiFiClient serverClients[MAX_SRV_CLIENTS];

// 315接受遥控对象
RCSwitch switch315Rec = RCSwitch();

// 315发送遥控对象
RCSwitch switch315Sen = RCSwitch();
 
void setup()
{
    Serial.begin(9600);
    delay(10);
    pinMode(16, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(led, OUTPUT);
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
          //有链接存在,就一直长亮
            digitalWrite(16, 0);
            
            if (serverClients[i].available())
            {;
                  uint8_t msg = serverClients[i].read();
                  serverClients[i].write(msg);
                  if('1' == msg){
                    digitalWrite(led, HIGH);
                    switch315Sen.send(1531148, 24);
                    } else if('0' == msg){
                      digitalWrite(led,LOW);
                      switch315Sen.send(1531148, 24);
                   
                      }
                  Serial.write(serverClients[i].read());
                    
            }
        }
    }

  if(switch315Rec.available()){
    int rec315 = switch315Rec.getReceivedValue();
    if(rec315 != 0){
      Serial.print("Receive Code: ");
      Serial.println(rec315);
      switch315Rec.resetAvailable();
      }
    }
}
 

