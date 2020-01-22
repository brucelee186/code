void setup() {
  // put your setup code here, to run once:
  pinMode(16, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(15, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(16,LOW);
  digitalWrite(4,HIGH);
  delay(200);

  digitalWrite(4,LOW);
  digitalWrite(2,HIGH);
  delay(200);

  digitalWrite(2,LOW);
  digitalWrite(14,HIGH);
  delay(200);

  digitalWrite(14 ,LOW);
  digitalWrite(12,HIGH);
  delay(200);

  digitalWrite(12 ,LOW);
  digitalWrite(15,HIGH);
  delay(200);

  digitalWrite(15 ,LOW);
  digitalWrite(16,HIGH);
  delay(200);
}
