#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX
//byte sendDec[8]={01, 03, 00, 48, 00, 8, 196, 26};
//byte sendDec[8]={0x01, 0x03, 0x00, 0x48, 0x00, 0x08, 0xC4, 0x1A};
//char sendDec[]={'01', '03', '00', '48', '00', '08', 'C4', '1A'};
unsigned char sendDec[8] = {0x01, 0x03, 0x00, 0x48, 0x00, 0x08, 0xC4, 0x1A};
String dataRec = "";
void setup() {
  // put your setup code here, to run once:
   Serial.begin(4800);
     while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  mySerial.begin(4800);
}

void loop() {
   mySerial.write(sendDec,8);
   delay(2000);
    while(mySerial.available() > 0){
      char tempChar = char(mySerial.read());
      dataRec += tempChar;
       delay(2);
      }
      
  char string[105];  
  int strRec[100];
   int j =0;
  int arrValtage[6];
  for(int i=0;i<dataRec.length();i++){
    int tmp = 0;
       tmp = dataRec[i];
        int hex0 = tmp&15; 
        tmp >>= 4;
        int hex1 = tmp&15;
         //Serial.println(hex1); 
         strRec[j]=hex1;
         j++;
          strRec[j]=hex0;
          j++;
      }
      // 电压
     long valtageTemp = 0;
     float valtage = 0.00;
     //电流
     long electricityTemp = 0;
     float electricity = 0.00;
      for(int i=0;i<6;i++){
        // 电压
        int valtageInt =  strRec[i+8];
        long valtageLong = pow(16, 5-i)*valtageInt;
         valtageTemp += valtageLong;

         // 电流
         int electricityInt = strRec[i+16];
         long electricityLong = pow(16, 5-i)*electricityInt;
         electricityTemp += electricityLong;
        }
        valtage = (float) valtageTemp/10000;
        Serial.print("Valtage:");
        Serial.print(valtage,4);
         Serial.println("V");

             electricity = (float) electricityTemp/10000;
        Serial.print("Electricity:");
        Serial.print(electricity,4);
         Serial.println("A");
         Serial.println("");
  dataRec = "";
}
