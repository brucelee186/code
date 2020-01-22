#include <DigiKeyboard.h>

// 433接收端
#define pinRec433 0

int led = 1;

void setup()
{
  Serial.begin(9600);
  pinMode(pinRec433,INPUT);
  pinMode(led,OUTPUT);
}
  

void loop()
{
  digitalWrite(led, digitalRead(pinRec433));
   //DigiKeyboard.print("Receive 433 Code: ");
   //DigiKeyboard.println(digitalRead(pinRec433));
}

