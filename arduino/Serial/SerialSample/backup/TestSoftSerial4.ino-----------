#include <SoftwareSerial.h>

SoftwareSerial mySerial(5, 6); // RX, TX

unsigned char sendDec[8] = {0x01, 0x03, 0x00, 0x48, 0x00, 0x08, 0xC4, 0x1A};
String dataRec = "";
void setup() {
   Serial.begin(4800);
     while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  mySerial.begin(4800);
}


void loop() {
	 mySerial.write(sendDec,8);
   delay(6000);
    while(mySerial.available() > 0){
      char tempChar = char(mySerial.read());
      dataRec += tempChar;
       delay(2);
      }
int strRec[100];
   int j =0;
  int arrValtage[6];
  for(int i=0;i<dataRec.length();i++){
    int tmp = 0;
       tmp = dataRec[i];
        int hex0 = tmp&15; 
        tmp >>= 4;
        int hex1 = tmp&15;
	//Serial.println(dataRec[i],HEX);
         strRec[j]=hex1;
         j++;
          strRec[j]=hex0;
          j++;
      }

      Serial.println("");
       Serial.println("********************** START ************************");
      float valtage =  getData(strRec,
      Serial.print("Valtage:");
      Serial.print(valtage,4);
      Serial.println("V");

int strRec[]float getData(int strRec[],int j){
     long valTemp = 0;
     float val = 0.00;
      for(int i=0;i<6;i++){ 
        int valInt =  strRec[i+j];
        long valLong = pow(16, 5-i)*valInt;
         valTemp += valLong;

        }
        val = (float) valTemp/10000;
       return val;
  }
}
