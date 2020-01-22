#include <bcm2835.h>
#define pin RPI_GPIO_P1_2

int main(int argc, char **argv)
{
  if (!bcm2835_init())
  return 1;

  bcm2835_gpio_fsel(pin, BCM2835_GPIO_FSEL_OUTP);    

  while (1)
  {
    bcm2835_gpio_write(pin, HIGH);
    bcm2835_delay(100);
    bcm2835_gpio_write(pin, LOW);
    bcm2835_delay(100);
  }
  bcm2835_close();
  return 0;
}
