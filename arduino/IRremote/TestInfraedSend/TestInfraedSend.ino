#include <IRremote.h>
 
IRsend irsend;
int ledIR = 3;
 
void setup()
{
  Serial.begin(9600);
  pinMode(ledIR, OUTPUT);
  digitalWrite(ledIR, HIGH);
  delay(3000);
  digitalWrite(ledIR, LOW);
}
 
void loop() {
    //irsend.sendSony(818876655, 12); // Sony TV power code
    // 12394719, 0xBD20DF是aoc显示器静音的数字编码
    irsend.sendNEC(12394712, 32);
    //irsend.sendNEC(0xBD20DF, 32);
    Serial.println(12394719);
    delay(1000);
}
