int pinSw1 = 16; 
int pinSw2 = 5;
int pinSw3 = 4;
int pinSw4 = 0;
int pinSw5 = 2;
int pinSw6 = 14;
int pinSw7 = 12;
int pinSw8 = 13;
void setup() {  
  pinMode(pinSw1, OUTPUT);
  pinMode(pinSw2, OUTPUT);  
  pinMode(pinSw3, OUTPUT);
  pinMode(pinSw4, OUTPUT);
  pinMode(pinSw5, OUTPUT);
  pinMode(pinSw6, OUTPUT);
  pinMode(pinSw7, OUTPUT);          
  pinMode(pinSw8, OUTPUT);  
}  
  
void loop() {   
   digitalWrite(pinSw1, HIGH);//输出HIGH电平,继电器模块闭合  
   digitalWrite(pinSw2, HIGH);//输出HIGH电平,继电器模块闭合  
   digitalWrite(pinSw3, HIGH);
   digitalWrite(pinSw4, HIGH);
   digitalWrite(pinSw5, HIGH);
   digitalWrite(pinSw6, HIGH);
   digitalWrite(pinSw7, HIGH);
   digitalWrite(pinSw8, HIGH);                  
   delay(3000); //等待5000毫秒  
  
   digitalWrite(pinSw1, LOW);//输出LOW电平,继电器模块断开  
   digitalWrite(pinSw2, LOW);
   digitalWrite(pinSw3, LOW);
   digitalWrite(pinSw4, LOW);
   digitalWrite(pinSw5, LOW);
   digitalWrite(pinSw6, LOW);
   digitalWrite(pinSw7, LOW);
   digitalWrite(pinSw8, LOW);                  
   delay(3000); //等待8000毫秒  
}  
