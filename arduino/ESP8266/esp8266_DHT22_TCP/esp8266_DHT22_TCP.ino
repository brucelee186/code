/*这篇把8266作为TCPcleint，加入手机创建的tcpServer中
来控制一个继电器*/
  
#include <ESP8266WiFi.h>
  
#define relay1 0// esp8266 led在2接口上
const char *ssid     = "NETGEAR19";//这里是我的wifi，你使用时修改为你要连接的wifi ssid
const char *password = "19821028";//你要连接的wifi密码
const char *host = "192.168.1.38";//修改为手机的的tcpServer服务端的IP地址，即手机在路由器上的ip
WiFiClient client;
const int tcpPort = 8266;//修改为你建立的Server服务端的端口号

#include "DHT.h"

#define DHTPIN 2

#define DHTTYPE DHT22 
DHT dht(DHTPIN, DHTTYPE);
  
void setup()
{
    dht.begin();
    Serial.begin(115200);
    pinMode(relay1,OUTPUT);
    delay(10);
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");//写几句提示，哈哈
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

    while (!client.connected())//几个非连接的异常处理
    {
        if (!client.connect(host, tcpPort))
        {
            Serial.println("connection....");
            //client.stop();
            delay(500);
  
        }
    }
 
    while (client.available())//available()同ARDUINO，不解释了
    {
      
        uint8_t val = client.read();//read()同arduino
        if(val=='t'){//pc端发送0和1来控制


  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");

    char   ch[10];  
  dtostrf(h,1,2,ch);
   
    char   ct[10];  
  dtostrf(t,1,2,ct);

  client.write("Temperature: ");
  client.write(ct);
  client.write(" *C "); 
        }
        if(val=='h')
        {

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");

    char   ch[10];  
  dtostrf(h,1,2,ch);
   
    char   ct[10];  
  dtostrf(t,1,2,ct);
  client.write("Humidity: ");
  client.write(ch);
  client.write(" %");
 
        }
    }
  
  
}
