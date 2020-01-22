
int ledTX = 0;
int ledRX = 1;
void setup() {
  Serial.begin(9600);
  pinMode(ledTX, OUTPUT);
  pinMode(ledRX, OUTPUT);
}

void loop() {
  while(Serial.available())
  {
    char c = Serial.read();
    Serial.println(c);
     if('1' == c)
     {
      Serial.println(c);
      digitalWrite(ledTX, LOW);
      digitalWrite(ledRX, LOW);
      delay(2000); 
     }
     if('0' == c)
     {
      Serial.println(c);
      digitalWrite(ledTX, HIGH);
      digitalWrite(ledRX, HIGH);
      delay(2000); 
     }
    if('a' == c)
    {
      Serial.println("I'm Ok");
    }
  }

}
