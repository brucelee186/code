//simple Rx on pin Dled
#include <VirtualWire.h>

int led = 13;
void setup() {
  Serial.begin(9600);
   vw_set_ptt_inverted(true); // Required for DR3100
   vw_set_rx_pin(led);
   vw_setup(4000); // Bits per sec
   pinMode(led, OUTPUT);
   vw_rx_start(); // Start the receiver PLL running
}

void loop() {
   uint8_t buf[VW_MAX_MESSAGE_LEN];
   uint8_t buflen = VW_MAX_MESSAGE_LEN;
   if (vw_get_message(buf, &buflen)){ // Non-blocking {
    Serial.println(buf[0]);
      if(buf[0]=='1') {
         digitalWrite(led,1);
      }
      if(buf[0]=='0') {
         digitalWrite(led,0);
      }
   }
}
