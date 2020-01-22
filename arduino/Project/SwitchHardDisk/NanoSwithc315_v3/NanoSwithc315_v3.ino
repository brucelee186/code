#include<RCSwitch.h>

// 这个针角对应的是终断0,1,arduion uno只有两个中断0,1对应pin,2,3
#define pinRec315 0
int led = 1;
  
//int pinPower = 3;
//int pinReset = 4;

int pinSw1 = 12;
int pinSw2 = 11;
int pinSw3 = 10;
int pinSw4 = 9;
int pinSw5 = 8;
int pinSw6 = 7;
int pinSw7 = 6;
int pinSw8 = 5;

int tagHdd1 = 0;
int tagHdd2 = 0;
int tagHdd3 = 0;
int tagHdd4 = 0;
int tagHdd5 = 0;
int tagHdd6 = 0;

int powerHdd1 = 0;
int powerHdd2 = 0;
// 硬盘编号 1到6
int hddNo = 0;
// 433接受遥控对象
RCSwitch switch315Rec = RCSwitch();
//表示EEPROM的当前地址，也就是即将要写入的地址
int addr = 1;
  
void setup() {
   Serial.begin(9600);

  pinMode(pinSw1, OUTPUT);
  pinMode(pinSw2, OUTPUT);  
  pinMode(pinSw3, OUTPUT);
  pinMode(pinSw4, OUTPUT);
  pinMode(pinSw5, OUTPUT);
  pinMode(pinSw6, OUTPUT);
  pinMode(pinSw7, OUTPUT);          
  pinMode(pinSw8, OUTPUT);
  
  digitalWrite(pinSw1, HIGH);  
  digitalWrite(pinSw2, HIGH); 
  digitalWrite(pinSw3, HIGH);
  digitalWrite(pinSw4, HIGH);
  digitalWrite(pinSw5, HIGH);
  digitalWrite(pinSw6, HIGH);
  digitalWrite(pinSw7, HIGH);
  digitalWrite(pinSw8, HIGH);

 // 这个针角对应的是终断0,1,arduion uno只有两个中断0,1对应pin,2,3
 switch315Rec.enableReceive(pinRec315);
 //Serial.println(powerHdd1);
 //Serial.println(powerHdd2);
}
void loop()
{
    long rec315 = 0;
    if(switch315Rec.available()){
      rec315 = switch315Rec.getReceivedValue();
      if(rec315 != 0){
            Serial.print("Receive 315: ");
            Serial.println(rec315);
            switch315Rec.resetAvailable();
        }
   
    }

                    if(5588737 == rec315){
                      hddNo++;
                      if(hddNo >= 7) hddNo = 0;
                      Serial.print("HDD NO: ");
                      Serial.println(hddNo);
                    } 
                          
                    if(5588740 == rec315){
                        if( 1 == hddNo){
                          if(0 == tagHdd1){
                            tagHdd1 = 1;
                            // 写入高电位使用硬盘1启动，不写也可，默认高电位
                            digitalWrite(pinSw1, HIGH);
                           // 写入低电位，断开硬盘2
                           //digitalWrite(pinSw2,LOW);
                          } else {
                            tagHdd1 = 0;
                            digitalWrite(pinSw1, LOW);
                          }
                           hddNo = 0;
                        }
                        else if( 2 == hddNo){
                          if(0 == tagHdd2){
                            tagHdd2 = 1;
                            // 写入高电位使用硬盘1启动，不写也可，默认高电位
                            digitalWrite(pinSw2, HIGH);
                          } else {
                            tagHdd2 = 0;
                            digitalWrite(pinSw2, LOW);
                          }
                        }
                        else if( 3 == hddNo){
                          if(0 == tagHdd3){
                            tagHdd3 = 1;
                            // 写入高电位使用硬盘1启动，不写也可，默认高电位
                            digitalWrite(pinSw3, LOW);
                          } else {
                            tagHdd3 = 0;
                            digitalWrite(pinSw3, HIGH);
                          }
                        }
                        else if( 4 == hddNo){
                          if(0 == tagHdd4){
                            tagHdd4 = 1;
                            // 写入高电位使用硬盘1启动，不写也可，默认高电位
                            digitalWrite(pinSw4, LOW);
                          } else {
                            tagHdd4 = 0;
                            digitalWrite(pinSw4, HIGH);
                          }
                        }
                         else if( 5 == hddNo){
                          if(0 == tagHdd5){
                            tagHdd5 = 1;
                            // 写入高电位使用硬盘1启动，不写也可，默认高电位
                            digitalWrite(pinSw5, LOW);
                          } else {
                            tagHdd5 = 0;
                            digitalWrite(pinSw5, HIGH);
                          }
                        }
                        else if( 6 == hddNo){
                          if(0 == tagHdd6){
                            tagHdd6 = 1;
                            // 写入高电位使用硬盘1启动，不写也可，默认高电位
                            digitalWrite(pinSw6, LOW);
                          } else {
                            tagHdd6 = 0;
                            digitalWrite(pinSw6, HIGH);
                          }
                        }
                    } 
                    switch315Rec.resetAvailable();
      
}
 
