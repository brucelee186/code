#define SSID "NETGEAR19"        //type your own SSID name
#define PASSWORD "19891114"        //type your own WIFI password
 
 
#include "uartWIFI.h"
#include <SoftwareSerial.h>
WIFI wifi;
 
extern int chlID;        //client id(0-4)
 
 
void setup()
{
 
pinMode(16,OUTPUT); //使用mega的时候在不改变接线的情况下，此处改为24脚
 
wifi.begin();
bool b = wifi.Initialize(STA, SSID, PASSWORD);
if(!b)
{
DebugSerial.println("Init error");
}
delay(8000); //make sure the module can have enough time to get an IP address 
String ipstring = wifi.showIP();
DebugSerial.println(ipstring);        //show the ip address of module
 
delay(2000);
wifi.confMux(1);
delay(100);
if(wifi.confServer(1,8266))
DebugSerial.println("Server is set up");
 
 
}
void loop()
{
 
char buf[100];
int iLen = wifi.ReceiveMessage(buf);
if(iLen > 0)
{
 
 
if (strcmp(buf, "1") == 0)
{
digitalWrite(16,HIGH);  //使用megajh时候在不改变接线的情况下，此处改为24脚
DebugSerial.println("1");
}
if (strcmp(buf, "0") == 0)
{
digitalWrite(16,LOW); //使用mega的时候在不改变接线的情况下，此处改为24脚
DebugSerial.println("0");
} 
}
}

