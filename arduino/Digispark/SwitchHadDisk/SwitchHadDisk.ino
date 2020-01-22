
#include <SoftSerial.h>     

SoftSerial softSerial(1, 2); // RX, TX

int pinSw1 = 0;
int pinSw2 = 3;
int pinSw3 = 4;
int pinSw4 = 5;

void setup()  
{
  softSerial.begin(9600);
  softSerial.println("Action!");

  pinMode(pinSw1, OUTPUT);
  pinMode(pinSw2, OUTPUT);  
  pinMode(pinSw3, OUTPUT);
  pinMode(pinSw4, OUTPUT);
  digitalWrite(pinSw1, HIGH);  
  digitalWrite(pinSw2, HIGH); 
  digitalWrite(pinSw3, HIGH);
  digitalWrite(pinSw4, HIGH);  
}

void loop()
{
  while (softSerial.available()){
     char msg = softSerial.read();
    softSerial.println("MySerial is avaiable!");
    softSerial.println(msg);
       if('1' == msg ){
                    digitalWrite(pinSw1, LOW);
                    } else if('a' == msg){
                      digitalWrite(pinSw1,HIGH);
                      }
              if('2' == msg ){
                    digitalWrite(pinSw2, LOW);
                    } else if('b' == msg){
                      digitalWrite(pinSw2,HIGH);
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
  }
}
