#include <IRremote.h>
#include <RCSwitch.h>

int RECV_PIN = 4;//定义红外接收器的引脚为11
IRrecv irrecv(RECV_PIN);
decode_results results;

RCSwitch mySwitch = RCSwitch();

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // 初始化红外接收器

   mySwitch.enableTransmit(5);

}

void loop() {
  if (irrecv.decode(&results)) {
    
    Serial.println(results.value, HEX);//以16进制换行输出接收代码
    Serial.println(results.value, 2);
    unsigned long code = results.value;
    Serial.print("long value:");
    Serial.println(code);
    //为了便于观看输出结果增加一个空行
    
    //mySwitch.send(code, 36);
    mySwitch.send(code, 24);
   Serial.println(code);
    irrecv.resume(); // 接收下一个值
  }
}
