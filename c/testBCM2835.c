
#include <bcm2835.h>
#define pinLed RPI_GPIO_P1_11

int main(void){
  if(!bcm2835_init())
  return 1;
  bcm2835_gpio_fsel(pinLed, BCM2835_GPIO_FSEL_OUTP);
  while(1){
    bcm2835_gpio_write(pinLed, HIGH);
    bcm2835_delay(1000);

    bcm2835_gpio_write(pinLed, LOW);
    bcm2835_delay(1000);
  }
  bcm2835_close();
  
}
