/**
 * ReadSHT1xValues
 *
 * Read temperature and humidity values from an SHT1x-series (SHT10,
 * SHT11, SHT15) sensor.
 *
 * Copyright 2009 Jonathan Oxer <jon@oxer.com.au>
 * www.practicalarduino.com
 */

#include <SHT1x.h>

// Specify data and clock connections and instantiate SHT1x object
#define dataPin  0
#define clockPin 2

SHT1x sht1x(dataPin, clockPin);

void setup()
{
   Serial.begin(9600); // Open serial connection to report values to host
   Serial.println("Starting up");
}

void loop()
{
  float temp_c;
  float temp_f;
  float humidity;

  // Read values from the sensor
  temp_c = sht1x.readTemperatureC();
  temp_f = sht1x.readTemperatureF();
  humidity = sht1x.readHumidity();

  // Print the values to the serial port
  char string[25];
  String json =  itoa(temp_c,string,10);
  char t[20];
  char h[5];
  dtostrf(temp_c,1,2,t);
  dtostrf(humidity,1,2,h);
  String res = t;
  res += ",";
  res += h;
  Serial.println(res);
//  Serial.print("t:");
//  Serial.print(temp_c, DEC);
//  Serial.print("h:");
//  Serial.print(humidity);
//  Serial.println("");

  delay(2000);
}
