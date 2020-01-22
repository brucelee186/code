
int pinSw1 = 12;
int pinSw2 = 11;
int pinSw3 = 10;
int pinSw4 = 9;
int pinSw5 = 8;
int pinSw6 = 7;
int pinSw7 = 6;
int pinSw8 = 5;
 
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
  
  digitalWrite(pinSw1, LOW);  
  digitalWrite(pinSw2, HIGH); 
  digitalWrite(pinSw3, HIGH);
  digitalWrite(pinSw4, HIGH);
  digitalWrite(pinSw5, HIGH);
  digitalWrite(pinSw6, HIGH);
  digitalWrite(pinSw7, HIGH);
  digitalWrite(pinSw8, HIGH);
}
  

void loop()
{
  char msg = Serial.read();

                  if('1' == msg){
                    digitalWrite(pinSw1, LOW);
                    } else if('a' == msg){
                      digitalWrite(pinSw1,HIGH);
                      }
              if('2' == msg){
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
                 if('7' == msg){
                    digitalWrite(pinSw7, LOW);
                    } else if('g' == msg){
                      digitalWrite(pinSw7,HIGH);
                      }  
                 if('8' == msg){
                    digitalWrite(pinSw8, LOW);
                    } else if('h' == msg){
                      digitalWrite(pinSw8,HIGH);
                      }                                                                                                            
}
 

