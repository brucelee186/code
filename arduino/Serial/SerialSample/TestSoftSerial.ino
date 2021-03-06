#include <SoftwareSerial.h>
#include <string.h>

SoftwareSerial mySerial(5, 6); // RX, TX

unsigned char sendDec[8] = {0x01, 0x03, 0x00, 0x48, 0x00, 0x08, 0xC4, 0x1A};
String dataRec = "";
String dataSen = "";
String strSerial = "";
// ec01:Electric 01;
String strComEc01 = "ec01";
void setup() {
   Serial.begin(4800);
     while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  mySerial.begin(4800);
}


void loop() {
	while(Serial.available() > 0){
		char dataSerRead= char(Serial.read());
		strSerial += dataSerRead;
		delay(3);
		// loop n times when serial prot is receive already
		//Serial.println(++j);
	}

	if(strComEc01.compareTo(strSerial) == 0){
		// run one times when read "ec01" already
		//Serial.println(++ti);
		strSerial = "";
		mySerial.write(sendDec,8);
		while(mySerial.available() > 0){
			char tempChar = char(mySerial.read());
			//Serial.println(tempChar, HEX);
			dataRec += tempChar;
			delay(3);
			// run n times when recieve soft serial prot done
			//Serial.println(++ti);
		}
		//Serial.println(dataRec, HEX);
		
		int strRec[100];
		int j =0;
		//Serial.print("Data Receive Array Length = ");
		//Serial.println(dataRec.length(),DEC);
		if(dataRec.length() == 37){
		for(int i=0;i<dataRec.length();i++){
			//Serial.println(dataRec[i],HEX);
			int tmp = 0;
			tmp = dataRec[i];
			int hex0 = tmp&15; 
			tmp >>= 4;
			int hex1 = tmp&15;
			strRec[j]=hex1;
			j++;
			strRec[j]=hex0;
			j++;
		}
		long valTemp = 0;
		j = 8;
		for(int i=0;i<6;i++){ 
			int valInt =  strRec[i+j];
			long valLong = pow(16, 5-i)*valInt;
			valTemp += valLong;
		}
		float val  =  (float)valTemp/10000;
		char charVal[8];
		dtostrf(val,3,4,charVal);
		dataSen =  "voltage:";
		dataSen += charVal;
	

                valTemp = 0;
                j = 16;
                for(int i=0;i<6;i++){
                        int valInt =  strRec[i+j];
                        long valLong = pow(16, 5-i)*valInt;
                        valTemp += valLong;
                }
                val =  (float)valTemp/10000;
                dtostrf(val,3,4,charVal);
                dataSen +=  ",electricity:";
                dataSen += charVal;

                valTemp = 0;
                j = 24;
                for(int i=0;i<6;i++){
                        int valInt =  strRec[i+j];
                        long valLong = pow(16, 5-i)*valInt;
                        valTemp += valLong;
                }
                val =  (float)valTemp/10000;

		dtostrf(val,5,2,charVal);
                dataSen +=  ",power:";
                dataSen += charVal;

                valTemp = 0;
                j = 32;
                for(int i=0;i<6;i++){
                        int valInt =  strRec[i+j];
                        long valLong = pow(16, 5-i)*valInt;
                        valTemp += valLong;
                }
                val =  (float)valTemp/10000;
                dtostrf(val,5,2,charVal);
                dataSen +=  ",electricEnergy:";
                dataSen += charVal;

                valTemp = 0;
                j = 40;
                for(int i=0;i<6;i++){
                        int valInt =  strRec[i+j];
                        long valLong = pow(16, 5-i)*valInt;
                        valTemp += valLong;
                }
                val =  (float)valTemp/10000;
	        dtostrf(val,2,4,charVal);
                dataSen +=  ",powerFactor:";
                dataSen += charVal;

                valTemp = 0;
                j = 48;
                for(int i=0;i<6;i++){
                        int valInt =  strRec[i+j];
                        long valLong = pow(16, 5-i)*valInt;
                        valTemp += valLong;
                }
                val =  (float)valTemp/10000;
                dtostrf(val,4,4,charVal);
                dataSen +=  ",co2:";
                dataSen += charVal;

                valTemp = 0;
                j = 64;
                for(int i=0;i<6;i++){
                        int valInt =  strRec[i+j];
                        long valLong = pow(16, 5-i)*valInt;
                        valTemp += valLong;
                }
                val =  (float)valTemp/100;
                dtostrf(val,4,4,charVal);
                dataSen +=  ",frequency:";
                dataSen += charVal;

		Serial.print(dataSen);
		dataRec = "";
		dataSen = "";
	}
	else {
		dataRec = "";
		dataSen = "";
		Serial.print("wait");
	}
	}

}


