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

#define DHTTYPE DHT22



#define RST_OLED 16
OLED display(4, 5);

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  dht.begin();
  
  pinMode(RST_OLED, OUTPUT);
  digitalWrite(RST_OLED, LOW);   // turn D2 low to reset OLED
  delay(50);
  digitalWrite(RST_OLED, HIGH);    // while OLED is running, must set D2 in high
  display.begin();
  
  Serial.begin(9600);
  
  

}



void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
  char   ch[10];  
  dtostrf(h,1,2,ch);  
  
  char   ct[10];  
  dtostrf(t,1,2,ct);
//   display.print("H:", 0, 0);
//  display.print(ch, 0, 2);
//  display.print("%",0, 7);  
//  
//  display.print("T: ", 0, 9);
//  display.print(ct, 0, 11);
//  display.print("C", 0, 16); 
  
  
  display.print(ch, 0, 0);
  display.print("%",0, 5);  
  
  display.print(ct, 0, 7);
  display.print("C", 0, 12); 
    

  display.print("T: ", 1, 0);
  display.print(ct,1, 2);
  display.print("C",1, 7); 
    
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");
  

    
}
