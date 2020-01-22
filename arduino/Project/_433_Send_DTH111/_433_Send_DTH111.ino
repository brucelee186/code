#include <RCSwitch.h>
#include "stdio.h"
double Fahrenheit(double celsius)
{
  return 1.8 * celsius + 32;
}    //摄氏温度度转化为华氏温度

double Kelvin(double celsius)
{
  return celsius + 273.15;
}     //摄氏温度转化为开氏温度

// 露点（点在此温度时，空气饱和并产生露珠）
// 参考: [url=http://wahiduddin.net/calc/density_algorithms.htm]http://wahiduddin.net/calc/density_algorithms.htm[/url]
double dewPoint(double celsius, double humidity)
{
  double A0 = 373.15 / (273.15 + celsius);
  double SUM = -7.90298 * (A0 - 1);
  SUM += 5.02808 * log10(A0);
  SUM += -1.3816e-7 * (pow(10, (11.344 * (1 - 1 / A0))) - 1) ;
  SUM += 8.1328e-3 * (pow(10, (-3.49149 * (A0 - 1))) - 1) ;
  SUM += log10(1013.246);
  double VP = pow(10, SUM - 3) * humidity;
  double T = log(VP / 0.61078); // temp var
  return (241.88 * T) / (17.558 - T);
}

// 快速计算露点，速度是5倍dewPoint()
// 参考: [url=http://en.wikipedia.org/wiki/Dew_point]http://en.wikipedia.org/wiki/Dew_point[/url]
double dewPointFast(double celsius, double humidity)
{
  double a = 17.271;
  double b = 237.7;
  double temp = (a * celsius) / (b + celsius) + log(humidity / 100);
  double Td = (b * temp) / (a - temp);
  return Td;
}

#include <dht11.h>

dht11 DHT11;

#define DHT11PIN 2

#define pinSen433 3

#define pinLed 13

RCSwitch switch433Sen = RCSwitch();

void setup()
{
  Serial.begin(9600);
  Serial.println("DHT11 TEST PROGRAM ");
  Serial.print("LIBRARY VERSION: ");
  Serial.println(DHT11LIB_VERSION);
  Serial.println();
  pinMode(pinLed, OUTPUT);

  switch433Sen.enableTransmit(pinSen433);
}

void loop()
{
  Serial.println("\n");

  int chk = DHT11.read(DHT11PIN);

 Serial.print("Read sensor: ");
  switch (chk)
  {
    case DHTLIB_OK:
      Serial.println("OK");
      break;
    case DHTLIB_ERROR_CHECKSUM:
      Serial.println("Checksum error");
      break;
    case DHTLIB_ERROR_TIMEOUT:
      Serial.println("Time out error");
      break;
    default:
      Serial.println("Unknown error");
      break;
  }

  char humidity = DHT11.humidity;
  char temperature = DHT11.temperature;
    Serial.print("Humidity (%): ");
    Serial.println((float)DHT11.humidity, 2);
  
    Serial.print("Temperature (oC): ");
    Serial.println((float)DHT11.temperature, 2);
  //
  //  Serial.print("Temperature (oF): ");
  //  Serial.println(Fahrenheit(DHT11.temperature), 2);
  //
  //  Serial.print("Temperature (K): ");
  //  Serial.println(Kelvin(DHT11.temperature), 2);
  //
  //  Serial.print("Dew Point (oC): ");
  //  Serial.println(dewPoint(DHT11.temperature, DHT11.humidity));
  //
  //  Serial.print("Dew PointFast (oC): ");
  //  Serial.println(dewPointFast(DHT11.temperature, DHT11.humidity));

  //  switch433Sen.send(humidity, 20);
  //    Serial.println("Send 433 Code: ");
//      Serial.println(humidity,20);

//  char rfCode[] = "dht11_01///";
//  char tag[] = "///";
  char rfCode[20] = {'1','0','0','1'};
  char t[4];
  dtostrf(temperature, 0, 0, t);
// Serial.println(t);
   
  char   h[2];
  dtostrf(humidity, 0, 0, h);
  strcat(t,h);
  //Serial.println(t);
  strcat(rfCode,t);
   //Serial.println(rfCode);
//  strcat(rfCode,h);
//   Serial.println(rfCode);
  digitalWrite(pinLed, HIGH);
//switch433Sen.send(long(rfCode), 20);
 //Serial.println(t);
  //Serial.println(long(10012819));

  // unsigned char code[]={'1','2','3','4','6','5'};
  long codeSend433;
  sscanf((char *)rfCode,"%ld",&codeSend433);
    //Serial.println(x);
   // Serial.println(rfCode);
  Serial.println(codeSend433); 
  switch433Sen.send(codeSend433, 24);
   //switch433Sen.send(10012819, 24);
  delay(1000);
  digitalWrite(pinLed, LOW); 
  delay(1000); 
  
//  //定义一个字符串
//  //进行字符串拼接操作
//      strcat(t,tag);
//      strcat(t,h);
//      strcat(rfCode, t);
//      Serial.println(rfCode);
      //switch433Sen.send(long(rfCode), 20);
//  strcat(t, h);
//      String code433 = "";
//      for(int i=0; i< 4;i++){
//          code433 += t[i];
//        }
 // strcat(t,h);
//  digitalWrite(pinLed, HIGH);
  //Serial.println(t);
//  //    switch433Sen.send(long(t) , 20);
//
//  delay(2000);
//  digitalWrite(13, LOW);
}
