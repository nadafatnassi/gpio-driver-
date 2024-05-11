#include "gpio.h"

void INVALID()
{
  while(1){
  }
};
void VALID()
{ 
  __asm("NOP")
    ;}

void GPIO_ClockEnable(unsigned int* gpio_x) {
__assert(__IS_GPIO_ALL_INSTANCE(gpio_x));
            *RCC_AHB1ENR |= (1<< ((gpio_x - GPIO_A)/PAS));
      
}
 

void GPIO_DeInit(unsigned int * gpio_x)
{__assert(__IS_GPIO_ALL_INSTANCE(gpio_x));

     { *RCC_AHB1RSTR|=  (1<< ((gpio_x-GPIO_A)/PAS));
       *RCC_AHB1RSTR&=~ (1<< ((gpio_x-GPIO_A)/PAS));}
}



void GPIO_Init(unsigned int * gpio_x, char Mode, char typeOutput, char pin)
{__assert(__IS_GPIO_ALL_INSTANCE(gpio_x));
 __assert(__VALID_MODE(Mode));
 __assert(__VALID_TYPE_OUTPUT(typeOutput));
 __assert(__VALID_PIN(pin));
 
   {*(gpio_x + OFFSET_MODER) &=~ (3<<(2*pin));
    *(gpio_x + OFFSET_MODER) |= (Mode<<(2*pin));}
 
    *(gpio_x + OFFSET_OTYPER/4) &=~ (1<<pin); 
    *(gpio_x + OFFSET_OTYPER/4) |= (typeOutput<<pin); 
 }
 

unsigned  char GPIO_ReadInputDataBit(unsigned int *  gpio_x, unsigned  char GPIO_Pin)
{
__assert(__IS_GPIO_ALL_INSTANCE(gpio_x));
__assert(__VALID_PIN(GPIO_Pin));



if ((* (gpio_x + OFFSET_IDR/4 ) &= (1<<GPIO_Pin)) == 0x00)
  return 0;
 else 
  return 1;
}



unsigned  short int GPIO_ReadInputData(unsigned int *  gpio_x)
{
__assert(__IS_GPIO_ALL_INSTANCE(gpio_x));



return * (gpio_x + OFFSET_IDR/4);
}


void GPIO_WriteBit(unsigned int * gpio_x, unsigned  short int GPIO_Pin, char BitVal)
{
__assert(__IS_GPIO_ALL_INSTANCE(gpio_x));
__assert(__VALID_PIN(GPIO_Pin));
__assert(__VALID_VALUE(BitVal));


if (BitVal == 0x00)
  *(gpio_x + OFFSET_ODR/4) &=~ (1<<(GPIO_Pin)) ;
 else *(gpio_x + OFFSET_ODR/4) |= (1<<GPIO_Pin) ;
}

void GPIO_Write(unsigned int * gpio_x, unsigned  short int PortVal)
{
__assert(__IS_GPIO_ALL_INSTANCE(gpio_x));


* (gpio_x + OFFSET_ODR/4) = PortVal;
}