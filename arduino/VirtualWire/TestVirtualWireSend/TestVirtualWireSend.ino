//simple Tx on pin D12
#include <VirtualWire.h>
char *controller;

void setup() {
   Serial.begin(9600);
   pinMode(13,OUTPUT);
   vw_set_ptt_inverted(true);
   vw_set_tx_pin(3);
   vw_setup(4000);// speed of data transfer Kbps
}

void loop() {
   controller="1" ;
   vw_send((uint8_t *)controller, strlen(controller));
   vw_wait_tx(); // Wait until the whole message is gone
   digitalWrite(13,1);
   Serial.println("Send 1");
   delay(2000);
   controller="0" ;
   vw_send((uint8_t *)controller, strlen(controller));
   vw_wait_tx(); // Wait until the whole message is gone
   digitalWrite(13,0);
   Serial.println("Send 0");
   delay(2000);
}
