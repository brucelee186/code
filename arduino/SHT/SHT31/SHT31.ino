/* 溫溼度計錄器
  Note: 須安裝 SHT1x Library:
        [url]https://github.com/practicalarduino/SHT1x/[/url]
 */
 
// 引用 LiquidCrystal & SHT1x Library
#include <LiquidCrystal.h>
#include <SHT1x.h>
 
// 建立 LiquidCrystal 的變數 lcd
//                 LCD 接腳:  rs, enable, d4, d5, d6, d7  
//      對應到 Arduino 接腳:  12,     11,  5,  4,  3,  2
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
// 定義 SHT1x 連接的腳位
#define dataPin  6
#define clockPin 7
 
// 初始化 sht1x 物件
SHT1x sht1x(dataPin, clockPin);
 
void setup() {
  Serial.begin(9600);
   
  // 設定 LCD 的行列數目 (2 x 16)
  lcd.begin(16, 2); 
}
 
void loop() {
  // 宣告 2 個變數，分別代表溫度(攝氏)與溼度
  float temp_c, humidity;
 
  // 讀取 SHT1x 溫溼度值
  temp_c = sht1x.readTemperatureC();
  humidity = sht1x.readHumidity();
   
  // 將游標設到 column 0, line 0  (第一行)
  lcd.setCursor(0, 0); 
  lcd.print("TEMP. : ");
  lcd.print(temp_c, 1);      // 顯示到小數點後一位
  lcd.print((char)223);      // 溫度符號(degree symbol)
  lcd.print("C");
 
  // 將游標設到 column 0, line 1  (第二行)
  lcd.setCursor(0, 1);  
  lcd.print("Humidity: ");
  lcd.print(humidity, 1);    // 顯示到小數點後一位
  lcd.print("%");
   
  Serial.print(temp_c);
  Serial.print(",");
  Serial.println(humidity);
   
  delay(2000);
}
