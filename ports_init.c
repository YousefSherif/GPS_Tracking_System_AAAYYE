#include "tm4c123gh6pm.h"
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "functions_prototype.h"


//portF intit
void portF_init(void)
{
//portF 
	SYSCTL_RCGCGPIO_R |= 0x20; // Enable clock for ports
	while ((SYSCTL_PRGPIO_R & 0x00000020)==0){};  //wait til ports are activated
		
	GPIO_PORTF_LOCK_R = 0x4C4F434B; // unlock port F
	GPIO_PORTF_CR_R = 0x1F;    //allow changes
	GPIO_PORTF_DIR_R  = 0x0E;  // Configure pORTF Pin1, 2 and 3 digital output pins
  GPIO_PORTF_DEN_R  = 0x1F;  // Enable PORTF Pin 0 and 4 as a digital pins
	GPIO_PORTF_PUR_R = 0x11; //Enable pull up for PF0,PF1
	GPIO_PORTF_AMSEL_R = 0x00;        // 3) disable analog on PF
  GPIO_PORTF_PCTL_R = 0x00000000;   // 4) PCTL GPIO on PF4-0
  GPIO_PORTF_AFSEL_R = 0x00;        // 6) disable alt funct on PF7-0
}

//portF input
uint32_t portF_input(void)
	{
  return (GPIO_PORTF_DATA_R&0x11);  // read PF4,PF0 inputs
	}
//portF output
void portF_output(uint32_t data)
	{ // write PF3-PF1 outputs
  GPIO_PORTF_DATA_R = data;
	}
	

	
	
