int led = 1;
int pinSr501 = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(pinSr501,INPUT);
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int valSr501 = digitalRead(pinSr501);
  Serial.println(valSr501);
}

