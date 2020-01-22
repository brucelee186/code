#define led  13
void setup() {
  Serial.begin(9600);
  Serial.print("hello Ting");
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led,HIGH);
  Serial.println("ON");
  delay(2000);
  digitalWrite(led,LOW);
  delay(2000);  
   Serial.println("OFF");
}
