#include <stdint.h>

#include "LPC17xx.h"

#define PAUSE 1000000

int pause() {
	int i,j,k;
	for (i=0;i<PAUSE;i++) {
		k++;
	}
	return k;
}


void SysTick_Handler(void) {
	LPC_GPIO1->FIOCLR3 = 0x20;
	
}

int main() {
	int result = 0;
    int j=0;
    //LPC_GPIO1->FIODIR = 1 << 29;		/* P2.xx defined as Outputs */

    	//for(j = 1000000; j > 0; j--);

	// while (1) {
	// 	LPC_GPIO1->FIODIR3 = 0xff;
	// 	
	// 	
	// }

	SysTick_Config(1000000);

    //LPC_GPIO1->FIODIR = 0xffffffff;
	//LPC_GPIO1->FIOCLR = 0xffffffff;		/* turn off all the LEDs */
    //LPC_GPIO1->FIOSET = 0xffffffff;
    //LPC_GPIO1->FIOCLR = 1 << 29;		/* turn off all the LEDs */
    LPC_GPIO1->FIODIR = 1 << 29;
	LPC_GPIO1->FIOCLR3 = 0x20;
	//LPC_GPIO1->FIOSET3 = 0x20;
	
	while(1)
	{
		LPC_GPIO1->FIOSET3 = 0x20;
		
		pause();
		
		//LPC_GPIO1->FIOCLR3 = 0x20;

			//return;
		pause();
				
	}
    
    
    
    return 0;
}
