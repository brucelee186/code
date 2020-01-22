int led = 0;
char c = '0';

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop()
{
            char s = Serial.read();
            if('1' == s || '0' == s)
            {
              c = s;  
            }
            
            if('1' == c)
            {
              Serial.println(c);
              digitalWrite(led, HIGH);
            } 
            else if('0' == c)
            {
              Serial.println(c);
              digitalWrite(led, LOW);
            }
}
