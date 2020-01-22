#include <ESP8266WiFi.h>

#define led 2
const char *ssid     = "NETGEAR19";//这里是我的wifi，你使用时修改为你要连接的wifi ssid
const char *password = "19891114";//你要连接的wifi密码
const char *host = "192.168.1.191";//修改为你建立的Server服务端的IP地址
WiFiClient client;
const int tcpPort = 8266;//修改为你建立的Server服务端的端口号
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  delay(10);
  Serial.println();
  Serial.println();
  Serial.println("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    // 如果没有联上wifi就发送....
    Serial.print(".");  
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
  

void loop() {

  while(!client.connected()){
    if(!client.connect(host,tcpPort)){
      Serial.println("connection...");
      delay(500);
      }
  }
  
  while(client.available()){
    char val = client.read();
    if('a' == val){
        digitalWrite(led, LOW);
      }
    else if('b' == val){
      digitalWrite(led, HIGH);
      }
    }
}
