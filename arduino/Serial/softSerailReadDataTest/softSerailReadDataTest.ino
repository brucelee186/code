#include <SoftwareSerial.h>

SoftwareSerial mySerial(5, 6); // RX, TX

unsigned char sendDec[8] = {0x01, 0x03, 0x00, 0x48, 0x00, 0x08, 0xC4, 0x1A};
String strSerial = "";
// ec:Electric 01
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
  	}
  	Serial.print("Read: ");
  	Serial.println(strSerial);

	if(strComEc01.compareTo(strSerial)){
		Serial.println("compareTo() is test done");
	}
	delay(1000);
}

