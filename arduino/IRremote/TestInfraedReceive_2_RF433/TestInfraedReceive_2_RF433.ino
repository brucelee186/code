#include <IRremote.h>

#include <RCSwitch.h>
// 测试用led
#define led 0

// 433发射端
#define pinSen433 4

 
int pinRecRF = 3;
 
IRrecv irrecv(pinRecRF);
 
decode_results results;

// 433发送遥控对象
RCSwitch switch433Sen = RCSwitch();
 
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); //初始化红外遥控
  pinMode(12,1);

  switch433Sen.enableTransmit(pinSen433);
}
 
void loop() 
{
  if (irrecv.decode(&results)) 
  {
    long codeRF = results.value;
    char decodeType = results.decode_type;
    Serial.println(results.decode_type);
     Serial.println(results.bits);
    Serial.print("Receive Infraed Code: ");
    Serial.println(codeRF);
    Serial.print("Receive Infraed Code HEX: ");
    Serial.println(results.value, HEX);
    switch433Sen.send(codeRF, 32);
    irrecv.resume(); // 接收下一个值
  }
}
