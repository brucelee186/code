/*
  Software serial multiple serial test
 
 Receives from the hardware serial, sends to software serial.
 Receives from software serial, sends to hardware serial.
 
 The circuit: 
 * RX is digital pin 2 (connect to TX of other device)
 * TX is digital pin 3 (connect to RX of other device)
 
 created back in the mists of time
 modified 9 Apr 2012
 by Tom Igoe
 based on Mikal Hart's example
 
 This example code is in the public domain.
 
 <SoftSerial> adapted from <SoftwareSerial> for <TinyPinChange> library which allows sharing the Pin Change Interrupt Vector.
 Single difference with <SoftwareSerial>: add #include <TinyPinChange.h>  at the top of your sketch.
 RC Navy (2012): http://p.loussouarn.free.fr
 
 */
#include <SoftSerial.h>     /* Allows Pin Change Interrupt Vector Sharing */
#include <TinyPinChange.h>  /* Ne pas oublier d'inclure la librairie <TinyPinChange> qui est utilisee par la librairie <RcSeq> */

SoftSerial mySerial(1, 2); // RX, TX

void setup()  
{
 // Open serial communications and wait for port to open:
  Serial.begin(115200);


  
  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  mySerial.println("Hello, world?");
}

void loop() // run over and over
{
  while (mySerial.available()){
    Serial.println("MySerial is avaiable!");
    Serial.println(mySerial.read());
    Serial.println(Serial.read());
  }
    
  while (Serial.available()){
    Serial.println("Serial is avaiable!");
    mySerial.write(Serial.read());
  }
  
   
  //   Serial.println("Goodnight moon!");
 //    delay(1000);
 //     mySerial.println("Hello, world?");
 //     delay(1000);
}
