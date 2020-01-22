#include <ESP8266WiFi.h>
#define MAX_SRV_CLIENTS 3   //最大同时联接数，即你想要接入的设备数量，8266tcpserver只能接入五个，哎
 
const char *ssid = "NETGEAR19"; ////这里是我的wifi，你使用时修改为你要连接的wifi ssid
const char *password = "19891114"; //你要连接的wifi密码
 
WiFiServer server(8266);//你要的端口号，随意修改，范围0-65535
WiFiClient serverClients[MAX_SRV_CLIENTS];

int pinSw1 = 16;
int pinSw2 = 5;
int pinSw3 = 4;
int pinSw4 = 0;
int pinSw5 = 2;
int pinSw6 = 14;
int pinSw7 = 12;
int pinSw8 = 13;
 
void setup()
{
    Serial.begin(115200);
    delay(10);
    //pinMode(16, OUTPUT);
    pinMode(2, OUTPUT);
    //digitalWrite(16, 0);
    WiFi.begin(ssid, password);
 
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
    }
    server.begin();
    server.setNoDelay(true);  //加上后才正常些

  pinMode(pinSw1, OUTPUT);
  pinMode(pinSw2, OUTPUT);  
  pinMode(pinSw3, OUTPUT);
  pinMode(pinSw4, OUTPUT);
  pinMode(pinSw5, OUTPUT);
  pinMode(pinSw6, OUTPUT);
  pinMode(pinSw7, OUTPUT);          
  pinMode(pinSw8, OUTPUT);      
}
  
void blink()
{
    static long previousMillis = 0;
    static int currstate = 0;
 
    if (millis() - previousMillis > 200)  //200ms
    {
        previousMillis = millis();
        currstate = 1 - currstate;
        //digitalWrite(16, currstate);
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
                if (serverClients[i]) serverClients[i].stop();//未联接,就释放
                serverClients[i] = server.available();//分配新的
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
            //digitalWrite(16, 0);//有链接存在,就一直长亮
            
            if (serverClients[i].available())
            {
//                  digitalWrite(2, HIGH);
//                  delay(1000);
//                  digitalWrite(2,LOW);
                  uint8_t msg = serverClients[i].read();
                  serverClients[i].write(msg);
                  if('1' == msg){
                    digitalWrite(pinSw1, HIGH);
                    } else if('a' == msg){
                      digitalWrite(pinSw1,LOW);
                      }
              if('2' == msg){
                    digitalWrite(pinSw2, HIGH);
                    } else if('b' == msg){
                      digitalWrite(pinSw2,LOW);
                      }    
                 if('3' == msg){
                    digitalWrite(pinSw3, HIGH);
                    } else if('c' == msg){
                      digitalWrite(pinSw3,LOW);
                      }     
                 if('4' == msg){
                    digitalWrite(pinSw4, HIGH);
                    } else if('d' == msg){
                      digitalWrite(pinSw4,LOW);
                      }      
                 if('5' == msg){
                    digitalWrite(pinSw5, HIGH);
                    } else if('e' == msg){
                      digitalWrite(pinSw5,LOW);
                      }  
                 if('6' == msg){
                    digitalWrite(pinSw6, HIGH);
                    } else if('f' == msg){
                      digitalWrite(pinSw6,LOW);
                      }  
                 if('7' == msg){
                    digitalWrite(pinSw7, HIGH);
                    } else if('g' == msg){
                      digitalWrite(pinSw7,LOW);
                      }  
                 if('8' == msg){
                    digitalWrite(pinSw8, HIGH);
                    } else if('h' == msg){
                      digitalWrite(pinSw8,LOW);
                      }                                                                                                            
                  Serial.write(serverClients[i].read());
                    
            }
        }
    }
    /*if (Serial.available())
    {
        size_t len = Serial.available();
        uint8_t sbuf[len];
        Serial.readBytes(sbuf, len);
        //push UART data to all connected telnet clients
        for (i = 0; i < MAX_SRV_CLIENTS; i++)
        {
            if (serverClients[i] && serverClients[i].connected())
            {
                serverClients[i].write(sbuf, len);  //向所有客户端发送数据
                delay(1);
            }
        }
    }*/
}
 

