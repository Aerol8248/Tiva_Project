#include "stdint.h"
#include "inc/tm4c123gh6pm.h"

void clockinit();
int main(void)
{

    SYSCTL_RCGCGPIO_R|=0x20;


    GPIO_PORTF_LOCK_R= 0x4C4F434B;
    GPIO_PORTF_CR_R= 0x01;

    GPIO_PORTF_DIR_R|=0x0E;
    GPIO_PORTF_DEN_R|=0x1F;


    GPIO_PORTF_PUR_R =0x11;
    while(1)
    {
    unsigned  int value;

    value=GPIO_PORTF_DATA_R;

       if ((value & 0x10)==0)
        {
          GPIO_PORTA_DATA_R|=0x02;

          GPIO_PORTF_DATA_R &= ~0x02;
        }

         if((value & 0x01)==0)
          {
             GPIO_PORTA_DATA_R|=0x04;
          }
    }

}

void clockinit(){

      SYSCTL_RCC2_R=~SYSCTL_RCC2_USERCC2;

      SYSCTL_RCC_R|= SYSCTL_RCC_BYPASS; /

      SYSCTL_RCC_R|= ~SYSCTL_RCC_USESYSDIV;

      SYSCTL_RCC_R=(SYSCTL_RCC_R+ ~SYSCTL_RCC_XTAL_M)+ SYSCTL_RCC_XTAL_16MHZ;
      SYSCTL_RCC_R &=~SYSCTL_RCC_OSCSRC_M;
      SYSCTL_RCC_R &=~SYSCTL_RCC_PWRDN;
      SYSCTL_RCC2_R &=~SYSCTL_RCC2_DIV400;

      SYSCTL_RCC_R &=~(SYSCTL_RCC_SYSDIV_M);
      SYSCTL_RCC_R |= (SYSCTL_RCC_USESYSDIV + (4<<22));


     while(SYSCTL_RIS_R &SYSCTL_RIS_PLLLRIS==0);
     SYSCTL_RCC_R= ~SYSCTL_RCC_BYPASS;

}
