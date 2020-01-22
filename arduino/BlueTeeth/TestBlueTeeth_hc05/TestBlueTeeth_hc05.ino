char val;
//int ledpin=13;
void setup()
{
  Serial.begin(9600);
  //pinMode(ledpin,OUTPUT);
}
 
void loop()
{
   while(Serial.available()){
   
  val=Serial.read();
  Serial.println(val);

 
  if(val=='q')
  {
    //digitalWrite(ledpin,HIGH);
    Serial.println("LED ON!");
  }else if(val=='w'){
  //digitalWrite(ledpin,LOW);
Serial.println("LED OFF!");
  }
   }
}
