#include <RCSwitch.h>

// 这个针角对应的是终断0,1,arduion uno只有两个中断0,1对应pin,2,3
#define pinRec315 0
int led = 1;
  
int pinPower = 3;
int pinReset = 4;

int pinSw1 = 12;
int pinSw2 = 11;
int pinSw3 = 10;
int pinSw4 = 9;
int pinSw5 = 8;
int pinSw6 = 7;
int pinSw7 = 6;
int pinSw8 = 5;

// 433接受遥控对象
RCSwitch switch315Rec = RCSwitch();

void setup()
{
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

   pinMode(pinRec315,INPUT);
    // 这个针角对应的是终断0,1,arduion uno只有两个中断0,1对应pin,2,3
    switch315Rec.enableReceive(pinRec315);
}
  

void loop()
{
    // long rec315 = 0;
    if(switch315Rec.available()){
      long rec315 = switch315Rec.getReceivedValue();
      if(rec315 != 0){
               Serial.print("Receive Code 433: ");
         Serial.println(rec315);
          switch315Rec.resetAvailable();
          // 开机
    if(5588928 == rec315){
        
       pinMode(pinPower, OUTPUT);
       digitalWrite(pinPower, LOW);     
      }
      else{
         
        pinMode(pinPower,   INPUT);
        digitalWrite(pinPower, HIGH); 
        }    
        }
    }
    
                                                                                                    
}
 


