#include <stdint.h>

#include "LPC17xx.h"

#define PAUSE 5000000

int pause() {
	int i,j,k;
	for (i=0;i<PAUSE;i++) {
		k++;
	}
	return k;
}

extern void hest();

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


    //LPC_GPIO1->FIODIR = 0xffffffff;
	//LPC_GPIO1->FIOCLR = 0xffffffff;		/* turn off all the LEDs */
    //LPC_GPIO1->FIOSET = 0xffffffff;
    //LPC_GPIO1->FIOCLR = 1 << 29;		/* turn off all the LEDs */
    LPC_GPIO1->FIODIR = 1 << 29;
	
	while(1)
	{
		LPC_GPIO1->FIOSET3 = 0x20;
		
		pause();
		
		LPC_GPIO1->FIOCLR3 = 0x20;

			//return;
		pause();
				
// 		int i=0;
// 		for (i=0;i<32;i++) {
// 			LPC_GPIO1->FIODIR = 1 << i;
// 			LPC_GPIO1->FIOSET = 1 << i;
// 		}
// //        LPC_GPIO1->FIOSET = 1 << 29;
// 			//LPC_GPIO1->FIOCLR = 0xffffffff;		/* turn off all the LEDs */
// 
//         //for(j = 1000000; j > 0; j--);
// 
// 		for (i=0;i<32;i++) {
// 			LPC_GPIO1->FIODIR = 1 << i;
// 			LPC_GPIO1->FIOCLR = 1 << i;
// 		}
// 
			//LPC_GPIO1->FIOSET = 0xffffffff;		/* turn off all the LEDs */
	    
//		LPC_GPIO1->FIOCLR = 1 << 29;
	}
    
    
    
    return 0;
}
