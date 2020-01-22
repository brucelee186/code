void setup() {
  // put your setup code here, to run once:
 pinMode(16,OUTPUT);

 pinMode(14,INPUT);

// 让14号口电位为正
 digitalWrite(14, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 14号口被短路到地,也就是触发按钮按下事件 
  if(digitalRead(14) == LOW)
    digitalWrite(16,HIGH);
  else
    digitalWrite(16,LOW);
}
