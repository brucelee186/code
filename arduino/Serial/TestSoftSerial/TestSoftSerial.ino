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
 // Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(4800);
 // mySerial.println("Hello, world?");
}

void loop() {
  // put your main code here, to run repeatedly:

  //  Serial.write("01 03 00 48 00 08 196 26");
 

   //mySerial.write("01 03 00 48 00 08 C4 1A");
   //Serial.write(sendDec,8);
   mySerial.write(sendDec,8);.
//   mySerial.println("01 03 00 48 00 08 C4 1A");
//   Serial.println("01 03 00 48 00 08 C4 1A");
   delay(10000);
//   if (Serial.available()) {
//      
//    //Serial.println(Serial.read());
//   }
    while(mySerial.available() > 0){
      char tempChar = char(mySerial.read());
      dataRec += tempChar;
      // Serial.println(tempChar,HEX);
       delay(2);
      }
         //Serial.println(dataRec);
    //Serial.println(dataRec.length());
//     if (mySerial.available()) {
//    Serial.println(dataRec);
//    Serial.println(dataRec.length());
//  }
//  for(int i=0;i<dataRec.length();i++){
//       Serial.print("comdata[");
//       Serial.print(i,DEC);
//       Serial.print("]=");
//       Serial.println(dataRec[i],HEX);  
//      }
  char string[105];  
  int strRec[100];
   int j =0;
  for(int i=0;i<dataRec.length();i++){
       //Serial.println(dataRec[i],HEX);
        //  Serial.println(dataRec[i]);
       //toolHex(dataRec[i]);
       //char *itoa(int value,  char *string, int radix);
  //原型说明：
  //value：欲转换的数据。
  //string：目标字符串的地址。
  //radix：转换后的进制数，可以是10进制、16进制等。
       itoa(dataRec[i], string, 16);  
  Serial.println(string);
  int tmp = 0;
       tmp = dataRec[i];
       printf("%02X ",tmp&255);
        int hex0 = tmp&15;
        Serial.println(hex0); 
        tmp >>= 4;
        int hex1 = tmp&15;
         Serial.println(hex1); 
         strRec[j]=hex1;
         j++;
          strRec[j]=hex0;
          j++;
        Serial.println("************************" );
        //Serial.println(j);
      }
      for(int i=0;i<100;i++){
         Serial.println(strRec[i],DEC);
        }
        
  dataRec = "";
}

void toolHex(int g){ // 把 g 最右邊 byte 印成 Hex 倆位
  int a = g& 0xf0;  // 左邊 4 bits
  int b = g& 0x0f;  // 右邊 4 bits
  char c = a < 10 ? a + '0' : a + 'A' - 10;
  Serial.write(c);
 // c = b < 10 ? b + '0' : b + 'A' - 10;
  //Serial.write(c);
} 
