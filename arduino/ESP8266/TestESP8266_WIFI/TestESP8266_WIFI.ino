/*show you home wifi AP*/
#include <uartWIFI.h>
WIFI wifi;
void setup() {
  Serial.begin(9600);
  delay(2000);
  wifi.confMode(STA);  // STA or  AP or  AP+STA
  wifi.Reset();
  Serial.println(wifi.showAP()); //print wifi
}
void loop() {
 
}

