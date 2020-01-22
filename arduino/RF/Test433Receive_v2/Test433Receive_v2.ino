int rec433 = 3;
int led = 0;
void setup()
{
  Serial.begin(9600);
pinMode(rec433,INPUT); //设置12脚为数据接收（datain）脚
pinMode(led,OUTPUT); //设置13脚为LED显示管脚
}
void loop ()
{
  digitalWrite(led, HIGH);
  delay(1000);
  int val433 = digitalRead(rec433);
  Serial.print("Receive 433 code:");
  Serial.println(val433);
  digitalWrite(led, LOW);
  delay(1000);
}
