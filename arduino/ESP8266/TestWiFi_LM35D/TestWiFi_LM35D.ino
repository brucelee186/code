#include <ESP8266WiFi.h>
#include <RCSwitch.h>

 //最大同时联接数，即你想要接入的设备数量，8266tcpserver只能接入五个
#define MAX_SRV_CLIENTS 3  
// 测试用led
#define led 0

// LM35D端口
const char *pinLM35D = "A0";

const char *ssid = "NETGEAR19";
const char *password = "19891114"; 


 //端口号，范围0-65535
WiFiServer server(8266);
WiFiClient serverClients[MAX_SRV_CLIENTS];
 
void setup()
{
    Serial.begin(9600);
    delay(10);
  
    WiFi.begin(ssid, password);
 
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
    }
    server.begin();
 
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
            {
                  size_t len = 20;
                  uint8_t msg = serverClients[i].read();
                  while(true){
                   // 读取温度
                   int temperatureVoltage = analogRead(A0);
                   float temperature = temperatureVoltage*(5.0 / 1023.0 * 100);
                  
                   String temp = String("") + temperature;
                   serverClients[i].println(temp);
                  Serial.write(serverClients[i].read());
                  delay(1000);
                }
            
            }
        }
    }
}

