//preprossing
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "tm4c123gh6pm.h"

//Constants Delecration

#define M_PI   3.14159265358979323846264338327950288

//functions prototype

void SystemInit(){};
void ports_init();
unsigned int portF_input();
void portF_output(uint32_t data);

	
//main function
int main(void)
{
	ports_init();
  uint32_t x ;
	/*while(1)
		{
    x = PortF_input();
			if (x == 0x01)
				{
					portF_output(0x02);	
					break;
        }
				
			else if(x == 0x10)
        {
				  portF_output(0x04);
					break;					
        }	
			
			else if(x == 0x00)
			{
				portF_output(0x08);	
				break;
			}
			else
			{
			  portF_output(0);	
			}
		}	*/
		 while(1){
    x = portF_input();
    switch(x){                    // switches are negative logic on PF0 and PF4
      case 0x01: portF_output(0x02); break;   // SW1 pressed
      case 0x10: portF_output(0x04); break;    // SW2 pressed
      case 0x00: portF_output(0x08); break;  // both switches pressed
      case 0x11: portF_output(0); break;      // neither switch pressed
    }
  }

return 0;

}




//functions body 
void ports_init(void)
{
	SYSCTL_RCGCGPIO_R |= 0x1F; // Enable clock for ports
	while ((SYSCTL_PRGPIO_R & 0x1F)==0){};  //wait til ports are activated
	
//port A
	
//port B

//port C

//port D

//port E

//port F
	GPIO_PORTF_LOCK_R = 0x4C4F434B; // unlock port F
	GPIO_PORTF_CR_R = 0x1F;    //allow changes
	GPIO_PORTF_DIR_R  = 0x0E;  // Configure pORTF Pin1, 2 and 3 digital output pins
  GPIO_PORTF_DEN_R  = 0x11;  // Enable PORTF Pin 0 and 4 as a digital pins
	GPIO_PORTF_PUR_R = 0x11; //Enable pull up for PF0,PF1
	GPIO_PORTF_AMSEL_R = 0x00;        // 3) disable analog on PF
  GPIO_PORTF_PCTL_R = 0x00000000;   // 4) PCTL GPIO on PF4-0
  GPIO_PORTF_AFSEL_R = 0x00;        // 6) disable alt funct on PF7-0


}


uint32_t PortF_Input(void){
  return (GPIO_PORTF_DATA_R&0x11);  // read PF4,PF0 inputs
}

void PortF_Output(uint32_t data){ // write PF3-PF1 outputs
  GPIO_PORTF_DATA_R = data;
}

