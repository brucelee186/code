// This example just provide basic function test;
// For more informations, please vist www.heltec.cn or mail to support@heltec.cn

#include <Wire.h>
#include "OLED.h"
#include "DHT.h"

#define DHTPIN 2

//WIFI_Kit_8's OLED connection:
//SDA -- GPIO4 -- D2
//SCL -- GPIO5 -- D1
//RST -- GPIO16 -- D0

#define DHTTYPE DHT11



#define RST_OLED 16
OLED display(4, 5);

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  dht.begin();
  
  pinMode(RST_OLED, OUTPUT);
  digitalWrite(RST_OLED, LOW);   // turn D2 low to reset OLED
  delay(50);
  digitalWrite(RST_OLED, HIGH);    // while OLED is running, must set D2 in high
  
  Serial.begin(9600);
  Serial.println("OLED test!");

  // Initialize display
  display.begin();

}

int r = 0, c = 0;

void loop() {
    Serial.println("OLED test!");
    r = r % 4;
    c = micros() % 6;
    if (r == 0) display.clear();
    display.print("Hello Moto", r++, c++);
    delay(2000);
    float h = dht.readHumidity();
    Serial.print(h);
    
}
