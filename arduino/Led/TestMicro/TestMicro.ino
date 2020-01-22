// the setup routine runs once when you press reset:

int led1 = 1;
int led2 = 0;
void setup() {                
  // initialize the digital pin as an output.
  //pinMode(0, OUTPUT); //LED on Model B
  pinMode(led1, OUTPUT); //LED on Model A   
  pinMode(led2, OUTPUT);
}
 
// the loop routine runs over and over again forever:
void loop() {
  //digitalWrite(0, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  delay(2000);               // wait for a second
  //digitalWrite(0, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(led1, LOW); 
  digitalWrite(led2, HIGH); 
  delay(2000);               // wait for a second
}

