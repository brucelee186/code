void setup(){
 Serial.begin(9600);
 pinMode(16,OUTPUT); 
  
}


void loop(){
  int message = Serial.read();
  if('N' == message){
    Serial.println(message);
    digitalWrite(16,HIGH);
    delay(2000);
    Serial.println("Hello Ting");
    digitalWrite(16,LOW);
    delay(2000);
  }
}
