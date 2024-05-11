

#include "gpio.h"
void Delay(volatile unsigned int nCount)
{ while(nCount--)
  {} }
int main(void)
{
    GPIO_ClockEnable(GPIO_D);
    
    GPIO_DeInit(GPIO_D);
  
    GPIO_Init(GPIO_D,MODE_OUTPUT,PUSH_PULL,12);
    GPIO_Init(GPIO_D,MODE_OUTPUT,PUSH_PULL,13);
   
    while(1){
    GPIO_WriteBit(GPIO_D,12,SET_PIN);
    GPIO_WriteBit(GPIO_D,13,SET_PIN);
    Delay(0X2FFFFF);
    GPIO_WriteBit(GPIO_D,12,RESET_PIN);
    GPIO_WriteBit(GPIO_D,13,RESET_PIN);
    Delay(0X2FFFFF);}
  }







