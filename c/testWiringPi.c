#include <wiringPi.h>

int main(void){
  int pinLed = 8;
  wiringPiSetup();
  pinMode(pinLed,OUTPUT);
  for(;;){
    digitalWrite(pinLed,HIGH);
    delay(1000);
    digitalWrite(pinLed,LOW);
    delay(1000);
  }
}
