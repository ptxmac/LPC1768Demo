#include <stdint.h>

#include "LPC17xx.h"

#define PAUSE 1000000

// Busy loop
int pause() {
	int i,k=0;
	for (i=0;i<PAUSE;i++) {
		k++;
	}
	return k;
}


void SysTick_Handler(void) {
	LPC_GPIO1->FIOCLR = 1 << 29;
	
}

int main() {

	SysTick_Config(1000000); // 12 mhz / 1000000 = 1/12s

    LPC_GPIO1->FIODIR = 1 << 29; // Prepare LED for output
	LPC_GPIO1->FIOCLR = 1 << 29; // turn off LED

	
	while(1)
	{
		LPC_GPIO1->FIOSET = 1 << 29;
		
		pause();
		
		//LPC_GPIO1->FIOCLR = 1 << 29;

		pause();
				
	}
    
    
    
    return 0;
}
