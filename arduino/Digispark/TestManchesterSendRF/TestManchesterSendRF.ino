//will work on Attiny85/45

//RF433=D0 pin 5

// libraries
#include <Manchester.h>
#define TX_PIN 3 

#define ledSend 13
//variables
float h=0;
float t=0;
int transmit_t = 0;
int transmit_h = 0;
int transmit_data = 213213;

void setup() 
{
  man.setupTransmit(TX_PIN, MAN_1200);
  pinMode(ledSend, OUTPUT);
}

void loop() {
  man.transmit(transmit_data);
  digitalWrite(ledSend,HIGH);
  delay(500);
  digitalWrite(ledSend,LOW);
  delay(500);   
}
