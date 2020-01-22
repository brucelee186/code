#include <Wire.h>
#include "OLED.h"
#include <SHT1x.h>

// 定义OLED通信针角
#define RST_OLED 16
OLED display(4, 5);

// 定义 SHT1x 数据交互针脚
#define dataPin  1
#define clockPin 3

// 初始化 sht1x 物件
SHT1x sht1x(dataPin, clockPin);

void setup() {
  //pinMode(RST_OLED, OUTPUT);
  //digitalWrite(RST_OLED, LOW);   // turn D2 low to reset OLED
 // delay(50);
 // digitalWrite(RST_OLED, HIGH);    // while OLED is running, must set D2 in high

  Serial.begin(9600);
  Serial.println("OLED test!");
  
  // Initialize display
  //display.begin();
  
}

void loop() {
   // 宣告三個變數，分別代表溫度(攝氏), 溫度(華氏) 以及溼度
   Serial.print("Temperature1: ");
  float temp_c, temp_f, humidity;
 Serial.print("Temperature2: ");
  // 讀取 SHT1x 溫溼度值
  temp_c = sht1x.readTemperatureC();
  temp_f = sht1x.readTemperatureF();
  humidity = sht1x.readHumidity();
 
  // 將讀到的溫溼度讀值輸出至 Serial Port
  Serial.print("Temperature: ");
  Serial.print(temp_c, 1);  // 顯示到小數點後一位
  Serial.print("C / ");
  Serial.print(temp_f, 1);  // 顯示到小數點後一位
  Serial.print("F. Humidity: ");
  Serial.print(humidity);
  Serial.println("%");
 
  delay(1000);
  char   c[10];  
dtostrf(temp_c,1,2,c);  
Serial.println(c);  
  // display.print(c, 0,3);
  //display.print("forever row2", 1);
  // display.print("forever row3", 2);
   //display.print("forever row4", 3);

}
