void setup() {
  // put your setup code here, to run once:
  pinMode(4,INPUT);
  pinMode(16,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(4)==HIGH){
    digitalWrite(16,HIGH);
    }
   else{
    digitalWrite(16,LOW);
    }
}
