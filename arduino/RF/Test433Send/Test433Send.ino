#include <RCSwitch.h>
// 娴嬭瘯鐢╨ed
#define led 1

// 433鎺ユ敹绔�
//#define pinRec433 5

// 433鍙戝皠绔�
#define pinSen433 2


// 433鎺ュ彈閬ユ帶瀵硅薄
//RCSwitch switch433Rec = RCSwitch();

// 433鍙戦�侀仴鎺у璞�
RCSwitch switch433Sen = RCSwitch();

 
void setup()
{
    Serial.begin(9600);
    //switch433Rec.enableReceive(pinRec433);
    switch433Sen.enableTransmit(pinSen433);
}
  

void loop()
{
    switch433Sen.send(24996, 12);
    Serial.println("Send 433 Code: 2499600");
    delay(300);

}


