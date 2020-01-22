void setup() {
  // put your setup code here, to run once:
  pinMode(16,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 取值(0到255)
  // 由灭到亮
  for(int i = 0; i <= 30; i++){
      analogWrite(16, i);
      delay(10);
    }
   // 由这到灭
  for(int i = 30; i > 0; i--){
      analogWrite(16, i);
      delay(10);
    }
}
