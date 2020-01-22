byte number = 0;

int led = 13;
void setup(){
     Serial.begin(9600);
     pinMode(led, OUTPUT);
}

void loop(){
    if (Serial.available()) {
      digitalWrite(led, HIGH);
      
       number = Serial.read();
       Serial.print("character recieved: ");
       Serial.println(number, DEC);
       delay(500);
       digitalWrite(led, LOW);
   }
}
