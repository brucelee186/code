#include<RCSwitch.h>

// 这个针角对应的是终断0,1,arduion uno只有两个中断0,1对应pin,2,3
#define pinRec315 0
int led = 1;
  
//int pinPower = 3;
//int pinReset = 4;

int pinSw1 = 1;
int pinSw2 = 2;
int pinSw3 = 10;
int pinSw4 = 9;
int pinSw5 = 8;
int pinSw6 = 7;
int pinSw7 = 6;
int pinSw8 = 5;

int tagHdd1 = 0;
int tagHdd2 = 0;

int powerHdd1 = 0;
int powerHdd2 = 0;
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
           switch315Rec.resetAvailable();
           Serial.print("Receive 315: ");
           Serial.println(rec315);
        }
      
    }

                    if(5588739 == rec315){
                       if( 0 == tagHdd1){
                          // 写入高电位使用硬盘1启动，不写也可，默认高电位
                          digitalWrite(pinSw1, HIGH);
                          // 写入低电位，断开硬盘2
                          digitalWrite(pinSw2,LOW);
                        }
                        else if(1 == tagHdd1){
                          digitalWrite(pinSw1,LOW);
                          digitalWrite(pinSw2,HIGH);
                          }
                      if(0 == tagHdd1){
                        tagHdd1 = 1;
                        } else {
                          tagHdd1 = 0;
                          }
                    } 
                    if(5588748 == rec315){
                       if( 0 == tagHdd2){
                          digitalWrite(pinSw2, HIGH);
                          digitalWrite(pinSw1,LOW);
                        }
                        else if(1 == tagHdd2){
                          digitalWrite(pinSw2,LOW);
                          digitalWrite(pinSw1,HIGH);
                          }
                      if(0 == tagHdd2){
                        tagHdd2 = 1;
                        } else {
                          tagHdd2 = 0;
                          }
                    } 
                      
  char msg = Serial.read();
                  if('1' == msg ){
                    digitalWrite(pinSw1, HIGH);
                    } else if('a' == msg){
                      digitalWrite(pinSw1,LOW);
                      }
              if('2' == msg ){
                    digitalWrite(pinSw2, HIGH);
                    } else if('b' == msg){
                      digitalWrite(pinSw2,LOW);
                      }    
                 if('3' == msg){
                    digitalWrite(pinSw3, LOW);
                    } else if('c' == msg){
                      digitalWrite(pinSw3,HIGH);
                      }     
                 if('4' == msg){
                    digitalWrite(pinSw4, LOW);
                    } else if('d' == msg){
                      digitalWrite(pinSw4,HIGH);
                      }      
                 if('5' == msg){
                    digitalWrite(pinSw5, LOW);
                    } else if('e' == msg){
                      digitalWrite(pinSw5,HIGH);
                      }  
                 if('6' == msg){
                    digitalWrite(pinSw6, LOW);
                    } else if('f' == msg){
                      digitalWrite(pinSw6,HIGH);
                      }  
                 if('7' == msg || 5588928 == rec315){
                    digitalWrite(pinSw7, LOW);
                    delay(500);
                    } else if('g' == msg || 0 == rec315){
                      digitalWrite(pinSw7,HIGH);
                      }  
                 if('8' == msg || 5588784 == rec315){
                    digitalWrite(pinSw8, LOW);
                    delay(500);
                    } else if('h' == msg || 0 == rec315){
                      digitalWrite(pinSw8,HIGH);
                      }                                                                                                            
}
 
