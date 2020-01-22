
String msg = "";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  
  while(!Serial);
}

void loop() {
  while(Serial.available() > 0){
    // 等待数据接收完毕
    //delay(100);
    msg += char(Serial.read());
    delay(5);
    }
    if(msg.length() > 0){
      Serial.println("Receive char: " + msg);
      msg = "";
    }
    
  }

