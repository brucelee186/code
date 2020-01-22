/*这篇把8266作为TCPcleint，加入电脑创建的tcpServer中
来控制一个继电器*/
 
#include <ESP8266WiFi.h>
 
#define relay1 16 
const char *ssid     = "NETGEAR19";
const char *password = "19891114";

const char *host = "192.168.1.1";
WiFiClient client;
const int tcpPort = 8266;
 
 
void setup()
{
    Serial.begin(115200);    pinMode(relay1,OUTPUT);
    delay(10);
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);
 
    WiFi.begin(ssid, password);
 
    while (WiFi.status() != WL_CONNECTED)//WiFi.status() ，这个函数是wifi连接状态，返回wifi链接状态
                                         //这里就不一一赘述它返回的数据了，有兴趣的到ESP8266WiFi.cpp中查看
    {
        delay(500);
        Serial.print(".");
    }//如果没有连通向串口发送.....
 
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());//WiFi.localIP()返回8266获得的ip地址
}
 
 
void loop()
{
    while (!client.connected())//异常处理
    {
        if (!client.connect(host, tcpPort))
        {
            Serial.println("connection....");
            //client.stop();
            delay(500);
 
        }
    }
 
    while (client.available())//如果是有效连接
    {
        char val = client.read();//read()同arduino
        Serial.println(val);
        if(val=='a'){//pc端或者手机端发送0和1来控制,测试用
           digitalWrite(relay1, LOW);
        }
        if(val=='b')
        {
            digitalWrite(relay1, HIGH);
        }
    }
 
 
}
