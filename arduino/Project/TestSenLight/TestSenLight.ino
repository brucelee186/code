// 光线传感器
#define pinLight 0

void setup()
{
    Serial.begin(9600);
}


void loop()
{
   int senLight = analogRead(pinLight);
 Serial.print("Sense Ligth: ");
             Serial.println(senLight);


}
